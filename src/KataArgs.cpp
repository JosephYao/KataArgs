//============================================================================
// Name        : KataArgs.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <assert.h>
#include "ArgsParserSchema.h"
#include "ArgsParser.h"
#include "ArgsParserExpection.h"
#include "Args.h"

using namespace std;

#define STRINGS_EQUAL(expect, actual) assert((actual).compare(expect) == 0)
#define FAIL() assert(0)
#define INTS_EQUAL(expect, actual) assert(expect == actual)

ArgsParserSchema schema;
void test_should_be_fine_when_no_schema_no_option()
{
	ArgsParser parser(schema);
	try
	{
		Args * args = parser.parse(NULL, 0);
		delete args;
	} catch (ArgsParserExpection *e)
	{
		FAIL();
	}
}

void test_should_have_error_message_when_no_matched_option()
{
	bool errorCatched = false;
	ArgsParser parser(schema);
	const char * option = "-x";
	try
	{
		parser.parse(&option, 1);
	} catch (ArgsParserExpection *e)
	{
		errorCatched = true;
		STRINGS_EQUAL("no such option: -x", e->errorMessage());
	}
	assert(errorCatched);
}

void test_should_have_default_int_value_when_schdma_include_int_option_and_no_option_passed()
{
	schema.addIntOption('x');
	ArgsParser parser(schema);
	Args * args = parser.parse(NULL, 0);
	INTS_EQUAL(ArgsParserSchema::DEFAULT_INT_VALUE, args->getIntValue('x'));
	delete args;
}

int main()
{
	test_should_be_fine_when_no_schema_no_option();
	test_should_have_error_message_when_no_matched_option();
	test_should_have_default_int_value_when_schdma_include_int_option_and_no_option_passed();
	cout << "OK" << endl; // prints !!!Hello World!!!
	return 0;
}
