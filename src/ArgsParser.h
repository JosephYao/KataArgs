#ifndef ARGS_PARSER__H
#define ARGS_PARSER__H

class ArgsParserSchema;
class Args;
class ArgsParser
{
public:
	void addIntOption(char option);
	Args * parse(const char * argv[], int argc) const;

	static const int DEFAULT_INT_VALUE;
};

#endif
