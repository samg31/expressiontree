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
    EXCLMEQ,    
    INT,
    TRUE,
    FALSE,
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

struct ExclmEqToken : Token
{
    ExclmEqToken() :Token( EXCLMEQ ) {}
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

struct EqualToken : Token
{
    EqualToken() :Token( EQUAL ) {}
};

struct LessToken : Token
{
    LessToken() : Token( LESS ) {}
};

struct GreaterToken : Token
{
    GreaterToken() : Token( GREATER ) {}
};

struct LessEqToken : Token
{
    LessEqToken() : Token( LESSEQ ) {}
};

struct GreaterEqToken : Token
{
    GreaterEqToken() : Token( GREATEREQ ) {}
};

struct QuestionToken : Token
{
    QuestionToken() : Token( QUESTION ) {}
};

struct ColonToken : Token
{
    ColonToken() : Token( COLON ) {}
};

struct PlusToken : Token
{
    PlusToken() : Token( PLUS ) {}
};

struct MinusToken : Token
{
    MinusToken() : Token( MINUS ) {}
};

struct AstrxToken : Token
{
    AstrxToken() : Token( ASTRX ) {}
};

struct SlashToken : Token
{
    SlashToken() : Token( SLASH ) {}
};

struct PrcntToken : Token
{
    PrcntToken() : Token( PRCNT ) {}
};

#endif
