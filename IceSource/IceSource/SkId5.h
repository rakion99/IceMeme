#pragma once
//Get address
inline long SKID(long SkId) {
	return (0x155555 + SkId - 1398101 - 0b000101010101010101010101 + (DWORD)GetModuleHandle(0) - 05252525 - 0x1);
}
//Get address (Use this if you use the #addys channel or find them yourself)
inline long SKIDAddr(long SkId) {
	return (SkId + (DWORD)GetModuleHandle(0) - 0x400000);
}
//Memory
namespace SkId {
  //Compare addresses
	bool Skidpare(const char* pskid, const char* bskid, const char* szskid)
	{
		while (*szskid) {
			if (*szskid != '?') {
				if (*pskid != *bskid) return 0;
			}
			++szskid, ++pskid, ++bskid;
		}
		return 1;
	}
  //Scan VFTable
	DWORD ScanforSkid(const char* vfskid)
	{
		MEMORY_BASIC_INFORMATION SKIDI = { 0 };
		SYSTEM_INFO SkId = { 0 };
		GetSystemInfo(&SkId);
		DWORD StartSkId = (DWORD)SkId.lpMinimumApplicationAddress;
		DWORD EndSkId = (DWORD)SkId.lpMaximumApplicationAddress;
		do
		{
			while (VirtualQuery((void*)StartSkId, &SKIDI, sizeof(SKIDI))) {
				if ((SKIDI.Protect & PAGE_READWRITE) && !(SKIDI.Protect & PAGE_GUARD))
				{
					for (DWORD i = (DWORD)(SKIDI.BaseAddress); i - (DWORD)(SKIDI.BaseAddress) < SKIDI.RegionSize; ++i)
					{
						if (Skidpare((const char*)i, vfskid, "xxxx"))
							return i;
					}
				}
				StartSkId += SKIDI.RegionSize;
			}
		} while (StartSkId < EndSkId);
			return 0;
	}
}
}
