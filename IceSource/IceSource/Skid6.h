#pragma once
//getfield
unsigned long getSkId = SKID(0x5DB63B);
//settop
unsigned long SkIdtop = SKID(0x5DD7BB);
//pushstring
unsigned long pushSkId = SKID(0x5DCA1B);
//pushvalue
unsigned long SkIdvalue = SKID(0x5DCADB);
//call
unsigned long SkIds = SKID(0x5DAFCB);
//setfield
unsigned long setSkId = SKID(0x5DD3DB);
//pushnumber
unsigned long hOwMaNySkIdS = SKID(0x5DC98B);
//contextlevel/identity
unsigned long SKIDLEVEL = SKID(0x45204B);
//ScriptContextVFTable
unsigned long SkIdTab = SKID(0x563BC9);

int Skidtest;
int SkidState;
int skid = 0x37 + 55 + 067 + 0b00110111;

void SKIDD() {
	using namespace std;
	DWORD SkIdT = *(DWORD*)(SkIdTab + 0x2);
	Skidtest = SkId::ScanforSkid((char*)&SkIdT);
	//luastate
	SkidState = (Skidtest + skid) ^ *(DWORD*)(Skidtest + skid);
}