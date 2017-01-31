#include "expr.hpp"
#include "astcontext.hpp"

#include <memory>
#include <iostream>

int main()
{
    ASTContext context;

    Expr* e1 = new TrueExpr;
    Expr* e2 = new TrueExpr;
    Expr* e3 = new AndExpr( e1, e2 );

    std::cout << e3->Evaluate( context ) << '\n';
    return 0;
}
