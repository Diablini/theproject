

#pragma once

#include <string>

class Base_Exception
{
	Base_Exception();
	Base_Exception(void * source);
	Base_Exception(std::string message);
	Base_Exception(std::string message, void * source);

	operator std::string () const;

	void * getSource() const;

protected:
	std::string error_message;
	void * source;
};

