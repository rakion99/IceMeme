#pragma once

inline long SKID(long Address) {
	return (Address + (DWORD)GetModuleHandle(0));
}

namespace SkId {
	bool Compare(const BYTE *pData, const BYTE *bMask, const char *szMask)
	{
		for (; *szMask; ++szMask, ++pData, ++bMask)
			if (*szMask == 'x' && *pData != *bMask) return 0;
		return (*szMask) == NULL;
	}

	DWORD FindPattern(DWORD dwAddress, DWORD dwLen, BYTE *bMask, char *szMask)
	{
		for (int i = 0; i<(int)dwLen; i++)
			if (Compare((BYTE*)(dwAddress + (int)i), bMask, szMask))  return (int)(dwAddress + i);
		return 0;
	}

	long Scan(char* content)
	{
		MEMORY_BASIC_INFORMATION meminfo;
		SYSTEM_INFO SystemInfo;
		GetSystemInfo(&SystemInfo);
		long PageSize = SystemInfo.dwPageSize;
		long Start = (long)SystemInfo.lpMinimumApplicationAddress;
		long End = (long)SystemInfo.lpMaximumApplicationAddress;
		do {
			while (VirtualQuery((void*)Start, &meminfo, PageSize) == sizeof(meminfo)) {
				if (meminfo.Protect == PAGE_READWRITE) {
					long ScannedAddress = FindPattern(Start, PageSize, (PBYTE)content, "xxxx");
					if (ScannedAddress != 0) return ScannedAddress;
				}
				Start += PageSize;
			}
		} while (Start <= End);
	}
}