#include "expr.hpp"
#include <iostream>

Expr::~Expr()
{
}

AndExpr::AndExpr( Expr* lhs, Expr* rhs )
    :e1( lhs ), e2( rhs )
{
}

int AndExpr::Evaluate( ASTContext& context )
{
    return ( e1->Evaluate( context ) && e2->Evaluate( context ) );
}

const Type* AndExpr::Check( ASTContext& context )
{
    if( e1->Check( context ) != &context.boolTy )
	throw( "Expression 1 not of type bool\n" );

    if( e2->Check( context ) != &context.boolTy )
	throw( "Expression 2 not of type bool\n" );
}

OrExpr::OrExpr( Expr* lhs, Expr* rhs )
    :e1( lhs ), e2( rhs )
{
}

int OrExpr::Evaluate( ASTContext& context )
{
    return ( e1->Evaluate( context ) || e2->Evaluate( context ) );
}

const Type* OrExpr::Check( ASTContext& context )
{
    if( e1->Check( context ) != &context.boolTy )
	throw( "Expression 1 not of type bool\n" );

    if( e2->Check( context ) != &context.boolTy )
	throw( "Expression 2 not of type bool\n" );
}

NotExpr::NotExpr( Expr* ex )
    :e( ex )
{
}

const Type* NotExpr::Check( ASTContext& context )
{
    if( e->Check( context ) != &context.boolTy )
	throw( "Expression not of type bool\n" );
}

int NotExpr::Evaluate( ASTContext& context )
{
    return ( !e->Evaluate( context ) );
}

IntExpr::IntExpr( int val )
	:value( val )
{
	if( val > ( ( 2 << 31 ) - 1 ) ||
		val < ( 2 >> 31 ) )
		throw( "Integer overflow exception\n" );
}

int IntExpr::Evaluate( ASTContext& context )
{
	return value;
}

const Type* IntExpr::Check( ASTContext& context )
{
	return &context.intTy;
}

