#include "Gentemplate.hpp"

#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

Gentemplate::Gentemplate(ArgumentHandler & ah)
{
	flag = ah.getflags();
	generate(flag.name, flag.template_name);
}

Gentemplate::~Gentemplate()
{
}

void Gentemplate::generate(std::string _temp, std::string _name)
{
	if (!fs::exists(database_path + _temp))
	{
		std::cerr << "Template '" << _temp << "' was not found!\nUpdate database using --update <hostpath>.";
		std::exit(-1);
	}
	else if (fs::exists(_name))
	{
		std::cerr << "File '" << _name << "' already exists!\n";
		std::exit(-1);
	}
	else
	{
		fs::copy(
			database_path + _temp,
			_name);
		std::cout << "Successfully generated template '" << _temp << "' as '" << _name << "'\n";
	}
}
