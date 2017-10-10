#include "stdafx.h"
#include "Scan.h"
#include "Main.h"

#pragma once

typedef int(RLUAState);
typedef int(PMSGTYPE);

#define ERRMSG		3
#define WARNMSG		2
#define INFOMSG		1
#define NORMMSG		0

#define LUA_GLOBALSINDEX -10002
#define LUA_REGISTRYINDEX -10000

#define rlua_getglobal(l,g)			 Rlua::rlua_getfield(l, LUA_GLOBALSINDEX, g)
#define rlua_pushbool(luaState, boolean)     int property = *(DWORD *)(luaState + 16); *(DWORD*)property = boolean; *(DWORD *)(property + 8) = 3; *(DWORD *)(luaState + 16) += 16;
#define rlua_pushnil(a1)             *(DWORD *)(*(DWORD *)(a1 + 16) + 8) = 0; *(DWORD *)(a1 + 16) += 16
#define rlua_tostring(l,idx)		 Rlua::rlua_toLstring(l, (idx), 0)
#define rlua_pop(L,n)                Rlua::rlua_settop(L, -(n)-1)
#define rlua_isnil(L,n)			     (Rlua::rlua_type(L, (n), TRUE) == 0)
#define RLUA_TNONE					 (-1)
#define RLUA_TNIL                     0
#define RLUA_TNUMBER                  2
#define RLUA_TBOOLEAN                 3
#define RLUA_TSTRING                  4
#define RLUA_TLIGHTUSERDATA		      1
#define RLUA_TTABLE                   7
#define RLUA_TUSERDATA			      8
#define RLUA_TFUNCTION				  6
#define RLUA_TPROTO                   9
#define RLUA_TTHREAD                  5
#define RLUA_TUPVALUE                 10

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
	Lua_pushvalue rlua_pushvalue = (Lua_pushvalue)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\x56\xFF\x75\x0C\x8B\x75\x08\x56\xE8\x00\x00\x00\x00\x8B\x56\x1C\x83\xC4\x08", "xxxxxxxxxxxx????xxxxxx"));

	typedef int(__cdecl *Lua_pcall)(RLUAState lst, int nargs, int nresults, int errfunc);
	Lua_pcall rlua_pcall = (Lua_pcall)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\x8B\x4D\x0C\x57\x8B\x7D\x08\xFF\x75\x10", "xxxxxxxxxxxxx"));//this is call aobs/signature, i will change the name soon :P

	typedef void(__cdecl *Lua_setfield)(RLUAState lst, int index, const char *k);
	Lua_setfield rlua_setfield = (Lua_setfield)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\x83\xEC\x10\x53\x56\x8B\x75\x08\x57\xFF\x75\x0C\x56\xE8\x00\x00\x00\x00\x8B\x55\x10\x83\xC4\x08\x8B\xCA\x8B\xF8\x8D\x59\x01\x8A\x01\x41\x84\xC0\x75\xF9\x2B\xCB\x51\x52\x56\xE8\x00\x00\x00\x00\x89\x45\xF0", "xxxxxxxxxxxxxxxxx????xxxxxxxxxxxxxxxxxxxxxxxxxx????xxx"));

	typedef void(__cdecl *Lua_pushnumber)(RLUAState lst, double n);
	Lua_pushnumber rlua_pushnumber = (Lua_pushnumber)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\x8B\x4D\x08\x0F\x28\x15", "xxxxxxxxx"));

	typedef const char*(__cdecl *Lua_ToLString)(RLUAState lst, int idx, size_t *len);
	Lua_ToLString rlua_toLstring = (Lua_ToLString)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\x56\x8B\x75\x08\xB9\x00\x00\x00\x00\x66\xFF\x46\x34", "xxxxxxxx????xxxx"));

	typedef bool(__cdecl *Lua_toBoolean)(RLUAState lst, int idx);
	Lua_toBoolean rlua_toBool = (Lua_toBoolean)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\xFF\x75\x0C\xFF\x75\x08\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B\x48\x08\x85\xC9", "xxxxxxxxxx????xxxxxxxx"));

	typedef int(__cdecl *Lua_tonumber)(RLUAState lst, int idx);
	Lua_tonumber rlua_tonumber = (Lua_tonumber)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\x83\xEC\x10\xFF\x75\x0C\xFF\x75\x08\xE8", "xxxxxxxxxxxxx"));

	typedef int(__cdecl *Lua_type)(RLUAState lst, int idx, bool type);
	Lua_type rlua_type = (Lua_type)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\xFF\x75\x0C\xFF\x75\x08\xE8\x00\x00\x00\x00\x83\xC4\x08\x3D\x00\x00\x00\x00\x75\x05", "xxxxxxxxxx????xxxx????xx"));

	typedef int(__cdecl *Lua_next)(RLUAState lst, int idx);
	Lua_next rlua_next = (Lua_next)Retcheck::unprotect(aobscan::scan("\x55\x8B\xEC\x83\xEC\x18\x56\x8B\x75\x08\x57\xFF\x75\x0C", "xxxxxxxxxxxxxx"));

	int rlua_gettop(RLUAState state) {
		return (*(DWORD *)(state + 16) - *(DWORD *)(state + 28)) >> 4;
	}

}

void rlua_print(PMSGTYPE out, const char * msgfmt, ...)
{
	va_list args;
	va_start(args, msgfmt);
	char buff[1024];
	vsnprintf_s(buff, sizeof(buff), msgfmt, args);
	((int(*)(int, int, const char*, ...))aobscan::scan("\x55\x8B\xEC\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x64\x89\x25\x00\x00\x00\x00\x83\xEC\x30\x8D\x45\x14", "xxxxxx????xx????xxxx????xxxxxx"))(((int(__cdecl*)())aobscan::scan("\x55\x8B\xEC\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x64\x89\x25\x00\x00\x00\x00\x51\x64\xA1\x00\x00\x00\x00\x8B\x0D\x00\x00\x00\x00\x8B\x0C\x88\xA1\x00\x00\x00\x00\x3B\x81\x00\x00\x00\x00\x7E\x4F", "xxxxxx????xx????xxxx????xxx????xx????xxxx????xx????xx"))(), out, buff);
	va_end(args);
}