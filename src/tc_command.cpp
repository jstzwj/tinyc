#include"tc_command.h"

using namespace tinyc;
int command(int argc,char **argv,code & source)
{
	//标记从命令行获取的输入属于哪个参数
	char state = 'c';
	//从命令行获取输入文件和输出文件的位置
	//默认加-c
	for (int i = 0; i < argc; ++i)
	{
		std::string line = argv[i];
		//判断参数类型
		if (line == "-c")
		{
			state = 'c';
		}
		else if (line == "-C")
		{
			state = 'C';
		}
		else if (line == "-o")
		{
			state = 'o';
		}
		else if (line == "-O")
		{
			state = 'O';
			//优化代码生成，暂不处理
		}
		else if (line == "-L")
		{
			state = 'L';
		}
		else if (line == "-l")
		{
			state = 'l';
		}
		else if (line == "-i")
		{
			state = 'i';
			//保留，暂不处理，报错
		}
		else if (line == "-I")
		{
			state = 'I';
		}
		else if (line == "-include")
		{
			state = 'i';
		}
		else if (line == "-shared")
		{
			state = 's';
		}
		else
		{
			//输入的是文件名
			//读取内容
			switch (state)
			{
			case 'c':
				source.infile.push_back(line);
				break;
			case 'C':
				source.infile.push_back(line);
				break;
			case 'o':
				source.outfile.push_back(line);
				break;
			case 'O':
				source.outfile.push_back(line);
				break;
			default:
				break;
			}
		}
	}
	//从程序读代码到内存
	for (const string_t & eachfile:source.infile)
	{
		//打开文件
		ifstream_t in(eachfile, std::ios::in);
		string_t temp;
		if (!in)
		{
			//读取文件出错
			std::cerr << "fail to open file:" << eachfile << std:: endl;
			return 1;
		}
		codefile tempfile;
		tempfile.filename = eachfile;
		//读取文件
		while (getline(in, temp))
		{
			string_t s;
			s += temp;
			s += '\n';
			tempfile.source.push_back(s);
		}
		//存储
		source.filelist.push_back(tempfile);
		//关闭文件流
		in.close();
	}
	return 0;
}