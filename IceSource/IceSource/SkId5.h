#pragma once
//Get address
inline long SKID(long SkId) {
	return (SkId + (DWORD)GetModuleHandle(0));
}
//Get address (Use this if you use the #addys channel or find them yourself)
inline long SKIDAddr(long SkId) {
	return (SkId + (DWORD)GetModuleHandle(0) - 0x400000);
}
//Memory
namespace SkId {
	//Compare addys
	bool SkIdpare(const BYTE *pSkId, const BYTE *bSkId, const char *szSkId)
	{
		for (; *szSkId; ++szSkId, ++pSkId, ++bSkId)
			if (*szSkId == 'x' && *pSkId != *bSkId) return 0;
		return (*szSkId) == NULL;
	}
	//Find patterns
	DWORD FindPattern(DWORD dwSkId, DWORD dwLenSkId, BYTE *bSkId, char *szSkId)
	{
		for (int i = 0; i<(int)dwLenSkId; i++)
			if (SkIdpare((BYTE*)(dwSkId + (int)i), bSkId, szSkId))  return (int)(dwSkId + i);
		return 0;
	}
	//scan addys
	long Scan(char* SkId)
	{
		MEMORY_BASIC_INFORMATION meme;
		SYSTEM_INFO SkIdInfo;
		GetSystemInfo(&SkIdInfo);
		long SkIdSize = SkIdInfo.dwPageSize;
		long SkIdStart = (long)SkIdInfo.lpMinimumApplicationAddress;
		long SkIdEnd = (long)SkIdInfo.lpMaximumApplicationAddress;
		do {
			while (VirtualQuery((void*)SkIdStart, &meme, SkIdSize) == sizeof(meme)) {
				if (meme.Protect == PAGE_READWRITE) {
					long ScannedSkId = FindPattern(SkIdStart, SkIdSize, (PBYTE)SkId, "xxxx");
					if (ScannedSkId != 0) return ScannedSkId;
				}
				SkIdStart += SkIdSize;
			}
		} while (SkIdStart <= SkIdEnd);
	}
}
