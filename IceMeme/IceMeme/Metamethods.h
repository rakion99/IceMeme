#pragma once

bool game_didGlobal = false;
bool workspace_didGlobal = false;
int arg_size = 1;
std::string typeshit;
int xx, yy, zz;

int Vector3_new(lua_State* L) {
	typeshit = "Vector3";
	xx = lua_tointeger(L, 1);
	yy = lua_tointeger(L, 2);
	zz = lua_tointeger(L, 3);
	return 0;
}

int Color3_new(lua_State* L) {
	typeshit = "Color3";
	xx = lua_tointeger(L, 1);
	yy = lua_tointeger(L, 2);
	zz = lua_tointeger(L, 3);
	return 0;
}

int GameIndex(lua_State* L) {
	if (game_didGlobal == false) {
		rlua_getglobal(luaState, "game");
		game_didGlobal = true;
	}
	lua_getglobal(L, "game");
	Rlua::rlua_getfield(luaState, -1, lua_tostring(L, -2));
	return 1;
}

int GameNewIndex(lua_State* L) {
	game_didGlobal = true;
	lua_getglobal(L, "game");
	if (typeshit == "Vector3") {
		/*	MsgBox("Vector3", "getglobal");*/
		rlua_getglobal(luaState, "Vector3");
		/*MsgBox("new", "getfield -1");*/
		Rlua::rlua_getfield(luaState, -1, "new");
		/*MsgBox(std::to_string(xx), "pushnumber");*/
		Rlua::rlua_pushnumber(luaState, xx);
		/*MsgBox(std::to_string(yy), "pushnumber");*/
		Rlua::rlua_pushnumber(luaState, yy);
		/*MsgBox(std::to_string(zz), "pushnumber");*/
		Rlua::rlua_pushnumber(luaState, zz);
		/*MsgBox("3 1 0", "pcall");*/
		rlua_pcall(luaState, 3, 1, 0);
		/*	MsgBox(lua_tostring(L, -3), "setfield -3");*/
		rlua_setfield(luaState, -3, lua_tostring(L, -3));
		xx, yy, zz = 0;
		typeshit = "";
	}
	else if (typeshit == "Color3") {
		/*	MsgBox("Color3", "getglobal");*/
		rlua_getglobal(luaState, "Color3");
		/*MsgBox("-1 new", "getfield");*/
		Rlua::rlua_getfield(luaState, -1, "new");
		/*MsgBox(std::to_string(xx), "pushnumber");*/
		Rlua::rlua_pushnumber(luaState, xx);
		/*MsgBox(std::to_string(yy), "pushnumber");*/
		Rlua::rlua_pushnumber(luaState, yy);
		/*MsgBox(std::to_string(zz), "pushnumber");*/
		Rlua::rlua_pushnumber(luaState, zz);
		/*MsgBox("3 1 0", "pcall");*/
		rlua_pcall(luaState, 3, 1, 0);
		/*MsgBox(lua_tostring(L, -3), "setfield -3");*/
		rlua_setfield(luaState, -3, lua_tostring(L, -3));
		xx, yy, zz = 0;
		typeshit = "";
	}
	else {
		if (lua_isnumber(L, -2)) {
			Rlua::rlua_pushnumber(luaState, lua_tonumber(L, -2));
			/*MsgBox(std::to_string(lua_tonumber(L, -2)), "pushnumber");*/
			rlua_setfield(luaState, -2, lua_tostring(L, -3));
			/*MsgBox(lua_tostring(L, -3), "setfield -2");*/
		}
		else if (lua_isboolean(L, -2)) {
			Rlua::rlua_pushboolean(luaState, lua_toboolean(L, -2));
			/*MsgBox(std::to_string(lua_toboolean(L, -2)), "pushboolean");*/
			rlua_setfield(luaState, -2, lua_tostring(L, -3));
			/*MsgBox(lua_tostring(L, -3), "setfield -2");*/
		}
		else if (lua_isstring(L, -2)) {
			Rlua::rlua_pushstring(luaState, lua_tostring(L, -2));
			/*	MsgBox(lua_tostring(L, -2), "pushstring");*/
			rlua_setfield(luaState, -2, lua_tostring(L, -3));
			/*MsgBox(lua_tostring(L, -3), "setfield -2");*/
		}
		else if (lua_istable(L, -2)) {

		}
		else if (lua_isnil(L, -2)) {
			Rlua::rlua_pushnil(luaState);
			/*	MsgBox("nil", "pushnil");*/
			rlua_setfield(luaState, -2, lua_tostring(L, -3));
			/*MsgBox(lua_tostring(L, -3), "setfield -2");*/
		}
	}
	return 1;
}

