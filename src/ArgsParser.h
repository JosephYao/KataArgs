#ifndef ARGS_PARSER__H
#define ARGS_PARSER__H

#include <set>
class ArgsParserSchema;
class Args;
class ArgsParser
{
public:
	void addIntOption(char option);
	void addBooleanOption(char option);
	Args * parse(const char * argv[], int argc) const;

	static const int DEFAULT_INT_VALUE;
	static const bool DEFAULT_BOOLEAN_VALUE;
private:
	std::set<char> booleanArgumentOptions_;
	bool hasOption(char& option) const;

};

#endif
