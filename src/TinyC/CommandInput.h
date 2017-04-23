#pragma once
#ifndef TINYC_COMMANDINPUT
#define TINYC_COMMANDINPUT

#include<vector>
#include<string>

#include"StringUtil.h"

namespace tinyc
{
	class CommandInput
	{
	public:
		CommandInput();
		~CommandInput();
		void getInput(int argc, char ** argv);
	private:
		std::vector<std::string> infile;
		std::vector<std::string> outfile;
	};
}

#endif // !TINYC_COMMANDINPUT




