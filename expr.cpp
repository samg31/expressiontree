#include "expr.hpp"
#include <iostream>
#include <cassert>

Expr::~Expr()
{
}


AndExpr::AndExpr( Expr* lhs, Expr* rhs, ASTContext& context )
    :e1( lhs ), e2( rhs )
{
	if( e1->Check( context ) != &context.boolTy )
	{
		std::cerr << "Expression 1 not of type bool\n";
		assert( false );
	}

    if( e2->Check( context ) != &context.boolTy )
	{
		std::cerr << "Expression 2 not of type bool\n";
		assert( false );
	}
}

const Type* AndExpr::Check( ASTContext& context )
{
	return e1->Check( context );	
}

void AndExpr::Accept( Visitor& v )
{
    v.visit( this );
}

OrExpr::OrExpr( Expr* lhs, Expr* rhs, ASTContext& context )
    :e1( lhs ), e2( rhs )
{
	if( e1->Check( context ) != &context.boolTy )
	{
		std::cerr << "Expression 1 not of type bool\n";
		assert( false );
	}

    if( e2->Check( context ) != &context.boolTy )
	{
		std::cerr << "Expression 2 not of type bool\n";
		assert( false );
	}	
}

void OrExpr::Accept( Visitor& v )
{
    v.visit( this );
}

const Type* OrExpr::Check( ASTContext& context )
{
	return e1->Check( context );
}

// XorExpr::XorExpr( Expr* lhs, Expr* rhs, ASTContext& context )
//     :e1( lhs ), e2( rhs )
// {
// 	if( e1->Check( context ) != &context.boolTy )
// 	{
// 		std::cerr << "Expression 1 not of type bool\n";
// 		assert( false );
// 	}

//     if( e2->Check( context ) != &context.boolTy )
// 	{
// 		std::cerr << "Expression 2 not of type bool\n";
// 		assert( false );
// 	}
// }

// int XorExpr::Evaluate( ASTContext& context )
// {
//     return ( e1->Evaluate( context ) ^ e2->Evaluate( context ) );
// }

// const Type* XorExpr::Check( ASTContext& context )
// {
// 	return e1->Check( context );
// }


// NotExpr::NotExpr( Expr* ex, ASTContext& context )
//     :e( ex )
// {
// 	if( ex->Check( context ) != &context.boolTy )
// 	{
// 		std::cerr << "Expression not of type bool\n";
// 		assert( false );
// 	}
// }

// const Type* NotExpr::Check( ASTContext& context )
// {
//     return e->Check( context );
// }

// int NotExpr::Evaluate( ASTContext& context )
// {
//     return ( !e->Evaluate( context ) );
// }

// ConditionalExpr::ConditionalExpr( Expr* ex_if, Expr* ex_then, Expr* ex_else, ASTContext& context )
//     :e1(ex_if), e2(ex_then), e3(ex_else)
// {
// 	if( e1->Check( context ) != &context.boolTy )
// 	{
// 		std::cerr << "Conditional expression not of type bool\n";
// 		assert( false );
// 	}

//     if( e2->Check( context ) != e3->Check( context ) )
// 	{
// 		std::cerr << "Resultant expressions not of same type\n";
// 		assert( false );
// 	}
// }

// int ConditionalExpr::Evaluate( ASTContext& context )
// {
//     return ( e1->Evaluate( context ) ) ? e2->Evaluate( context ) : false;
// }

// const Type* ConditionalExpr::Check( ASTContext& context )
// {
// 	return e2->Check( context );
// }

// OrElseExpr::OrElseExpr( Expr* lhs, Expr* rhs, ASTContext& context )
//     :e1(lhs), e2(rhs)
// {
// }

// int OrElseExpr::Evaluate( ASTContext& context )
// {
//     return e2->Evaluate( context );
// }

// const Type* OrElseExpr::Check( ASTContext& context )
// {
// 	return e2->Check( context );	
// }

// AndThenExpr::AndThenExpr( Expr* ex_if, Expr* ex_then, Expr* ex_else, ASTContext& context )
//     :e1(ex_if), e2(ex_then), e3(ex_else)
// {
// 	if( e1->Check( context ) != &context.boolTy )
// 	{
// 		std::cerr << "Conditional expression not of type bool\n";
// 		assert( false );
// 	}

