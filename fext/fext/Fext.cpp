#include "Fext.hpp"

#include "Utils.hpp"

Fext::Fext()
{
}


Fext::~Fext()
{
}

void Fext::parse_flags(Flags& flag)
{
	if (flag.show_definition)
		define(flag._ext);
}

void Fext::define(std::string _ext)
{
	fs::path path = _ext;
	std::string ext = utils::to_lower(path.string());
	if (!fs::exists(definition_path + ext))
	{
		std::cerr << "The definiton of " << ext << " was not found.\n"
			"To add a definition use '--add-definition " << ext << " <description> <program> ...'\n";
	}
	else
	{
		std::ifstream file(definition_path + ext);
		std::getline(file, ent.def);
		while (std::getline(file, ent.ext))
		{
			ent.compatible_programs.push_back(ent.ext);
		}
		ent.ext = ext;
	}
	print_entry();
}

void Fext::print_entry()
{
	if (ent.ext == "")
		return;

	std::cout << "Definition:\n\t" << ent.def;

	if (ent.compatible_programs.size() > 0)
	{
		std::cout << "\nKnown programs:\n";
		for (auto& c : ent.compatible_programs)
		{
			std::cout << '\t' << c << '\n';
		}
	}
	else
		std::cout << "\nNo known compatible programs.\n";
}
