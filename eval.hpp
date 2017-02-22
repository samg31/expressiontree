#ifndef EVAL_HPP
#define EVAL_HPP

#include "expr.hpp"

int eval( Expr* e )
{
    class V : public Expr::Visitor
    {
    public:
	int r;
	void visit( BoolExpr* e ) { r = e->value; }
	void visit( AndExpr* e ) { r = eval( e->e1 ) & eval( e->e2 ); }
	void visit( OrExpr* e ) { r = eval( e->e1 ) | eval( e->e2 ); }
	void visit( XorExpr* e ) { r = eval( e->e1 ) ^ eval( e->e2 ); }
	void visit( NotExpr* e ) { r = !eval( e->e1 ); }
	void visit( ConditionalExpr* e ) { r = eval( e->e1 ) ? eval( e->e2 ) : eval( e->e3 ); }
    };

    V vis;
    e->Accept( vis );
    return vis.r;
}

#endif
