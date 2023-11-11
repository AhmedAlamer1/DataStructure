#pragma once
class IDataStructure
{
public:
	virtual void Insert(int input)=0;
	virtual void clear() = 0;
	virtual void Display() = 0;
	virtual int Size() = 0;
};

