#pragma once
//getfield
unsigned long getSkId = SKID(0x730b90);
//settop
unsigned long SkIdtop = SKID(0x732d10);
//pushstring
unsigned long pushSkId = SKID(0x731f70);
//pushvalue
unsigned long SkIdvalue = SKID(0x732030);
//call
unsigned long SkIds = SKID(0x730520);
//setfield
unsigned long setSkId = SKID(0x732930);
//pushnumber
unsigned long hOwMaNySkIdS = SKID(0x731ee0);
//contextlevel/identity
unsigned long SKIDLEVEL = SKID(0x5a75a0);
//ScriptContextVFTable
unsigned long SkIdTab = SKID(0x6b911e + 0x2);

int Skidtest;
int SkidState;
int skid = 220;

void SKIDD() {
	using namespace std;
	DWORD SkIdT = *(DWORD*)(SkIdTab);
	Skidtest = SkId::Scan((char*)&SkIdT);
	//luastate
	SkidState = (Skidtest + skid) ^ *(DWORD *)(Skidtest + skid);
}
