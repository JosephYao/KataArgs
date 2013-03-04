#ifndef ARGS_PARSER__H
#define ARGS_PARSER__H

class ArgsParserSchema;
class Args;
class ArgsParser
{
public:
	ArgsParser(ArgsParserSchema& schema);
	Args * parse(const char * argv[], int argc) const;
};

#endif
