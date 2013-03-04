//============================================================================
// Name        : KataArgs.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <assert.h>
#include "ArgsParser.h"
#include "ArgsParserExpection.h"
#include "Args.h"
#include <memory>

using namespace std;

#define STRINGS_EQUAL(expect, actual) assert((actual).compare(expect) == 0)
#define FAIL() assert(0)
#define CHECK_EQUAL(expect, actual) assert(expect == actual)
#define CHECK(actual) assert(actual)

ArgsParser parser;
void test_should_have_error_message_when_no_matched_option()
{
	bool errorCatched = false;
	parser.addBooleanOption('y');
	const char * options[] = {"-x", "-y"};
	try
	{
		parser.parse(options, 2);
	} catch (ArgsParserExpection *e)
	{
		errorCatched = true;
		STRINGS_EQUAL("no such option: -x", e->errorMessage());
	}
	CHECK(errorCatched);
}

void test_should_have_default_int_value_when_schdma_include_int_option_and_no_option_passed()
{
	parser.addIntOption('x');
	auto_ptr<Args> args(parser.parse(NULL, 0));
	CHECK_EQUAL(ArgsParser::DEFAULT_INT_VALUE, args->getIntValue('x'));
}

void test_should_have_default_bool_value_when_schdma_include_bool_option_and_no_option_passed()
{
	parser.addBooleanOption('x');
	auto_ptr<Args> args(parser.parse(NULL, 0));
	CHECK_EQUAL(ArgsParser::DEFAULT_BOOLEAN_VALUE, args->getBooleanValue('x'));
}

void test_should_return_true_when_bool_option_passed()
{
	parser.addBooleanOption('x');
	parser.addBooleanOption('y');
	const char * options[] = {"-x", "-y"};
	auto_ptr<Args> args(parser.parse(options, 2));
	CHECK(args->getBooleanValue('x'));
	CHECK(args->getBooleanValue('y'));
}

void test_should_return_default_value_when_having_multiple_schema()
{
	parser.addBooleanOption('x');
	parser.addBooleanOption('y');
	const char * options = "-x";
	auto_ptr<Args> args(parser.parse(&options, 1));
	CHECK(!args->getBooleanValue('y'));
}

int main()
{
	test_should_have_error_message_when_no_matched_option();
	test_should_have_default_int_value_when_schdma_include_int_option_and_no_option_passed();
	test_should_have_default_bool_value_when_schdma_include_bool_option_and_no_option_passed();
	test_should_return_true_when_bool_option_passed();
	test_should_return_default_value_when_having_multiple_schema();
	cerr << "OK" << endl; // prints !!!Hello World!!!
	return 0;
}
