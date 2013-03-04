#ifndef ARGS__H
#define ARGS__H
#include <string>
#include <set>
class Args
{
public:
	void addBooleanArgument(char option);
	int getIntValue(char option) const;
	bool getBooleanValue(char option) const;
private:
	std::set<char> booleanArgumentOptions_;
};

#endif
