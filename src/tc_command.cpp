#include"tc_command.h"

using namespace tinyc;
int command(int argc,char **argv,code & source)
{
	//��Ǵ������л�ȡ�����������ĸ�����
	char state = 'c';
	//�������л�ȡ�����ļ�������ļ���λ��
	//Ĭ�ϼ�-c
	for (int i = 0; i < argc; ++i)
	{
		std::string line = argv[i];
		//�жϲ�������
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
			//�Ż��������ɣ��ݲ�����
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
			//�������ݲ���������
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
			//��������ļ���
			//��ȡ����
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
	//�ӳ�������뵽�ڴ�
	for (const string_t & eachfile:source.infile)
	{
		//���ļ�
		ifstream_t in(eachfile, std::ios::in);
		string_t temp;
		if (!in)
		{
			//��ȡ�ļ�����
			std::cerr << "fail to open file:" << eachfile << std:: endl;
			return 1;
		}
		codefile tempfile;
		tempfile.filename = eachfile;
		//��ȡ�ļ�
		while (getline(in, temp))
		{
			string_t s;
			s += temp;
			s += '\n';
			tempfile.source.push_back(s);
		}
		//�洢
		source.filelist.push_back(tempfile);
		//�ر��ļ���
		in.close();
	}
	return 0;
}