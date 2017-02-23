#include "expr.hpp"
#include "astcontext.hpp"
#include "eval.hpp"

#include <memory>
#include <iostream>

int main()
{
    ASTContext context;

    Expr* t = new BoolExpr( true );
    Expr* f = new BoolExpr( false );
    Expr* zero = new IntExpr( 0, context );    

    Expr* e1 = new IntExpr( 10, context );
    Expr* e2 = new NegativeExpr( e1, context );
    Expr* e3 = new IntExpr( 20, context );
    Expr* e4 = new RemExpr( e1, e3, context );
    
    Expr* AndEx = new AndThenExpr( t, t, context );
    std::cout << eval( e4 ) << '\n';
	
    // Expr* e2 = new IntExpr( 10, context );
    // Expr* e3 = new AddExpr( e1, e2, context );
    // Expr* e4 = new SubtrExpr( e1, e2, context );
    // Expr* e5 = new MulExpr( e1, e2, context );
    // Expr* e6 = new DivExpr( e1, e2, context );    
    // Expr* e7 = new RemExpr( e1, e2, context );

    // Expr* e8 = new XorExpr( t, t, context );
    // Expr* e9 = new OrExpr( t, t, context );
    // Expr* e10 = new ConditionalExpr( f, e8, e9, context );
 
    // Expr* e11 = new NegativeExpr( e1, context );
    // Expr* e12 = new LessExpr( e1, e2, context );
    // Expr* e13 = new GreaterExpr( e1, e2, context );
    // Expr* e14 = new LessEqualExpr( e1, e2, context );
    // Expr* e15 = new GreaterEqualExpr( e1, e2, context );
    // Expr* e16 = new EqualExpr( e1, e2, context );
    // Expr* e17 = new NotEqualExpr( e1, e2, context );

    // 	// Commented declarations will fail at runtime
    // 	// Expr* bad1 = new IntExpr( 203309430493409340, context );
    // 	// Expr* bad2 = new AddExpr( t, e1, context );
    // 	// Expr* bad3 = new DivExpr( e1, zero, context );
    // 	// Expr* bad4 = new AndExpr( t, e1, context );
    // 	// Expr* bad5 = new EqualExpr( t, e1, context );    

    // std::cout << e3->Evaluate( context ) << '\n';
    // std::cout << e4->Evaluate( context ) << '\n';
    // std::cout << e5->Evaluate( context ) << '\n';
    // std::cout << e6->Evaluate( context ) << '\n';
    // std::cout << e7->Evaluate( context ) << '\n';
    // std::cout << e8->Evaluate( context ) << '\n';
    // std::cout << e9->Evaluate( context ) << '\n';
    // std::cout << e10->Evaluate( context ) << '\n';
    // std::cout << e11->Evaluate( context ) << '\n';
    // std::cout << e12->Evaluate( context ) << '\n';
    // std::cout << e13->Evaluate( context ) << '\n';
    // std::cout << e14->Evaluate( context ) << '\n';
    // std::cout << e15->Evaluate( context ) << '\n';
    // std::cout << e16->Evaluate( context ) << '\n';
    // std::cout << e17->Evaluate( context ) << '\n';

    return 0;
}
