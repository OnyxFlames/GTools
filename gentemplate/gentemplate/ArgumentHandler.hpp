#pragma once

#include <string>
#include <vector>


// Note:
//		Have program track last list of files that were generated, allowing for an 'undo' feature

struct Flags
{
	enum search_types
	{
		keyword = 0,
		regex,
	};
	// Updates
	bool update_database		= false;
	std::string update_path		= "../";
	// Searching
	bool search_template		= false;
	bool search_mode			= search_types::keyword;
	std::string search_term		= "";
	// Template generation
	bool gen_template			= false;
	std::string name			= "";
	std::string template_name	= "";


};

typedef std::vector<std::string> ArgumentList;

class ArgumentHandler
{
private:
	std::string prog_name;
	Flags flag;
	ArgumentList args;
public:
	ArgumentHandler(int _c, char* _v[]);
	~ArgumentHandler();
	void setflags();
	Flags& getflags();
};

