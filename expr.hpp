#ifndef EXPR_HPP
#define EXPR_HPP

#include "astcontext.hpp"

class BoolExpr;
class AndExpr;
class OrExpr;
class XorExpr;
class NotExpr;
class ConditionalExpr;
class OrElseExpr;
class AndThenExpr;
class IntExpr;
class NegativeExpr;
class AddExpr;
class SubtrExpr;

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
    virtual void visit( NotExpr* ) = 0;
    virtual void visit( ConditionalExpr* ) = 0;
    virtual void visit( OrElseExpr* ) = 0;
    virtual void visit( AndThenExpr* ) = 0;
    virtual void visit( IntExpr* ) = 0;
    virtual void visit( NegativeExpr* ) = 0;
    virtual void visit( AddExpr* ) = 0;
    virtual void visit( SubtrExpr* ) = 0;
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

class NotExpr : public Expr
{
public:    
    Expr* e1;
    NotExpr( Expr* ex, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class ConditionalExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;
    Expr* e3;
    
    ConditionalExpr( Expr* ex_if, Expr* ex_then, Expr* ex_else, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class OrElseExpr : public Expr
{
public:
    Expr* e1;
    Expr* e2;
    OrElseExpr( Expr* lhs, Expr* rhs, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class AndThenExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;

    AndThenExpr( Expr* ex_if, Expr* ex_then, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

// INTEGER EXPRESSIONS
class IntExpr : public Expr
{
public:    
    int value;
    IntExpr( int val, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class NegativeExpr : public Expr
{
public:
    Expr* e1;
    NegativeExpr( Expr* ex, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class AddExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;
    AddExpr( Expr* lhs, Expr* rhs, ASTContext& context );
    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class SubtrExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;
    SubtrExpr( Expr* lhs, Expr* rhs, ASTContext& context );
    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

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