//     if( e2->Check( context ) != e3->Check( context ) )
// 	{
// 		std::cerr << "Resultant expressions not of same type\n";
// 		assert( false );
// 	}
// }

// int AndThenExpr::Evaluate( ASTContext& context )
// {
//     return ( e1->Evaluate( context ) ) ? e2->Evaluate( context ) : e3->Evaluate( context );
// }

// const Type* AndThenExpr::Check( ASTContext& context )
// {
// 	return e2->Check( context );
// }



// IntExpr::IntExpr( int val, ASTContext& context )
// 	:value( val )
// {
// 	if( val > ( ( 1 << 31 ) - 1 ) ||
// 		val < ( ( 1 >> 31 ) ) )
// 	{
// 		std::cerr << "Integer overflow exception\n";
// 		assert( false );
// 	}
// }

// int IntExpr::Evaluate( ASTContext& context )
// {
// 	return value;
// }

// const Type* IntExpr::Check( ASTContext& context )
// {
// 	return &context.intTy;
// }

// NegativeExpr::NegativeExpr( Expr* ex, ASTContext& context )
//     :e1( ex )
// {
// 	if( ex->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Negation of non-int type\n";
// 		assert( false );
// 	}
// }

// int NegativeExpr::Evaluate( ASTContext& context )
// {
//     return -e1->Evaluate( context );
// }

// const Type* NegativeExpr::Check( ASTContext& context )
// {
// 	return e1->Check( context );
// }

// AddExpr::AddExpr( Expr* lhs, Expr* rhs, ASTContext& context )
// 	:e1( lhs ), e2( rhs )
// {
// 	if( e1->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 1 not of type int\n";
// 		assert( false );
// 	}

//     if( e2->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 2 not of type int\n";
// 		assert( false );
// 	}	
// }

// int AddExpr::Evaluate( ASTContext& context )
// {
// 	return e1->Evaluate( context )
// 		+ e2->Evaluate( context );
// }

// const Type* AddExpr::Check( ASTContext& context )
// {
// 	return e1->Check( context );
// }

// SubtrExpr::SubtrExpr( Expr* lhs, Expr* rhs, ASTContext& context )
// 	:e1( lhs ), e2( rhs )
// {
// 	if( e1->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 1 not of type int\n";
// 		assert( false );
// 	}

//     if( e2->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 2 not of type int\n";
// 		assert( false );
// 	}	
// }

// int SubtrExpr::Evaluate( ASTContext& context )
// {
// 	return e1->Evaluate( context )
// 		- e2->Evaluate( context );
// }

// const Type* SubtrExpr::Check( ASTContext& context )
// {
// 	return e1->Check( context );
// }

// MulExpr::MulExpr( Expr* lhs, Expr* rhs, ASTContext& context )
// 	:e1( lhs ), e2( rhs )
// {
// 	if( e1->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 1 not of type int\n";
// 		assert( false );
// 	}

//     if( e2->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 2 not of type int\n";
// 		assert( false );
// 	}	
// }

// int MulExpr::Evaluate( ASTContext& context )
// {
// 	return e1->Evaluate( context )
// 		* e2->Evaluate( context );
// }

// const Type* MulExpr::Check( ASTContext& context )
// {
// 	return e1->Check( context );
// }

// DivExpr::DivExpr( Expr* lhs, Expr* rhs, ASTContext& context )
// 	:e1( lhs ), e2( rhs )
// {
// 	if( e2->Evaluate( context ) == 0 )
// 	{
// 		std::cerr << "Division by zero\n";
// 		assert( false );
// 	}
	
// 	if( e1->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 1 not of type int\n";
// 		assert( false );
// 	}

//     if( e2->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 2 not of type int\n";
// 		assert( false );
// 	}	
// }

// int DivExpr::Evaluate( ASTContext& context )
// {
// 	return e1->Evaluate( context )
// 		/ e2->Evaluate( context );
// }

// const Type* DivExpr::Check( ASTContext& context )
// {
// 	return e1->Check( context );
// }

// RemExpr::RemExpr( Expr* lhs, Expr* rhs, ASTContext& context )
// 	:e1( lhs ), e2( rhs )
// {
// 	if( e2->Evaluate( context ) == 0 )
// 	{
// 		std::cerr << "Division by zero\n";
// 		assert( false );
// 	}
	
