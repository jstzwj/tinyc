#include<iostream>
#include"tc_type.h"
#include"tc_code.h"
#include"tc_precompiler.h"
#include"tc_command.h"

using namespace tinyc;

#define FILE_NAME_MAX 260


int main(int argc,char **argv)
{
	char com[][10] = {"test.c","-o","test.exe"};
	//钦定一下文件名
	argc = 3;
	argv[0] = com[0];
	argv[1] = com[1];
	argv[2] = com[2];
	tinyc::code compilerinfo;
	MsgList msglist;
	command(argc,argv,compilerinfo);
	PreCompiler precompiler(compilerinfo,msglist);
	precompiler.compile();

	return 0;
}