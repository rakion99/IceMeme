#pragma once
#include "LuaCParser.h"
#include "Metamethods.h"
#include "MemeFunctions.h"

std::vector<std::string> Parse(std::string input)
{
	std::string a;
	std::vector<std::string> vstr;
	std::istringstream str(input);
	while (str >> a) {
		vstr.push_back(a);
	}
	return vstr;
}

int opencustomlibs(lua_State* L) {
	lua_newtable(L);
	lua_pushcfunction(L, Instance_new);
	lua_setfield(L, -2, "new");
	lua_setglobal(L, "Instance");
	lua_settop(L, 0);
	lua_newtable(L);
	lua_pushcfunction(L, Vector3_new);
	lua_setfield(L, -2, "new");
	lua_setglobal(L, "Vector3");
	lua_settop(L, 0);
	lua_getglobal(L, "Vector3");
	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	lua_settop(L, 0);
	lua_newtable(L);
	lua_pushcfunction(L, Color3_new);
	lua_setfield(L, -2, "new");
	lua_setglobal(L, "Color3");
	lua_settop(L, 0);
	lua_getglobal(L, "Color3");
	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	lua_settop(L, 0);
	lua_newtable(L);
	lua_pushstring(L, "deadass should already know that this is locked");
	lua_setfield(L, -2, "__metatable");
	lua_settop(L, 0);
	lua_newtable(L);
	lua_createtable(L, 0, 1);
	lua_pushcfunction(L, GameIndex);
	lua_setfield(L, -2, "__index");
	lua_pushcfunction(L, GameNewIndex);
	lua_setfield(L, -2, "__newindex");
	lua_pushcfunction(L, GameCall);
	lua_setfield(L, -2, "__call");
	lua_setmetatable(L, -2);
	lua_setglobal(L, "game");
	lua_settop(L, 0);
	lua_newtable(L);
	lua_createtable(L, 0, 1);
	lua_pushcfunction(L, WorkspaceIndex);
	lua_setfield(L, -2, "__index");
	lua_pushcfunction(L, WorkspaceNewIndex);
	lua_setfield(L, -2, "__newindex");
	lua_pushcfunction(L, WorkspaceCall);
	lua_setfield(L, -2, "__call");
	lua_setmetatable(L, -2);
	lua_setglobal(L, "workspace");
	lua_settop(L, 0);
	lua_pushcfunction(L, PrintIdentity);
	lua_setglobal(L, "printidentity");
	lua_settop(L, 0);
	lua_pushcfunction(L, Warn);
	lua_setglobal(L, "warn");
	lua_settop(L, 0);
	lua_pushcfunction(L, Print);
	lua_setglobal(L, "print");
	lua_settop(L, 0);
	lua_pushcfunction(L, Wait);
	lua_setglobal(L, "wait");
	lua_settop(L, 0);
	lua_pushcfunction(L, LuaCAPI);
	lua_setglobal(L, "luac");
	lua_settop(L, 0);
	return 1;
}

void Exe(std::string input) {
	lua_State* luaS = luaL_newstate();
	lua_State* LuaS = lua_newthread(luaS);
	luaL_openlibs(LuaS);
	opencustomlibs(LuaS);
	std::string total;
	luaL_dostring(LuaS, "local IceMeme = Instance.new(\"ByPassChecks\", workspace)");//wink
	int dang_skids = luaL_dostring(LuaS, input.c_str());
	luaL_dostring(LuaS, "local IceMeme = Instance.new(\"RestoreChecks\", workspace)");//wink
	if (dang_skids) {
		IceMemebox(lua_tostring(LuaS, -1));
		lua_pop(LuaS, 1);
		return;
	}
	lua_settop(LuaS, 0);
	lua_close(LuaS);
}