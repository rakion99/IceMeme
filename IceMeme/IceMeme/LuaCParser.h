#pragma once

using std::vector;
using std::string;

extern vector<string> Parse(string input);

enum LuaC_OPCODES {
	OP_GETGLOBAL,
	OP_GETFIELD,
	OP_SETFIELD,
	OP_SETGLOBAL,
	OP_RAWGETI,
	OP_RAWSETI,
	OP_PUSHSTRING,
	OP_PUSHVALUE,
	OP_PUSHNUMBER,
	OP_PUSHBOOLEAN,
	OP_PUSHNIL,
	OP_PUSHINTEGER,
	OP_PCALL,
	OP_CALL,
	OP_SETTOP,
	OP_EMPTYSTACK,
	OP_WAIT,
	OP_POP,
	OP_PUSH,
	OP_TOSTRING
};

inline LuaC_OPCODES returnop(std::string func) {
	if (func == "getglobal") return OP_GETGLOBAL;
	if (func == "getfield") return OP_GETFIELD;
	if (func == "setglobal") return OP_SETGLOBAL;
	if (func == "setfield") return OP_SETFIELD;
	if (func == "rawgeti") return OP_RAWGETI;
	if (func == "rawseti") return OP_RAWSETI;
	if (func == "pushstring") return OP_PUSHSTRING;
	if (func == "pushnumber") return OP_PUSHNUMBER;
	if (func == "pushvalue") return OP_PUSHVALUE;
	if (func == "pushnil") return OP_PUSHNIL;
	if (func == "pushinteger") return OP_PUSHINTEGER;
	if (func == "pushboolean" || func == "pushbool") return OP_PUSHBOOLEAN;
	if (func == "pcall") return OP_PCALL;
	if (func == "call") return OP_CALL;
	if (func == "settop") return OP_SETTOP;
	if (func == "emptystack") return OP_EMPTYSTACK;
	if (func == "wait") return OP_WAIT;
	if (func == "pop") return OP_POP;
	if (func == "tostring") return OP_TOSTRING;
}

inline void LuaCExecute(std::string input) {
	vector<std::string> Input;
	Input = Parse(input);

	switch (returnop(Input.at(0))) {

	case OP_GETGLOBAL: {
		rlua_getglobal(luaState, Input.at(1).c_str());
		break;
	}

	case OP_GETFIELD: {
		int one = stoi(Input.at(1));
		std::string two;
		for (size_t i = 2; i < Input.size(); ++i) {
			if ((Input.size() - 1) > i) two.append(Input.at(i) + " ");
			else if ((Input.size() - 1) == i) two.append(Input.at(i));
		}
		Rlua::rlua_getfield(luaState, one, two.c_str());
		break;
	}

	case OP_SETGLOBAL: {
		rlua_setglobal(luaState, Input.at(1).c_str());
		break;
	}

	case OP_SETFIELD: {
		int one = stoi(Input.at(1));
		std::string two;
		for (size_t i = 2; i < Input.size(); ++i) {
			if ((Input.size() - 1) > i) two.append(Input.at(i) + " ");
			else if ((Input.size() - 1) == i) two.append(Input.at(i));
		}
		rlua_setfield(luaState, one, two.c_str());
		break;
	}

					  //case OP_RAWGETI: {
					  //	int one = stoi(Input.at(1));
					  //	int two = stoi(Input.at(2));
					  //	Rlua::rlua_rawgeti(luaState, one, two);
					  //}

					  //case OP_RAWSETI: {
					  //	int one = stoi(Input.at(1));
					  //	signed int two = stoi(Input.at(2));
					  //	Rlua::rlua_rawseti(luaState, one, two);
					  //}

	case OP_PCALL: {
		int nargs = stoi(Input.at(1));
		int nresults = stoi(Input.at(2));
		int errfunc = stoi(Input.at(3));
		rlua_pcall(luaState, nargs, nresults, errfunc);
		break;
	}

	case OP_CALL: {
		int one = stoi(Input.at(1));
		int two = stoi(Input.at(2));
		rlua_pcall(luaState, one, two, 0);
		break;
	}

	case OP_PUSHNIL: {
		Rlua::rlua_pushnil(luaState);
		break;
	}

	case OP_PUSHSTRING: {
		std::string one;
		int size = Input.size();
		for (int i = 1; i < size; ++i) {
			if ((size - 1) > i) one.append(Input.at(i) + " ");
			else if ((size - 1) == i) one.append(Input.at(i));
		}
		Rlua::rlua_pushstring(luaState, one.c_str());
		break;
	}

	case OP_PUSHVALUE: {
		int one = stoi(Input.at(1));
		Rlua::rlua_pushvalue(luaState, one);
		break;
	}

	case OP_PUSHNUMBER: {
		double one = stod(Input.at(1));
		Rlua::rlua_pushnumber(luaState, one);
		break;
	}

	case OP_SETTOP: {
		int one = stoi(Input.at(1));
		Rlua::rlua_settop(luaState, one);
		break;
	}

	case OP_PUSHBOOLEAN: {
		if (Input.at(1) == "true" || Input.at(1) == "1") {
			Rlua::rlua_pushboolean(luaState, true);
		}
		else if (Input.at(1) == "false" || Input.at(1) == "0") {
			Rlua::rlua_pushboolean(luaState, false);
		}
		break;
	}

	case OP_POP: {
		int one = stoi(Input.at(1));
		rlua_pop(luaState, one);
		break;
	}

	case OP_WAIT: {
		//double one = stod(Input.at(1));
		int time = stoi(Input.at(1));
		Sleep(time * 1000);
		break;
	}

				  //I WANT TO DIE ^

	case OP_EMPTYSTACK: {
		Rlua::rlua_settop(luaState, 0);
		break;
	}

	default: {
		break;
	}
	}
}

//WHAT A GREAT MEME