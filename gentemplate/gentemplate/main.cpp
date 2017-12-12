#include <iostream>

#include <experimental/filesystem>

#include "Gentemplate.hpp"

namespace fs = std::experimental::filesystem;

int main(int argc, char* argv[])
{
	ArgumentHandler ah(argc, argv);
	ah.setflags();
	Gentemplate gt(ah);

	return 0;
}