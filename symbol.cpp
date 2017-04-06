#include "symbol.hpp"

symbol* symbol_table::insert( const std::string& in )
{
	auto result = symbols.insert( {in, nullptr} );
	return &result.first->first;
}

symbol* symbol_table::find( const std::string& in )
{
	auto result = symbols.find( in );
	return &result->first;
}
