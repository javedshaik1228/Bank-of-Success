#include <iostream>
#include <string>
using namespace std;

#include "CustomConsole.h"

namespace BOS
{
	string CustomConsole::ReadString()
	{
		string str;
		cin >> str;
		return str;
	}

	float CustomConsole::ReadFloat()
	{
		float f;
		cin >> f;
		return f;
	}

	double CustomConsole::ReadDouble()
	{
		double d;
		cin >> d;
		return d;
	}

	int CustomConsole::ReadInt()
	{
		int i;
		cin >> i;
		return i;
	}

	char CustomConsole::ReadChar()
	{
		char c;
		cin >> c;
		return c;
	}

	short CustomConsole::ReadShort()
	{
		short s;
		cin >> s;
		return s;
	}

	long CustomConsole::ReadLong() {
		long l;
		cin >> l;
		return l;
	}
}
