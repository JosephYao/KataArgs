#include "ArgsParser.h"
#include "Args.h"
#include "ArgsParserExpection.h"
#include "stddef.h"

ArgsParser::ArgsParser(ArgsParserSchema& schema) {

}

Args * ArgsParser::parse(const char * argv[], int argc) const {
	Args * args = new Args;
	if (argc == 1)
		throw new ArgsParserExpection();
	return args;
}