int WorkspaceIndex(lua_State* L) {
	if (workspace_didGlobal == false) {
		/*MsgBox("game", "getglobal");*/
		rlua_getglobal(luaState, "workspace");
		workspace_didGlobal = true;
	}
	lua_getglobal(L, "workspace");
	/*MsgBox(lua_tostring(L, -2), "getfield -1");*/
	Rlua::rlua_getfield(luaState, -1, lua_tostring(L, -2));
	return 1;
}

int WorkspaceNewIndex(lua_State* L) {
	workspace_didGlobal = false;
	lua_getglobal(L, "workspace");
	if (typeshit == "Vector3") {
		/*	MsgBox("Vector3", "getglobal");*/
		rlua_getglobal(luaState, "Vector3");
		/*MsgBox("new", "getfield -1");*/
		Rlua::rlua_getfield(luaState, -1, "new");
		/*MsgBox(std::to_string(xx), "pushnumber");*/
		Rlua::rlua_pushnumber(luaState, xx);
		/*MsgBox(std::to_string(yy), "pushnumber");*/
		Rlua::rlua_pushnumber(luaState, yy);
		/*MsgBox(std::to_string(zz), "pushnumber");*/
		Rlua::rlua_pushnumber(luaState, zz);
		/*MsgBox("3 1 0", "pcall");*/
		rlua_pcall(luaState, 3, 1, 0);
		/*	MsgBox(lua_tostring(L, -3), "setfield -3");*/
		rlua_setfield(luaState, -3, lua_tostring(L, -3));
		xx, yy, zz = 0;
		typeshit = "";
	}
	else if (typeshit == "Color3.new") {
		/*	MsgBox("Color3", "getglobal");*/
		rlua_getglobal(luaState, "Color3");
		/*MsgBox("-1 new", "getfield");*/
		Rlua::rlua_getfield(luaState, -1, "new");
		/*MsgBox(std::to_string(xx), "pushnumber");*/
		Rlua::rlua_pushnumber(luaState, xx);
		/*MsgBox(std::to_string(yy), "pushnumber");*/
		Rlua::rlua_pushnumber(luaState, yy);
		/*MsgBox(std::to_string(zz), "pushnumber");*/
		Rlua::rlua_pushnumber(luaState, zz);
		/*MsgBox("3 1 0", "pcall");*/
		rlua_pcall(luaState, 3, 1, 0);
		/*MsgBox(lua_tostring(L, -3), "setfield -3");*/
		rlua_setfield(luaState, -3, lua_tostring(L, -3));
		xx, yy, zz = 0;
		typeshit = "";
	}
	else {
		if (lua_isnumber(L, -2)) {
			Rlua::rlua_pushnumber(luaState, lua_tonumber(L, -2));
			/*MsgBox(std::to_string(lua_tonumber(L, -2)), "pushnumber");*/
			rlua_setfield(luaState, -2, lua_tostring(L, -3));
			/*MsgBox(lua_tostring(L, -3), "setfield -2");*/
		}
		else if (lua_isboolean(L, -2)) {
			Rlua::rlua_pushboolean(luaState, lua_toboolean(L, -2));
			/*MsgBox(std::to_string(lua_toboolean(L, -2)), "pushboolean");*/
			rlua_setfield(luaState, -2, lua_tostring(L, -3));
			/*MsgBox(lua_tostring(L, -3), "setfield -2");*/
		}
		else if (lua_isstring(L, -2)) {
			Rlua::rlua_pushstring(luaState, lua_tostring(L, -2));
			/*	MsgBox(lua_tostring(L, -2), "pushstring");*/
			rlua_setfield(luaState, -2, lua_tostring(L, -3));
			/*MsgBox(lua_tostring(L, -3), "setfield -2");*/
		}
		else if (lua_isnil(L, -2)) {
			Rlua::rlua_pushnil(luaState);
			/*	MsgBox("nil", "pushnil");*/
			rlua_setfield(luaState, -2, lua_tostring(L, -3));
			/*MsgBox(lua_tostring(L, -3), "setfield -2");*/
		}
	}
	return 1;
}

