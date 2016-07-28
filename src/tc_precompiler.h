#pragma once
#include"tc_type.h"
#include"tc_code.h"
#include"tc_error.h"
using namespace tinyc;

class PreCompiler
{
private:
	code & allcode;
	MsgList & msglist;
	//全部预编译指令
	static const char precommand[15][8];
public:
	//设定设置列表与消息列表
	PreCompiler(code & s,MsgList &ml);
	//开始预编译
	int compile();
	//预编译一个文件
	int compile(codefile & eachfile);
private:
	//各种命令的处理函数
	//宏定义
	int com_define(codefile &eachfile,const pos& startPoint);

};