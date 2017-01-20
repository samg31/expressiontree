#include "expr.hpp"

Expr::~Expr()
{
}

AndExpr::AndExpr( Expr* lhs, Expr* rhs )
    :e1( lhs ), e2( rhs )
{
}

NotExpr::NotExpr( Expr* ex )
    :e( ex )
{
}
