#ifndef TYPE_HPP
#define TYPE_HPP

class Type
{
public:
    virtual ~Type(){}
};

class BoolType : public Type
{
};

class IntType : public Type
{
};

#endif
