#pragma once

#include "stdafx.h"

#include "Rlua.h"
#include "Functions.h"

using namespace std;
using namespace Rlua;

void ExecuteCommand(std::string cmd) {
	std::vector<std::string> In = Split(cmd, ' ');
	if (In.size() != 0) {
		if (tolower(In.at(0)) == "cmds") {
			cout << "----------------------------------" << endl;
			cout << "          Server Commands         " << endl;
			cout << "----------------------------------" << endl;
			cout << "- ff [p] - Gives A Player A Forcefield" << endl;
			cout << "- kill [p] - Kills Player" << endl;
			cout << "- jp [p] - Sets Jump Power" << endl;
			cout << "- ws [p] - Sets Walkspeed" << endl;
			cout << "- smoke [p] - Spawns Smoke On Player" << endl;
			cout << "- btools [p] - Gives Player Building Tools" << endl;
			cout << "- god [p] - Makes Player Have Unlimited Health" << endl;
			cout << "- hipheight [p] - Sets Players Hip Height" << endl;
			cout << "- box [p] - Box's Player" << endl;
			cout << "- fire [p] - Spawns A Fire" << endl;
			cout << "- sit [p] - Makes A Player Sit" << endl;
			cout << "- rhat [p] - Removes The Players Hat" << endl;
			cout << "- fog [val] - Sets Fog" << endl;
			cout << "- rfog - Removes Fog" << endl;
			cout << "- gravity [val] - Sets Servers Gravity" << endl;
			cout << "- sp [p] - Sparkles" << endl;
			cout << "- bigfire [p] - Spawns A Bigfire" << endl;
			cout << "- char [p] [id] - Changes Character's Apperance" << endl;
			cout << "- time [val] - Changes Time" << endl;
			cout << "- noob [p] - Makes Player A Noob" << endl;
			cout << "- fchat [p] [red/blue/green] [msg] - Forces Player To Chat" << endl;
			cout << "- keemstar [p] - Turn Someone Into Keemstar" << endl;
			cout << "- illuminati [p] - Turn Someone Into The Illuminati" << endl;
			cout << "- duck [p] - Turn Someone Into Epic Duck" << endl;
			cout << "- mlg [p] - Turn Someone Into A Mountain Dew" << endl;
			cout << "- pussy [p] - Turn Someone Into A ...." << endl;
			cout << "- heaven [p] - Send A Player To Heaven" << endl;
			cout << "- ghost [p] - Makes A Player Semi-Visible" << endl;
			cout << "- statchange [p] [stat] [val] - Changes A Players Leaderboard Stats" << endl;
			cout << "----------------------------------" << endl;
			cout << "         Jailbreak Commands       " << endl;
			cout << "----------------------------------" << endl;
			cout << "- criminal - Teleport To The Criminal Base" << endl;
			cout << "- garage - Teleport To The Garage" << endl;
			cout << "- bank - Teleport To The Bank" << endl;
			cout << "- jewelry - Teleport To The Jewelry Store" << endl;
			cout << "- prison - Teleport Back To Prison" << endl;
			cout << "- nodoors - Removes All Doors" << endl;
			cout << "- banklazers - Removes All Bank Lazers" << endl;
			cout << "- jewelrylazers - Removes Jewelry Lazers" << endl;
			cout << "- jewelryflazers - Removes Jewelry Floor Lazers" << endl;
			cout << "- nocameras - Removes Jewelry Store Lazers" << endl;
			cout << "----------------------------------" << endl;
			cout << "            Misc Commands         " << endl;
			cout << "----------------------------------" << endl;
			cout << "- drivebloxmoney [p] - Driveblox Unlimited Money" << endl;
			cout << "----------------------------------" << endl;
			cout << "            Destruction           " << endl;
			cout << "----------------------------------" << endl;
			cout << "- unanchorall - Unanchors All" << endl;
			cout << "- clearws - Clears Workspace" << endl;
			cout << "----------------------------------" << endl;
			cout << "               Music              " << endl;
			cout << "----------------------------------" << endl;
			cout << "- rickroll - NEVER GONNA GIVE YOU UP" << endl;
			cout << "- ppap - Pineapple Pen" << endl;
			cout << "- billnye - BILL NYE DANK SCIENCE GUY" << endl;
			cout << "- illuminati - EAR RAPE FROM THE GODS" << endl;
			cout << "- rage - Kid Raging" << endl;
			cout << "- cringe - Pure Cringe From The Godss" << endl;
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "ff") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getglobal(luaState, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "ForceField");
				rlua_pushvalue(luaState, -4);
				rlua_call(luaState, 2, 0);;
			}
			else {
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getglobal(luaState, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "ForceField");
				rlua_pushvalue(luaState, -4);
				rlua_call(luaState, 2, 0);;
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "heaven") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getglobal(luaState, "game");
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Head");
				rlua_getglobal(luaState, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "BodyVelocity");
				rlua_pushvalue(luaState, -4);
				rlua_call(luaState, 2, 1);;

				rlua_getglobal(luaState, "game");
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Head");
				rlua_pushstring(luaState, "BodyVelocity");
				rlua_getfield(luaState, -1, "Destroy");
				rlua_pushvalue(luaState, -2);
				rlua_call(luaState, 1, 0);;
			}
			else {
				rlua_getglobal(luaState, "game");
				getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Head");
				rlua_getglobal(luaState, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "BodyVelocity");
				rlua_pushvalue(luaState, -4);
				rlua_call(luaState, 2, 1);;

				rlua_getglobal(luaState, "game");
				getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Head");
				rlua_pushstring(luaState, "BodyVelocity");
				rlua_getfield(luaState, -1, "Destroy");
				rlua_pushvalue(luaState, -2);
				rlua_call(luaState, 1, 0);;
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "ghost") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Head");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_call(luaState, 1, 0);;
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Head");
				rlua_getfield(luaState, -1, "face");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_call(luaState, 1, 0);;
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Torso");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_call(luaState, 1, 0);;
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Right Arm");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_call(luaState, 1, 0);;
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Left Arm");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_call(luaState, 1, 0);;
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Right Leg");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_call(luaState, 1, 0);;
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Left Leg");
				rlua_setfield(luaState, -2, "Transparency");
				rlua_call(luaState, 1, 0);;
				rlua_settop(luaState, 0);
			}
			else {
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Head");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_call(luaState, 1, 0);;
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Head");
				rlua_getfield(luaState, -1, "face");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_call(luaState, 1, 0);;
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Torso");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_call(luaState, 1, 0);;
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Right Arm");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_call(luaState, 1, 0);;
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Left Arm");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_call(luaState, 1, 0);;
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Right Leg");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_call(luaState, 1, 0);;
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Left Leg");
				rlua_setfield(luaState, -2, "Transparency");
				rlua_call(luaState, 1, 0);;
				rlua_settop(luaState, 0);
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "statchange") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "leaderstats");
				rlua_getfield(luaState, -1, In.at(2).c_str());
				rlua_pushnumber(luaState, atoi(In.at(3).c_str()));
				rlua_setfield(luaState, -2, "Value");
			}
			else {
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "leaderstats");
				rlua_getfield(luaState, -1, In.at(2).c_str());
				rlua_pushnumber(luaState, atoi(In.at(3).c_str()));
				rlua_setfield(luaState, -2, "Value");
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "keemstar") {

			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Torso");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "SpecialMesh");
			rlua_pushvalue(luaState, -4);
			rlua_call(luaState, 2, 1);;
			std::string MeshId = "rbxassetid://471652548";
			std::string TextureId = "rbxassetid://471652580";//

			rlua_pushstring(luaState, TextureId.c_str());
			rlua_setfield(luaState, -2, "TextureId");
			rlua_pushstring(luaState, MeshId.c_str());;
			rlua_setfield(luaState, -2, "MeshId");
			rlua_getglobal(luaState, "Vector3");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_call(luaState, 3, 1);;
			rlua_setfield(luaState, -3, "Scale");

			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Humanoid");
			rlua_pushstring(luaState, "20");
			rlua_setfield(luaState, -2, "HipHeight");

			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Left Leg");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Right Leg");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Left Arm");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (In.at(1) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Right Arm");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Head");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Humanoid");
			rlua_pushnumber(luaState, 50);
			rlua_setfield(luaState, -2, "WalkSpeed");
			std::string music = "433992205";
			rlua_getglobal(luaState, "workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_call(luaState, 2, 1);;

			rlua_pushstring(luaState, ("rbxassetid://" + music).c_str());
			rlua_setfield(luaState, -2, "SoundId");

			rlua_pushstring(luaState, "KEEMSTAR_AUDIO_ICE");
			rlua_setfield(luaState, -2, "Name");

			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Volume");

			rlua_getfield(luaState, -1, "Play");
			rlua_pushvalue(luaState, -2);
			rlua_call(luaState, 1, 0);;
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "illuminati") {

			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Torso");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "SpecialMesh");
			rlua_pushvalue(luaState, -4);
			rlua_call(luaState, 2, 1);;
			std::string MeshId = "rbxassetid://438530093";
			std::string TextureId = "rbxassetid://438530120";//

			rlua_pushstring(luaState, TextureId.c_str());
			rlua_setfield(luaState, -2, "TextureId");
			rlua_pushstring(luaState, MeshId.c_str());;
			rlua_setfield(luaState, -2, "MeshId");
			rlua_getglobal(luaState, "Vector3");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_call(luaState, 3, 1);;
			rlua_setfield(luaState, -3, "Scale");

			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Humanoid");
			rlua_pushstring(luaState, "20");
			rlua_setfield(luaState, -2, "HipHeight");

			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Left Leg");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Right Leg");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Left Arm");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (In.at(1) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Right Arm");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Head");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Humanoid");
			rlua_pushnumber(luaState, 50);
			rlua_setfield(luaState, -2, "WalkSpeed");
			std::string music = "433992205";
			rlua_getglobal(luaState, "workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_call(luaState, 2, 1);;

			rlua_pushstring(luaState, ("rbxassetid://" + music).c_str());
			rlua_setfield(luaState, -2, "SoundId");
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "duck") {

			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Torso");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "SpecialMesh");
			rlua_pushvalue(luaState, -4);
			rlua_call(luaState, 2, 1);;
			std::string MeshId = "rbxassetid://521754610";
			std::string TextureId = "rbxassetid://521754612";

			rlua_pushstring(luaState, TextureId.c_str());
			rlua_setfield(luaState, -2, "TextureId");
			rlua_pushstring(luaState, MeshId.c_str());;
			rlua_setfield(luaState, -2, "MeshId");
			rlua_getglobal(luaState, "Vector3");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_call(luaState, 3, 1);;
			rlua_setfield(luaState, -3, "Scale");

			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Humanoid");
			rlua_pushstring(luaState, "0");
			rlua_setfield(luaState, -2, "HipHeight");

			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Left Leg");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Right Leg");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Left Arm");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (In.at(1) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Right Arm");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Head");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Humanoid");
			rlua_pushnumber(luaState, 20);
			rlua_setfield(luaState, -2, "WalkSpeed");
			std::string music = "";
			rlua_getglobal(luaState, "workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_call(luaState, 2, 1);;

			rlua_pushstring(luaState, ("rbxassetid://" + music).c_str());
			rlua_setfield(luaState, -2, "SoundId");
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "mlg") {

			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Torso");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "SpecialMesh");
			rlua_pushvalue(luaState, -4);
			rlua_call(luaState, 2, 1);;
			std::string MeshId = "rbxassetid://430452142";
			std::string TextureId = "rbxassetid://430452215";

			rlua_pushstring(luaState, TextureId.c_str());
			rlua_setfield(luaState, -2, "TextureId");
			rlua_pushstring(luaState, MeshId.c_str());;
			rlua_setfield(luaState, -2, "MeshId");
			rlua_getglobal(luaState, "Vector3");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_call(luaState, 3, 1);;
			rlua_setfield(luaState, -3, "Scale");

			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Humanoid");
			rlua_pushstring(luaState, "17");
			rlua_setfield(luaState, -2, "HipHeight");

			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Left Leg");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Right Leg");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Left Arm");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (In.at(1) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Right Arm");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Head");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Humanoid");
			rlua_pushnumber(luaState, 50);
			rlua_setfield(luaState, -2, "WalkSpeed");
			std::string music = "";
			rlua_getglobal(luaState, "workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_call(luaState, 2, 1);;

			rlua_pushstring(luaState, ("rbxassetid://" + music).c_str());
			rlua_setfield(luaState, -2, "SoundId");
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "pussy") {

			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Torso");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "SpecialMesh");
			rlua_pushvalue(luaState, -4);
			rlua_call(luaState, 2, 1);;
			std::string MeshId = "rbxassetid://477053700";
			std::string TextureId = "rbxassetid://477053711";

			rlua_pushstring(luaState, TextureId.c_str());
			rlua_setfield(luaState, -2, "TextureId");
			rlua_pushstring(luaState, MeshId.c_str());;
			rlua_setfield(luaState, -2, "MeshId");
			rlua_getglobal(luaState, "Vector3");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_call(luaState, 3, 1);;
			rlua_setfield(luaState, -3, "Scale");

			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Humanoid");
			rlua_pushstring(luaState, "17");
			rlua_setfield(luaState, -2, "HipHeight");

			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Left Leg");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Right Leg");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Left Arm");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (In.at(1) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Right Arm");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Head");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Transparency");
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				rlua_getfield(luaState, -1, "LocalPlayer");
			}
			else {
				rlua_getfield(luaState, -1, In.at(1).c_str());
			}
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "Humanoid");
			rlua_pushnumber(luaState, 50);
			rlua_setfield(luaState, -2, "WalkSpeed");
			std::string music = "";
			rlua_getglobal(luaState, "workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_call(luaState, 2, 1);;

			rlua_pushstring(luaState, ("rbxassetid://" + music).c_str());
			rlua_setfield(luaState, -2, "SoundId");
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "fog") {
			rlua_getglobal(luaState, "Game");
			rlua_getfield(luaState, -1, "GetService");
			rlua_pushvalue(luaState, -2);
			rlua_pushstring(luaState, "Lighting");
			rlua_call(luaState, 2, 1);;
			rlua_pushnumber(luaState, stof(In.at(1).c_str()));
			rlua_setfield(luaState, -2, "FogEnd");
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "rfog") {
			rlua_getglobal(luaState, "Game");
			rlua_getfield(luaState, -1, "GetService");
			rlua_pushvalue(luaState, -2);
			rlua_pushstring(luaState, "Lighting");
			rlua_call(luaState, 2, 1);;
			rlua_pushnumber(luaState, 1000000);
			rlua_setfield(luaState, -2, "FogEnd");
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "rhat") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Head");

				rlua_getfield(luaState, LUA_GLOBALSINDEX, "Vector3");
				rlua_getfield(luaState, -1, "new");
				rlua_pushnumber(luaState, 1);
				rlua_pushnumber(luaState, 1);
				rlua_pushnumber(luaState, 1);
				rlua_pushnumber(luaState, 1);
				rlua_pushnumber(luaState, 1);
				rlua_pushnumber(luaState, 1);
				rlua_call(luaState, 6, 1);;
				rlua_setfield(luaState, -3, "Size");
			}
			else {
				getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Head");

				rlua_getfield(luaState, LUA_GLOBALSINDEX, "Vector3");
				rlua_getfield(luaState, -1, "new");
				rlua_pushnumber(luaState, 1);
				rlua_pushnumber(luaState, 1);
				rlua_pushnumber(luaState, 1);
				rlua_pushnumber(luaState, 1);
				rlua_pushnumber(luaState, 1);
				rlua_pushnumber(luaState, 1);
				rlua_call(luaState, 6, 1);;
				rlua_setfield(luaState, -3, "Size");
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "ws") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushnumber(luaState, stof(In.at(2).c_str()));
				rlua_setfield(luaState, -2, "WalkSpeed");
			}
			else {
				getService("Players");
				rlua_getfield(luaState, -1, "FindFirstChild");
				rlua_pushvalue(luaState, -2);
				rlua_pushstring(luaState, In.at(1).c_str());
				rlua_call(luaState, 2, 1);;
				if (!rlua_isnil(luaState, -1)) {
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, -1, "Humanoid");
					rlua_pushnumber(luaState, stof(In.at(2).c_str()));
					rlua_setfield(luaState, -2, "WalkSpeed");
				}
				else
					cout << "?> Unable to find player: " << In.at(1) << "\n";
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "sit") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushnumber(luaState, 1);
				rlua_setfield(luaState, -2, "Sit");
			}
			else {
				getService("Players");
				rlua_getfield(luaState, -1, "FindFirstChild");
				rlua_pushvalue(luaState, -2);
				rlua_pushstring(luaState, In.at(1).c_str());
				rlua_call(luaState, 2, 1);;
				if (!rlua_isnil(luaState, -1)) {
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, -1, "Humanoid");
					rlua_pushnumber(luaState, 1);
					rlua_setfield(luaState, -2, "Sit");
				}
				else
					cout << "?> Unable to find player: " << In.at(1) << "\n";
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "hipheight") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushnumber(luaState, stof(In.at(2).c_str()));
				rlua_setfield(luaState, -2, "HipHeight");
			}
			else {
				getService("Players");
				rlua_getfield(luaState, -1, "FindFirstChild");
				rlua_pushvalue(luaState, -2);
				rlua_pushstring(luaState, In.at(1).c_str());
				rlua_call(luaState, 2, 1);;
				if (!rlua_isnil(luaState, -1)) {
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, -1, "Humanoid");
					rlua_pushnumber(luaState, stof(In.at(2).c_str()));
					rlua_setfield(luaState, -2, "HipHeight");
				}
				else
					cout << "?> Unable to find player: " << In.at(1) << "\n";
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "jp") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushnumber(luaState, stof(In.at(2).c_str()));
				rlua_setfield(luaState, -2, "JumpPower");
			}
			else {
				getService("Players");
				rlua_getfield(luaState, -1, "FindFirstChild");
				rlua_pushvalue(luaState, -2);
				rlua_pushstring(luaState, In.at(1).c_str());
				rlua_call(luaState, 2, 1);;
				if (!rlua_isnil(luaState, -1)) {
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, -1, "Humanoid");
					rlua_pushnumber(luaState, stof(In.at(2).c_str()));
					rlua_setfield(luaState, -2, "JumpPower");
				}
				else
					cout << "?> Unable to find player: " << In.at(1) << "\n";
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "kill") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushstring(luaState, "0");
				rlua_setfield(luaState, -2, "Health");
			}
			else {
				getService("Players");
				rlua_getfield(luaState, -1, "FindFirstChild");
				rlua_pushvalue(luaState, -2);
				rlua_pushstring(luaState, In.at(1).c_str());
				rlua_call(luaState, 2, 1);;
				if (!rlua_isnil(luaState, -1)) {
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, -1, "Humanoid");
					rlua_pushstring(luaState, "0");
					rlua_setfield(luaState, -2, "Health");
				}
				else
					cout << "?> Unable to find player: " << In.at(1) << "\n";
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "drivebloxmoney") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Playerdata");
				rlua_getfield(luaState, -1, "Money");
				rlua_pushnumber(luaState, 999999999);
				rlua_setfield(luaState, -2, "Value");
			}
			else {
				getService("Players");
				rlua_getfield(luaState, -1, "FindFirstChild");
				rlua_pushvalue(luaState, -2);
				rlua_pushstring(luaState, In.at(1).c_str());
				rlua_call(luaState, 2, 1);;
				if (!rlua_isnil(luaState, -1)) {
					rlua_getfield(luaState, -1, "Playerdata");
					rlua_getfield(luaState, -1, "Money");
					rlua_pushnumber(luaState, 999999999);
					rlua_setfield(luaState, -2, "Value");
				}
				else
					cout << "?> Unable to find player: " << In.at(1) << "\n";
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "gravity") {
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Workspace");
			rlua_pushnumber(luaState, stof(In.at(1).c_str()));
			rlua_setfield(luaState, -2, "Gravity");
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "btools") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				for (int i = 1; i <= 4; i++) {
					getService("Players");
					rlua_getfield(luaState, -1, "LocalPlayer");
					rlua_getfield(luaState, -1, "Backpack");
					rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
					rlua_getfield(luaState, -1, "new");
					rlua_pushstring(luaState, "HopperBin");
					rlua_pushvalue(luaState, -4);
					rlua_call(luaState, 2, 1);;

					rlua_pushnumber(luaState, i);
					rlua_setfield(luaState, -2, "Name");
					rlua_pushnumber(luaState, i);
					rlua_setfield(luaState, -2, "BinType");
				}
				cout << ">-> ";
			}
			else {
				for (int i = 1; i <= 4; i++) {
					getService("Players");
					rlua_getfield(luaState, -1, "FindFirstChild");
					rlua_pushvalue(luaState, -2);
					rlua_pushstring(luaState, In.at(1).c_str());
					rlua_call(luaState, 2, 1);;
					if (!rlua_isnil(luaState, -1)) {
						rlua_getfield(luaState, -1, "Backpack");
						rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
						rlua_getfield(luaState, -1, "new");
						rlua_pushstring(luaState, "HopperBin");
						rlua_pushvalue(luaState, -4);
						rlua_call(luaState, 2, 1);;

						rlua_pushnumber(luaState, i);
						rlua_setfield(luaState, -2, "Name");
						rlua_pushnumber(luaState, i);
						rlua_setfield(luaState, -2, "BinType");
					}
					else
						cout << "?> Unable to find player: " << In.at(1) << "\n";
				}
				cout << ">-> ";
			}
		}


		if (tolower(In.at(0)) == "god") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushnumber(luaState, HUGE_VAL);
				rlua_setfield(luaState, -2, "MaxHealth");
			}
			else {
				getService("Players");
				rlua_getfield(luaState, -1, "FindFirstChild");
				rlua_pushvalue(luaState, -2);
				rlua_pushstring(luaState, In.at(1).c_str());
				rlua_call(luaState, 2, 1);;
				if (!rlua_isnil(luaState, -1)) {
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, -1, "Humanoid");
					rlua_pushnumber(luaState, HUGE_VAL);
					rlua_setfield(luaState, -2, "MaxHealth");
				}
				else
					cout << "?> Unable to find player: " << In.at(1) << "\n";
			}
			cout << ">-> ";
		}
		if (tolower(In.at(0)) == "bigfire" || tolower(In.at(0)) == "bodyfire") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Torso");
				rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "Fire");
				rlua_pushvalue(luaState, -4);
				rlua_call(luaState, 2, 1);;
				if (!rlua_isnil(luaState, -1)) {
					rlua_pushstring(luaState, "29");
					rlua_setfield(luaState, -2, "Size");
				}
			}
			else {
				getService("Players");
				rlua_getfield(luaState, -1, "FindFirstChild");
				rlua_pushvalue(luaState, -2);
				rlua_pushstring(luaState, In.at(1).c_str());
				rlua_call(luaState, 2, 1);;
				if (!rlua_isnil(luaState, -1)) {
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, -1, "Torso");
					rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
					rlua_getfield(luaState, -1, "new");
					rlua_pushstring(luaState, "Fire");
					rlua_pushvalue(luaState, -4);
					rlua_call(luaState, 2, 1);;
					if (!rlua_isnil(luaState, -1)) {
						rlua_pushstring(luaState, "29");
						rlua_setfield(luaState, -2, "Size");
					}
				}
				else
					cout << "?> Unable to find player: " << In.at(1) << "\n";
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "time") {
			if (In.size() > 2)
				cout << "?> The command `time` doesn't support more than 1 argument!\n";
			else {
				getService("Lighting");
				if (!rlua_isnil(luaState, -1)) {
					rlua_pushnumber(luaState, atoi(In.at(1).c_str()));
					rlua_setfield(luaState, -2, "TimeOfDay");
				}
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "select" || tolower(In.at(0)) == "box") {
			if (tolower(In.at(1)) == "me") {
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "SelectionBox");
				rlua_pushvalue(luaState, -4);
				rlua_call(luaState, 2, 1);;

				rlua_pushvalue(luaState, -3);
				rlua_setfield(luaState, -2, "Adornee");

			}
			else {
				getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				if (!rlua_isnil(luaState, -1)) {
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
					rlua_getfield(luaState, -1, "new");
					rlua_pushstring(luaState, "SelectionBox");
					rlua_pushvalue(luaState, -4);
					rlua_call(luaState, 2, 1);;

					rlua_pushvalue(luaState, -3);
					rlua_setfield(luaState, -2, "Adornee");
				}
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "fencingr" || tolower(In.at(0)) == "freach") {
			getService("Players");
			rlua_getfield(luaState, -1, "LocalPlayer");
			rlua_getfield(luaState, -1, "Backpack");
			rlua_getfield(luaState, -1, "Foil");
			rlua_getfield(luaState, -1, "Handle");

			rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "SelectionBox");
			rlua_pushvalue(luaState, -4);
			rlua_call(luaState, 2, 1);;

			rlua_pushvalue(luaState, -3);
			rlua_setfield(luaState, -2, "Adornee");

			getService("Players");
			rlua_getfield(luaState, -1, "LocalPlayer");
			rlua_getfield(luaState, -1, "Backpack");
			rlua_getfield(luaState, -1, "Foil");
			rlua_getfield(luaState, -1, "Handle");

			getService("Players");
			rlua_getfield(luaState, -1, "LocalPlayer");
			rlua_getfield(luaState, -1, "Backpack");
			rlua_getfield(luaState, -1, "Foil");
			rlua_getfield(luaState, -1, "Handle");

			rlua_getfield(luaState, LUA_GLOBALSINDEX, "Vector3");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "1");
			rlua_pushstring(luaState, "1");
			rlua_pushstring(luaState, "30");
			rlua_call(luaState, 3, 1);;
			rlua_setfield(luaState, -7, "Size");
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "forcechat" || tolower(In.at(0)) == "fchat") {
			if (tolower(In.at(1)) == "me") {
				if (tolower(In.at(2)) == "green") {
					std::string string;
					for (size_t i = 3; i < In.size(); i++) {
						if (i < (In.size() - 1)) {
							string.append(In.at(i) + ' ');
						}
						if (i == (In.size() - 1)) {
							string.append(In.at(i));
						}
					}
					getService("Players");
					rlua_getfield(luaState, -1, "LocalPlayer");
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, -1, "Head");

					rlua_getfield(luaState, LUA_GLOBALSINDEX, "game");
					rlua_getfield(luaState, -1, "Chat");
					rlua_getfield(luaState, -1, "Chat");
					rlua_pushvalue(luaState, -2);
					rlua_pushvalue(luaState, -5);
					rlua_pushstring(luaState, string.c_str());
					rlua_pushstring(luaState, "Green");
					rlua_call(luaState, 4, 1);;

				}
				if (tolower(In.at(2)) == "red") {
					std::string string;
					for (size_t i = 3; i < In.size(); i++) {
						if (i < (In.size() - 1)) {
							string.append(In.at(i) + ' ');
						}
						if (i == (In.size() - 1)) {
							string.append(In.at(i));
						}
					}
					getService("Players");
					rlua_getfield(luaState, -1, "LocalPlayer");
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, -1, "Head");

					rlua_getfield(luaState, LUA_GLOBALSINDEX, "game");
					rlua_getfield(luaState, -1, "Chat");
					rlua_getfield(luaState, -1, "Chat");
					rlua_pushvalue(luaState, -2);
					rlua_pushvalue(luaState, -5);
					rlua_pushstring(luaState, string.c_str());
					rlua_pushstring(luaState, "Red");
					rlua_call(luaState, 4, 1);;
				}
				if (tolower(In.at(2)) == "blue") {
					std::string string;
					for (size_t i = 3; i < In.size(); i++) {
						if (i < (In.size() - 1)) {
							string.append(In.at(i) + ' ');
						}
						if (i == (In.size() - 1)) {
							string.append(In.at(i));
						}
					}
					getService("Players");
					rlua_getfield(luaState, -1, "LocalPlayer");
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, -1, "Head");

					rlua_getfield(luaState, LUA_GLOBALSINDEX, "game");
					rlua_getfield(luaState, -1, "Chat");
					rlua_getfield(luaState, -1, "Chat");
					rlua_pushvalue(luaState, -2);
					rlua_pushvalue(luaState, -5);
					rlua_pushstring(luaState, string.c_str());
					rlua_pushstring(luaState, "Blue");
					rlua_call(luaState, 4, 1);;
				}
			}
			else {
				if (tolower(In.at(2)) == "green") {
					std::string string;
					for (size_t i = 3; i < In.size(); i++) {
						if (i < (In.size() - 1)) {
							string.append(In.at(i) + ' ');
						}
						if (i == (In.size() - 1)) {
							string.append(In.at(i));
						}
					}
					getService("Players");
					rlua_getfield(luaState, -1, In.at(1).c_str());
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, -1, "Head");

					rlua_getfield(luaState, LUA_GLOBALSINDEX, "game");
					rlua_getfield(luaState, -1, "Chat");
					rlua_getfield(luaState, -1, "Chat");
					rlua_pushvalue(luaState, -2);
					rlua_pushvalue(luaState, -5);
					rlua_pushstring(luaState, string.c_str());
					rlua_pushstring(luaState, "Green");
					rlua_call(luaState, 4, 1);;
				}
				if (tolower(In.at(2)) == "red") {
					std::string string;
					for (size_t i = 3; i < In.size(); i++) {
						if (i < (In.size() - 1)) {
							string.append(In.at(i) + ' ');
						}
						if (i == (In.size() - 1)) {
							string.append(In.at(i));
						}
					}
					getService("Players");
					rlua_getfield(luaState, -1, In.at(1).c_str());
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, -1, "Head");

					rlua_getfield(luaState, LUA_GLOBALSINDEX, "game");
					rlua_getfield(luaState, -1, "Chat");
					rlua_getfield(luaState, -1, "Chat");
					rlua_pushvalue(luaState, -2);
					rlua_pushvalue(luaState, -5);
					rlua_pushstring(luaState, string.c_str());
					rlua_pushstring(luaState, "Red");
					rlua_call(luaState, 4, 1);;
				}
				if (tolower(In.at(2)) == "blue") {
					std::string string;
					for (size_t i = 3; i < In.size(); i++) {
						if (i < (In.size() - 1)) {
							string.append(In.at(i) + ' ');
						}
						if (i == (In.size() - 1)) {
							string.append(In.at(i));
						}
					}
					getService("Players");
					rlua_getfield(luaState, -1, In.at(1).c_str());
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, -1, "Head");

					rlua_getfield(luaState, LUA_GLOBALSINDEX, "game");
					rlua_getfield(luaState, -1, "Chat");
					rlua_getfield(luaState, -1, "Chat");
					rlua_pushvalue(luaState, -2);
					rlua_pushvalue(luaState, -5);
					rlua_pushstring(luaState, string.c_str());
					rlua_pushstring(luaState, "Blue");
					rlua_call(luaState, 4, 1);;
				}
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "charapp" || tolower(In.at(0)) == "char") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				if (!rlua_isnil(luaState, -1)) {
					std::string InitialID = "http://www.roblox.com/Asset/CharacterFetch.ashx?userId=" + In.at(2);
					rlua_pushstring(luaState, InitialID.c_str());
					rlua_setfield(luaState, -2, "CharacterAppearance");
				}

			}
			else {
				getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				if (!rlua_isnil(luaState, -1)) {
					std::string InitialID = "http://www.roblox.com/Asset/CharacterFetch.ashx?userId=" + In.at(2);
					rlua_pushstring(luaState, InitialID.c_str());
					rlua_setfield(luaState, -2, "CharacterAppearance");
				}
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "noob") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				if (!rlua_isnil(luaState, -1)) {
					std::string InitialID = "http://www.roblox.com/Asset/CharacterFetch.ashx?userId=5";
					rlua_pushstring(luaState, InitialID.c_str());
					rlua_setfield(luaState, -2, "CharacterAppearance");

				}
			}
			else {
				getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				if (!rlua_isnil(luaState, -1)) {
					std::string InitialID = "http://www.roblox.com/Asset/CharacterFetch.ashx?userId=5";
					rlua_pushstring(luaState, InitialID.c_str());
					rlua_setfield(luaState, -2, "CharacterAppearance");

				}
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "fire") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Torso");
				rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "Fire");
				rlua_pushvalue(luaState, -4);
				rlua_call(luaState, 2, 1);;
			}
			else {
				getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				if (!rlua_isnil(luaState, -1)) {
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, -1, "Torso");
					rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
					rlua_getfield(luaState, -1, "new");
					rlua_pushstring(luaState, "Fire");
					rlua_pushvalue(luaState, -4);
					rlua_call(luaState, 2, 1);;
				}
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "smoke") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Torso");
				rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "Smoke");
				rlua_pushvalue(luaState, -4);
				rlua_call(luaState, 2, 1);;
			}
			else {
				getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				if (!rlua_isnil(luaState, -1)) {
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, -1, "Torso");
					rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
					rlua_getfield(luaState, -1, "new");
					rlua_pushstring(luaState, "Smoke");
					rlua_pushvalue(luaState, -4);
					rlua_call(luaState, 2, 1);;
				}
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "sethealth" || tolower(In.at(0)) == "shealth") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				if (!rlua_isnil(luaState, -1)) {
					rlua_getfield(luaState, -1, "Character");
					rlua_pushnumber(luaState, atoi(In.at(2).c_str()));
					rlua_setfield(luaState, -2, "MaxHealth");
				}
			}
			else {
				getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				if (!rlua_isnil(luaState, -1)) {
					rlua_getfield(luaState, -1, "Character");
					rlua_pushnumber(luaState, atoi(In.at(2).c_str()));
					rlua_setfield(luaState, -2, "MaxHealth");
				}
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "addhealth") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_getfield(luaState, -1, "MaxHealth");
				const char* MaxHealthVal = rlua_tostring(luaState, -1);
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushstring(luaState, (const char*)MaxHealthVal + atoi(In.at(2).c_str()));
				rlua_setfield(luaState, -2, "MaxHealth");
			}
			else {
				getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_getfield(luaState, -1, "MaxHealth");
				const char* MaxHealthVal = rlua_tostring(luaState, -1);
				getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushstring(luaState, (const char*)MaxHealthVal + atoi(In.at(2).c_str()));
				rlua_setfield(luaState, -2, "MaxHealth");
			}
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "sparkles" || tolower(In.at(0)) == "sp") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Torso");
				if (!rlua_isnil(luaState, -1)) {
					rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
					rlua_getfield(luaState, -1, "new");
					rlua_pushstring(luaState, "Sparkles");
					rlua_pushvalue(luaState, -4);
					rlua_call(luaState, 2, 1);;

					rlua_pushstring(luaState, "Ice Sparkles");
					rlua_setfield(luaState, -2, "Name");
				}
				else {
					getService("Players");
					rlua_getfield(luaState, -1, "LocalPlayer");
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, -1, "UpperTorso");
					if (!rlua_isnil(luaState, -1)) {
						rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
						rlua_getfield(luaState, -1, "new");
						rlua_pushstring(luaState, "Sparkles");
						rlua_pushvalue(luaState, -4);
						rlua_call(luaState, 2, 1);;

						rlua_pushstring(luaState, "Ice Sparkles");
						rlua_setfield(luaState, -2, "Name");
					}
				}
			}
			else {
				getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				if (!rlua_isnil(luaState, -1)) {
					rlua_getfield(luaState, -1, "Character");
					rlua_getfield(luaState, -1, "Torso");
					rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
					rlua_getfield(luaState, -1, "new");
					rlua_pushstring(luaState, "Sparkles");
					rlua_pushvalue(luaState, -4);
					rlua_call(luaState, 2, 1);;

					rlua_pushstring(luaState, "Ice Sparkles");
					rlua_setfield(luaState, -2, "Name");
				}
			}
			cout << ">-> ";
		}


		/*
		JAILBREAK COMMANDS
		*/

		if (tolower(In.at(0)) == "criminal") {
			getService("Players");
			rlua_getfield(luaState, -1, "LocalPlayer");
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "HumanoidRootPart");
			rlua_getglobal(luaState, "CFrame");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, -222.339157);
			rlua_pushnumber(luaState, 17.9125443);
			rlua_pushnumber(luaState, 1575.82336);
			rlua_call(luaState, 3, 1);;
			rlua_setfield(luaState, -3, "CFrame");
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "garage") {
			getService("Players");
			rlua_getfield(luaState, -1, "LocalPlayer");
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "HumanoidRootPart");
			rlua_getglobal(luaState, "CFrame");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, -342.130798);
			rlua_pushnumber(luaState, 19.3135223);
			rlua_pushnumber(luaState, 1182.73669);
			rlua_call(luaState, 3, 1);;
			rlua_setfield(luaState, -3, "CFrame");
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "bank") {
			getService("Players");
			rlua_getfield(luaState, -1, "LocalPlayer");
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "HumanoidRootPart");
			rlua_getglobal(luaState, "CFrame");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, 1.1110189);
			rlua_pushnumber(luaState, 17.9213142);
			rlua_pushnumber(luaState, 782.103455);
			rlua_call(luaState, 3, 1);;
			rlua_setfield(luaState, -3, "CFrame");
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "prison") {
			getService("Players");
			rlua_getfield(luaState, -1, "LocalPlayer");
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "HumanoidRootPart");
			rlua_getglobal(luaState, "CFrame");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, -1100.4469);
			rlua_pushnumber(luaState, 17.7500038);
			rlua_pushnumber(luaState, -1493.18286);
			rlua_call(luaState, 3, 1);;
			rlua_setfield(luaState, -3, "CFrame");
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "nodoors") {
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Workspace");
			rlua_getfield(luaState, -1, "Doors");
			rlua_getfield(luaState, -1, "Destroy");
			rlua_pushvalue(luaState, -2);
			rlua_call(luaState, 1, 0);;
			cout << ">-> ";
		}

		if (tolower(In.at(0)) == "banklazers") {
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Workspace");
			rlua_getfield(luaState, -1, "Banks");
			rlua_getfield(luaState, -1, "Bank");
			rlua_getfield(luaState, -1, "Lasers");
			rlua_getfield(luaState, -1, "Destroy");
			rlua_pushvalue(luaState, -2);
			rlua_call(luaState, 1, 0);;
			cout << ">-> ";
		}

		if (tolower(In.at(0)) == "jewelrycameras") {
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Workspace");
			rlua_getfield(luaState, -1, "Jewelrys");
			rlua_getfield(luaState, -1, "Jewelry");
			rlua_getfield(luaState, -1, "Cameras");
			rlua_getfield(luaState, -1, "Destroy");
			rlua_pushvalue(luaState, -2);
			rlua_call(luaState, 1, 0);;
			cout << ">-> ";
		}

		if (tolower(In.at(0)) == "jewelrylazers") {
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Workspace");
			rlua_getfield(luaState, -1, "Jewelrys");
			rlua_getfield(luaState, -1, "Jewelry");
			rlua_getfield(luaState, -1, "Lasers");
			rlua_getfield(luaState, -1, "Destroy");
			rlua_pushvalue(luaState, -2);
			rlua_call(luaState, 1, 0);;
			cout << ">-> ";
		}

		if (tolower(In.at(0)) == "jewelryflazers") {
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Workspace");
			rlua_getfield(luaState, -1, "Jewelrys");
			rlua_getfield(luaState, -1, "Jewelry");
			rlua_getfield(luaState, -1, "FloorLasers");
			rlua_getfield(luaState, -1, "Destroy");
			rlua_pushvalue(luaState, -2);
			rlua_call(luaState, 1, 0);;
			cout << ">-> ";
		}

		if (tolower(In.at(0)) == "jewelry") {
			getService("Players");
			rlua_getfield(luaState, -1, "LocalPlayer");
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "HumanoidRootPart");
			rlua_getglobal(luaState, "CFrame");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, 124);
			rlua_pushnumber(luaState, 17);
			rlua_pushnumber(luaState, 1317);
			rlua_call(luaState, 3, 1);;
			rlua_setfield(luaState, -3, "CFrame");
			cout << ">-> ";
		}


		/*
		MUSIC COMMANDS
		*/


		if (tolower(In.at(0)) == "rickroll") {
			rlua_getglobal(luaState, "Workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_call(luaState, 2, 0);;

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "Sound");
			rlua_pushstring(luaState, "LuaC_Music");
			rlua_setfield(luaState, -2, "Name");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Volume");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_pushstring(luaState, "rbxassetid://151758509");
			rlua_setfield(luaState, -2, "SoundId");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_getfield(luaState, -1, "Play");
			rlua_pushvalue(luaState, -2);
			rlua_call(luaState, 1, 0);;
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "ppap") {
			rlua_getglobal(luaState, "Workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_call(luaState, 2, 0);;

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "Sound");
			rlua_pushstring(luaState, "LuaC_Music");
			rlua_setfield(luaState, -2, "Name");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Volume");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_pushstring(luaState, "rbxassetid://514558366");
			rlua_setfield(luaState, -2, "SoundId");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_getfield(luaState, -1, "Play");
			rlua_pushvalue(luaState, -2);
			rlua_call(luaState, 1, 0);;
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "billnye") {
			rlua_getglobal(luaState, "Workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_call(luaState, 2, 0);;

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "Sound");
			rlua_pushstring(luaState, "LuaC_Music");
			rlua_setfield(luaState, -2, "Name");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Volume");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_pushstring(luaState, "rbxassetid://318733059");
			rlua_setfield(luaState, -2, "SoundId");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_getfield(luaState, -1, "Play");
			rlua_pushvalue(luaState, -2);
			rlua_call(luaState, 1, 0);;
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "illuminati") {
			rlua_getglobal(luaState, "Workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_call(luaState, 2, 0);;

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "Sound");
			rlua_pushstring(luaState, "LuaC_Music");
			rlua_setfield(luaState, -2, "Name");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Volume");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_pushstring(luaState, "rbxassetid://271908621");
			rlua_setfield(luaState, -2, "SoundId");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_getfield(luaState, -1, "Play");
			rlua_pushvalue(luaState, -2);
			rlua_call(luaState, 1, 0);;
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "rage") {
			rlua_getglobal(luaState, "Workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_call(luaState, 2, 0);;

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "Sound");
			rlua_pushstring(luaState, "LuaC_Music");
			rlua_setfield(luaState, -2, "Name");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Volume");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_pushstring(luaState, "rbxassetid://382795033");
			rlua_setfield(luaState, -2, "SoundId");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_getfield(luaState, -1, "Play");
			rlua_pushvalue(luaState, -2);
			rlua_call(luaState, 1, 0);;
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "cringe") {
			rlua_getglobal(luaState, "Workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_call(luaState, 2, 0);;

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "Sound");
			rlua_pushstring(luaState, "LuaC_Music");
			rlua_setfield(luaState, -2, "Name");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Volume");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_pushstring(luaState, "rbxassetid://555159200");
			rlua_setfield(luaState, -2, "SoundId");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_getfield(luaState, -1, "Play");
			rlua_pushvalue(luaState, -2);
			rlua_call(luaState, 1, 0);;
			cout << ">-> ";
		}


		/*
		DESTRUCTION COMMANDS
		*/


		if (tolower(In.at(0)) == "clearws") {
			getService("Workspace");
			rlua_getfield(luaState, -1, "ClearAllChildren");
			rlua_pushvalue(luaState, -2);
			rlua_call(luaState, 1, 0);;
		}


		if (tolower(In.at(0)) == "unanchorall") {
			getService("Workspace");
			rlua_getfield(luaState, -1, "GetChildren");
			rlua_pushvalue(luaState, -2);
			rlua_call(luaState, 1, 1);;
			rlua_pushnil(luaState);
			while (rlua_next(luaState, -2) != 0) {
				rlua_getfield(luaState, -1, "ClassName");
				if (rlua_tostring(luaState, -1) == "Part" || rlua_tostring(luaState, -1) == "SpawnLocation" || rlua_tostring(luaState, -1) == "Seat") {
					rlua_pushvalue(luaState, false);
					rlua_setfield(luaState, -2, "Anchored");
				}
				else if (rlua_tostring(luaState, -1) == "Model") {
					rlua_getfield(luaState, -1, "GetChildren");
					rlua_pushvalue(luaState, -2);
					rlua_call(luaState, 1, 1);;
					rlua_pushnil(luaState);
					while (rlua_next(luaState, -2) != 0) {
						rlua_getfield(luaState, -1, "ClassName");
						if (rlua_tostring(luaState, -1) == "Part" || rlua_tostring(luaState, -1) == "SpawnLocation" || rlua_tostring(luaState, -1) == "Seat") {
							rlua_pushvalue(luaState, false);
							rlua_setfield(luaState, -2, "Anchored");
						}
					}
				}
			}
		}
		rlua_settop(luaState, 0);
	}
	else
	{
		return;
	}
}

