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

int main()
{
	ASTContext context;
	std::vector<Token*> Tokens;
	keyword_table kw;

	bool quit = false;

	while( !quit )
	{
		std::string input;
		std::string line;
		getline(std::cin, line);
		input += line + '\n';
		Lexer l ( input.begin(), input.end(), kw );

		Parser p( l, context );
		Expr* e = p.Expression();
		std::cout << eval( e ) << std::endl;
	}

	return 0;
}
