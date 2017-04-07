#include <iostream>
#include <iterator>
#include <typeinfo>
#include <vector>

#include "expr.hpp"
#include "astcontext.hpp"
#include "eval.hpp"
#include "check.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "stmt.hpp"

int main()
{
	ASTContext context;
	std::vector<Token*> Tokens;
	keyword_table kw;
	symbol_table sym;

	bool quit = false;

	while( !quit )
	{
		std::string input;
		std::string line;
		getline(std::cin, line);
		input += line + '\n';
		Lexer l ( input.begin(), input.end(), kw, sym );

		Parser p( l, context );
		stmt* s = p.Statement();
		if( dynamic_cast<expr_stmt*>(s) )
		{
			expr_stmt* exst = dynamic_cast<expr_stmt*>( s );			
			std::cout << eval(exst->expression) << '\n';
		}
		else if( dynamic_cast<decl_stmt*>(s) )
		{
			decl_stmt* d = dynamic_cast<decl_stmt*>( s );
			var_decl* v = dynamic_cast<var_decl*>( d->entity );
			std::cout << eval(v->init) << '\n';
		}

	}

	return 0;
}
