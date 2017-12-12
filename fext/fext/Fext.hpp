#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "Utils.hpp"

#include "Argument_Handler.hpp"

struct Entry
{
	std::string ext = "";
	std::string def = "";
	std::vector<std::string> compatible_programs = {};
};

class Fext
{
private:
	Entry ent;
public:
	Fext();
	~Fext();
	void parse_flags(Flags& flag);
	void define(std::string _ext);
	void print_entry();
};

