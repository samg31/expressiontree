#include "parser.hpp"
#include <iostream>

Parser::Parser( Lexer l, ASTContext& cxt )
	:lexer( l ), cxt( cxt ), sema( Translator( cxt ) )
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
			ast_1 = sema.on_add( ast_1, ast_2 );
		}
		else if( MatchIf( MINUS ) )
		{
			Expr* ast_2 = MultiplicativeExpression();
			ast_1 = sema.on_sub( ast_1, ast_2 );
		}
		else break;
	}
	return ast_1;
}

Expr* Parser::MultiplicativeExpression()
{
	Expr* ast_1 = UnaryExpression();
	while( true )
	{
		if( MatchIf( ASTRX ) )
		{
		    Expr* ast_2 = UnaryExpression();
			ast_1 = sema.on_mul( ast_1, ast_2 );
		}
		else if( MatchIf( SLASH ) )
		{
		    Expr* ast_2 = UnaryExpression();
			ast_1 = sema.on_div( ast_1, ast_2 );
		}
		else if( MatchIf( PRCNT ) )
		{
		    Expr* ast_2 = UnaryExpression();
			ast_1 = sema.on_rem( ast_1, ast_2 );
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
			ast_1 = sema.on_cond( ast_1, ast_2, ast_3 );
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
			ast_1 = sema.on_or( ast_1, ast_2 );
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
			ast_1 = sema.on_and( ast_1, ast_2 );
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
			ast_1 = sema.on_equal( ast_1, ast_2 );
		}
		else if( MatchIf( EXCLMEQ ) )
		{
			Expr* ast_2 = OrderingExpression();
			ast_1 = sema.on_inequal( ast_1, ast_2 );
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
		return sema.on_neg( ast_1 );
	}
	else if( MatchIf( EXCLM ) )
	{
		Expr* ast_1 = UnaryExpression();
		return sema.on_not( ast_1 );
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
			ast_1 = sema.on_less( ast_1, ast_2 );
		}
		else if( MatchIf( GREATER ) )
		{
			Expr* ast_2 = AdditiveExpression();
			ast_1 = sema.on_greater( ast_1, ast_2 );
		}
		else if( MatchIf( LESSEQ ) )
		{
			Expr* ast_2 = AdditiveExpression();
			ast_1 = sema.on_lesseq( ast_1, ast_2 );
		}
		else if( MatchIf( GREATEREQ ) )
		{
			Expr* ast_2 = AdditiveExpression();
			ast_1 = sema.on_greatereq( ast_1, ast_2 );
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
	case TRUE_KW:
	case FALSE_KW:
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

// STATEMENT PARSING

stmt* Parser::Statement()
{
	switch( Lookahead() )
	{
	case VAR_KW:
		return DeclarationStatement();
	default:
		return ExpressionStatement();
	}
}

stmt* Parser::DeclarationStatement()
{
	decl* d = Declaration();
	return sema.on_decl_stmt( d );
}

stmt* Parser::ExpressionStatement()
{
	Expr* e = Expression();
	Match( SEMICOLON );
	return sema.on_expr_stmt( e );
}

decl* Parser::Declaration()
{
	switch( Lookahead() )
	{
	case VAR_KW:
		return VariableDeclaration();
	}
	throw std::runtime_error( "Unexpected declaration\n" );
}

decl* Parser::VariableDeclaration()
{
	Consume();
	const Type* t = TypeSpecifier();	
	symbol* n = Identifier();
	decl* var = sema.on_var_decl( t, n );
	Match( ASSIGN );
	Expr* e = Expression();
	sema.on_var_compl( var, e );
	Match( SEMICOLON );
	return var;
}

symbol* Parser::Identifier()
{
	Token* id = Match( ID );
	return sema.on_id( id );
}

const Type* Parser::TypeSpecifier()
{
	switch( Lookahead() )
	{
	case BOOL_KW:
		Consume();
		return sema.on_bool_type();
	case INT_KW:
		Consume();
		return sema.on_int_type();
	}
}
