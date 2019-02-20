#pragma once

typedef int(RluaState);

#define rlua_setglobal(L,s)			 rlua_setfield(L, LUA_GLOBALSINDEX, (s))
#define rlua_getglobal(L,s)			 Rlua::rlua_getfield(L, LUA_GLOBALSINDEX, (s))
#define rlua_pop(L,n)				 Rlua::rlua_settop(L, -(n)-1)
#define rlua_isnil(L,n)				 (Rlua::rlua_type(L, (n)) == LUA_TNIL)

//retcheck by eternal
DWORD unprotect(DWORD addr)
{
	BYTE* tAddr = (BYTE*)addr;

	/* Calcualte the size of the function
	In theory this will run until it hits the next
	functions prolog. It assumes all calls are aligned to
	16 bytes. (grazie katie)
	*/
	do
	{
		tAddr += 16;
	} while (!(tAddr[0] == 0x55 && tAddr[1] == 0x8B && tAddr[2] == 0xEC));

	DWORD funcSz = tAddr - (BYTE*)addr;

	/* Allocate memory for the new function */
	PVOID nFunc = VirtualAlloc(NULL, funcSz, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	if (nFunc == NULL)
		return addr;

	/* Copy the function to the newly allocated memory */
	memcpy(nFunc, (void*)addr, funcSz);

	BYTE* pos = (BYTE*)nFunc;
	BOOL valid = false;
	do
	{
		/* Check for the return check with the sig:
		72 ?? A1 ?? ?? ?? ?? 8B
		If the sig matches replace the the jb with a jmp.
		*/
		if (pos[0] == 0x72 && pos[2] == 0xA1 && pos[7] == 0x8B) {
			*(BYTE*)pos = 0xEB;

			DWORD cByte = (DWORD)nFunc;
			do
			{
				/* Check if the current byte is a call if it is,
				calculate the new relative call(s).
				*(->E8 + 1) = originalFunction - nextInstruction

				oFuncPos - Position of call in original function
				= originalFunction + (->E8 - newFunction)

				oFuncAddr - Original call location
				= oFuncPos + rel32Offset + sizeof(call)

				relativeAddr - New relative address
				= oFuncAddr - ->E8 - sizeof(call)

				Since we are not using a disassembler we assume
				that if we hit a E8 byte which is properly aligned
				it is a relative call.
				For a small amount of compensation I skip location
				of the call, since it is possible to have the byte
				E8 inside of it.
				*/
				if (*(BYTE*)cByte == 0xE8)
				{
					DWORD oFuncPos = addr + (cByte - (DWORD)nFunc);
					DWORD oFuncAddr = (oFuncPos + *(DWORD*)(oFuncPos + 1)) + 5;

					if (oFuncAddr % 16 == 0)
					{
						DWORD relativeAddr = oFuncAddr - cByte - 5;
						*(DWORD*)(cByte + 1) = relativeAddr;

						cByte += 4;
					}
				}

				cByte += 1;
			} while (cByte - (DWORD)nFunc < funcSz);

			valid = true;
		}
		pos += 1;
	} while ((DWORD)pos < (DWORD)nFunc + funcSz);

	/* This function has no return check, let's not waste memory */
	if (!valid)
	{
		VirtualFree(nFunc, funcSz, MEM_RELEASE);
		return addr;
	}

	return (DWORD)nFunc;
}

namespace Rlua {
	typedef void(getfieldcc *Lua_getfield)(RluaState lst, int index, const char *k);
	Lua_getfield rlua_getfield = (Lua_getfield)unprotect(getfieldaddress);
	typedef void(settopcc *Lua_settop)(RluaState lst, int index);
	Lua_settop rlua_settop = (Lua_settop)unprotect(settopaddress);
	typedef void(pushstringcc *Lua_pushstring)(RluaState lst, const char *s);
	Lua_pushstring rlua_pushstring = (Lua_pushstring)pushstringaddress;
	typedef void(pushvaluecc *Lua_pushvalue)(RluaState lst, int index);
	Lua_pushvalue rlua_pushvalue = (Lua_pushvalue)unprotect(pushvalueaddress);
	typedef void(setfieldcc *Lua_setfield)(RluaState lst, int index, const char *k);
	Lua_setfield rlua_setfield2 = (Lua_setfield)unprotect(setfieldaddress);
	typedef void(pushnumbercc *Lua_pushnumber)(RluaState lst, double n);
	Lua_pushnumber rlua_pushnumber = (Lua_pushnumber)unprotect(pushnumberaddress);
	typedef int(getmetatablecc *Lua_getmetatable)(RluaState lst, int idx);
	Lua_getmetatable rlua_getmetatable = (Lua_getmetatable)unprotect(getmetatableaddress);
	typedef int(pcallcc *Lua_pcall)(RluaState lst, int nargs, int nresults, int errfunc);
	Lua_pcall rlua_pcall2 = (Lua_pcall)unprotect(pcalladdress);
	typedef int(pushboolcc *Lua_pushboolean)(RluaState lst, bool type);
	Lua_pushboolean rlua_pushboolean = (Lua_pushboolean)unprotect(pushbooleanaddress);
	typedef int(pushnilcc *lua_pushnil)(RluaState lst);
	lua_pushnil rlua_pushnil = (lua_pushnil)unprotect(pushniladdress);
	typedef int(typecc *Lua_type)(RluaState lst, int idx);
	Lua_type rlua_type = (Lua_type)unprotect(typeaddress);
}

void rlua_pcall(RluaState lst, int nargs, int nresults, int errfunc) {
	//we dont need more rawrcheck bypass duh but 2 lazy to remove these shit
	//Bypass RawrCheck by tepig
	//WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(rawrjzaddress), "\xEB", 1, 0);
	Rlua::rlua_pcall2(lst, nargs, nresults, errfunc);
	//Restore RawrCheck by tepig
	//WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(rawrjzaddress), "\x74", 1, 0);
}

//bypass/workaround for setting values on non-fe games thanks to DOGGO from SpoonFeed Hub Discord
//idk if still needed but 2 lazy to check
void rlua_setfield(int L, int idx, const char *k) {
	Rlua::rlua_pushvalue(L, idx);
	if (Rlua::rlua_getmetatable(L, -1)) {
		Rlua::rlua_getfield(L, -1, "__newindex");
		Rlua::rlua_pushvalue(L, -3);
		Rlua::rlua_pushstring(L, k);
		Rlua::rlua_pushvalue(L, -6);
		rlua_pcall(L, 3, 0, 0);
		rlua_pop(L, 3);
	}
	else {
		rlua_pop(L, 1);
		Rlua::rlua_setfield2(L, idx, k);
	}
}