#include"tc_precompiler.h"

using namespace tinyc;

//ȫ��Ԥ����ָ��
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
	//���ζ�ȡԴ����
	for (codefile & eachfile : allcode.filelist)
	{
		compile(eachfile);
	}
	return 0;
}

int PreCompiler::compile(codefile & eachfile)
{
	//��ȡÿһ��
	for (string_t & eachline : eachfile.source)
	{
		if (eachline[0] == '#')
		{
			int i = 1;
			int commandResult = -1;
			//�ҵ�Ԥ����ָ���ʼԤ����
			//ȥ���ո�
			for (i = 1; eachline[i] == ' '; ++i) {}
			//ƥ��
			std::deque<std::pair<int, int>> de;

			//����ʶ������
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
					//�ж����
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
			//�������������
			if (commandResult != -1)
			{
				switch (commandResult)
				{
				case 0:
					//��ʱ֧�ֻ���define

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
					//������
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