std::vector<std::string> LuaCSplit(std::string s)
{
	std::vector<std::string> elems;
	std::stringstream ss(s);
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	std::vector<std::string> vstrings(begin, end);
	return vstrings;
}

void luaC(std::string input) {
	try {
		std::vector<std::string> In = LuaCSplit(input);

		if (In.at(0) == "getfield") {
			std::string field;
			for (size_t i = 2; i < In.size(); i++) {
				if (i < (In.size() - 1)) {
					field.append(In.at(i) + ' ');
				}
				if (i == (In.size() - 1)) {
					field.append(In.at(i));
				}
			}
			rlua_getfield(luaState, stoi(In.at(1)), field.c_str());
		}

		else if (In.at(0) == "getglobal") {
			rlua_getglobal(luaState, In.at(1).c_str());
		}

		else if (In.at(0) == "setfield") {
			rlua_setfield(luaState, stoi(In.at(1)), In.at(2).c_str());
		}

		else if (In.at(0) == "pushvalue") {
			rlua_pushvalue(luaState, stoi(In.at(1)));
		}

		else if (In.at(0) == "pushstring") {
			std::string string;
			for (size_t i = 1; i < In.size(); i++) {
				if (i < (In.size() - 1)) {
					string.append(In.at(i) + ' ');
				}
				if (i == (In.size() - 1)) {
					string.append(In.at(i));
				}
			}
			rlua_pushstring(luaState, string.c_str());
		}

		else if (In.at(0) == "pushnumber") {
			rlua_pushnumber(luaState, stoi(In.at(1)));
		}

		else if (In.at(0) == "pcall") {//this will be still pcall so you don't need to edit the lua c script
			rlua_call(luaState, stoi(In.at(1)), stoi(In.at(2)));
		}

		else if (In.at(0) == "emptystack") {
			rlua_settop(luaState, 0);
		}

		else if (In.at(0) == "settop") {
			rlua_settop(luaState, stoi(In.at(1)));
		}

		else if (In.at(0) == "getService") {
			getService(In.at(1).c_str());
		}

		else if (In.at(0) == "pushboolean") {
			if (In.at(1) == "false") {
				rlua_pushbool(luaState, false);
			}
			else if (In.at(1) == "true") {
				rlua_pushbool(luaState, true);
			}
		}

	}
	catch (...) {

	}
}