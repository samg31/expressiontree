#ifndef TOKEN_HPP
#define TOKEN_HPP

enum TokenKind
{
    EOFT,
    LPAREN,
    RPAREN,
    AMPRSND,
    BAR,
    CARET,
    EXCLM,
    INT,
    TRUE,
    FALSE
};

struct Token
{
    TokenKind kind;
    Token( TokenKind k ) : kind(k) {}
    virtual ~Token() = default;
};

struct LParenToken : Token
{
    LParenToken() :Token( LPAREN ) {}
};

struct RParenToken : Token
{
    RParenToken() :Token( RPAREN ) {}
};

struct AmprsndToken : Token
{
    AmprsndToken() :Token( AMPRSND ) {}
};

struct BarToken : Token
{
    BarToken() :Token( BAR ) {}
};

struct CaretToken : Token
{
    CaretToken() :Token( CARET ) {}
};

struct ExclmToken : Token
{
    ExclmToken() :Token( EXCLM ) {}    
};

struct IntToken : Token
{
    int value;
    IntToken( int value ) : Token( INT ), value( value ) {}
};

struct TrueToken : Token
{
    int value;
    TrueToken() :Token( TRUE ), value( true ) {}
};

struct FalseToken : Token
{
    int value;
    FalseToken() :Token( FALSE ), value( false ) {}
};

#endif
