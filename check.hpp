#ifndef CHECK_HPP
#define CHECK_HPP

#include "astcontext.hpp"
#include "expr.hpp"

const Type* check( Expr* e, ASTContext& context )
{
    class V : public Expr::Visitor
    {
    public:
	ASTContext& context;
	const Type* r;
	V( ASTContext& context ) : context( context ) {}
	void visit( BoolExpr* e ) { r = &context.boolTy; }
	void visit( AndExpr* e ) { r = &context.boolTy; }
	void visit( OrExpr* e ) { r = &context.boolTy; }
	void visit( XorExpr* e ) { r = &context.boolTy; }
	void visit( NotExpr* e ) { r = &context.boolTy; }
	void visit( ConditionalExpr* e ) { r = check( e->e2, context ); }
	void visit( OrElseExpr* e ) { r = check( e->e1, context ); }
	void visit( AndThenExpr* e ) { r = check( e->e1, context ); }
	void visit( IntExpr* e ) { r = &context.intTy; }
	void visit( NegativeExpr* e ) { r = check( e->e1, context ); }
	void visit( AddExpr* e ) { r = check( e->e1, context ); }
	void visit( SubtrExpr* e ) { r = check( e->e1, context ); }
	void visit( MulExpr* e ) { r = check( e->e1, context ); }
	void visit( DivExpr* e ) { r = check( e->e1, context ); }
	void visit( RemExpr* e ) { r = check( e->e1, context ); }
	void visit( EqualExpr* e ) { r = &context.boolTy; }
	void visit( NotEqualExpr* e ) { r = &context.boolTy; }
	void visit( LessExpr* e ) { r = &context.boolTy; }
	void visit( GreaterExpr* e ) { r = &context.boolTy; }
	void visit( GreaterEqualExpr* e ) { r = &context.boolTy; }
	void visit( LessEqualExpr* e ) { r = &context.boolTy; }
    };

    V vis( context );
    e->Accept( vis );
    return vis.r;
}

#endif
