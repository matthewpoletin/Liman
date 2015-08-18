#pragma once

#include <string>
#include <windows.h>

bool WildcardMatch(const char *pat, const char *str);

extern std::string ws2s(const std::wstring& s);
extern std::wstring s2ws(const std::string &s);