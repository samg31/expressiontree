#include "expr.hpp"

Expr::~Expr()
{
}

AndExpr::AndExpr( Expr* lhs, Expr* rhs )
    :e1( lhs ), e2( rhs )
{
}

bool AndExpr::Evaluate()
{
    return ( e1->Evaluate() && e2->Evaluate() );
}

OrExpr::OrExpr( Expr* lhs, Expr* rhs )
    :e1( lhs ), e2( rhs )
{
}

bool OrExpr::Evaluate()
{
    return ( e1->Evaluate() || e2->Evaluate() );
}

NotExpr::NotExpr( Expr* ex )
    :e( ex )
{
}

bool NotExpr::Evaluate()
{
    return ( !e->Evaluate() );
}