int GameCall(lua_State* L) {
	game_didGlobal = false;
	arg_size = 1;
	Rlua::rlua_pushvalue(luaState, -2);
	/*MsgBox("-2", "pushvalue");*/
	int i = 2;
	while (!lua_isnil(L, -i)) {
		if (lua_isnumber(L, -i)) {
			Rlua::rlua_pushnumber(luaState, lua_tonumber(L, -i));
			/*MsgBox(std::to_string(lua_tonumber(L, -i)), "pushnumber");*/
			arg_size++;
		}
		if (lua_isstring(L, -i)) {
			Rlua::rlua_pushstring(luaState, lua_tostring(L, -i));
			/*MsgBox(lua_tostring(L, -i), "pushstring");*/
			arg_size++;
		}
		if (lua_isboolean(L, -i)) {
			Rlua::rlua_pushboolean(luaState, lua_toboolean(L, -i));
			/*MsgBox(std::to_string(lua_toboolean(L, -i)), "pushboolean");*/
			arg_size++;
		}
		i++;
	}
	rlua_pcall(luaState, arg_size, 1, 0);
	/*MsgBox(std::to_string(arg_size) + " 1 0", "pcall");*/
	arg_size = 1;
	return 1;
}

int WorkspaceCall(lua_State* L) {
	workspace_didGlobal = false;
	arg_size = 1;
	Rlua::rlua_pushvalue(luaState, -2);
	/*MsgBox("-2", "pushvalue");*/
	int i = 2;
	while (!lua_isnil(L, -i)) {
		if (lua_isnumber(L, -i)) {
			Rlua::rlua_pushnumber(luaState, lua_tonumber(L, -i));
			/*MsgBox(std::to_string(lua_tonumber(L, -i)), "pushnumber");*/
			arg_size++;
		}
		if (lua_isstring(L, -i)) {
			Rlua::rlua_pushstring(luaState, lua_tostring(L, -i));
			/*MsgBox(lua_tostring(L, -i), "pushstring");*/
			arg_size++;
		}
		if (lua_isboolean(L, -i)) {
			Rlua::rlua_pushboolean(luaState, lua_toboolean(L, -i));
			/*MsgBox(std::to_string(lua_toboolean(L, -i)), "pushboolean");*/
			arg_size++;
		}
		i++;
	}
	rlua_pcall(luaState, arg_size, 1, 0);
	/*MsgBox(std::to_string(arg_size) + " 1 0", "pcall");*/
	arg_size = 1;
	return 1;
}

int Instance_new(lua_State* L) {
	game_didGlobal = false;
	workspace_didGlobal = false;
	int a = lua_gettop(L);
	/*MsgBox("Instance", "getglobal");*/
	rlua_getglobal(luaState, "Instance");
	/*MsgBox("new", "getfield -1");*/
	Rlua::rlua_getfield(luaState, -1, "new");
	if (lua_isstring(L, 1)) {
		/*MsgBox(lua_tostring(L, 1), "pushstring");*/
		Rlua::rlua_pushstring(luaState, lua_tostring(L, 1));
		if (a == 2) Rlua::rlua_pushvalue(luaState, -4);/* MsgBox("-4", "pushvalue");*/
	}
	/*MsgBox(std::to_string(a) + " 1 0", "pcall");*/
	rlua_pcall(luaState, a, 1, 0);
	return 1;
}