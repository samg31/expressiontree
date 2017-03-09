#include <iostream>
#include <iterator>
#include <typeinfo>
#include <vector>

#include "expr.hpp"
#include "astcontext.hpp"
#include "eval.hpp"
#include "check.hpp"
#include "lexer.hpp"

int main()
{
    ASTContext context;
    std::vector<Token*> Tokens;

    std::string input;
    std::string line;
    while (getline(std::cin, line))
    {
	input += '\n' + line;
    }
    std::cout << input << std::endl;
    Lexer l ( input.begin(), input.end() );
    
    while( !l.Eof() )
    {
    	Tokens.push_back( l.Next() );
    }
    
    for( auto& t : Tokens )
    {
    	std::cout << t->Kind() << ' ' <<
	    t->Value() << '\n';
    }

    return 0;
}
