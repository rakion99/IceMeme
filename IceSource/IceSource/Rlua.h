#include "stdafx.h"
#include "Scan.h"
#include "Main.h"

#pragma once

typedef int(RLUAState);

#define LUA_GLOBALSINDEX -10002

#define rlua_getglobal(l,g)			 Rlua::rlua_getfield(l, LUA_GLOBALSINDEX, g)
#define rlua_pushbool(luaState, boolean)     int property = *(DWORD *)(luaState + 32); *(DWORD*)property = boolean; *(DWORD *)(property + 8) = 3; *(DWORD *)(luaState + 32) += 16;
#define rlua_pushnil(a1)             *(DWORD *)(*(DWORD *)(a1 + 32) + 8) = 0; *(DWORD *)(a1 + 32) += 16
#define rlua_tostring(l,idx)		 Rlua::rlua_toLstring(l, (idx), 0)
#define rlua_isnil(L,n)			     (Rlua::rlua_type(L, (n), TRUE) == 0)

namespace Retcheck {
	DWORD unprotect(DWORD addr)
	{
		BYTE* tAddr = (BYTE *)addr;

		do {
			tAddr += 0x10;
		} while (!(tAddr[0] == 0x55 && tAddr[1] == 0x8B && tAddr[2] == 0xEC));

		DWORD funcSz = tAddr - (BYTE*)addr;

		PVOID nFunc = VirtualAlloc(NULL, funcSz, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
		if (nFunc == NULL)
			return addr;

		memcpy(nFunc, (void*)addr, funcSz);

		DWORD pos = (DWORD)nFunc;
		BOOL valid = false;
		do {
			if (*(BYTE*)pos == 0x72 && *(BYTE*)(pos + 0x2) == 0xA1 && (*(BYTE*)(pos + 0x7)) == 0x8B) {
				memcpy((void*)pos, "\xEB", 1);

				DWORD cNFunc = (DWORD)nFunc;
				do {
					if (*(BYTE*)cNFunc == 0xE8)
					{
						DWORD tFunc = addr + (cNFunc - (DWORD)nFunc);
						DWORD oFunc = (tFunc + *(DWORD*)(tFunc + 1)) + 5;

						if (oFunc % 16 == 0)
						{
							DWORD realCAddr = oFunc - cNFunc - 5;
							*(DWORD*)(cNFunc + 1) = realCAddr;
						}
						cNFunc += 5;
					}
					else
						cNFunc += 1;
				} while (cNFunc - (DWORD)nFunc < funcSz);

				valid = true;
			}
			pos += 1;
		} while (pos < (DWORD)nFunc + funcSz);

		if (!valid) {
			VirtualFree(nFunc, funcSz, MEM_RELEASE);
			return addr;
		}

		return (DWORD)nFunc;
	}
}

namespace Rlua {
	typedef void(__cdecl *Lua_getfield)(RLUAState lst, int index, const char *k);
	Lua_getfield rlua_getfield = (Lua_getfield)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\x6A\x01\xFF\x75\x10", "xxxxxxxx"));

	typedef void(__cdecl *Lua_settop)(RLUAState lst, int index);
	Lua_settop rlua_settop = (Lua_settop)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\x8B\x55\x0C\x85\xD2\x78\x38", "xxxxxxxxxx"));

	typedef void(__cdecl *Lua_pushstring)(RLUAState lst, const char *s);
	Lua_pushstring rlua_pushstring = (Lua_pushstring)aobscan::scan("\x55\x8B\xEC\x8B\x55\x0C\x85\xD2\x75\x0D", "xxxxxxxxxx");

	typedef void(__cdecl *Lua_pushvalue)(RLUAState lst, int index);
	Lua_pushvalue rlua_pushvalue = (Lua_pushvalue)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\x56\xFF\x75\x0C\x8B\x75\x08\x56\xE8\x00\x00\x00\x00\x8B\x56\x20\x83\xC4\x08", "xxxxxxxxxxxx????xxxxxx"));

	typedef int(__cdecl *Lua_call)(RLUAState lst, int nargs, int nresults);
	Lua_call rlua_call = (Lua_call)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\x8B\x4D\x0C\x57\x8B\x7D\x08\xFF\x75\x10", "xxxxxxxxxxxxx"));

	typedef void(__cdecl *Lua_setfield)(RLUAState lst, int index, const char *k);
	Lua_setfield rlua_setfield = (Lua_setfield)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\x83\xEC\x10\x53\x56\x8B\x75\x08\x57\xFF\x75\x0C\x56\xE8\x00\x00\x00\x00\x8B\x55\x10\x83\xC4\x08\x8B\xCA\x8B\xF8\x8D\x59\x01\x8A\x01\x41\x84\xC0\x75\xF9\x2B\xCB\x51\x52\x56\xE8\x00\x00\x00\x00\x89\x45\xF0", "xxxxxxxxxxxxxxxxx????xxxxxxxxxxxxxxxxxxxxxxxxxx????xxx"));

	typedef void(__cdecl *Lua_pushnumber)(RLUAState lst, double n);
	Lua_pushnumber rlua_pushnumber = (Lua_pushnumber)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\x8B\x4D\x08\x0F\x28\x15", "xxxxxxxxx"));

	typedef const char*(__cdecl *Lua_ToLString)(RLUAState lst, int idx, size_t *len);
	Lua_ToLString rlua_toLstring = (Lua_ToLString)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\x56\x8B\x75\x08\xB9\x00\x00\x00\x00\x66\xFF\x46\x34", "xxxxxxxx????xxxx"));

	typedef int(__cdecl *Lua_type)(RLUAState lst, int idx, bool type);
	Lua_type rlua_type = (Lua_type)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\xFF\x75\x0C\xFF\x75\x08\xE8\x00\x00\x00\x00\x83\xC4\x08\x3D\x00\x00\x00\x00\x75\x05", "xxxxxxxxxx????xxxx????xx"));

	typedef int(__cdecl *Lua_next)(RLUAState lst, int idx);
	Lua_next rlua_next = (Lua_next)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\x56\xFF\x75\x0C\x8B\x75\x08\x56\xE8\x00\x00\x00\x00\x8B\x4E\x20\x83\xE9\x10\x51\xFF\x30\x56", "xxxxxxxxxxxx????xxxxxxxxxx"));

}