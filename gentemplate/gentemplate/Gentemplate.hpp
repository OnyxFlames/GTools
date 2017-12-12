#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include "ArgumentHandler.hpp"

const std::string database_path = "../templates/";

class Gentemplate
{
public:
	Gentemplate(ArgumentHandler& ah);
	~Gentemplate();
	void generate(std::string _temp, std::string _name);
};

