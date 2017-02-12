#include "expr.hpp"
#include <iostream>
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

XorExpr::XorExpr( Expr* lhs, Expr* rhs )
    :e1( lhs ), e2( rhs )
{
}

int XorExpr::Evaluate( ASTContext& context )
{
    return ( e1->Evaluate( context ) ^ e2->Evaluate( context ) );
}

const Type* XorExpr::Check( ASTContext& context )
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

ConditionalExpr::ConditionalExpr( Expr* ex_if, Expr* ex_then, Expr* ex_else )
    :e1(ex_if), e2(ex_then), e3(ex_else)
{
}

int ConditionalExpr::Evaluate( ASTContext& context )
{
    return ( e1->Evaluate( context ) ) ? e2->Evaluate( context ) : e3->Evaluate( context );
}

const Type* ConditionalExpr::Check( ASTContext& context )
{
    if( e1->Check( context ) != &context.boolTy )
	std::cerr << "Conditional expression not of type bool.\n";

    if( e2->Check( context ) != e3->Check( context ) )
	std::cerr << "Outcomes of a conditional must be of the same type.\n";
}

IntExpr::IntExpr( int val )
	:value( val )
{
	if( val > ( ( 1 << 31 ) - 1 ) ||
		val < ( ( 1 >> 31 ) ) )
		std::cerr << "Integer overflow exception\n";
}

int IntExpr::Evaluate( ASTContext& context )
{
	return value;
}

const Type* IntExpr::Check( ASTContext& context )
{
	return &context.intTy;
}

NegativeExpr::NegativeExpr( Expr* ex )
    :e1( ex )
{
}

int NegativeExpr::Evaluate( ASTContext& context )
{
    return -e1->Evaluate( context );
}

const Type* NegativeExpr::Check( ASTContext& context )
{
    return e1->Check( context );
}

AddExpr::AddExpr( Expr* lhs, Expr* rhs )
	:e1( lhs ), e2( rhs )
{
}

int AddExpr::Evaluate( ASTContext& context )
{
	return e1->Evaluate( context )
		+ e2->Evaluate( context );
}

const Type* AddExpr::Check( ASTContext& context )
{
	if( e1->Check( context ) != &context.intTy )
		std::cerr <<
			"Type Exception: expression 1 is not of type int\n";
	if( e2->Check( context ) != &context.intTy )
		std::cerr <<
			"Type Exception: expression 2 is not of type int\n";
}

SubtrExpr::SubtrExpr( Expr* lhs, Expr* rhs )
	:e1( lhs ), e2( rhs )
{
}

int SubtrExpr::Evaluate( ASTContext& context )
{
	return e1->Evaluate( context )
		- e2->Evaluate( context );
}

const Type* SubtrExpr::Check( ASTContext& context )
{
	if( e1->Check( context ) != &context.intTy )
		std::cerr <<
			"Type Exception: expression 1 is not of type int\n";
	if( e2->Check( context ) != &context.intTy )
		std::cerr <<
			"Type Exception: expression 2 is not of type int\n";
}

MulExpr::MulExpr( Expr* lhs, Expr* rhs )
	:e1( lhs ), e2( rhs )
{
}

int MulExpr::Evaluate( ASTContext& context )
{
	return e1->Evaluate( context )
		* e2->Evaluate( context );
}

const Type* MulExpr::Check( ASTContext& context )
{
	if( e1->Check( context ) != &context.intTy )
		std::cerr <<
			"Type Exception: expression 1 is not of type int\n";
	if( e2->Check( context ) != &context.intTy )
		std::cerr <<
			"Type Exception: expression 2 is not of type int\n";
}

DivExpr::DivExpr( Expr* lhs, Expr* rhs )
	:e1( lhs ), e2( rhs )
{
}

int DivExpr::Evaluate( ASTContext& context )
{
	return e1->Evaluate( context )
		/ e2->Evaluate( context );
}

const Type* DivExpr::Check( ASTContext& context )
{
	if( e1->Check( context ) != &context.intTy )
		std::cerr <<
			"Type Exception: expression 1 is not of type int\n";
	if( e2->Check( context ) != &context.intTy )
		std::cerr <<
			"Type Exception: expression 2 is not of type int\n";
}

RemExpr::RemExpr( Expr* lhs, Expr* rhs )
	:e1( lhs ), e2( rhs )
{
}

int RemExpr::Evaluate( ASTContext& context )
{
	return e1->Evaluate( context )
		% e2->Evaluate( context );
}

const Type* RemExpr::Check( ASTContext& context )
{
	if( e1->Check( context ) != &context.intTy )
		std::cerr <<
			"Type Exception: expression 1 is not of type int\n";
	if( e2->Check( context ) != &context.intTy )
		std::cerr <<
			"Type Exception: expression 2 is not of type int\n";
}
