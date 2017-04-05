#ifndef TRANSLATOR_HPP
#define TRANSLATOR_HPP

#include "expr.hpp"
#include "astcontext.hpp"
#include "token.hpp"

class Translator
{
	ASTContext& cxt;
public:
	Translator( ASTContext& cxt );
	Expr* on_add( Expr*, Expr* );
	Expr* on_sub( Expr*, Expr* );
	Expr* on_mul( Expr*, Expr* );
	Expr* on_div( Expr*, Expr* );
	Expr* on_rem( Expr*, Expr* );
	Expr* on_neg( Expr* );

	Expr* on_and( Expr*, Expr* );
	Expr* on_or( Expr*, Expr* );
	Expr* on_cond( Expr*, Expr*, Expr* );

	Expr* on_equal( Expr*, Expr* );
	Expr* on_inequal( Expr*, Expr* );
	
	Expr* on_less( Expr*, Expr* );
	Expr* on_greater( Expr*, Expr* );
	Expr* on_lesseq( Expr*, Expr* );
	Expr* on_greatereq( Expr*, Expr* );
	Expr* on_not( Expr* );
	
	Expr* on_bool( BoolToken* );
	Expr* on_int( IntToken* );
};

#endif
