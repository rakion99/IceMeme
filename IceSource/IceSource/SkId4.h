#include "stdafx.h"
#include "SkId5.h"
#include "SkId.h"

#pragma once

typedef int(RSkidState);

#define LUA_GLOBALSKID -10002
#define SKID_globalSkId(l,g)			 Rlua::SKID_getSkId(l, LUA_GLOBALSKID, g)

DWORD SkidCheck(DWORD SkIdr)
{
	BYTE* tSkId = (BYTE *)SkIdr;

	do {
		tSkId += 0x10;
	} while (!(tSkId[0] == 0x55 && tSkId[1] == 0x8B && tSkId[2] == 0xEC));

	DWORD SkIdSz = tSkId - (BYTE*)SkIdr;

	PVOID nSkId = VirtualAlloc(NULL, SkIdSz, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	if (nSkId == NULL)
		return SkIdr;

	memcpy(nSkId, (void*)SkIdr, SkIdSz);

	DWORD poSkId = (DWORD)nSkId;
	BOOL vSkId = false;
	do {
		if (*(BYTE*)poSkId == 0x72 && *(BYTE*)(poSkId + 0x2) == 0xA1 && (*(BYTE*)(poSkId + 0x7)) == 0x8B) {
			memcpy((void*)poSkId, "\xEB", 1);

			DWORD cnSkId = (DWORD)nSkId;
			do {
				if (*(BYTE*)cnSkId == 0xE8)
				{
					DWORD tFSkId = SkIdr + (cnSkId - (DWORD)nSkId);
					DWORD oSkId = (tFSkId + *(DWORD*)(tFSkId + 1)) + 5;

					if (oSkId % 16 == 0)
					{
						DWORD realSkId = oSkId - cnSkId - 5;
						*(DWORD*)(cnSkId + 1) = realSkId;
					}
					cnSkId += 5;
				}
				else
					cnSkId += 1;
			} while (cnSkId - (DWORD)nSkId < SkIdSz);

			vSkId = true;
		}
		poSkId += 1;
	} while (poSkId < (DWORD)nSkId + SkIdSz);

	if (!vSkId) {
		VirtualFree(nSkId, SkIdSz, MEM_RELEASE);
		return SkIdr;
	}

	return (DWORD)nSkId;
}

namespace Rlua {
	typedef void(__cdecl *Lua_getSkId)(RSkidState lst, int index, const char *k);
	Lua_getSkId SKID_getSkId = (Lua_getSkId)SkidCheck(SKID(015155660));

	typedef void(__cdecl *Lua_SkIdtop)(RSkidState lst, int index);
	Lua_SkIdtop SKID_SkIdtop = (Lua_SkIdtop)SkidCheck(SKID(015176400));

	typedef void(__cdecl *Lua_pushSkId)(RSkidState lst, const char *s);
	Lua_pushSkId SKID_pushSkId = (Lua_pushSkId)SKID(015167600);

	typedef void(__cdecl *Lua_SkIdvalue)(RSkidState lst, int index);
	Lua_SkIdvalue SKID_SkIdvalue = (Lua_SkIdvalue)SkidCheck(SKID(015170100));

	typedef int(__cdecl *Lua_SkId)(RSkidState lst, int nargs, int nresults);
	Lua_SkId SKID_SkId = (Lua_SkId)SkidCheck(SKID(015152500));

	typedef void(__cdecl *Lua_setSkId)(RSkidState lst, int index, const char *k);
	Lua_setSkId SKID_setSkId = (Lua_setSkId)SkidCheck(SKID(015174440));

	typedef void(__cdecl *Lua_hOwMaNySkIdS)(RSkidState lst, double n);
	Lua_hOwMaNySkIdS SKID_hOwMaNySkIdS = (Lua_hOwMaNySkIdS)SkidCheck(SKID(015167360));

	typedef int*(__cdecl *SKIDLeVEL)();
	SKIDLeVEL SKIDLeVeL = (SKIDLeVEL)SKID(06556440);
}