#ifndef PARSER_HPP
#define PARSER_HPP

#include <deque>

#include "lexer.hpp"
#include "astcontext.hpp"
#include "token.hpp"
#include "expr.hpp"
#include "type.hpp"
#include "translator.hpp"
#include "stmt.hpp"
#include "decl.hpp"

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

	stmt* Statement();
	stmt* DeclarationStatement();
	stmt* ExpressionStatement();

	decl* Declaration();
	decl* VariableDeclaration();

	const Type* TypeSpecifier();

	symbol* Identifier();
	
	Lexer lexer;
	ASTContext& cxt;
	std::deque<Token*> tokens;
	Translator sema;
};

#endif
