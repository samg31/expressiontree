#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <cctype>
#include <memory>
#include <cassert>
#include <iostream>

#include "token.hpp"

struct Lexer
{
    std::string::iterator first;
    std::string::iterator last;
    
    std::string buf;
    Lexer( std::string::iterator first, std::string::iterator last )
	:first( first ), last( last )
    {}
    bool Eof() const { return (first == (last - 1)); }
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
		Token* t = new IntToken( n );
		return t;
	    }
		break;
	    case '(':
		Consume();
		return new PuncToken( LPAREN );
		break;
	    case ')':
		Consume();
		return new PuncToken( RPAREN );
		break;
	    case '&':
		Consume();
		if( LookAhead() == '&' )
		{
		    Consume();
		    return new PuncToken( AMPRSND );
		}
		else
		{
		    std::cout << "INVALID TOKEN '&'\n";
		    assert( true );
		}
		break;
	    case '|':
		Consume();		
		if( LookAhead() == '|' )
		{
		    Consume();
		    return new PuncToken( BAR );
		}
		break;
	    case '^':
		Consume();
		return new PuncToken( CARET );
		break;
	    case '!':
		Consume();
		if( LookAhead() == '=' )
		{
		    Consume();
		    return new PuncToken( EXCLMEQ );
		}
		return new PuncToken( EXCLM );
		break;
	    case '+':
		Consume();
		return new PuncToken( PLUS );
		break;
	    case '-':
		Consume();
		return new PuncToken( MINUS );
		break;
	    case '*':
		Consume();
		return new PuncToken( ASTRX );
		break;
	    case '/':
		Consume();
		return new PuncToken( SLASH );
		break;
	    case '%':
		Consume();
		return new PuncToken( PRCNT );
		break;
	    case '?':
		Consume();
		return new PuncToken( QUESTION );
		break;
	    case ':':
		Consume();
		return new PuncToken( COLON );
		break;
	    case '<':
		Consume();
		if( LookAhead() == '=' )
		{
		    Consume();
		    return new PuncToken( LESSEQ );
		}
		else
		    return new PuncToken( LESS );
		break;
	    case '>':
		Consume();
		if( LookAhead() == '=' )
		{
		    Consume();
		    return new PuncToken( GREATEREQ );
		}
		else
		    return new PuncToken( GREATER );
		break;
	    case '=':
		Consume();
		if( LookAhead() == '=' )
		{
		    Consume();
		    return new PuncToken( EQUAL );
		}
		break;
	    case '#':
		while( LookAhead() != '\n' )
		{
		    Ignore();
		}
	    case 't':
		Consume();
		if( LookAhead() == 'r' )
		{
		    Consume();
		    if( LookAhead() == 'u' )
		    {
			Consume();
			if( LookAhead() == 'e' )
			{
			    Consume();
			    return new BoolToken( true );
			}
			break;
		    }
		}
		std::cout << "invalid token\n";
		assert( false );
	    case 'f':
		Consume();
		if( LookAhead() == 'a' )
		{
		    Consume();
		    if( LookAhead() == 'l' )
		    {
			Consume();
			if( LookAhead() == 's' )
			{
			    Consume();
			    if( LookAhead() == 'e' )
			    {
				Consume();
				return new BoolToken( false );
			    }
			}
		    }
		}
	    case ' ':
	    case '\t':
	    case '\n':
		Ignore();
		continue;
	    default:
		std::cout << "invalid token\n";
		return nullptr;
	    }
	}
    }
};

#endif
