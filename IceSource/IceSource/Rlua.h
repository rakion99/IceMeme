#include "stdafx.h"
#include "Scan.h"
#include "Main.h"

#pragma once

typedef int(RSkidState);

#define LUA_GLOBALSINDEX -10002
#define SKID_getglobal(l,g)			 Rlua::SKID_getfield(l, LUA_GLOBALSINDEX, g)
#define SKID_pushbool(SkidState, boolean)     int property = *(DWORD *)(SkidState + 24); *(DWORD*)property = boolean; *(DWORD *)(property + 8) = 3; *(DWORD *)(SkidState + 24) += 16;
#define SKID_tostring(l,idx)		 Rlua::SKID_toLstring(l, (idx), 0)

DWORD SkidCheck(DWORD addr)
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

namespace Rlua {
	typedef void(__cdecl *Lua_getfield)(RSkidState lst, int index, const char *k);
	Lua_getfield SKID_getfield = (Lua_getfield)SkidCheck(SKID(3491776));

	typedef void(__cdecl *Lua_settop)(RSkidState lst, int index);
	Lua_settop SKID_settop = (Lua_settop)SkidCheck(SKID(3500352));

	typedef void(__cdecl *Lua_pushstring)(RSkidState lst, const char *s);
	Lua_pushstring SKID_pushstring = (Lua_pushstring)SKID(3496864);

	typedef void(__cdecl *Lua_pushvalue)(RSkidState lst, int index);
	Lua_pushvalue SKID_pushvalue = (Lua_pushvalue)SkidCheck(SKID(3497072));

	typedef int(__cdecl *Lua_call)(RSkidState lst, int nargs, int nresults);
	Lua_call SKID_call = (Lua_call)SkidCheck(SKID(3490112));

	typedef void(__cdecl *Lua_setfield)(RSkidState lst, int index, const char *k);
	Lua_setfield SKID_setfield = (Lua_setfield)SkidCheck(SKID(3499360));

	typedef void(__cdecl *Lua_pushnumber)(RSkidState lst, double n);
	Lua_pushnumber SKID_pushnumber = (Lua_pushnumber)SkidCheck(SKID(3496720));

	typedef const char*(__cdecl *Lua_ToLString)(RSkidState lst, int idx, size_t *len);
	Lua_ToLString SKID_toLstring = (Lua_ToLString)SkidCheck(SKID(3500928));
}