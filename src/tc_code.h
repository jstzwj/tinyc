#pragma once

#include"tc_type.h"

namespace tinyc
{
	class codefile
	{
	public:
		std::list<string_t> source;	//一次一行
		string_t filename;
	};
	class code
	{
	public:
		//保存从命令行输入的文件和输出的文件的位置
		std::vector<string_t> outfile;	//-0
		std::vector<string_t> infile;	//-c
		std::vector<string_t> includefile;	//-i	Additional Include Directories
		std::vector<string_t> libfile;	//-l
		std::vector<string_t> sharedfile;	//-shared
		//源代码保存在这里
		std::vector<codefile> filelist;
	};
}


