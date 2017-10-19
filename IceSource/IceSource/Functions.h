#pragma once

#include "stdafx.h"
#include "Rlua.h"

using namespace Rlua;

int DataModel;
int Players;
int Lighting;
int Workspace;
int ScriptContext;
int luaState;

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

void getService(std::string service)
{
	using namespace Rlua;
	rlua_getfield(luaState, LUA_GLOBALSINDEX, "game");
	rlua_getfield(luaState, -1, "GetService");
	rlua_pushvalue(luaState, -2);
	rlua_pushstring(luaState, service.c_str());
	rlua_call(luaState, 2, 1);
}

const char* GetClass(int self)
{
	return (const char*)(*(int(**)(void))(*(int*)self + 16));
}

int GetParent(int Instance) {
	return *(int*)(Instance + 0x34);
}

int FindFirstClass(int Instance, const char* ClassName) {
	if (Instance > 10000) {
		DWORD StartOfChildren = *(DWORD*)(Instance + 0x2C);
		if (StartOfChildren != 0) {
			DWORD EndOfChildren = *(DWORD*)(StartOfChildren + 4);
			if (EndOfChildren != 0) {
				for (int i = *(int*)StartOfChildren; i != EndOfChildren; i += 8) {
					try {
						if (memcmp(GetClass(*(int*)i), ClassName, strlen(ClassName)) == 0) {
							return *(int*)i;
						}
					}
					catch (std::exception) {
						Sleep(1);
					}
					catch (...) {
						Sleep(1);
					}
				}
			}
		}
	}
	return 0;
}

void Scan() {
	using namespace std;
	DWORD ScriptContextVFTable = *(DWORD*)((aobscan::scan("\xC7\x07\x00\x00\x00\x00\xC7\x47\x00\x00\x00\x00\x00\x8B\x87", "xx????xx?????xx")) + 0x02);
	ScriptContext = Memory::Scan(PAGE_READWRITE, (char*)&ScriptContextVFTable, "xxxx");
	DataModel = GetParent(ScriptContext);
	Workspace = FindFirstClass(DataModel, "Workspace");
	Players = FindFirstClass(DataModel, "Players");
	Lighting = FindFirstClass(DataModel, "Lighting");
	luaState = ScriptContext + 220 - *(DWORD*)(ScriptContext + 220);
}
