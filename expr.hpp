#ifndef EXPR_HPP
#define EXPR_HPP

#include "astcontext.hpp"

class Expr
{
public:
    virtual bool Evaluate( ASTContext& context ) = 0;
    virtual const Type* Check( ASTContext& context ) = 0;
    virtual ~Expr();
};

class TrueExpr : public Expr
{
    bool Evaluate( ASTContext& context ) override { return true; }
    const Type* Check( ASTContext& context ) override { return &context.boolTy; }    
};

class FalseExpr : public Expr
{
    bool Evaluate( ASTContext& context ) override { return false; }
    const Type* Check( ASTContext& context ) override { return &context.boolTy; }
};

class AndExpr : public Expr
{
    Expr* e1;
    Expr* e2;
public:
    AndExpr( Expr* lhs, Expr* rhs );

    bool Evaluate( ASTContext& context ) override;
    const Type* Check( ASTContext& context ) override;
};

class OrExpr : public Expr
{
    Expr* e1;
    Expr* e2;
public:
    OrExpr( Expr* lhs, Expr* rhs );
    
    bool Evaluate( ASTContext& context ) override;
    const Type* Check( ASTContext& context ) override;
};

class NotExpr : public Expr
{
    Expr* e;
public:
    NotExpr( Expr* ex );

    bool Evaluate( ASTContext& context ) override;
    const Type* Check( ASTContext& context ) override;
};

#endif