// 	if( e1->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 1 not of type int\n";
// 		assert( false );
// 	}

//     if( e2->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 2 not of type int\n";
// 		assert( false );
// 	}	
// }

// int RemExpr::Evaluate( ASTContext& context )
// {
// 	return e1->Evaluate( context )
// 		% e2->Evaluate( context );
// }

// const Type* RemExpr::Check( ASTContext& context )
// {
// 	return e1->Check( context );
// }

// EqualExpr::EqualExpr( Expr* lhs, Expr* rhs, ASTContext& context )
// 	:e1( lhs ), e2( rhs )
// {
// 	if( e1->Check( context ) != e2->Check( context ) )
// 	{
// 		std::cerr << "Operands must be of the same type\n";
// 		assert( false );
// 	}
// }

// int EqualExpr::Evaluate( ASTContext& context )
// {
// 	return e1->Evaluate( context )
// 		== e2->Evaluate( context );
// }

// const Type* EqualExpr::Check( ASTContext& context )
// {
// 	return &context.boolTy;
// }

// NotEqualExpr::NotEqualExpr( Expr* lhs, Expr* rhs, ASTContext& context )
// 	:e1( lhs ), e2( rhs )
// {
// 	if( e1->Check( context ) != e2->Check( context ) )
// 	{
// 		std::cerr << "Operands must be of the same type\n";
// 		assert( false );
// 	}	
// }

// int NotEqualExpr::Evaluate( ASTContext& context )
// {
// 	return e1->Evaluate( context )
// 		!= e2->Evaluate( context );
// }

// const Type* NotEqualExpr::Check( ASTContext& context )
// {
// 	return &context.boolTy;
// }

// LessExpr::LessExpr( Expr* lhs, Expr* rhs, ASTContext& context )
// 	:e1( lhs ), e2( rhs )
// {
// 	if( e1->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 1 not of type int\n";
// 		assert( false );
// 	}

//     if( e2->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 2 not of type int\n";
// 		assert( false );
// 	}	
// }

// int LessExpr::Evaluate( ASTContext& context )
// {
// 	return e1->Evaluate( context )
// 		< e2->Evaluate( context );
// }

// const Type* LessExpr::Check( ASTContext& context )
// {
// 	return &context.boolTy;
// }

// GreaterExpr::GreaterExpr( Expr* lhs, Expr* rhs, ASTContext& context )
// 	:e1( lhs ), e2( rhs )
// {
// 	if( e1->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 1 not of type int\n";
// 		assert( false );
// 	}

//     if( e2->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 2 not of type int\n";
// 		assert( false );
// 	}	
// }

// int GreaterExpr::Evaluate( ASTContext& context )
// {
// 	return e1->Evaluate( context )
// 		> e2->Evaluate( context );
// }

// const Type* GreaterExpr::Check( ASTContext& context )
// {
// 	return &context.boolTy;
// }

// LessEqualExpr::LessEqualExpr( Expr* lhs, Expr* rhs, ASTContext& context )
// 	:e1( lhs ), e2( rhs )
// {
// 	if( e1->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 1 not of type int\n";
// 		assert( false );
// 	}

//     if( e2->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 2 not of type int\n";
// 		assert( false );
// 	}	
	
// }

// int LessEqualExpr::Evaluate( ASTContext& context )
// {
// 	return e1->Evaluate( context )
// 		<= e2->Evaluate( context );
// }

// const Type* LessEqualExpr::Check( ASTContext& context )
// {
// 	return &context.boolTy;
// }

// GreaterEqualExpr::GreaterEqualExpr( Expr* lhs, Expr* rhs, ASTContext& context )
// 	:e1( lhs ), e2( rhs )
// {
// 	if( e1->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 1 not of type int\n";
// 		assert( false );
// 	}

//     if( e2->Check( context ) != &context.intTy )
// 	{
// 		std::cerr << "Expression 2 not of type int\n";
// 		assert( false );
// 	}	

// }

// int GreaterEqualExpr::Evaluate( ASTContext& context )
// {
// 	return e1->Evaluate( context )
// 		>= e2->Evaluate( context );
// }

// const Type* GreaterEqualExpr::Check( ASTContext& context )
// {
// 	return &context.boolTy;
// }
