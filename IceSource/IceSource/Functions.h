#pragma once

#include "stdafx.h"
#include "Rlua.h"

using namespace Rlua;

int ScriptContext;
int SkidState;
int skid = 0xDC;

std::vector<std::string> Split(std::string str, char Delim) {
	std::vector<std::string> Args;
	std::stringstream ss(str);
	std::string Arg;
	while (getline(ss, Arg, Delim))
		Args.push_back(Arg);
	return Args;
}

std::string tolower(std::string str)
{
	std::string retn("");
	for (size_t i = 0; i < str.length(); i++)
	{
		int ascii = (int)str.at(i);
		if (ascii >= (int)'a' && ascii <= (int)'z')
			retn += (char)ascii;
		else
			retn += (char)(ascii + ((int)'a' - (int)'A'));
	}
	return retn;
}

void getSKID(std::string service)
{
	using namespace Rlua;
	SKID_getfield(SkidState, LUA_GLOBALSINDEX, "game");
	SKID_getfield(SkidState, -1, "GetService");
	SKID_pushvalue(SkidState, -2);
	SKID_pushstring(SkidState, service.c_str());
	SKID_call(SkidState, 2, 1);
}

void Scan() {
	using namespace std;
	DWORD SkIdT = *(DWORD*)(SKID(2970144));
	ScriptContext = SkId::Scan((char*)&SkIdT);
	SkidState = *(DWORD*)(ScriptContext + skid) - (ScriptContext + skid);
}
