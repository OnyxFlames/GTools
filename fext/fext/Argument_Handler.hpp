#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "Utils.hpp"

struct Flags
{
	bool show_definition = false;
	bool add_extension = false;
	bool add_relation = false;

	std::string _ext = "";
	std::string _def = "";
	std::vector<std::string> _compat_programs;
};

class Argument_Handler
{
private:
	Flags flag;
	std::vector<std::string> arguments;
public:
	Argument_Handler();
	~Argument_Handler();
	void parse(int _c, char* _v[]);
	void set_flags();
	Flags& get_flags();
};

