#include "Utils.hpp"

std::string get_filename(std::string path)
{
	return
		fs::path(path)
		.filename()
		.string();
}

std::string get_extension(std::string path)
{
	return
		fs::path(path)
		.filename()
		.extension()
		.string();
}
