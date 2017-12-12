#pragma once

#include <string>

#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

const std::string definition_path = "../definitions/";

namespace utils
{
	std::string get_filename(const std::string path);

	std::string to_lower(std::string str);
	std::string to_upper(std::string str);

	bool is_installed(std::string program);
}