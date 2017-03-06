#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <cctype>
#include <memory>

#include "token.hpp"

struct Lexer
{
    std::string::iterator first;
    std::string::iterator last;
    
    std::string buf;
    Lexer( std::string::iterator first, std::string::iterator last )
	:first( first ), last( last )
    {}
    bool Eof() const { return first == last; }
    char Consume()
    {
	if( Eof() )
	    return 0;
	buf += *first++;
	return buf.back();
    }
    char Ignore() { return ( Eof() ) ? 0 : *first++; }
    char LookAhead() { return ( Eof() ) ? 0 : *first; }
    Token* Next()
    {
	Token* r;
	buf.clear();
	while( !Eof() )
	{
	    switch( LookAhead() )
	    {
	    case '0':
	    case '1':
	    case '2':
	    case '3':
	    case '4':
	    case '5':
	    case '6':
	    case '7':
	    case '8':
	    case '9':
	    {
		do
		{
		    Consume();
		} while( !Eof() && std::isdigit( LookAhead() ) );
		int n = std::stoi( buf );
		r = new IntToken( n );
		std::cout << n << '\n';
	    }
		break;
	    case '(':
		r = new LParenToken;
		break;
	    case ')':
		r = new RParenToken;
		break;
	    case '&':
		if( LookAhead() == '&' )
		{
		    Consume();
		    r = new AmprsndToken;
		}
		break;
	    case '|':
		if( LookAhead() == '|' )
		{
		    Consume();
		    r = new BarToken;
		}
		break;
	    case '^':
		r = new CaretToken;
		break;
	    case '!':
		if( LookAhead() == '=' )
		{
		    Consume();
		    // r = new ExclmEqToken;
		}
		r = new ExclmToken;
		break;
	    case '+':
		r = new PlusToken;
		break;
	    case '-':
		r = new MinusToken;
		break;
	    case '*':
		r = new AstrxToken;
		break;
	    case '/':
		r = new SlashToken;
		break;
	    case '%':
		r = new PrcntToken;
		break;
	    case '?':
		r = new QuestionToken;
		break;
	    case ':':
		r = new ColonToken;
		break;
	    case '<':
		if( LookAhead() == '=' )
		{
		    Consume();
		    r = new LessEqToken;
		}
		else
		    r = new LessToken;
		break;
	    case '>':
		if( LookAhead() == '=' )
		{
		    Consume();
		    r = new GreaterEqToken;
		}
		else
		    r = new GreaterToken;
		break;
	    case '=':
		if( LookAhead() == '=' )
		{
		    Consume();
		    r = new EqualToken;
		}
		break;
	    case '#':
		while( LookAhead() != '\n' )
		{
		    Consume();
		}
	    case 't':
		break;
	    case ' ':
	    case '\t':
	    case '\n':
		Consume();
	    }
	}
	return r;
    }
};

#endif
