class Expr
{
public:
    virtual ~Expr();
};

class TrueExpr : public Expr
{
};

class FalseExpr : public Expr
{
};


class AndExpr : public Expr
{
    Expr* e1;
    Expr* e2;
};

class OrExpr : public Expr
{
    Expr* e1;
    Expr* e2;
};

class NotExpr : public Expr
{
    Expr* e;
};
