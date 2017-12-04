#pragma once

typedef int(RSkidState);

#define LUA_GLOBALSKID -10002
#define SKID_globalSkId(l,g)			 Rlua::SKID_getSkId(l, LUA_GLOBALSKID, g)
#define SKID_popSkId(L,n)		SKID_SkIdtop(L, -(n)-1)

DWORD SkidCheck(DWORD skider)
{
	BYTE* tskider = (BYTE*)skider;

	/* Calcualte the size of the function
	In theory this will run until it hits the next
	functions prolog. It assumes all calls are aligned to
	16 bytes. (grazie katie)
	*/
	do
	{
		tskider += 16;
	} while (!(tskider[0] == 0x55 && tskider[1] == 0x8B && tskider[2] == 0xEC));

	DWORD SkidSz = tskider - (BYTE*)skider;

	/* Allocate memory for the new function */
	PVOID nSkid = VirtualAlloc(NULL, SkidSz, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	if (nSkid == NULL)
		return skider;

	/* Copy the function to the newly allocated memory */
	memcpy(nSkid, (void*)skider, SkidSz);

	BYTE* poSkid = (BYTE*)nSkid;
	BOOL isskid = false;
	do
	{
		/* Check for the return check with the sig:
		72 ?? A1 ?? ?? ?? ?? 8B
		If the sig matches replace the the jb with a jmp.
		*/
		if (poSkid[0] == 0x72 && poSkid[2] == 0xA1 && poSkid[7] == 0x8B) {
			*(BYTE*)poSkid = 0xEB;

			DWORD cSkid = (DWORD)nSkid;
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
				if (*(BYTE*)cSkid == 0xE8)
				{
					DWORD oSkidPos = skider + (cSkid - (DWORD)nSkid);
					DWORD oSkidAddr = (oSkidPos + *(DWORD*)(oSkidPos + 1)) + 5;

					if (oSkidAddr % 16 == 0)
					{
						DWORD relativeSkid = oSkidAddr - cSkid - 5;
						*(DWORD*)(cSkid + 1) = relativeSkid;

						cSkid += 4;
					}
				}

				cSkid += 1;
			} while (cSkid - (DWORD)nSkid < SkidSz);

			isskid = true;
		}
		poSkid += 1;
	} while ((DWORD)poSkid < (DWORD)nSkid + SkidSz);

	/* This function has no return check, let's not waste memory */
	if (!isskid)
	{
		VirtualFree(nSkid, SkidSz, MEM_RELEASE);
		return skider;
	}

	return (DWORD)nSkid;
}

namespace Rlua {
	unsigned int PENV = 0x72A2E7;
	void set_jz()
	{
		DWORD o_buff;
		VirtualProtect((void*)PENV, 5, PAGE_EXECUTE_READWRITE, &o_buff);
		*(char*)PENV = 0x74; //opcode for jz
		VirtualProtect((void*)PENV, 5, o_buff, &o_buff);
	}
	void set_jnz()
	{
		DWORD o_buff;
		VirtualProtect((void*)PENV, 5, PAGE_EXECUTE_READWRITE, &o_buff);
		*(char*)PENV = 0x75; //op_code for jnz. 
		VirtualProtect((void*)PENV, 5, o_buff, &o_buff);
	}
	
	typedef void(__cdecl *Lua_getSkId)(RSkidState lst, int index, const char *k);
	Lua_getSkId SKID_getSkId = (Lua_getSkId)SkidCheck(getSkId);
	typedef void(__cdecl *Lua_SkIdtop)(RSkidState lst, int index);
	Lua_SkIdtop SKID_SkIdtop = (Lua_SkIdtop)SkidCheck(SkIdtop);
	typedef void(__cdecl *Lua_pushSkId)(RSkidState lst, const char *s);
	Lua_pushSkId SKID_pushSkId = (Lua_pushSkId)pushSkId;
	typedef void(__cdecl *Lua_SkIdvalue)(RSkidState lst, int index);
	Lua_SkIdvalue SKID_SkIdvalue = (Lua_SkIdvalue)SkidCheck(SkIdvalue);
	typedef int(__cdecl *Lua_SkId)(RSkidState lst, int nargs, int nresults);
	Lua_SkId SKID_SkId = (Lua_SkId)SkidCheck(SkIds);
	typedef int(__cdecl *Lua_SkId)(RSkidState lst, int nargs, int nresults, int errfunc);
	int SKID_PSkId(RSkidState lst, int nargs, int nresults, int errfunc)
	{
		set_jnz();
		Lua_SkId PCALL = (Lua_SkId)SkidCheck(PSkIds);
		set_jz();
	}
	typedef int(__cdecl *Lua_getSkIdtable)(RSkidState lst, int objectidx);
	Lua_getSkIdtable SKID_getSkIdtable = (Lua_getSkIdtable)SkidCheck(getSkIdtable);
	typedef void(__cdecl *Lua_setSkId)(RSkidState lst, int index, const char *k);
	void SKID_setSkId(RSkidState lst, int index, const char *k)
	{
		SKID_SkIdvalue(lst, index);
		if (SKID_getSkIdtable(lst, -1))
		{
			SKID_getSkId(lst, -1, "__newindex");
			SKID_SkIdvalue(lst, -3);
			SKID_pushSkId(lst, k);
			SKID_SkIdvalue(lst, -6);
			SKID_PSkId(lst, 3, 0, 0);
			SKID_popSkId(lst, 3);
		}
		else
		{
			SKID_popSkId(lst, 1);
			Lua_setSkId setfield = (Lua_setSkId)SkidCheck(setSkId);
			setfield(lst, index, k);
		}
	}
	typedef void(__cdecl *Lua_hOwMaNySkIdS)(RSkidState lst, double n);
	Lua_hOwMaNySkIdS SKID_hOwMaNySkIdS = (Lua_hOwMaNySkIdS)SkidCheck(hOwMaNySkIdS);
	typedef int*(__cdecl *SKIDLeVEL)();
	SKIDLeVEL SKIDLeVeL = (SKIDLeVEL)SKIDLEVEL;
}
