#pragma once

#include "stdafx.h"

#include "Rlua.h"
#include "Functions.h"

using namespace std;
using namespace Rlua;

void ExecuteCommand(std::string cmd) {
	std::vector<std::string> In = Split(cmd, ' ');
	if (In.size() != 0) {
		if (tolower(In.at(0)) == "ff") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getglobal(SkidState, "Instance");
				SKID_getfield(SkidState, -1, "new");
				SKID_pushstring(SkidState, "ForceField");
				SKID_pushvalue(SkidState, -4);
				SKID_call(SkidState, 2, 0);;
			}
			else {
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getglobal(SkidState, "Instance");
				SKID_getfield(SkidState, -1, "new");
				SKID_pushstring(SkidState, "ForceField");
				SKID_pushvalue(SkidState, -4);
				SKID_call(SkidState, 2, 0);;
			}
		}


		if (tolower(In.at(0)) == "heaven") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				SKID_getglobal(SkidState, "game");
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Head");
				SKID_getglobal(SkidState, "Instance");
				SKID_getfield(SkidState, -1, "new");
				SKID_pushstring(SkidState, "BodyVelocity");
				SKID_pushvalue(SkidState, -4);
				SKID_call(SkidState, 2, 1);;

				SKID_getglobal(SkidState, "game");
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Head");
				SKID_pushstring(SkidState, "BodyVelocity");
				SKID_getfield(SkidState, -1, "Destroy");
				SKID_pushvalue(SkidState, -2);
				SKID_call(SkidState, 1, 0);;
			}
			else {
				SKID_getglobal(SkidState, "game");
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Head");
				SKID_getglobal(SkidState, "Instance");
				SKID_getfield(SkidState, -1, "new");
				SKID_pushstring(SkidState, "BodyVelocity");
				SKID_pushvalue(SkidState, -4);
				SKID_call(SkidState, 2, 1);;

				SKID_getglobal(SkidState, "game");
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Head");
				SKID_pushstring(SkidState, "BodyVelocity");
				SKID_getfield(SkidState, -1, "Destroy");
				SKID_pushvalue(SkidState, -2);
				SKID_call(SkidState, 1, 0);;
			}
		}


		if (tolower(In.at(0)) == "ghost") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Head");
				SKID_pushnumber(SkidState, .5);
				SKID_setfield(SkidState, -2, "Transparency");
				SKID_call(SkidState, 1, 0);;
				SKID_settop(SkidState, 0);
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Head");
				SKID_getfield(SkidState, -1, "face");
				SKID_pushnumber(SkidState, .5);
				SKID_setfield(SkidState, -2, "Transparency");
				SKID_call(SkidState, 1, 0);;
				SKID_settop(SkidState, 0);
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Torso");
				SKID_pushnumber(SkidState, .5);
				SKID_setfield(SkidState, -2, "Transparency");
				SKID_call(SkidState, 1, 0);;
				SKID_settop(SkidState, 0);
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Right Arm");
				SKID_pushnumber(SkidState, .5);
				SKID_setfield(SkidState, -2, "Transparency");
				SKID_call(SkidState, 1, 0);;
				SKID_settop(SkidState, 0);
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Left Arm");
				SKID_pushnumber(SkidState, .5);
				SKID_setfield(SkidState, -2, "Transparency");
				SKID_call(SkidState, 1, 0);;
				SKID_settop(SkidState, 0);
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Right Leg");
				SKID_pushnumber(SkidState, .5);
				SKID_setfield(SkidState, -2, "Transparency");
				SKID_call(SkidState, 1, 0);;
				SKID_settop(SkidState, 0);
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Left Leg");
				SKID_setfield(SkidState, -2, "Transparency");
				SKID_call(SkidState, 1, 0);;
				SKID_settop(SkidState, 0);
			}
			else {
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Head");
				SKID_pushnumber(SkidState, .5);
				SKID_setfield(SkidState, -2, "Transparency");
				SKID_call(SkidState, 1, 0);;
				SKID_settop(SkidState, 0);
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Head");
				SKID_getfield(SkidState, -1, "face");
				SKID_pushnumber(SkidState, .5);
				SKID_setfield(SkidState, -2, "Transparency");
				SKID_call(SkidState, 1, 0);;
				SKID_settop(SkidState, 0);
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Torso");
				SKID_pushnumber(SkidState, .5);
				SKID_setfield(SkidState, -2, "Transparency");
				SKID_call(SkidState, 1, 0);;
				SKID_settop(SkidState, 0);
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Right Arm");
				SKID_pushnumber(SkidState, .5);
				SKID_setfield(SkidState, -2, "Transparency");
				SKID_call(SkidState, 1, 0);;
				SKID_settop(SkidState, 0);
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Left Arm");
				SKID_pushnumber(SkidState, .5);
				SKID_setfield(SkidState, -2, "Transparency");
				SKID_call(SkidState, 1, 0);;
				SKID_settop(SkidState, 0);
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Right Leg");
				SKID_pushnumber(SkidState, .5);
				SKID_setfield(SkidState, -2, "Transparency");
				SKID_call(SkidState, 1, 0);;
				SKID_settop(SkidState, 0);
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Left Leg");
				SKID_setfield(SkidState, -2, "Transparency");
				SKID_call(SkidState, 1, 0);;
				SKID_settop(SkidState, 0);
			}
		}


		if (tolower(In.at(0)) == "statchange") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "leaderstats");
				SKID_getfield(SkidState, -1, In.at(2).c_str());
				SKID_pushnumber(SkidState, atoi(In.at(3).c_str()));
				SKID_setfield(SkidState, -2, "Value");
			}
			else {
				SKID_getglobal(SkidState, "game");
				SKID_getfield(SkidState, -1, "Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "leaderstats");
				SKID_getfield(SkidState, -1, In.at(2).c_str());
				SKID_pushnumber(SkidState, atoi(In.at(3).c_str()));
				SKID_setfield(SkidState, -2, "Value");
			}
		}


		if (tolower(In.at(0)) == "keemstar") {

			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Torso");
			SKID_getglobal(SkidState, "Instance");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "SpecialMesh");
			SKID_pushvalue(SkidState, -4);
			SKID_call(SkidState, 2, 1);;
			std::string MeshId = "rbxassetid://471652548";
			std::string TextureId = "rbxassetid://471652580";//

			SKID_pushstring(SkidState, TextureId.c_str());
			SKID_setfield(SkidState, -2, "TextureId");
			SKID_pushstring(SkidState, MeshId.c_str());;
			SKID_setfield(SkidState, -2, "MeshId");
			SKID_getglobal(SkidState, "Vector3");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushnumber(SkidState, 4);
			SKID_pushnumber(SkidState, 4);
			SKID_pushnumber(SkidState, 4);
			SKID_call(SkidState, 3, 1);;
			SKID_setfield(SkidState, -3, "Scale");

			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Humanoid");
			SKID_pushstring(SkidState, "20");
			SKID_setfield(SkidState, -2, "HipHeight");

			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Left Leg");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Right Leg");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Left Arm");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (In.at(1) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Right Arm");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Head");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Humanoid");
			SKID_pushnumber(SkidState, 50);
			SKID_setfield(SkidState, -2, "WalkSpeed");
			std::string music = "433992205";
			SKID_getglobal(SkidState, "workspace");
			SKID_getglobal(SkidState, "Instance");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "Sound");
			SKID_pushvalue(SkidState, -4);
			SKID_call(SkidState, 2, 1);;

			SKID_pushstring(SkidState, ("rbxassetid://" + music).c_str());
			SKID_setfield(SkidState, -2, "SoundId");

			SKID_pushstring(SkidState, "KEEMSTAR_AUDIO_ICE");
			SKID_setfield(SkidState, -2, "Name");

			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Volume");

			SKID_getfield(SkidState, -1, "Play");
			SKID_pushvalue(SkidState, -2);
			SKID_call(SkidState, 1, 0);;
		}


		if (tolower(In.at(0)) == "illuminati") {

			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Torso");
			SKID_getglobal(SkidState, "Instance");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "SpecialMesh");
			SKID_pushvalue(SkidState, -4);
			SKID_call(SkidState, 2, 1);;
			std::string MeshId = "rbxassetid://438530093";
			std::string TextureId = "rbxassetid://438530120";//

			SKID_pushstring(SkidState, TextureId.c_str());
			SKID_setfield(SkidState, -2, "TextureId");
			SKID_pushstring(SkidState, MeshId.c_str());;
			SKID_setfield(SkidState, -2, "MeshId");
			SKID_getglobal(SkidState, "Vector3");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushnumber(SkidState, 4);
			SKID_pushnumber(SkidState, 4);
			SKID_pushnumber(SkidState, 4);
			SKID_call(SkidState, 3, 1);;
			SKID_setfield(SkidState, -3, "Scale");

			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Humanoid");
			SKID_pushstring(SkidState, "20");
			SKID_setfield(SkidState, -2, "HipHeight");

			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Left Leg");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Right Leg");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Left Arm");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (In.at(1) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Right Arm");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Head");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Humanoid");
			SKID_pushnumber(SkidState, 50);
			SKID_setfield(SkidState, -2, "WalkSpeed");
			std::string music = "433992205";
			SKID_getglobal(SkidState, "workspace");
			SKID_getglobal(SkidState, "Instance");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "Sound");
			SKID_pushvalue(SkidState, -4);
			SKID_call(SkidState, 2, 1);;

			SKID_pushstring(SkidState, ("rbxassetid://" + music).c_str());
			SKID_setfield(SkidState, -2, "SoundId");
		}


		if (tolower(In.at(0)) == "duck") {

			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Torso");
			SKID_getglobal(SkidState, "Instance");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "SpecialMesh");
			SKID_pushvalue(SkidState, -4);
			SKID_call(SkidState, 2, 1);;
			std::string MeshId = "rbxassetid://521754610";
			std::string TextureId = "rbxassetid://521754612";

			SKID_pushstring(SkidState, TextureId.c_str());
			SKID_setfield(SkidState, -2, "TextureId");
			SKID_pushstring(SkidState, MeshId.c_str());;
			SKID_setfield(SkidState, -2, "MeshId");
			SKID_getglobal(SkidState, "Vector3");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushnumber(SkidState, 4);
			SKID_pushnumber(SkidState, 4);
			SKID_pushnumber(SkidState, 4);
			SKID_call(SkidState, 3, 1);;
			SKID_setfield(SkidState, -3, "Scale");

			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Humanoid");
			SKID_pushstring(SkidState, "0");
			SKID_setfield(SkidState, -2, "HipHeight");

			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Left Leg");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Right Leg");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Left Arm");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (In.at(1) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Right Arm");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Head");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Humanoid");
			SKID_pushnumber(SkidState, 20);
			SKID_setfield(SkidState, -2, "WalkSpeed");
			std::string music = "";
			SKID_getglobal(SkidState, "workspace");
			SKID_getglobal(SkidState, "Instance");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "Sound");
			SKID_pushvalue(SkidState, -4);
			SKID_call(SkidState, 2, 1);;

			SKID_pushstring(SkidState, ("rbxassetid://" + music).c_str());
			SKID_setfield(SkidState, -2, "SoundId");
		}


		if (tolower(In.at(0)) == "mlg") {

			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Torso");
			SKID_getglobal(SkidState, "Instance");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "SpecialMesh");
			SKID_pushvalue(SkidState, -4);
			SKID_call(SkidState, 2, 1);;
			std::string MeshId = "rbxassetid://430452142";
			std::string TextureId = "rbxassetid://430452215";

			SKID_pushstring(SkidState, TextureId.c_str());
			SKID_setfield(SkidState, -2, "TextureId");
			SKID_pushstring(SkidState, MeshId.c_str());;
			SKID_setfield(SkidState, -2, "MeshId");
			SKID_getglobal(SkidState, "Vector3");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushnumber(SkidState, 4);
			SKID_pushnumber(SkidState, 4);
			SKID_pushnumber(SkidState, 4);
			SKID_call(SkidState, 3, 1);;
			SKID_setfield(SkidState, -3, "Scale");

			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Humanoid");
			SKID_pushstring(SkidState, "17");
			SKID_setfield(SkidState, -2, "HipHeight");

			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Left Leg");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Right Leg");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Left Arm");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (In.at(1) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Right Arm");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Head");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Humanoid");
			SKID_pushnumber(SkidState, 50);
			SKID_setfield(SkidState, -2, "WalkSpeed");
			std::string music = "";
			SKID_getglobal(SkidState, "workspace");
			SKID_getglobal(SkidState, "Instance");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "Sound");
			SKID_pushvalue(SkidState, -4);
			SKID_call(SkidState, 2, 1);;

			SKID_pushstring(SkidState, ("rbxassetid://" + music).c_str());
			SKID_setfield(SkidState, -2, "SoundId");
		}


		if (tolower(In.at(0)) == "pussy") {

			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Torso");
			SKID_getglobal(SkidState, "Instance");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "SpecialMesh");
			SKID_pushvalue(SkidState, -4);
			SKID_call(SkidState, 2, 1);;
			std::string MeshId = "rbxassetid://477053700";
			std::string TextureId = "rbxassetid://477053711";

			SKID_pushstring(SkidState, TextureId.c_str());
			SKID_setfield(SkidState, -2, "TextureId");
			SKID_pushstring(SkidState, MeshId.c_str());;
			SKID_setfield(SkidState, -2, "MeshId");
			SKID_getglobal(SkidState, "Vector3");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushnumber(SkidState, 4);
			SKID_pushnumber(SkidState, 4);
			SKID_pushnumber(SkidState, 4);
			SKID_call(SkidState, 3, 1);;
			SKID_setfield(SkidState, -3, "Scale");

			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Humanoid");
			SKID_pushstring(SkidState, "17");
			SKID_setfield(SkidState, -2, "HipHeight");

			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Left Leg");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Right Leg");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Left Arm");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (In.at(1) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Right Arm");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Head");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Transparency");
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Players");
			if (tolower(In.at(1)) == "me") {
				SKID_getfield(SkidState, -1, "LocalPlayer");
			}
			else {
				SKID_getfield(SkidState, -1, In.at(1).c_str());
			}
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "Humanoid");
			SKID_pushnumber(SkidState, 50);
			SKID_setfield(SkidState, -2, "WalkSpeed");
			std::string music = "";
			SKID_getglobal(SkidState, "workspace");
			SKID_getglobal(SkidState, "Instance");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "Sound");
			SKID_pushvalue(SkidState, -4);
			SKID_call(SkidState, 2, 1);;

			SKID_pushstring(SkidState, ("rbxassetid://" + music).c_str());
			SKID_setfield(SkidState, -2, "SoundId");
		}


		if (tolower(In.at(0)) == "fog") {
			SKID_getglobal(SkidState, "Game");
			SKID_getfield(SkidState, -1, "GetService");
			SKID_pushvalue(SkidState, -2);
			SKID_pushstring(SkidState, "Lighting");
			SKID_call(SkidState, 2, 1);;
			SKID_pushnumber(SkidState, stof(In.at(1).c_str()));
			SKID_setfield(SkidState, -2, "FogEnd");
		}


		if (tolower(In.at(0)) == "rfog") {
			SKID_getglobal(SkidState, "Game");
			SKID_getfield(SkidState, -1, "GetService");
			SKID_pushvalue(SkidState, -2);
			SKID_pushstring(SkidState, "Lighting");
			SKID_call(SkidState, 2, 1);;
			SKID_pushnumber(SkidState, 1000000);
			SKID_setfield(SkidState, -2, "FogEnd");
		}


		if (tolower(In.at(0)) == "rhat") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Head");

				SKID_getfield(SkidState, LUA_GLOBALSINDEX, "Vector3");
				SKID_getfield(SkidState, -1, "new");
				SKID_pushnumber(SkidState, 1);
				SKID_pushnumber(SkidState, 1);
				SKID_pushnumber(SkidState, 1);
				SKID_pushnumber(SkidState, 1);
				SKID_pushnumber(SkidState, 1);
				SKID_pushnumber(SkidState, 1);
				SKID_call(SkidState, 6, 1);;
				SKID_setfield(SkidState, -3, "Size");
			}
			else {
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Head");

				SKID_getfield(SkidState, LUA_GLOBALSINDEX, "Vector3");
				SKID_getfield(SkidState, -1, "new");
				SKID_pushnumber(SkidState, 1);
				SKID_pushnumber(SkidState, 1);
				SKID_pushnumber(SkidState, 1);
				SKID_pushnumber(SkidState, 1);
				SKID_pushnumber(SkidState, 1);
				SKID_pushnumber(SkidState, 1);
				SKID_call(SkidState, 6, 1);;
				SKID_setfield(SkidState, -3, "Size");
			}
		}


		if (tolower(In.at(0)) == "ws") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Humanoid");
				SKID_pushnumber(SkidState, stof(In.at(2).c_str()));
				SKID_setfield(SkidState, -2, "WalkSpeed");
			}
			else {
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Humanoid");
				SKID_pushnumber(SkidState, stof(In.at(2).c_str()));
				SKID_setfield(SkidState, -2, "WalkSpeed");
			}
		}


		if (tolower(In.at(0)) == "sit") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Humanoid");
				SKID_pushnumber(SkidState, 1);
				SKID_setfield(SkidState, -2, "Sit");
			}
			else {
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Humanoid");
				SKID_pushnumber(SkidState, 1);
				SKID_setfield(SkidState, -2, "Sit");
			}
		}


		if (tolower(In.at(0)) == "hipheight") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Humanoid");
				SKID_pushnumber(SkidState, stof(In.at(2).c_str()));
				SKID_setfield(SkidState, -2, "HipHeight");
			}
			else {
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Humanoid");
				SKID_pushnumber(SkidState, stof(In.at(2).c_str()));
				SKID_setfield(SkidState, -2, "HipHeight");
			}
		}


		if (tolower(In.at(0)) == "jp") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Humanoid");
				SKID_pushnumber(SkidState, stof(In.at(2).c_str()));
				SKID_setfield(SkidState, -2, "JumpPower");
			}
			else {
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Humanoid");
				SKID_pushnumber(SkidState, stof(In.at(2).c_str()));
				SKID_setfield(SkidState, -2, "JumpPower");
			}
		}


		if (tolower(In.at(0)) == "kill") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Humanoid");
				SKID_pushstring(SkidState, "0");
				SKID_setfield(SkidState, -2, "Health");
			}
			else {
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Humanoid");
				SKID_pushstring(SkidState, "0");
				SKID_setfield(SkidState, -2, "Health");
			}
		}


		if (tolower(In.at(0)) == "drivebloxmoney") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Playerdata");
				SKID_getfield(SkidState, -1, "Money");
				SKID_pushnumber(SkidState, 999999999);
				SKID_setfield(SkidState, -2, "Value");
			}
			else {
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Playerdata");
				SKID_getfield(SkidState, -1, "Money");
				SKID_pushnumber(SkidState, 999999999);
				SKID_setfield(SkidState, -2, "Value");
			}
		}


		if (tolower(In.at(0)) == "gravity") {
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Workspace");
			SKID_pushnumber(SkidState, stof(In.at(1).c_str()));
			SKID_setfield(SkidState, -2, "Gravity");
			cout << ">-> ";
		}


		if (tolower(In.at(0)) == "btools") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				for (int i = 1; i <= 4; i++) {
					getSKID("Players");
					SKID_getfield(SkidState, -1, "LocalPlayer");
					SKID_getfield(SkidState, -1, "Backpack");
					SKID_getfield(SkidState, LUA_GLOBALSINDEX, "Instance");
					SKID_getfield(SkidState, -1, "new");
					SKID_pushstring(SkidState, "HopperBin");
					SKID_pushvalue(SkidState, -4);
					SKID_call(SkidState, 2, 1);;

					SKID_pushnumber(SkidState, i);
					SKID_setfield(SkidState, -2, "Name");
					SKID_pushnumber(SkidState, i);
					SKID_setfield(SkidState, -2, "BinType");
				}
			}
			else {
				for (int i = 1; i <= 4; i++) {
					getSKID("Players");
					SKID_getfield(SkidState, -1, In.at(1).c_str());
					SKID_getfield(SkidState, -1, "Backpack");
					SKID_getfield(SkidState, LUA_GLOBALSINDEX, "Instance");
					SKID_getfield(SkidState, -1, "new");
					SKID_pushstring(SkidState, "HopperBin");
					SKID_pushvalue(SkidState, -4);
					SKID_call(SkidState, 2, 1);;

					SKID_pushnumber(SkidState, i);
					SKID_setfield(SkidState, -2, "Name");
					SKID_pushnumber(SkidState, i);
					SKID_setfield(SkidState, -2, "BinType");
				}
			}
		}


		if (tolower(In.at(0)) == "god") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Humanoid");
				SKID_pushnumber(SkidState, HUGE_VAL);
				SKID_setfield(SkidState, -2, "MaxHealth");
			}
			else {
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Humanoid");
				SKID_pushnumber(SkidState, HUGE_VAL);
				SKID_setfield(SkidState, -2, "MaxHealth");
			}
		}
		if (tolower(In.at(0)) == "bigfire" || tolower(In.at(0)) == "bodyfire") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Torso");
				SKID_getfield(SkidState, LUA_GLOBALSINDEX, "Instance");
				SKID_getfield(SkidState, -1, "new");
				SKID_pushstring(SkidState, "Fire");
				SKID_pushvalue(SkidState, -4);
				SKID_call(SkidState, 2, 1);;
				SKID_pushstring(SkidState, "29");
				SKID_setfield(SkidState, -2, "Size");
			}
			else {
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Torso");
				SKID_getfield(SkidState, LUA_GLOBALSINDEX, "Instance");
				SKID_getfield(SkidState, -1, "new");
				SKID_pushstring(SkidState, "Fire");
				SKID_pushvalue(SkidState, -4);
				SKID_call(SkidState, 2, 1);;
				SKID_pushstring(SkidState, "29");
				SKID_setfield(SkidState, -2, "Size");
			}
		}


		if (tolower(In.at(0)) == "time") {
				getSKID("Lighting");
				SKID_pushnumber(SkidState, atoi(In.at(1).c_str()));
				SKID_setfield(SkidState, -2, "TimeOfDay");
		}


		if (tolower(In.at(0)) == "select" || tolower(In.at(0)) == "box") {
			if (tolower(In.at(1)) == "me") {
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, LUA_GLOBALSINDEX, "Instance");
				SKID_getfield(SkidState, -1, "new");
				SKID_pushstring(SkidState, "SelectionBox");
				SKID_pushvalue(SkidState, -4);
				SKID_call(SkidState, 2, 1);;

				SKID_pushvalue(SkidState, -3);
				SKID_setfield(SkidState, -2, "Adornee");

			}
			else {
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, LUA_GLOBALSINDEX, "Instance");
				SKID_getfield(SkidState, -1, "new");
				SKID_pushstring(SkidState, "SelectionBox");
				SKID_pushvalue(SkidState, -4);
				SKID_call(SkidState, 2, 1);;

				SKID_pushvalue(SkidState, -3);
				SKID_setfield(SkidState, -2, "Adornee");
			}
		}


		if (tolower(In.at(0)) == "fencingr" || tolower(In.at(0)) == "freach") {
			getSKID("Players");
			SKID_getfield(SkidState, -1, "LocalPlayer");
			SKID_getfield(SkidState, -1, "Backpack");
			SKID_getfield(SkidState, -1, "Foil");
			SKID_getfield(SkidState, -1, "Handle");

			SKID_getfield(SkidState, LUA_GLOBALSINDEX, "Instance");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "SelectionBox");
			SKID_pushvalue(SkidState, -4);
			SKID_call(SkidState, 2, 1);;

			SKID_pushvalue(SkidState, -3);
			SKID_setfield(SkidState, -2, "Adornee");

			getSKID("Players");
			SKID_getfield(SkidState, -1, "LocalPlayer");
			SKID_getfield(SkidState, -1, "Backpack");
			SKID_getfield(SkidState, -1, "Foil");
			SKID_getfield(SkidState, -1, "Handle");

			getSKID("Players");
			SKID_getfield(SkidState, -1, "LocalPlayer");
			SKID_getfield(SkidState, -1, "Backpack");
			SKID_getfield(SkidState, -1, "Foil");
			SKID_getfield(SkidState, -1, "Handle");

			SKID_getfield(SkidState, LUA_GLOBALSINDEX, "Vector3");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "1");
			SKID_pushstring(SkidState, "1");
			SKID_pushstring(SkidState, "30");
			SKID_call(SkidState, 3, 1);;
			SKID_setfield(SkidState, -7, "Size");
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
					getSKID("Players");
					SKID_getfield(SkidState, -1, "LocalPlayer");
					SKID_getfield(SkidState, -1, "Character");
					SKID_getfield(SkidState, -1, "Head");

					SKID_getfield(SkidState, LUA_GLOBALSINDEX, "game");
					SKID_getfield(SkidState, -1, "Chat");
					SKID_getfield(SkidState, -1, "Chat");
					SKID_pushvalue(SkidState, -2);
					SKID_pushvalue(SkidState, -5);
					SKID_pushstring(SkidState, string.c_str());
					SKID_pushstring(SkidState, "Green");
					SKID_call(SkidState, 4, 1);;

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
					getSKID("Players");
					SKID_getfield(SkidState, -1, "LocalPlayer");
					SKID_getfield(SkidState, -1, "Character");
					SKID_getfield(SkidState, -1, "Head");

					SKID_getfield(SkidState, LUA_GLOBALSINDEX, "game");
					SKID_getfield(SkidState, -1, "Chat");
					SKID_getfield(SkidState, -1, "Chat");
					SKID_pushvalue(SkidState, -2);
					SKID_pushvalue(SkidState, -5);
					SKID_pushstring(SkidState, string.c_str());
					SKID_pushstring(SkidState, "Red");
					SKID_call(SkidState, 4, 1);;
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
					getSKID("Players");
					SKID_getfield(SkidState, -1, "LocalPlayer");
					SKID_getfield(SkidState, -1, "Character");
					SKID_getfield(SkidState, -1, "Head");

					SKID_getfield(SkidState, LUA_GLOBALSINDEX, "game");
					SKID_getfield(SkidState, -1, "Chat");
					SKID_getfield(SkidState, -1, "Chat");
					SKID_pushvalue(SkidState, -2);
					SKID_pushvalue(SkidState, -5);
					SKID_pushstring(SkidState, string.c_str());
					SKID_pushstring(SkidState, "Blue");
					SKID_call(SkidState, 4, 1);;
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
					getSKID("Players");
					SKID_getfield(SkidState, -1, In.at(1).c_str());
					SKID_getfield(SkidState, -1, "Character");
					SKID_getfield(SkidState, -1, "Head");

					SKID_getfield(SkidState, LUA_GLOBALSINDEX, "game");
					SKID_getfield(SkidState, -1, "Chat");
					SKID_getfield(SkidState, -1, "Chat");
					SKID_pushvalue(SkidState, -2);
					SKID_pushvalue(SkidState, -5);
					SKID_pushstring(SkidState, string.c_str());
					SKID_pushstring(SkidState, "Green");
					SKID_call(SkidState, 4, 1);;
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
					getSKID("Players");
					SKID_getfield(SkidState, -1, In.at(1).c_str());
					SKID_getfield(SkidState, -1, "Character");
					SKID_getfield(SkidState, -1, "Head");

					SKID_getfield(SkidState, LUA_GLOBALSINDEX, "game");
					SKID_getfield(SkidState, -1, "Chat");
					SKID_getfield(SkidState, -1, "Chat");
					SKID_pushvalue(SkidState, -2);
					SKID_pushvalue(SkidState, -5);
					SKID_pushstring(SkidState, string.c_str());
					SKID_pushstring(SkidState, "Red");
					SKID_call(SkidState, 4, 1);;
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
					getSKID("Players");
					SKID_getfield(SkidState, -1, In.at(1).c_str());
					SKID_getfield(SkidState, -1, "Character");
					SKID_getfield(SkidState, -1, "Head");

					SKID_getfield(SkidState, LUA_GLOBALSINDEX, "game");
					SKID_getfield(SkidState, -1, "Chat");
					SKID_getfield(SkidState, -1, "Chat");
					SKID_pushvalue(SkidState, -2);
					SKID_pushvalue(SkidState, -5);
					SKID_pushstring(SkidState, string.c_str());
					SKID_pushstring(SkidState, "Blue");
					SKID_call(SkidState, 4, 1);;
				}
			}
		}


		if (tolower(In.at(0)) == "charapp" || tolower(In.at(0)) == "char") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				std::string InitialID = "http://www.roblox.com/Asset/CharacterFetch.ashx?userId=" + In.at(2);
				SKID_pushstring(SkidState, InitialID.c_str());
				SKID_setfield(SkidState, -2, "CharacterAppearance");
			}
			else {
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				std::string InitialID = "http://www.roblox.com/Asset/CharacterFetch.ashx?userId=" + In.at(2);
				SKID_pushstring(SkidState, InitialID.c_str());
				SKID_setfield(SkidState, -2, "CharacterAppearance");
			}
		}


		if (tolower(In.at(0)) == "noob") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				std::string InitialID = "http://www.roblox.com/Asset/CharacterFetch.ashx?userId=5";
				SKID_pushstring(SkidState, InitialID.c_str());
				SKID_setfield(SkidState, -2, "CharacterAppearance");
			}
			else {
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				std::string InitialID = "http://www.roblox.com/Asset/CharacterFetch.ashx?userId=5";
				SKID_pushstring(SkidState, InitialID.c_str());
				SKID_setfield(SkidState, -2, "CharacterAppearance");
			}
		}


		if (tolower(In.at(0)) == "fire") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Torso");
				SKID_getfield(SkidState, LUA_GLOBALSINDEX, "Instance");
				SKID_getfield(SkidState, -1, "new");
				SKID_pushstring(SkidState, "Fire");
				SKID_pushvalue(SkidState, -4);
				SKID_call(SkidState, 2, 1);;
			}
			else {
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Torso");
				SKID_getfield(SkidState, LUA_GLOBALSINDEX, "Instance");
				SKID_getfield(SkidState, -1, "new");
				SKID_pushstring(SkidState, "Fire");
				SKID_pushvalue(SkidState, -4);
				SKID_call(SkidState, 2, 1);;
			}
		}


		if (tolower(In.at(0)) == "smoke") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Torso");
				SKID_getfield(SkidState, LUA_GLOBALSINDEX, "Instance");
				SKID_getfield(SkidState, -1, "new");
				SKID_pushstring(SkidState, "Smoke");
				SKID_pushvalue(SkidState, -4);
				SKID_call(SkidState, 2, 1);;
			}
			else {
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Torso");
				SKID_getfield(SkidState, LUA_GLOBALSINDEX, "Instance");
				SKID_getfield(SkidState, -1, "new");
				SKID_pushstring(SkidState, "Smoke");
				SKID_pushvalue(SkidState, -4);
				SKID_call(SkidState, 2, 1);;
			}
		}


		if (tolower(In.at(0)) == "sethealth" || tolower(In.at(0)) == "shealth") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_pushnumber(SkidState, atoi(In.at(2).c_str()));
				SKID_setfield(SkidState, -2, "MaxHealth");
			}
			else {
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_pushnumber(SkidState, atoi(In.at(2).c_str()));
				SKID_setfield(SkidState, -2, "MaxHealth");
			}
		}


		if (tolower(In.at(0)) == "addhealth") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Humanoid");
				SKID_getfield(SkidState, -1, "MaxHealth");
				const char* MaxHealthVal = SKID_tostring(SkidState, -1);
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Humanoid");
				SKID_pushstring(SkidState, (const char*)MaxHealthVal + atoi(In.at(2).c_str()));
				SKID_setfield(SkidState, -2, "MaxHealth");
			}
			else {
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Humanoid");
				SKID_getfield(SkidState, -1, "MaxHealth");
				const char* MaxHealthVal = SKID_tostring(SkidState, -1);
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Humanoid");
				SKID_pushstring(SkidState, (const char*)MaxHealthVal + atoi(In.at(2).c_str()));
				SKID_setfield(SkidState, -2, "MaxHealth");
			}
		}


		if (tolower(In.at(0)) == "sparkles" || tolower(In.at(0)) == "sp") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				getSKID("Players");
				SKID_getfield(SkidState, -1, "LocalPlayer");
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Torso");
				SKID_getfield(SkidState, LUA_GLOBALSINDEX, "Instance");
				SKID_getfield(SkidState, -1, "new");
				SKID_pushstring(SkidState, "Sparkles");
				SKID_pushvalue(SkidState, -4);
				SKID_call(SkidState, 2, 1);;
				SKID_pushstring(SkidState, "Ice Sparkles");
				SKID_setfield(SkidState, -2, "Name");
			}
			else {
				getSKID("Players");
				SKID_getfield(SkidState, -1, In.at(1).c_str());
				SKID_getfield(SkidState, -1, "Character");
				SKID_getfield(SkidState, -1, "Torso");
				SKID_getfield(SkidState, LUA_GLOBALSINDEX, "Instance");
				SKID_getfield(SkidState, -1, "new");
				SKID_pushstring(SkidState, "Sparkles");
				SKID_pushvalue(SkidState, -4);
				SKID_call(SkidState, 2, 1);;
				SKID_pushstring(SkidState, "Ice Sparkles");
				SKID_setfield(SkidState, -2, "Name");
			}
		}

		if (tolower(In.at(0)) == "criminal") {
			getSKID("Players");
			SKID_getfield(SkidState, -1, "LocalPlayer");
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "HumanoidRootPart");
			SKID_getglobal(SkidState, "CFrame");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushnumber(SkidState, -222.339157);
			SKID_pushnumber(SkidState, 17.9125443);
			SKID_pushnumber(SkidState, 1575.82336);
			SKID_call(SkidState, 3, 1);;
			SKID_setfield(SkidState, -3, "CFrame");
		}


		if (tolower(In.at(0)) == "garage") {
			getSKID("Players");
			SKID_getfield(SkidState, -1, "LocalPlayer");
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "HumanoidRootPart");
			SKID_getglobal(SkidState, "CFrame");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushnumber(SkidState, -342.130798);
			SKID_pushnumber(SkidState, 19.3135223);
			SKID_pushnumber(SkidState, 1182.73669);
			SKID_call(SkidState, 3, 1);;
			SKID_setfield(SkidState, -3, "CFrame");
		}


		if (tolower(In.at(0)) == "bank") {
			getSKID("Players");
			SKID_getfield(SkidState, -1, "LocalPlayer");
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "HumanoidRootPart");
			SKID_getglobal(SkidState, "CFrame");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushnumber(SkidState, 1.1110189);
			SKID_pushnumber(SkidState, 17.9213142);
			SKID_pushnumber(SkidState, 782.103455);
			SKID_call(SkidState, 3, 1);;
			SKID_setfield(SkidState, -3, "CFrame");
		}


		if (tolower(In.at(0)) == "prison") {
			getSKID("Players");
			SKID_getfield(SkidState, -1, "LocalPlayer");
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "HumanoidRootPart");
			SKID_getglobal(SkidState, "CFrame");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushnumber(SkidState, -1100.4469);
			SKID_pushnumber(SkidState, 17.7500038);
			SKID_pushnumber(SkidState, -1493.18286);
			SKID_call(SkidState, 3, 1);;
			SKID_setfield(SkidState, -3, "CFrame");
		}


		if (tolower(In.at(0)) == "nodoors") {
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Workspace");
			SKID_getfield(SkidState, -1, "Doors");
			SKID_getfield(SkidState, -1, "Destroy");
			SKID_pushvalue(SkidState, -2);
			SKID_call(SkidState, 1, 0);;
		}

		if (tolower(In.at(0)) == "banklazers") {
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Workspace");
			SKID_getfield(SkidState, -1, "Banks");
			SKID_getfield(SkidState, -1, "Bank");
			SKID_getfield(SkidState, -1, "Lasers");
			SKID_getfield(SkidState, -1, "Destroy");
			SKID_pushvalue(SkidState, -2);
			SKID_call(SkidState, 1, 0);;
		}

		if (tolower(In.at(0)) == "jewelrycameras") {
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Workspace");
			SKID_getfield(SkidState, -1, "Jewelrys");
			SKID_getfield(SkidState, -1, "Jewelry");
			SKID_getfield(SkidState, -1, "Cameras");
			SKID_getfield(SkidState, -1, "Destroy");
			SKID_pushvalue(SkidState, -2);
			SKID_call(SkidState, 1, 0);;
		}

		if (tolower(In.at(0)) == "jewelrylazers") {
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Workspace");
			SKID_getfield(SkidState, -1, "Jewelrys");
			SKID_getfield(SkidState, -1, "Jewelry");
			SKID_getfield(SkidState, -1, "Lasers");
			SKID_getfield(SkidState, -1, "Destroy");
			SKID_pushvalue(SkidState, -2);
			SKID_call(SkidState, 1, 0);;
		}

		if (tolower(In.at(0)) == "jewelryflazers") {
			SKID_getglobal(SkidState, "game");
			SKID_getfield(SkidState, -1, "Workspace");
			SKID_getfield(SkidState, -1, "Jewelrys");
			SKID_getfield(SkidState, -1, "Jewelry");
			SKID_getfield(SkidState, -1, "FloorLasers");
			SKID_getfield(SkidState, -1, "Destroy");
			SKID_pushvalue(SkidState, -2);
			SKID_call(SkidState, 1, 0);;
		}

		if (tolower(In.at(0)) == "jewelry") {
			getSKID("Players");
			SKID_getfield(SkidState, -1, "LocalPlayer");
			SKID_getfield(SkidState, -1, "Character");
			SKID_getfield(SkidState, -1, "HumanoidRootPart");
			SKID_getglobal(SkidState, "CFrame");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushnumber(SkidState, 124);
			SKID_pushnumber(SkidState, 17);
			SKID_pushnumber(SkidState, 1317);
			SKID_call(SkidState, 3, 1);;
			SKID_setfield(SkidState, -3, "CFrame");
		}

		if (tolower(In.at(0)) == "rickroll") {
			SKID_getglobal(SkidState, "Workspace");
			SKID_getglobal(SkidState, "Instance");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "Sound");
			SKID_pushvalue(SkidState, -4);
			SKID_call(SkidState, 2, 0);;

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "Sound");
			SKID_pushstring(SkidState, "LuaC_Music");
			SKID_setfield(SkidState, -2, "Name");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Volume");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_pushstring(SkidState, "rbxassetid://151758509");
			SKID_setfield(SkidState, -2, "SoundId");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_getfield(SkidState, -1, "Play");
			SKID_pushvalue(SkidState, -2);
			SKID_call(SkidState, 1, 0);;
		}


		if (tolower(In.at(0)) == "ppap") {
			SKID_getglobal(SkidState, "Workspace");
			SKID_getglobal(SkidState, "Instance");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "Sound");
			SKID_pushvalue(SkidState, -4);
			SKID_call(SkidState, 2, 0);;

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "Sound");
			SKID_pushstring(SkidState, "LuaC_Music");
			SKID_setfield(SkidState, -2, "Name");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Volume");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_pushstring(SkidState, "rbxassetid://514558366");
			SKID_setfield(SkidState, -2, "SoundId");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_getfield(SkidState, -1, "Play");
			SKID_pushvalue(SkidState, -2);
			SKID_call(SkidState, 1, 0);;
		}


		if (tolower(In.at(0)) == "billnye") {
			SKID_getglobal(SkidState, "Workspace");
			SKID_getglobal(SkidState, "Instance");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "Sound");
			SKID_pushvalue(SkidState, -4);
			SKID_call(SkidState, 2, 0);;

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "Sound");
			SKID_pushstring(SkidState, "LuaC_Music");
			SKID_setfield(SkidState, -2, "Name");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Volume");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_pushstring(SkidState, "rbxassetid://318733059");
			SKID_setfield(SkidState, -2, "SoundId");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_getfield(SkidState, -1, "Play");
			SKID_pushvalue(SkidState, -2);
			SKID_call(SkidState, 1, 0);;
		}


		if (tolower(In.at(0)) == "illuminati") {
			SKID_getglobal(SkidState, "Workspace");
			SKID_getglobal(SkidState, "Instance");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "Sound");
			SKID_pushvalue(SkidState, -4);
			SKID_call(SkidState, 2, 0);;

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "Sound");
			SKID_pushstring(SkidState, "LuaC_Music");
			SKID_setfield(SkidState, -2, "Name");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Volume");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_pushstring(SkidState, "rbxassetid://271908621");
			SKID_setfield(SkidState, -2, "SoundId");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_getfield(SkidState, -1, "Play");
			SKID_pushvalue(SkidState, -2);
			SKID_call(SkidState, 1, 0);;
		}


		if (tolower(In.at(0)) == "rage") {
			SKID_getglobal(SkidState, "Workspace");
			SKID_getglobal(SkidState, "Instance");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "Sound");
			SKID_pushvalue(SkidState, -4);
			SKID_call(SkidState, 2, 0);;

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "Sound");
			SKID_pushstring(SkidState, "LuaC_Music");
			SKID_setfield(SkidState, -2, "Name");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Volume");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_pushstring(SkidState, "rbxassetid://382795033");
			SKID_setfield(SkidState, -2, "SoundId");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_getfield(SkidState, -1, "Play");
			SKID_pushvalue(SkidState, -2);
			SKID_call(SkidState, 1, 0);;
		}


		if (tolower(In.at(0)) == "cringe") {
			SKID_getglobal(SkidState, "Workspace");
			SKID_getglobal(SkidState, "Instance");
			SKID_getfield(SkidState, -1, "new");
			SKID_pushstring(SkidState, "Sound");
			SKID_pushvalue(SkidState, -4);
			SKID_call(SkidState, 2, 0);;

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "Sound");
			SKID_pushstring(SkidState, "LuaC_Music");
			SKID_setfield(SkidState, -2, "Name");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_pushnumber(SkidState, 1);
			SKID_setfield(SkidState, -2, "Volume");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_pushstring(SkidState, "rbxassetid://555159200");
			SKID_setfield(SkidState, -2, "SoundId");

			SKID_getglobal(SkidState, "Workspace");
			SKID_getfield(SkidState, -1, "LuaC_Music");
			SKID_getfield(SkidState, -1, "Play");
			SKID_pushvalue(SkidState, -2);
			SKID_call(SkidState, 1, 0);;
		}

		if (tolower(In.at(0)) == "clearws") {
			getSKID("Workspace");
			SKID_getfield(SkidState, -1, "ClearAllChildren");
			SKID_pushvalue(SkidState, -2);
			SKID_call(SkidState, 1, 0);;
		}

		SKID_settop(SkidState, 0);
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
			SKID_getfield(SkidState, stoi(In.at(1)), field.c_str());
		}

		else if (In.at(0) == "getglobal") {
			SKID_getglobal(SkidState, In.at(1).c_str());
		}

		else if (In.at(0) == "setfield") {
			SKID_setfield(SkidState, stoi(In.at(1)), In.at(2).c_str());
		}

		else if (In.at(0) == "pushvalue") {
			SKID_pushvalue(SkidState, stoi(In.at(1)));
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
			SKID_pushstring(SkidState, string.c_str());
		}

		else if (In.at(0) == "pushnumber") {
			SKID_pushnumber(SkidState, stoi(In.at(1)));
		}

		else if (In.at(0) == "pcall") {//this will be still pcall so you don't need to edit the lua c script
			SKID_call(SkidState, stoi(In.at(1)), stoi(In.at(2)));
		}

		else if (In.at(0) == "emptystack") {
			SKID_settop(SkidState, 0);
		}

		else if (In.at(0) == "settop") {
			SKID_settop(SkidState, stoi(In.at(1)));
		}

		else if (In.at(0) == "getservice") {
			getSKID(In.at(1).c_str());
		}

		else if (In.at(0) == "pushboolean") {
			if (In.at(1) == "false") {
				SKID_pushbool(SkidState, false);
			}
			else if (In.at(1) == "true") {
				SKID_pushbool(SkidState, true);
			}
		}

	}
	catch (...) {

	}
}