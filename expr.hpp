#ifndef EXPR_HPP
#define EXPR_HPP

#include "astcontext.hpp"

class BoolExpr;
class AndExpr;
class OrExpr;
class XorExpr;

class Expr
{
public:    
    struct Visitor;
    virtual const Type* Check( ASTContext& context ) = 0;
    virtual void Accept( Visitor& ) = 0;
    virtual ~Expr();
};

struct Expr::Visitor
{    
    virtual void visit( BoolExpr* ) = 0;
    virtual void visit( AndExpr* ) = 0;
    virtual void visit( OrExpr* ) = 0;
    virtual void visit( XorExpr* ) = 0;
};

// BOOLEAN EXPRESSIONS

class BoolExpr : public Expr
{
public:    
    int value;
    BoolExpr( int val ):value(val){}
    const Type* Check( ASTContext& context ) override { return &context.boolTy; }
    void Accept( Visitor& v ) { v.visit( this ); }
};

class AndExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;
    AndExpr( Expr* lhs, Expr* rhs, ASTContext& context );

    const Type* Check( ASTContext& context ) override;
    void Accept( Visitor& v );
};

class OrExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;
    OrExpr( Expr* lhs, Expr* rhs, ASTContext& context );
    
    const Type* Check( ASTContext& context ) override;
    void Accept( Visitor& v );
};

class XorExpr : public Expr
{
public:
    Expr* e1;
    Expr* e2;
    
    XorExpr( Expr* lhs, Expr* rhs, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

// class NotExpr : public Expr
// {
//     Expr* e;
// public:
//     NotExpr( Expr* ex, ASTContext& context );

//     int Evaluate( ASTContext& context ) override;
//     const Type* Check( ASTContext& context ) override;
// };

// class ConditionalExpr : public Expr
// {
//     Expr* e1;
//     Expr* e2;
//     Expr* e3;
// public:
//     ConditionalExpr( Expr* ex_if, Expr* ex_then, Expr* ex_else, ASTContext& context );

//     int Evaluate( ASTContext& context ) override;
//     const Type* Check( ASTContext& context ) override;
// };

// class OrElseExpr : public Expr
// {
//     Expr* e1;
//     Expr* e2;
// public:
//     OrElseExpr( Expr* lhs, Expr* rhs, ASTContext& context );

//     int Evaluate( ASTContext& context ) override;
//     const Type* Check( ASTContext& context ) override;
// };

// class AndThenExpr : public Expr
// {
//     Expr* e1;
//     Expr* e2;
//     Expr* e3;
// public:
//     AndThenExpr( Expr* ex_if, Expr* ex_then, Expr* ex_else, ASTContext& context );

//     int Evaluate( ASTContext& context ) override;
//     const Type* Check( ASTContext& context ) override;
// };

// // INTEGER EXPRESSIONS
// class IntExpr : public Expr
// {
// 	int value;
// public:
// 	IntExpr( int val, ASTContext& context );

//     int Evaluate( ASTContext& context ) override;
//     const Type* Check( ASTContext& context ) override;
// };

// class NegativeExpr : public Expr
// {
//     Expr* e1;
// public:
//     NegativeExpr( Expr* ex, ASTContext& context );

//     int Evaluate( ASTContext& context ) override;
//     const Type* Check( ASTContext& context ) override;
// };

// class AddExpr : public Expr
// {
// 	Expr* e1;
// 	Expr* e2;
// public:
// 	AddExpr( Expr* lhs, Expr* rhs, ASTContext& context );
// 	int Evaluate( ASTContext& context ) override;
// 	const Type* Check( ASTContext& context ) override;
// };

// class SubtrExpr : public Expr
// {
// 	Expr* e1;
// 	Expr* e2;
// public:
// 	SubtrExpr( Expr* lhs, Expr* rhs, ASTContext& context );
// 	int Evaluate( ASTContext& context ) override;
// 	const Type* Check( ASTContext& context ) override;
// };

// class MulExpr : public Expr
// {
// 	Expr* e1;
// 	Expr* e2;
// public:
// 	MulExpr( Expr* lhs, Expr* rhs, ASTContext& context );
// 	int Evaluate( ASTContext& context ) override;
// 	const Type* Check( ASTContext& context ) override;
// };

// class DivExpr : public Expr
// {
// 	Expr* e1;
// 	Expr* e2;
// public:
// 	DivExpr( Expr* lhs, Expr* rhs, ASTContext& context );
// 	int Evaluate( ASTContext& context ) override;
// 	const Type* Check( ASTContext& context ) override;
// };

// class RemExpr : public Expr
// {
// 	Expr* e1;
// 	Expr* e2;
// public:
// 	RemExpr( Expr* lhs, Expr* rhs, ASTContext& context );
// 	int Evaluate( ASTContext& context ) override;
// 	const Type* Check( ASTContext& context ) override;
// };

// class EqualExpr : public Expr
// {
//     Expr* e1;
//     Expr* e2;
// public:
//     EqualExpr( Expr* lhs, Expr* rhs, ASTContext& context );

//     int Evaluate( ASTContext& context ) override;
//     const Type* Check( ASTContext& context ) override;  
// };

// class NotEqualExpr : public Expr
// {
//     Expr* e1;
//     Expr* e2;
// public:
//     NotEqualExpr( Expr* lhs, Expr* rhs, ASTContext& context );

//     int Evaluate( ASTContext& context ) override;
//     const Type* Check( ASTContext& context ) override;  
// };

// class LessExpr : public Expr
// {
//     Expr* e1;
//     Expr* e2;
// public:
//     LessExpr( Expr* lhs, Expr* rhs, ASTContext& context );

//     int Evaluate( ASTContext& context ) override;
//     const Type* Check( ASTContext& context ) override;

// };

// class GreaterExpr : public Expr
// {
//     Expr* e1;
//     Expr* e2;
// public:
//     GreaterExpr( Expr* lhs, Expr* rhs, ASTContext& context );

//     int Evaluate( ASTContext& context ) override;
//     const Type* Check( ASTContext& context ) override;

// };

// class LessEqualExpr : public Expr
// {
//     Expr* e1;
//     Expr* e2;
// public:
//     LessEqualExpr( Expr* lhs, Expr* rhs, ASTContext& context );

//     int Evaluate( ASTContext& context ) override;
//     const Type* Check( ASTContext& context ) override;

// };

// class GreaterEqualExpr : public Expr
// {
//     Expr* e1;
//     Expr* e2;
// public:
//     GreaterEqualExpr( Expr* lhs, Expr* rhs, ASTContext& context );

//     int Evaluate( ASTContext& context ) override;
//     const Type* Check( ASTContext& context ) override;

// };
    
#endif

