#pragma once

#include"tc_type.h"

namespace tinyc
{
	class codefile
	{
	public:
		std::list<string_t> source;	//һ��һ��
		string_t filename;
	};
	class code
	{
	public:
		//�����������������ļ���������ļ���λ��
		std::vector<string_t> outfile;	//-0
		std::vector<string_t> infile;	//-c
		std::vector<string_t> includefile;	//-i	Additional Include Directories
		std::vector<string_t> libfile;	//-l
		std::vector<string_t> sharedfile;	//-shared
		//Դ���뱣��������
		std::vector<codefile> filelist;
	};
}


