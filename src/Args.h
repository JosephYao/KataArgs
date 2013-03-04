#ifndef ARGS__H
#define ARGS__H
#include <string>
class Args
{
public:
	int getIntValue(char option) const;
	static const int DEFAULT_INT_VALUE;
};

#endif
