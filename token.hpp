#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

enum TokenKind
{
    EOFT,
    LPAREN,
    RPAREN,
    AMPRSND,
    BAR,
    CARET,
    EXCLM,
    EXCLMEQ,    
    INT,
    BOOL,
    EQUAL,
    LESS,
    GREATER,
    LESSEQ,
    GREATEREQ,
    QUESTION,
    COLON,
    PLUS,
    MINUS,
    ASTRX,
    SLASH,
    PRCNT
};

struct Token
{
    TokenKind kind;
    Token( TokenKind k ) : kind(k) {}
    virtual std::string Kind() = 0;
    virtual std::string Value() = 0;
    virtual ~Token() = default;
};

struct IntToken : Token
{
    int value;
    IntToken( int value ) : Token( INT ), value( value ) {}
    std::string Kind() { return std::string( "int" ); }
    std::string Value() { return std::to_string( value ); }
};

struct BoolToken : Token
{
    int value;
    BoolToken( bool value ) :Token( BOOL ), value( value ) {}
    std::string Kind() { return std::string( "bool" ); }
    std::string Value()
    {
	return (value) ? std::string("true") : std::string("false");
    }
};

struct PuncToken : Token
{
    PuncToken( TokenKind k ) : Token( k ) {}
    std::string Value() { return std::string("no value"); }
    std::string Kind()
    {
	switch( kind )
	{
	case LPAREN:
	    return std::string( "lparen" );
	    break;
	case RPAREN:
	    return std::string( "rparen" );
	    break;
	case AMPRSND:
	    return std::string( "amprsnd" );
	    break;
	case BAR:
	    return std::string( "bar" );
	    break;
	case CARET:
	    return std::string( "caret" );
	    break;
	case EXCLM:
	    return std::string( "exclamation" );
	    break;
	case EXCLMEQ:
	    return std::string( "not equals" );
	    break;
	case EQUAL:
	    return std::string( "equals" );
	    break;
	case LESS:
	    return std::string( "less than" );
	    break;
	case GREATER:
	    return std::string( "greater than" );
	    break;
	case LESSEQ:
	    return std::string( "less than or equal" );
	    break;
	case GREATEREQ:
	    return std::string( "greater than or equal" );
	    break;
	case QUESTION:
	    return std::string( "question" );
	    break;
	case COLON:
	    return std::string( "colon" );
	    break;
	case PLUS:
	    return std::string( "plus" );
	    break;
	case MINUS:
	    return std::string( "minus" );
	    break;
	case ASTRX:
	    return std::string( "asterix" );
	    break;
	case SLASH:
	    return std::string( "slash" );
	    break;
	case PRCNT:
	    return std::string( "percent" );
	    break;
	}
    }
};

#endif
