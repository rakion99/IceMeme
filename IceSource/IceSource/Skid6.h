#pragma once
//getfield
unsigned long getSkId = SKID(034522360 - 0b010000000000000000000000);
//settop
unsigned long SkIdtop = SKID(11716176 - 0x800000);
//pushstring
unsigned long pushSkId = SKID(0b00101011100010110000 + 0x300000);
//pushvalue
unsigned long SkIdvalue = SKID(06256270 + 1662136);
//call
unsigned long SkIds = SKID(0b001100101001111010000000);
//setfield
unsigned long setSkId = SKID(014541160);
//pushnumber
unsigned long hOwMaNySkIdS = SKID(0x32B820);
//contextlevel/identity
unsigned long SKIDLEVEL = SKID(1715376);
//ScriptContextVFTable
unsigned long SkIdTab = SKID(0x2B27C0);

int Skidtest;
int SkidState;
int skid = 0x37 + 55 + 067 + 0b00110111;
//The scan method
void SKIDD() {
	using namespace std;
	//Get the vftable
	DWORD SkIdT = *(DWORD*)(SkIdTab);
	//Scan the vftable
	Skidtest = SkId::Scan((char*)&SkIdT);
	//luastate
	SkidState = Skidtest + skid - *(DWORD*)(Skidtest + skid);
}
