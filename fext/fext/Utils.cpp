#include "Utils.hpp"

#include <cctype>



std::string utils::get_filename(const std::string path)
{
	return fs::path(path).filename().string();
}

std::string utils::to_lower(std::string str)
{
	for (auto& c : str)
		c = tolower(c);
	return str;
}

std::string utils::to_upper(std::string str)
{
	for (auto& c : str)
		c = toupper(c);
	return str;
}

bool utils::is_installed(std::string program)
{
	fs::path path("C:/Program Files (x86)/");
	
	for (auto& p : fs::recursive_directory_iterator(path))
	{
		if (fs::is_directory(p) && p.path().filename() == program)
			return true;
		else
		{
			if(fs::is_directory(p))
				printf("Checking %ls\n", p.path().filename().c_str());
		}
	}

	path = "C:/Program Files/";

	for (auto& p : fs::recursive_directory_iterator(path))
	{
		if (fs::is_directory(p) && p.path().filename() == program)
			return true;
		else
		{
			if (fs::is_directory(p))
				printf("Checking %ls\n", p.path().filename().c_str());
		}
	}
	return false;

}
