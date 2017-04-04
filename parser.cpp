#include "parser.hpp"
#include <iostream>

Parser::Parser( Lexer l, ASTContext& cxt )
	:lexer( l ), cxt( cxt )
{
	if( Token* token = lexer.Next() )
		tokens.push_front( token );
}

TokenKind Parser::Lookahead()
{
	if( !tokens.empty() )
	{
		Token* next = tokens.front();
		return next->kind;
	}
	else
	{
		return EOFT;
	}
}

Token* Parser::Consume()
{
	assert( !tokens.empty() );

	Token* token = tokens.front();
	tokens.pop_front();

	if( tokens.empty() )
	{
		if( Token* next = lexer.Next() )
			tokens.push_front( next );
	}

	return token;
}

Token* Parser::Match( TokenKind tk )
{
	if( Lookahead() == tk )
		return Consume();
	else
	{
		std::cerr << "Unexpected token\n";
	}
}

Token* Parser::MatchIf( TokenKind tk )
{
	return ( Lookahead() == tk ) ? Consume() : nullptr;
}

Expr* Parser::Expression()
{
	return ConditionalExpression();
}

Expr* Parser::AdditiveExpression()
{
	Expr* ast_1 = MultiplicativeExpression();
	while( true )
	{
		if( MatchIf( PLUS ) )
		{
			Expr* ast_2 = MultiplicativeExpression();
			ast_1 = new AddExpr( ast_1, ast_2, cxt );
		}
		else if( MatchIf( MINUS ) )
		{
			Expr* ast_2 = MultiplicativeExpression();
			ast_1 = new SubtrExpr( ast_1, ast_2, cxt );
		}
		else break;
	}
	return ast_1;
}

Expr* Parser::MultiplicativeExpression()
{
	Expr* ast_1 = PrimaryExpression();
	while( true )
	{
		if( MatchIf( ASTRX ) )
		{
		    Expr* ast_2 = UnaryExpression();
			ast_1 = new MulExpr( ast_1, ast_2, cxt );
		}
		else if( MatchIf( SLASH ) )
		{
		    Expr* ast_2 = UnaryExpression();
			ast_1 = new DivExpr( ast_1, ast_2, cxt );
		}
		else if( MatchIf( PRCNT ) )
		{
		    Expr* ast_2 = UnaryExpression();
			ast_1 = new RemExpr( ast_1, ast_2, cxt );
		}		
		else break;
	}
	return ast_1;
}

Expr* Parser::ConditionalExpression()
{
	Expr* ast_1 = ast_1 = LogicalOrExpression();
	while( true )
	{
		if( MatchIf( QUESTION ) )
		{
			Expr* ast_2 = Expression();
			Match( COLON );
			Expr* ast_3 = Expression();
			ast_1 = new ConditionalExpr( ast_1, ast_2, ast_3, cxt );
		}
		else break;
	}
	return ast_1;
}

Expr* Parser::LogicalOrExpression()
{
	Expr* ast_1 = LogicalAndExpression();
	while( true )
	{
		if( MatchIf( BAR ) )
		{
			Expr* ast_2 = LogicalAndExpression();
			ast_1 = new OrExpr( ast_1, ast_2, cxt );
		}
		else break;
	}
	return ast_1;
}

Expr* Parser::LogicalAndExpression()
{
	Expr* ast_1 = EqualityExpression();
	while( true )
	{
		if( MatchIf( AMPRSND ) )
		{
			Expr* ast_2 = EqualityExpression();
			ast_1 = new AndExpr( ast_1, ast_2, cxt );
		}
		else break;
	}
	return ast_1;
}

Expr* Parser::EqualityExpression()
{
	Expr* ast_1 = OrderingExpression();
	while( true )
	{
		if( MatchIf( EQUAL ) )
		{
			Expr* ast_2 = OrderingExpression();
			ast_1 = new EqualExpr( ast_1, ast_2, cxt );
		}
		else if( MatchIf( EXCLMEQ ) )
		{
			Expr* ast_2 = OrderingExpression();
			ast_1 = new NotEqualExpr( ast_1, ast_2, cxt );
		}
		else break;
	}
	return ast_1;
}

Expr* Parser::UnaryExpression()
{
	if( MatchIf( MINUS ) )
	{
		Expr* ast_1 = UnaryExpression();
		return new NegativeExpr( ast_1, cxt );
	}
	else if( MatchIf( EXCLM ) )
	{
		Expr* ast_1 = UnaryExpression();
		return new NotExpr( ast_1, cxt );
	}
	else
		return PrimaryExpression();
}

Expr* Parser::OrderingExpression()
{
	Expr* ast_1 = AdditiveExpression();
	while( true )
	{
		if( MatchIf( LESS ) )
		{
			Expr* ast_2 = AdditiveExpression();
			ast_1 = new LessExpr( ast_1, ast_2, cxt );
		}
		else if( MatchIf( GREATER ) )
		{
			Expr* ast_2 = AdditiveExpression();
			ast_1 = new GreaterExpr( ast_1, ast_2, cxt );
		}
		else if( MatchIf( LESSEQ ) )
		{
			Expr* ast_2 = AdditiveExpression();
			ast_1 = new LessEqualExpr( ast_1, ast_2, cxt );
		}
		else if( MatchIf( GREATEREQ ) )
		{
			Expr* ast_2 = AdditiveExpression();
			ast_1 = new GreaterEqualExpr( ast_1, ast_2, cxt );
		}
		else break;
	}

	return ast_1;
}

Expr* Parser::PrimaryExpression()
{
	switch( Lookahead() )
	{
	case INT:
	{
		IntToken* next = static_cast<IntToken*>( Consume() );
		return new IntExpr( next->value, cxt );
		break;
	}
	case BOOL:
	{
		BoolToken* next = static_cast<BoolToken*>( Consume() );
		return new BoolExpr( next->value );
		break;
	}
	case LPAREN:
	{
		Consume();
		Expr* e = Expression();
		Match( RPAREN );
		return e;
	}
	}
}
