#pragma once

int LuaCAPI(lua_State* LuaS) {
	DWORD a = lua_gettop(LuaS);
	std::string cmd;
	for (size_t i = 1; i <= a; ++i) cmd = lua_tostring(LuaS, i);
	LuaCExecute(cmd);
	return 0;
}

int PrintIdentity(lua_State* Lua51) {
	int arg = lua_gettop(Lua51);
	std::string print;
	for (int i = 1; i <= arg; ++i) {
		if (lua_isstring(Lua51, -(i))) {
			print = lua_tostring(Lua51, i);
			rlua_getglobal(luaState, "printidentity");
			Rlua::rlua_pushstring(luaState, print.c_str());
			rlua_pcall(luaState, 1, 0, 0);
			Rlua::rlua_settop(luaState, 0);
		}
		else if (lua_isboolean(Lua51, -(i))) {
			print = lua_toboolean(Lua51, i);
			rlua_getglobal(luaState, "printidentity");
			Rlua::rlua_pushstring(luaState, print.c_str());
			rlua_pcall(luaState, 1, 0, 0);
			Rlua::rlua_settop(luaState, 0);
		}
		else if (lua_isnil(Lua51, -(i))) {
			rlua_getglobal(luaState, "printidentity");
			Rlua::rlua_pushnil(luaState);
			rlua_pcall(luaState, 1, 0, 0);
			Rlua::rlua_settop(luaState, 0);
		}
	}
	if (arg == 0) {
		rlua_getglobal(luaState, "printidentity");
		rlua_pcall(luaState, 0, 0, 0);
		Rlua::rlua_settop(luaState, 0);
	}
	return 0;
}

int Print(lua_State* L) {
	std::string message;

	int n = lua_gettop(L);  /* number of arguments */
	int i;

	lua_getglobal(L, "tostring");
	for (i = 1; i <= n; ++i) {
		if (i > 1)
		{
			message += ' ';
		}

		lua_pushvalue(L, -1);  /* function to be called */
		lua_pushvalue(L, i);   /* value to print */
		lua_call(L, 1, 1);
		const char* s = lua_tostring(L, -1);  /* get result */
		message += s;
		if (i > 1) fputs("\t", stdout);
		lua_pop(L, 1);  /* pop result */
	}
	rlua_getglobal(luaState, "print");
	Rlua::rlua_pushstring(luaState, message.c_str());
	rlua_pcall(luaState, n, 0, 0);
	return 0;
}

int Warn(lua_State* L) {
	std::string message;

	int n = lua_gettop(L);  /* number of arguments */
	int i;

	lua_getglobal(L, "tostring");
	for (i = 1; i <= n; ++i) {
		if (i > 1)
		{
			message += ' ';
		}

		lua_pushvalue(L, -1);  /* function to be called */
		lua_pushvalue(L, i);   /* value to print */
		lua_call(L, 1, 1);
		const char* s = lua_tostring(L, -1);  /* get result */
		message += s;
		if (i > 1) fputs("\t", stdout);
		lua_pop(L, 1);  /* pop result */
	}
	rlua_getglobal(luaState, "warn");
	Rlua::rlua_pushstring(luaState, message.c_str());
	rlua_pcall(luaState, n, 0, 0);
	return 0;
}

//YALL KNOW DAMN WELL WHERE THAT SHIT CAME FROM ^^

int Wait(lua_State* Lua51) {
	DWORD arg = lua_gettop(Lua51);
	int time;
	for (size_t i = 1; i <= arg; ++i) {
		time = lua_tointeger(Lua51, i);
	}
	Sleep(time * 1000);
	// DISGUSTING ^
	return 0;
}