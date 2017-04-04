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
		void visit( OrElseExpr* e ) { r = eval( e->e1 ) || eval( e->e2 ); }
		void visit( AndThenExpr* e ) { r = eval( e->e1 ) && eval( e->e2 ); }
		void visit( IntExpr* e ) { r = e->value; }
		void visit( NegativeExpr* e ) { r = -eval( e->e1 ); }
		void visit( AddExpr* e ) { r = eval( e->e1 ) + eval( e->e2 ); }
		void visit( SubtrExpr* e ) { r = eval( e->e1 ) - eval( e->e2 ); }
		void visit( MulExpr* e ) { r = eval( e->e1 ) * eval( e->e2 ); }
		void visit( DivExpr* e ) { r = eval( e->e1 ) / eval( e->e2 ); }
		void visit( RemExpr* e ) { r = eval( e->e1 ) % eval( e->e2 ); }
		void visit( EqualExpr* e ) { r = eval( e->e1 ) == eval( e->e2 ); }
		void visit( NotEqualExpr* e ) { r = eval( e->e1 ) != eval( e->e2 ); }
		void visit( LessExpr* e ) { r = eval( e->e1 ) < eval( e->e2 ); }
		void visit( GreaterExpr* e ) { r = eval( e->e1 ) > eval( e->e2 ); }
		void visit( LessEqualExpr* e ) { r = eval( e->e1 ) <= eval( e->e2 ); }
		void visit( GreaterEqualExpr* e ) { r = eval( e->e1 ) >= eval( e->e2 ); }
    };

    V vis;
    e->Accept( vis );
    return vis.r;
}

#endif
