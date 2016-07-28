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
	//ȫ��Ԥ����ָ��
	static const char precommand[15][8];
public:
	//�趨�����б�����Ϣ�б�
	PreCompiler(code & s,MsgList &ml);
	//��ʼԤ����
	int compile();
	//Ԥ����һ���ļ�
	int compile(codefile & eachfile);
private:
	//��������Ĵ�����
	//�궨��
	int com_define(codefile &eachfile,const pos& startPoint);

};