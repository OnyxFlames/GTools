#pragma once

#include <string>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

std::string get_filename(std::string path);
std::string get_extension(std::string path);