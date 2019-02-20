#pragma once

#define IceMemebox(msg) MessageBox(NULL, msg, "ICEMEME - Uh Oh", MB_OK | MB_TOPMOST);

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

void rlua_getService(std::string service)
{
	Rlua::rlua_getfield(luaState, LUA_GLOBALSINDEX, "game");
	Rlua::rlua_getfield(luaState, -1, "GetService");
	Rlua::rlua_pushvalue(luaState, -2);
	Rlua::rlua_pushstring(luaState, service.c_str());
	rlua_pcall(luaState, 2, 1, 0);
}
//if you don't even know what's this then time to learn c++ SKID
void get_file(HINSTANCE dllName, const char* fileName, char* buffer, int bfSize) {
	GetModuleFileName(dllName, buffer, bfSize);
	if (strlen(fileName) + strlen(buffer) < MAX_PATH) {
		char* pathEnd = strrchr(buffer, '\\');
		strcpy_s(pathEnd + 1, sizeof(fileName), fileName);
	}
	else {
		*buffer = 0;
	}
}

EXTERN_C IMAGE_DOS_HEADER __ImageBase;

std::string getdllname() {
	char path[MAX_PATH];
	get_file((HINSTANCE)&__ImageBase, "", path, MAX_PATH);
	std::string dllpath = path;
	TCHAR   DllPath[MAX_PATH] = { 0 };
	GetModuleFileName((HINSTANCE)&__ImageBase, DllPath, _countof(DllPath));
	std::string FullDllPath = DllPath;
	std::string dllstuff = ".dll";
	FullDllPath.replace(FullDllPath.find(dllpath), dllpath.length(), "");
	FullDllPath.replace(FullDllPath.find(dllstuff), dllstuff.length(), "");
	return FullDllPath;
}

DWORD APIENTRY UglyToolBar()
{
	//meh
	HWND FindRobloxWindow = FindWindowExW(NULL, NULL, NULL, L"Roblox");
	HMENU GetUglyMenu = GetMenu(FindRobloxWindow);
	HMENU CreateUglyMenuBar = CreateMenu();
	std::string bar1 = "                              ";
	std::string bar2 = getdllname();
	std::string bar3 = " has loaded Correctly!           Hey! now you can use ";
	std::string bar4 = "                  Powered by IceMeme for FREE";
	std::string CustomBar = bar1 + bar2 + bar3 + bar2 + bar4;
	std::wstring s2temp = std::wstring(CustomBar.begin(), CustomBar.end());
	LPCWSTR NewCurstomBar = s2temp.c_str();
	InsertMenuW(CreateUglyMenuBar, NULL, MF_BYPOSITION | MF_STRING | MF_DISABLED, NULL, NewCurstomBar);
	SetMenu(FindRobloxWindow, CreateUglyMenuBar);
	std::string title1 = "Roblox Exploited with ";
	std::string title2 = getdllname();
	std::string CustomRbxTitle = title1 + title2;
	std::wstring stemp = std::wstring(CustomRbxTitle.begin(), CustomRbxTitle.end());
	LPCWSTR NewRobloxTitle = stemp.c_str();
	SetWindowTextW(FindRobloxWindow, NewRobloxTitle);
	return 0;
}