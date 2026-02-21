#pragma once
#include <string>
#include <algorithm>
#include <cstring>

bool TestCheat(const char* cheat)
{
	if (!cheat) return false;
	std::string s(cheat);
	if (s.empty() || s.length() >= 30) return false;

	std::reverse(s.begin(), s.end());

	char *c = (char *)0x00969110;
	if (_strnicmp(s.c_str(), c, s.length())) return false;
	c[0] = 0;
	return true;
}
