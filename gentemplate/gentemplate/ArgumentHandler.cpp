#include "ArgumentHandler.hpp"

#include <iostream>

#include "Utils.hpp"

void print_usage(std::string prog_name)
{
	std::cout << prog_name << "Usage:\n"
		"\t-u/--update <hostpath>\t-\tUpdate the local database of templates\n"
		"\t-s/--search <keyword>\t-\n\tSearch local templates and list ones that match with the given keyword\n"
		"\t<template> <alias>\t-\n\tGenerate <template> as <alias> in current working directory\n";
}

ArgumentHandler::ArgumentHandler(int _c, char * _v[])
{
	if (_c < 2)
	{
		printf("%s - Template generator\n\t", get_filename(_v[0]).c_str());
		print_usage(prog_name);
		std::exit(-1);
	}
	for (int i = 1; i < _c; i++)
		args.push_back(_v[i]);
	prog_name = _v[0];
}

ArgumentHandler::~ArgumentHandler()
{
}

void ArgumentHandler::setflags()
{
	for (size_t it = 0; it < args.size(); it++)
	{
		if (args[it] == "-u" || args[it] == "--update")
		{
			flag.update_database = true;
		}
		else if (args[it] == "-s" || args[it] == "--search")
		{
			// TODO: Implement search function when you have more templates
		}
		else if (!flag.update_database && !flag.gen_template)
		{
			flag.gen_template = true;
			if (it + 1 >= args.size() || (args.size() - it > 2))
			{
				std::cerr << "Invalid arguments\n";
				std::exit(-1);
			}
			flag.name = args[it];
			flag.template_name = args[it + 1];
			it++;
		}
	}
}

Flags& ArgumentHandler::getflags()
{
	return flag;
}
