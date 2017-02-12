#include "expr.hpp"
#include "astcontext.hpp"

#include <memory>
#include <iostream>

int main()
{
    ASTContext context;

    Expr* e1 = new IntExpr( 10 );
    Expr* e2 = new IntExpr( 10 );
    Expr* e3 = new AddExpr( e1, e2 );
    Expr* e4 = new SubtrExpr( e1, e2 );
    Expr* e5 = new MulExpr( e1, e2 );
    Expr* e6 = new DivExpr( e1, e2 );    
    Expr* e7 = new RemExpr( e1, e2 );

    Expr* t = new BoolExpr( true );
    Expr* f = new BoolExpr( false );
    Expr* e8 = new XorExpr( t, t );
    Expr* e9 = new OrExpr( t, t );
    Expr* e10 = new ConditionalExpr( f, e8, e9 );

    Expr* e11 = new NegativeExpr( e1 );
    Expr* e12 = new LessExpr( e1, e2 );
    Expr* e13 = new GreaterExpr( e1, e2 );
    Expr* e14 = new LessEqualExpr( e1, e2 );
    Expr* e15 = new GreaterEqualExpr( e1, e2 );
    Expr* e16 = new EqualExpr( e1, e2 );
    Expr* e17 = new NotEqualExpr( e1, e2 );
    

    std::cout << e3->Evaluate( context ) << '\n';
    std::cout << e4->Evaluate( context ) << '\n';
    std::cout << e5->Evaluate( context ) << '\n';
    std::cout << e6->Evaluate( context ) << '\n';
    std::cout << e7->Evaluate( context ) << '\n';
    std::cout << e8->Evaluate( context ) << '\n';
    std::cout << e9->Evaluate( context ) << '\n';
    std::cout << e10->Evaluate( context ) << '\n';
    std::cout << e11->Evaluate( context ) << '\n';
    std::cout << e12->Evaluate( context ) << '\n';
    std::cout << e13->Evaluate( context ) << '\n';
    std::cout << e14->Evaluate( context ) << '\n';
    std::cout << e15->Evaluate( context ) << '\n';
    std::cout << e16->Evaluate( context ) << '\n';
    std::cout << e17->Evaluate( context ) << '\n';    

    return 0;
}
