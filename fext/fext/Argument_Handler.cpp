#include "Argument_Handler.hpp"



Argument_Handler::Argument_Handler()
{
}


Argument_Handler::~Argument_Handler()
{
}

void Argument_Handler::parse(int _c, char * _v[])
{
	for (int i = 0; i < _c; i++)
	{
		arguments.push_back(_v[i]);
	}
}

void Argument_Handler::set_flags()
{
	for (size_t i = 1; i < arguments.size(); i++)
	{
		if (flag.add_extension)
		{
			flag._compat_programs.push_back(arguments[i]);
		}
		else if (arguments[i] == "--add-definition")
		{
			flag.add_extension = true;
			flag._ext = arguments[++i];
			flag._def = arguments[++i];
		}
		else
		{
			flag.show_definition = true;
			flag._ext = arguments[i];
		}
	}

	if (flag.add_extension)
	{
		std::cout << flag._ext << " now defined as \n'" << flag._def << "'\n";
		std::ofstream file(definition_path + flag._ext);
		file << flag._def << '\n';

		for (const auto& prog : flag._compat_programs)
			file << prog << '\n';
	}

}

Flags & Argument_Handler::get_flags()
{
	return flag;
}
