#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <map>

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

inline std::string tk_string( TokenKind tk )
{
	switch( tk )
	{
    case EOFT:
		return "EOFT";
		break;
    case LPAREN:
		return "LPAREN";
		break;
    case RPAREN:
		return "RPAREN";
		break;
    case AMPRSND:
		return "AMPRSND";
		break;
    case BAR:
		return "BAR";
		break;
    case CARET:
		return "CARET";
		break;
    case EXCLM:
		return "EXCLM";
		break;
    case EXCLMEQ:
		return "EXCLMEQ";
		break;
    case INT:
		return "INT";
		break;
    case BOOL:
		return "BOOL";
		break;
    case EQUAL:
		return "EQUAL";
		break;
    case LESS:
		return "LESS";
		break;
    case GREATER:
		return "GREATER";
		break;
    case LESSEQ:
		return "LESSEQ";
		break;
    case GREATEREQ:
		return "GREATEREQ";
		break;
    case QUESTION:
		return "QUESTION";
		break;
    case COLON:
		return "COLON";
		break;
    case PLUS:
		return "PLUS";
		break;
    case MINUS:
		return "MINUS";
		break;
    case ASTRX:
		return "ASTRX";
		break;
    case SLASH:
		return "SLASH";
		break;
    case PRCNT:
		return "PRCNT";
		break;
	}
}

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
