#pragma once
#ifndef TINYC_STRINGUTIL
#define TINYC_STRINGUTIL

#include<string>
#include<cstring>

namespace tinyc
{
	bool isBlank(char c)
	{
		return c == ' ' || c == '\t';
	}
	bool isChar(char *& str, char c)
	{
		if (*str != '\0'&&*str == c)
		{
			++str;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isStr(char *& str, const char * match_str)
	{
		char * strtmp = str;
		while (*strtmp != '\0'&&
			*match_str != '\0'&&
			*strtmp == *match_str)
		{
			strtmp++;
			match_str++;
		}
		if (*match_str == '\0')
		{
			str = strtmp;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool consume(char *& str)
	{
		if (*str == '\0')
		{
			return false;
		}
		else
		{
			++str;
			return true;
		}
	}
	void consume_space(char *& str)
	{
		while (*str != '\0'&&*str == ' ')
		{
			++str;
		}
	}
	void consume_blank(char *& str)
	{
		while (*str != '\0'&&isBlank(*str))
		{
			++str;
		}
	}

}

#endif // !TINYC_STRINGUTIL

