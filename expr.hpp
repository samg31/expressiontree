#ifndef EXPR_HPP
#define EXPR_HPP

#include "astcontext.hpp"
#include "value.hpp"

class Expr
{
public:
    virtual int Evaluate( ASTContext& context ) = 0;
    virtual const Type* Check( ASTContext& context ) = 0;
    virtual ~Expr();
};

// BOOLEAN EXPRESSIONS

class TrueExpr : public Expr
{
    int Evaluate( ASTContext& context ) override { return 1; }
    const Type* Check( ASTContext& context ) override { return &context.boolTy; }    
};

class FalseExpr : public Expr
{
    int Evaluate( ASTContext& context ) override { return 0; }
    const Type* Check( ASTContext& context ) override { return &context.boolTy; }
};

class AndExpr : public Expr
{
    Expr* e1;
    Expr* e2;
public:
    AndExpr( Expr* lhs, Expr* rhs );

    int Evaluate( ASTContext& context ) override;
    const Type* Check( ASTContext& context ) override;
};

class OrExpr : public Expr
{
    Expr* e1;
    Expr* e2;
public:
    OrExpr( Expr* lhs, Expr* rhs );
    
    int Evaluate( ASTContext& context ) override;
    const Type* Check( ASTContext& context ) override;
};

class NotExpr : public Expr
{
    Expr* e;
public:
    NotExpr( Expr* ex );

    int Evaluate( ASTContext& context ) override;
    const Type* Check( ASTContext& context ) override;
};

// INTEGER EXPRESSIONS
class IntExpr : public Expr
{
	int value;
public:
	IntExpr( int val );
	int Evaluate( ASTContext& context ) override;
	const Type* Check( ASTContext& context ) override;
};

class AddExpr : public Expr
{
	Expr* e1;
	Expr* e2;
public:
	AddExpr( Expr* lhs, Expr* rhs );
	int Evaluate( ASTContext& context ) override;
	const Type* Check( ASTContext& context ) override;
};

class SubtrExpr : public Expr
{
	Expr* e1;
	Expr* e2;
public:
	SubtrExpr( Expr* lhs, Expr* rhs );
	int Evaluate( ASTContext& context ) override;
	const Type* Check( ASTContext& context ) override;
};

class MulExpr : public Expr
{
	Expr* e1;
	Expr* e2;
public:
	MulExpr( Expr* lhs, Expr* rhs );
	int Evaluate( ASTContext& context ) override;
	const Type* Check( ASTContext& context ) override;
};

class DivExpr : public Expr
{
	Expr* e1;
	Expr* e2;
public:
	DivExpr( Expr* lhs, Expr* rhs );
	int Evaluate( ASTContext& context ) override;
	const Type* Check( ASTContext& context ) override;
};

class RemExpr : public Expr
{
	Expr* e1;
	Expr* e2;
public:
	RemExpr( Expr* lhs, Expr* rhs );
	int Evaluate( ASTContext& context ) override;
	const Type* Check( ASTContext& context ) override;
};

#endif

