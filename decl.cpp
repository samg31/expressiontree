#include "decl.hpp"

var_decl::var_decl( symbol* name, const Type* type )
	:name( name ), type( type ), initialized( false )
{
}

void var_decl::set_init( Expr* e )
{
	if( initialized )
		throw std::runtime_error(
			"variable has already been initialized\n" );
	else
		init = e;
}
