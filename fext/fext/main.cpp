#include <iostream>

#include "Fext.hpp"

#include "Utils.hpp"

#include "Argument_Handler.hpp"

int main(int argc, char* argv[])
{
	if (argc < 2)
		return -1;

	Argument_Handler ah;
	ah.parse(argc, argv);
	ah.set_flags();
	Fext fext;
	fext.parse_flags(ah.get_flags());

	return 0;
}