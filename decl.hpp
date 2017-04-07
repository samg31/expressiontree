#ifndef DECL_HPP
#define DECL_HPP

#include "symbol.hpp"
#include "type.hpp"
#include "expr.hpp"

class decl
{
public:
	virtual ~decl() = default;
};

class var_decl : public decl
{
public:
	symbol* name;
	const Type* type;
	Expr* init;
	bool initialized;
	
public:
	var_decl( symbol*, const Type* );
	void set_init( Expr* );
};

#endif
