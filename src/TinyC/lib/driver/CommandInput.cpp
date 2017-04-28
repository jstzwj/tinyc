#include "CommandInput.h"


namespace tinyc
{
	CommandInput::CommandInput()
	{
	}


	CommandInput::~CommandInput()
	{
	}
	void CommandInput::getInput(int argc, char ** argv)
	{
		/*
		-c 1
		-o,-O 2

		*/
		int cstate = 1;
		for (int i = 1; i < argc;++i)
		{
			consume_blank(argv[i]);
			if (isChar(argv[i], '-'))
			{
				switch (argv[i][0])
				{
				case 'c':
					cstate = 1;
					break;
				case 'o':
				case 'O':
					cstate = 2;
					break;
				default:
					//error
					break;
				}
			}
			else
			{
				switch (cstate)
				{
				case 1:
					infile.push_back(argv[i]);
					break;
				case 2:
					outfile.push_back(argv[i]);
					break;
				default:
					//never come here
					infile.push_back(argv[i]);
					break;
				}
			}
		}
	}
}
