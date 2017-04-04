#ifndef PARSER_HPP
#define PARSER_HPP

#include <deque>

#include "lexer.hpp"
#include "astcontext.hpp"
#include "token.hpp"
#include "expr.hpp"

struct Parser
{
	Parser( Lexer l, ASTContext& cxt );
	TokenKind Lookahead();
	Token* Consume();
	Token* Match( TokenKind tk );
	Token* MatchIf( TokenKind tk );
	Expr* Expression();
	Expr* AdditiveExpression();
	Expr* MultiplicativeExpression();
	Expr* ConditionalExpression();
	Expr* LogicalOrExpression();
	Expr* LogicalAndExpression();
	Expr* EqualityExpression();
	Expr* OrderingExpression();	
	Expr* UnaryExpression();	
	Expr* PrimaryExpression();

	Lexer lexer;
	ASTContext& cxt;
	std::deque<Token*> tokens;
};

#endif
