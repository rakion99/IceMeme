#pragma once

#define WRITABLE (PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY)

#define GetAddr(x) (x - 0x400000 + (int)GetModuleHandle(0));

DWORD GetAddr2(int address) {
	return (address - 0x400000 + (DWORD)GetModuleHandle(0));
}

namespace Memory {
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

	int Scan(DWORD mode, char* content, char* mask)
	{
		DWORD PageSize;
		SYSTEM_INFO si;
		GetSystemInfo(&si);
		PageSize = si.dwPageSize;
		MEMORY_BASIC_INFORMATION mi;
		for (DWORD lpAddr = 0; lpAddr<0x7FFFFFFF; lpAddr += PageSize)
		{
			DWORD vq = VirtualQuery((void*)lpAddr, &mi, PageSize);
			if (vq == ERROR_INVALID_PARAMETER || vq == 0) break;
			if (mi.Type == MEM_MAPPED) continue;
			if (mi.Protect == mode)
			{
				int addr = FindPattern(lpAddr, PageSize, (PBYTE)content, mask);
				if (addr != 0)
				{
					return addr;
				}
			}
		}
		return 0;
	}
}

namespace aobscan {
	BOOL compare(const BYTE* location, const BYTE* aob, const char* mask) {
		for (; *mask; ++aob, ++mask, ++location) {
			__try {
				if (*mask == 'x' && *location != *aob)
					return 0;
			}
			__except (EXCEPTION_EXECUTE_HANDLER) {
				return 0;
			}
		}
		return 1;
	};

	DWORD scan(const char* aob, const char* mask) {
		for (DWORD i = (DWORD)GetModuleHandle(NULL); i <= 0xF000000; ++i) {

			if (compare((BYTE*)i, (BYTE*)aob, mask))
				return i;
		}
		return 0;
	};

	DWORD scanWritable(const char* aob, const char* mask) {
		MEMORY_BASIC_INFORMATION memoryInfo;
		DWORD regionEnd = 0;
		DWORD maskLen = strlen(mask);
		for (DWORD i = (DWORD)GetModuleHandle(NULL); i <= 0x4FFFFFFF; ++i) {
			if (i + maskLen > regionEnd) {
				i += maskLen;
			}

			if (i > regionEnd || !regionEnd) {
				VirtualQuery((DWORD*)i, &memoryInfo, sizeof(memoryInfo));
				regionEnd = i + memoryInfo.RegionSize;
				if (!((memoryInfo.State & MEM_COMMIT) && (memoryInfo.Protect & WRITABLE))) {
					i = regionEnd + 1;
					continue;
				}
			}

			if (compare((BYTE*)i, (BYTE*)aob, mask))
				return i;
		}
		return 0;
	}
};