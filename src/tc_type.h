#pragma once
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<iostream>
#include <fstream>
#include<sstream>
#include<cctype>
namespace tinyc
{
#ifdef TINYC_UNICODE
	typedef wchar_t char_t;
	typedef std::wstring string_t;
	typedef std::wifstream ifstream_t;
	typedef std::wofstream ofstream_t;
	typedef std::wistream istream_t;
	typedef std::wostream ostream_t;
	typedef std::wstringstream stringstream_t;
#else
	typedef char char_t;
	typedef std::string string_t;
	typedef std::ifstream ifstream_t;
	typedef std::ofstream ofstream_t;
	typedef std::istream istream_t;
	typedef std::ostream ostream_t;
	typedef std::stringstream stringstream_t;
#endif
	class pos
	{
	public:
		int row;
		int col;
		pos(int r = 0, int c = 0) { row = r; col = c; }
		static pos make_pos(int r, int c) { return pos(r, c); }
	};
}
