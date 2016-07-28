#pragma once
#include"tc_type.h"
using namespace tinyc;
enum class MsgCode
{

};
enum class MsgType
{
	Warning,
	Error,
	Message
};
class Msg
{
public:
	pos msgpoint;
	MsgType msgtype;
	MsgCode msgcode;
	string_t filename;
	string_t description;
};

class MsgList
{
	int msglimit;
	std::list<Msg> msglist;
};