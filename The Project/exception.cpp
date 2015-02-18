

#include "exception.h"
#include <string>


Base_Exception::Base_Exception()
{
	source = NULL;
}

Base_Exception::Base_Exception(std::string message)
{
	error_message = message;
	source = NULL;
}

Base_Exception::Base_Exception(void * source)
{
	this->source = source;
}

Base_Exception::Base_Exception(std::string message, void * source)
{
	this->error_message = message;
	this->source = source;
}


Base_Exception::operator std::string() const
{
	return error_message;
}

void * Base_Exception::getSource() const
{
	return source;
}