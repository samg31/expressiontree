#include "expr.hpp"

#include <memory>
#include <iostream>

int main()
{
    Expr* e1 = new TrueExpr;
    Expr* e2 = new TrueExpr;
    Expr* e3 = new AndExpr( e1, e2 );

    std::cout << e3->Evaluate() << '\n';
    return 0;
}
