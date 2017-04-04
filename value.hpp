#ifndef VALUE_HPP
#define VALUE_HPP

enum ValueType
{
	IntTy,
	BoolTy
};

union ValueData
{
	int IntValue;
	bool BoolValue;
};

class Value
{
public:
	ValueType type;
	ValueData data;
};

#endif
