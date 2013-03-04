#include "ArgsParser.h"
#include "Args.h"
#include "ArgsParserExpection.h"
#include "stddef.h"

const int ArgsParser::DEFAULT_INT_VALUE = 0;

void ArgsParser::addIntOption(char option) {

}

Args * ArgsParser::parse(const char * argv[], int argc) const {
	Args * args = new Args;
	if (argc == 1)
		throw new ArgsParserExpection();
	return args;
}
