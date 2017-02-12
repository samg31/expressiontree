#include "expr.hpp"
#include "astcontext.hpp"

#include <memory>
#include <iostream>

int main()
{
    ASTContext context;

    Expr* e1 = new IntExpr( 10 );
    Expr* e2 = new IntExpr( 20 );
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
    

    std::cout << e3->Evaluate( context ) << '\n';
    std::cout << e4->Evaluate( context ) << '\n';
    std::cout << e5->Evaluate( context ) << '\n';
    std::cout << e6->Evaluate( context ) << '\n';
    std::cout << e7->Evaluate( context ) << '\n';
    std::cout << e8->Evaluate( context ) << '\n';
    std::cout << e9->Evaluate( context ) << '\n';
    std::cout << e10->Evaluate( context ) << '\n';
    std::cout << e11->Evaluate( context ) << '\n';
    return 0;
}
