#pragma once
typedef int*(__cdecl *GetContextA)();
GetContextA ContextLevel = (GetContextA)(Identityaddress);

int *Level = ContextLevel();
int ScriptContext;
int v51 = 1;
int luaState;

int DataModel = 0;
int Players = 0;
int CurrentPlayer;
std::string *PlayerName;

int GetParent2(int Instance) {
	try {
		return *(int*)(Instance + 0x34);
	}
	catch (std::exception e) {
		MessageBox(NULL, e.what(), "IceMeme - Uh Oh", MB_OK);
	}
	catch (...) {
		MessageBox(NULL, "An Unhandled Error Has Occured!", "IceMeme - Uh Oh", MB_OK);
	}
}

const char* GetClass(int self)
{
	try {
		return (const char*)(*(int(**)(void))(*(int*)self + 16))();
	}
	catch (std::exception e) {
		MessageBox(NULL, e.what(), "IceMeme - Uh Oh", MB_OK);
	}
	catch (...) {
		MessageBox(NULL, "An Unhandled Error Has Occured!", "IceMeme - Uh Oh", MB_OK);
	}
}

int FindFirstClass(int Instance, const char* Name)
{
	try {
		DWORD StartOfChildren = *(DWORD*)(Instance + 0x2C);
		DWORD EndOfChildren = *(DWORD*)(StartOfChildren + 4);

		for (int i = *(int*)StartOfChildren; i != EndOfChildren; i += 8)
		{
			if (memcmp(GetClass(*(int*)i), Name, strlen(Name)) == 0)
			{
				return *(int*)i;
			}
		}
	}
	catch (std::exception e) {
		MessageBox(NULL, e.what(), "IceMeme - Uh Oh", MB_OK);
	}
	catch (...) {
		MessageBox(NULL, "An Unhandled Error Has Occured!", "IceMeme - Uh Oh", MB_OK);
	}
}

int GetLocalPlayer(int Player) {
	try {
		return *(int*)(Player + 200);//this change sometimes so if ur crashing or not getting ur username rip update this offset
	}
	catch (std::exception e) {
		MessageBox(NULL, e.what(), "IceMeme - Uh Oh", MB_OK);
	}
	catch (...) {
		MessageBox(NULL, "An Unhandled Error Has Occured!", "IceMeme - Uh Oh", MB_OK);
	}
}

std::string* GetName(int Instance) {
	try {
		return (std::string*)(*(int*)(Instance + 40));//same with this but haven't changed in long time
	}
	catch (std::exception e) {
		MessageBox(NULL, e.what(), "IceMeme - Uh Oh", MB_OK);
	}
	catch (...) {
		MessageBox(NULL, "An Unhandled Error Has Occured!", "IceMeme - Uh Oh", MB_OK);
	}
}

void ScanScriptContext() {
	DWORD ScriptContextVFTable = *(DWORD*)((ScriptContextVFTableaddress)+0x02);
	ScriptContext = Memory::Scan((char*)&ScriptContextVFTable);
	luaState = *(DWORD *)(ScriptContext + 56 * v51 + 164) - (ScriptContext + 56 * v51 + 164);
	*Level = 6;

	DataModel = GetParent2(ScriptContext);
	Players = FindFirstClass(DataModel, "Players");
	CurrentPlayer = GetLocalPlayer(Players);
	PlayerName = GetName(CurrentPlayer);
}