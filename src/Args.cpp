#include "Args.h"

void Args::addBooleanArgument(char option)
{
	booleanArgumentOptions_.insert(option);
}

int Args::getIntValue(char option) const
{
	return 0;
}

bool Args::getBooleanValue(char option) const
{
	return booleanArgumentOptions_.count(option) > 0;
}
