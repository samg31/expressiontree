#include "expr.hpp"

int main()
{
    Expr* e1 = new TrueExpr;
    Expr* e2 = new FalseExpr;
    Expr* e3 = new AndExpr( e1, e2 );

    delete e1;
    delete e2;
    delete e3;

    return 0;
}
