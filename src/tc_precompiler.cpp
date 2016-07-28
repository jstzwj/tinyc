#include"tc_precompiler.h"

using namespace tinyc;

//全部预编译指令
const char PreCompiler::precommand[15][8] =
{
	"define",
	"elif",
	"else",
	"endif",
	"error",
	"if",
	"ifdef",
	"ifndef",
	"import",
	"include",
	"line",
	"pragma",
	"region",
	"undef",
	"using"
};


PreCompiler::PreCompiler(code & s, MsgList &ml)
	:allcode(s),msglist(ml)
{
}

int PreCompiler::compile()
{
	//依次读取源代码
	for (codefile & eachfile : allcode.filelist)
	{
		compile(eachfile);
	}
	return 0;
}

int PreCompiler::compile(codefile & eachfile)
{
	//获取每一行
	for (string_t & eachline : eachfile.source)
	{
		if (eachline[0] == '#')
		{
			int i = 1;
			int commandResult = -1;
			//找到预编译指令，开始预处理
			//去除空格
			for (i = 1; eachline[i] == ' '; ++i) {}
			//匹配
			std::deque<std::pair<int, int>> de;

			//广搜识别命令
			for (int j = 0; j < 15; ++j)
			{
				de.push_back(std::make_pair(j, 0));
			}
			while (!de.empty())
			{
				std::pair<int, int> cur = de.front();
				de.pop_front();
				if (precommand[cur.first][cur.second] == '\0')
				{
					//判断完毕
					commandResult = cur.first;
					break;
				}
				if (!isalpha(eachline[i + cur.second]))
				{
					std::cerr << "unknown command" << std::endl;
					return 1;
				}
				if (precommand[cur.first][cur.second] == eachline[i + cur.second])
				{
					cur.second++;
					de.push_back(cur);
				}
			}
			//真正进行命令处理
			if (commandResult != -1)
			{
				switch (commandResult)
				{
				case 0:
					//暂时支持基本define

					break;
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
				case 7:
					break;
				case 8:
					break;
				case 9:
					break;
				case 10:
					break;
				case 11:
					break;
				case 12:
					break;
				case 13:
					break;
				case 14:
					break;
				default:
					//TODO
					//错误处理
					break;
				}
			}


		}
	}
	return 0;
}

int PreCompiler::com_define(codefile & eachfile, const pos & startPoint)
{
	return 0;
}
