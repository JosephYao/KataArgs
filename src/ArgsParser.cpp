#include "ArgsParser.h"
#include "Args.h"
#include "ArgsParserExpection.h"
#include "stddef.h"

const int ArgsParser::DEFAULT_INT_VALUE = 0;
const bool ArgsParser::DEFAULT_BOOLEAN_VALUE = false;

void ArgsParser::addIntOption(char option) {

}

void ArgsParser::addBooleanOption(char option) {
	booleanArgumentOptions_.insert(option);
}

bool ArgsParser::hasOption(char& option) const
{
	return booleanArgumentOptions_.count(option) > 0;
}

Args * ArgsParser::parse(const char * argv[], int argc) const {
	Args * args = new Args;
	for (; argc > 0; argc--) {
		char option = argv[argc - 1][1];
		if (!hasOption(option))
			throw new ArgsParserExpection();
		args->addBooleanArgument(option);
	}
	return args;
}
