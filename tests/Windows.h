#ifndef MOCK_WINDOWS_H
#define MOCK_WINDOWS_H

#include <cstring>
#include <strings.h>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdint>

typedef unsigned int DWORD;
typedef void* HMODULE;
typedef const char* LPCSTR;
#define MAX_PATH 260
#define GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS 0
#define GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT 0

#define _stricmp strcasecmp
#define _strnicmp strncasecmp

// _snprintf_s(buffer, sizeOfBuffer, count, format, ...)
// snprintf(s, n, format, ...)
#define _snprintf_s(buf, size, count, format, ...) snprintf(buf, size, format, ##__VA_ARGS__)

#define __fastcall
#define __declspec(x)
#define __cdecl

typedef int errno_t;
inline errno_t fopen_s(FILE** f, const char* name, const char* mode) {
    *f = fopen(name, mode);
    return (*f == NULL);
}

inline void GetModuleHandleExA(int, LPCSTR, HMODULE*) {}
inline void GetModuleFileNameA(HMODULE, char* buf, int size) { std::strncpy(buf, "test.exe", size); }
inline void WritePrivateProfileStringA(const char*, const char*, const char*, const char*) {}

#endif
