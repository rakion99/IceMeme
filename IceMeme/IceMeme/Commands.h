#pragma once

bool ClickTpState = false;

void ClickTpScript();

void Commands(std::string cmd) {
	using namespace Rlua;
	std::vector<std::string> In = Split(cmd, ' ');
	if (In.size() != 0) {
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
				rlua_pcall(luaState, 2, 0, 0);
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
				rlua_pcall(luaState, 2, 0, 0);
			}
		}


		if (tolower(In.at(0)) == "heaven") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getglobal(luaState, "game");
				rlua_getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Head");
				rlua_getglobal(luaState, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "BodyVelocity");
				rlua_pushvalue(luaState, -4);
				rlua_pcall(luaState, 2, 1, 0);

				rlua_getglobal(luaState, "game");
				rlua_getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Head");
				rlua_pushstring(luaState, "BodyVelocity");
				rlua_getfield(luaState, -1, "Destroy");
				rlua_pushvalue(luaState, -2);
				rlua_pcall(luaState, 1, 0, 0);
			}
			else {
				rlua_getglobal(luaState, "game");
				rlua_getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Head");
				rlua_getglobal(luaState, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "BodyVelocity");
				rlua_pushvalue(luaState, -4);
				rlua_pcall(luaState, 2, 1, 0);

				rlua_getglobal(luaState, "game");
				rlua_getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Head");
				rlua_pushstring(luaState, "BodyVelocity");
				rlua_getfield(luaState, -1, "Destroy");
				rlua_pushvalue(luaState, -2);
				rlua_pcall(luaState, 1, 0, 0);
			}
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
				rlua_pcall(luaState, 1, 0, 0);
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Head");
				rlua_getfield(luaState, -1, "face");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_pcall(luaState, 1, 0, 0);
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Torso");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_pcall(luaState, 1, 0, 0);
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Right Arm");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_pcall(luaState, 1, 0, 0);
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Left Arm");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_pcall(luaState, 1, 0, 0);
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Right Leg");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_pcall(luaState, 1, 0, 0);
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Left Leg");
				rlua_setfield(luaState, -2, "Transparency");
				rlua_pcall(luaState, 1, 0, 0);
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
				rlua_pcall(luaState, 1, 0, 0);
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Head");
				rlua_getfield(luaState, -1, "face");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_pcall(luaState, 1, 0, 0);
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Torso");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_pcall(luaState, 1, 0, 0);
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Right Arm");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_pcall(luaState, 1, 0, 0);
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Left Arm");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_pcall(luaState, 1, 0, 0);
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Right Leg");
				rlua_pushnumber(luaState, .5);
				rlua_setfield(luaState, -2, "Transparency");
				rlua_pcall(luaState, 1, 0, 0);
				rlua_settop(luaState, 0);
				rlua_getglobal(luaState, "game");
				rlua_getfield(luaState, -1, "Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Left Leg");
				rlua_setfield(luaState, -2, "Transparency");
				rlua_pcall(luaState, 1, 0, 0);
				rlua_settop(luaState, 0);
			}
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
			rlua_pcall(luaState, 2, 1, 0);
			std::string MeshId = "rbxassetid://471652548";
			std::string TextureId = "rbxassetid://471652580";//

			rlua_pushstring(luaState, TextureId.c_str());
			rlua_setfield(luaState, -2, "TextureId");
			rlua_pushstring(luaState, MeshId.c_str());
			rlua_setfield(luaState, -2, "MeshId");
			rlua_getglobal(luaState, "Vector3");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_pcall(luaState, 3, 1, 0);
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
			rlua_pcall(luaState, 2, 1, 0);

			rlua_pushstring(luaState, ("rbxassetid://" + music).c_str());
			rlua_setfield(luaState, -2, "SoundId");

			rlua_pushstring(luaState, "KEEMSTAR_AUDIO_ICE");
			rlua_setfield(luaState, -2, "Name");

			rlua_pushnumber(luaState, 1);
			rlua_setfield(luaState, -2, "Volume");

			rlua_getfield(luaState, -1, "Play");
			rlua_pushvalue(luaState, -2);
			rlua_pcall(luaState, 1, 0, 0);
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
			rlua_pcall(luaState, 2, 1, 0);
			std::string MeshId = "rbxassetid://438530093";
			std::string TextureId = "rbxassetid://438530120";//

			rlua_pushstring(luaState, TextureId.c_str());
			rlua_setfield(luaState, -2, "TextureId");
			rlua_pushstring(luaState, MeshId.c_str());
			rlua_setfield(luaState, -2, "MeshId");
			rlua_getglobal(luaState, "Vector3");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_pcall(luaState, 3, 1, 0);
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
			rlua_pcall(luaState, 2, 1, 0);

			rlua_pushstring(luaState, ("rbxassetid://" + music).c_str());
			rlua_setfield(luaState, -2, "SoundId");
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
			rlua_pcall(luaState, 2, 1, 0);
			std::string MeshId = "rbxassetid://521754610";
			std::string TextureId = "rbxassetid://521754612";

			rlua_pushstring(luaState, TextureId.c_str());
			rlua_setfield(luaState, -2, "TextureId");
			rlua_pushstring(luaState, MeshId.c_str());
			rlua_setfield(luaState, -2, "MeshId");
			rlua_getglobal(luaState, "Vector3");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_pcall(luaState, 3, 1, 0);
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
			rlua_pcall(luaState, 2, 1, 0);

			rlua_pushstring(luaState, ("rbxassetid://" + music).c_str());
			rlua_setfield(luaState, -2, "SoundId");
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
			rlua_pcall(luaState, 2, 1, 0);
			std::string MeshId = "rbxassetid://430452142";
			std::string TextureId = "rbxassetid://430452215";

			rlua_pushstring(luaState, TextureId.c_str());
			rlua_setfield(luaState, -2, "TextureId");
			rlua_pushstring(luaState, MeshId.c_str());
			rlua_setfield(luaState, -2, "MeshId");
			rlua_getglobal(luaState, "Vector3");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_pcall(luaState, 3, 1, 0);
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
			rlua_pcall(luaState, 2, 1, 0);

			rlua_pushstring(luaState, ("rbxassetid://" + music).c_str());
			rlua_setfield(luaState, -2, "SoundId");
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
			rlua_pcall(luaState, 2, 1, 0);
			std::string MeshId = "rbxassetid://477053700";
			std::string TextureId = "rbxassetid://477053711";

			rlua_pushstring(luaState, TextureId.c_str());
			rlua_setfield(luaState, -2, "TextureId");
			rlua_pushstring(luaState, MeshId.c_str());
			rlua_setfield(luaState, -2, "MeshId");
			rlua_getglobal(luaState, "Vector3");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_pushnumber(luaState, 4);
			rlua_pcall(luaState, 3, 1, 0);
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
			rlua_pcall(luaState, 2, 1, 0);

			rlua_pushstring(luaState, ("rbxassetid://" + music).c_str());
			rlua_setfield(luaState, -2, "SoundId");
		}


		if (tolower(In.at(0)) == "fog") {
			rlua_getglobal(luaState, "Game");
			rlua_getfield(luaState, -1, "GetService");
			rlua_pushvalue(luaState, -2);
			rlua_pushstring(luaState, "Lighting");
			rlua_pcall(luaState, 2, 1, 0);
			rlua_pushnumber(luaState, std::stof(In.at(1).c_str()));
			rlua_setfield(luaState, -2, "FogEnd");
		}


		if (tolower(In.at(0)) == "rfog") {
			rlua_getglobal(luaState, "Game");
			rlua_getfield(luaState, -1, "GetService");
			rlua_pushvalue(luaState, -2);
			rlua_pushstring(luaState, "Lighting");
			rlua_pcall(luaState, 2, 1, 0);
			rlua_pushnumber(luaState, 1000000);
			rlua_setfield(luaState, -2, "FogEnd");
		}


		if (tolower(In.at(0)) == "rhat") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getService("Players");
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
				rlua_pcall(luaState, 6, 1, 0);
				rlua_setfield(luaState, -3, "Size");
			}
			else {
				rlua_getService("Players");
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
				rlua_pcall(luaState, 6, 1, 0);
				rlua_setfield(luaState, -3, "Size");
			}
		}


		if (tolower(In.at(0)) == "ws") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushnumber(luaState, std::stof(In.at(2).c_str()));
				rlua_setfield(luaState, -2, "WalkSpeed");
			}
			else {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushnumber(luaState, std::stof(In.at(2).c_str()));
				rlua_setfield(luaState, -2, "WalkSpeed");
			}
		}


		if (tolower(In.at(0)) == "sit") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushnumber(luaState, 1);
				rlua_setfield(luaState, -2, "Sit");
			}
			else {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushnumber(luaState, 1);
				rlua_setfield(luaState, -2, "Sit");
			}
		}


		if (tolower(In.at(0)) == "hipheight") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushnumber(luaState, std::stof(In.at(2).c_str()));
				rlua_setfield(luaState, -2, "HipHeight");
			}
			else {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushnumber(luaState, std::stof(In.at(2).c_str()));
				rlua_setfield(luaState, -2, "HipHeight");
			}
		}


		if (tolower(In.at(0)) == "jp") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushnumber(luaState, std::stof(In.at(2).c_str()));
				rlua_setfield(luaState, -2, "JumpPower");
			}
			else {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushnumber(luaState, std::stof(In.at(2).c_str()));
				rlua_setfield(luaState, -2, "JumpPower");
			}
		}


		if (tolower(In.at(0)) == "kill") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushstring(luaState, "0");
				rlua_setfield(luaState, -2, "Health");
			}
			else {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushstring(luaState, "0");
				rlua_setfield(luaState, -2, "Health");
			}
		}


		if (tolower(In.at(0)) == "drivebloxmoney") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Playerdata");
				rlua_getfield(luaState, -1, "Money");
				rlua_pushnumber(luaState, 999999999);
				rlua_setfield(luaState, -2, "Value");
			}
			else {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Playerdata");
				rlua_getfield(luaState, -1, "Money");
				rlua_pushnumber(luaState, 999999999);
				rlua_setfield(luaState, -2, "Value");
			}
		}


		if (tolower(In.at(0)) == "gravity") {
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Workspace");
			rlua_pushnumber(luaState, std::stof(In.at(1).c_str()));
			rlua_setfield(luaState, -2, "Gravity");
		}


		if (tolower(In.at(0)) == "btools") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				for (int i = 1; i <= 4; i++) {
					rlua_getService("Players");
					rlua_getfield(luaState, -1, "LocalPlayer");
					rlua_getfield(luaState, -1, "Backpack");
					rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
					rlua_getfield(luaState, -1, "new");
					rlua_pushstring(luaState, "HopperBin");
					rlua_pushvalue(luaState, -4);
					rlua_pcall(luaState, 2, 1, 0);

					rlua_pushnumber(luaState, i);
					rlua_setfield(luaState, -2, "Name");
					rlua_pushnumber(luaState, i);
					rlua_setfield(luaState, -2, "BinType");
				}
			}
			else {
				for (int i = 1; i <= 4; i++) {
					rlua_getService("Players");
					rlua_getfield(luaState, -1, In.at(1).c_str());
					rlua_getfield(luaState, -1, "Backpack");
					rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
					rlua_getfield(luaState, -1, "new");
					rlua_pushstring(luaState, "HopperBin");
					rlua_pushvalue(luaState, -4);
					rlua_pcall(luaState, 2, 1, 0);

					rlua_pushnumber(luaState, i);
					rlua_setfield(luaState, -2, "Name");
					rlua_pushnumber(luaState, i);
					rlua_setfield(luaState, -2, "BinType");
				}
			}
		}


		if (tolower(In.at(0)) == "god") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushnumber(luaState, HUGE_VAL);
				rlua_setfield(luaState, -2, "MaxHealth");
			}
			else {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Humanoid");
				rlua_pushnumber(luaState, HUGE_VAL);
				rlua_setfield(luaState, -2, "MaxHealth");
			}
		}
		if (tolower(In.at(0)) == "bigfire" || tolower(In.at(0)) == "bodyfire") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Torso");
				rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "Fire");
				rlua_pushvalue(luaState, -4);
				rlua_pcall(luaState, 2, 1, 0);
				rlua_pushstring(luaState, "29");
				rlua_setfield(luaState, -2, "Size");
			}
			else {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Torso");
				rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "Fire");
				rlua_pushvalue(luaState, -4);
				rlua_pcall(luaState, 2, 1, 0);
				rlua_pushstring(luaState, "29");
				rlua_setfield(luaState, -2, "Size");
			}
		}


		if (tolower(In.at(0)) == "time") {
			rlua_getService("Lighting");
			rlua_pushnumber(luaState, atoi(In.at(1).c_str()));
			rlua_setfield(luaState, -2, "TimeOfDay");
		}


		if (tolower(In.at(0)) == "select" || tolower(In.at(0)) == "box") {
			if (tolower(In.at(1)) == "me") {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "SelectionBox");
				rlua_pushvalue(luaState, -4);
				rlua_pcall(luaState, 2, 1, 0);

				rlua_pushvalue(luaState, -3);
				rlua_setfield(luaState, -2, "Adornee");

			}
			else {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "SelectionBox");
				rlua_pushvalue(luaState, -4);
				rlua_pcall(luaState, 2, 1, 0);

				rlua_pushvalue(luaState, -3);
				rlua_setfield(luaState, -2, "Adornee");
			}
		}


		if (tolower(In.at(0)) == "fencingr" || tolower(In.at(0)) == "freach") {
			rlua_getService("Players");
			rlua_getfield(luaState, -1, "LocalPlayer");
			rlua_getfield(luaState, -1, "Backpack");
			rlua_getfield(luaState, -1, "Foil");
			rlua_getfield(luaState, -1, "Handle");

			rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "SelectionBox");
			rlua_pushvalue(luaState, -4);
			rlua_pcall(luaState, 2, 1, 0);

			rlua_pushvalue(luaState, -3);
			rlua_setfield(luaState, -2, "Adornee");

			rlua_getService("Players");
			rlua_getfield(luaState, -1, "LocalPlayer");
			rlua_getfield(luaState, -1, "Backpack");
			rlua_getfield(luaState, -1, "Foil");
			rlua_getfield(luaState, -1, "Handle");

			rlua_getService("Players");
			rlua_getfield(luaState, -1, "LocalPlayer");
			rlua_getfield(luaState, -1, "Backpack");
			rlua_getfield(luaState, -1, "Foil");
			rlua_getfield(luaState, -1, "Handle");

			rlua_getfield(luaState, LUA_GLOBALSINDEX, "Vector3");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "1");
			rlua_pushstring(luaState, "1");
			rlua_pushstring(luaState, "30");
			rlua_pcall(luaState, 3, 1, 0);
			rlua_setfield(luaState, -7, "Size");
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
					rlua_getService("Players");
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
					rlua_pcall(luaState, 4, 1, 0);

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
					rlua_getService("Players");
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
					rlua_pcall(luaState, 4, 1, 0);
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
					rlua_getService("Players");
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
					rlua_pcall(luaState, 4, 1, 0);
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
					rlua_getService("Players");
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
					rlua_pcall(luaState, 4, 1, 0);
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
					rlua_getService("Players");
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
					rlua_pcall(luaState, 4, 1, 0);
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
					rlua_getService("Players");
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
					rlua_pcall(luaState, 4, 1, 0);
				}
			}
		}


		if (tolower(In.at(0)) == "charapp" || tolower(In.at(0)) == "char") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				std::string InitialID = "http://www.roblox.com/Asset/CharacterFetch.ashx?userId=" + In.at(2);
				rlua_pushstring(luaState, InitialID.c_str());
				rlua_setfield(luaState, -2, "CharacterAppearance");
			}
			else {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				std::string InitialID = "http://www.roblox.com/Asset/CharacterFetch.ashx?userId=" + In.at(2);
				rlua_pushstring(luaState, InitialID.c_str());
				rlua_setfield(luaState, -2, "CharacterAppearance");
			}
		}


		if (tolower(In.at(0)) == "noob") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				std::string InitialID = "http://www.roblox.com/Asset/CharacterFetch.ashx?userId=5";
				rlua_pushstring(luaState, InitialID.c_str());
				rlua_setfield(luaState, -2, "CharacterAppearance");
			}
			else {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				std::string InitialID = "http://www.roblox.com/Asset/CharacterFetch.ashx?userId=5";
				rlua_pushstring(luaState, InitialID.c_str());
				rlua_setfield(luaState, -2, "CharacterAppearance");
			}
		}


		if (tolower(In.at(0)) == "fire") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Torso");
				rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "Fire");
				rlua_pushvalue(luaState, -4);
				rlua_pcall(luaState, 2, 1, 0);
			}
			else {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Torso");
				rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "Fire");
				rlua_pushvalue(luaState, -4);
				rlua_pcall(luaState, 2, 1, 0);
			}
		}


		if (tolower(In.at(0)) == "smoke") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Torso");
				rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "Smoke");
				rlua_pushvalue(luaState, -4);
				rlua_pcall(luaState, 2, 1, 0);
			}
			else {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Torso");
				rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "Smoke");
				rlua_pushvalue(luaState, -4);
				rlua_pcall(luaState, 2, 1, 0);
			}
		}


		if (tolower(In.at(0)) == "sethealth" || tolower(In.at(0)) == "shealth") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_pushnumber(luaState, atoi(In.at(2).c_str()));
				rlua_setfield(luaState, -2, "MaxHealth");
			}
			else {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_pushnumber(luaState, atoi(In.at(2).c_str()));
				rlua_setfield(luaState, -2, "MaxHealth");
			}
		}

		if (tolower(In.at(0)) == "sparkles" || tolower(In.at(0)) == "sp") {
			if (tolower(In.at(1)) == "me" || tolower(In.at(1)) == "localplr") {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, "LocalPlayer");
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Torso");
				rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "Sparkles");
				rlua_pushvalue(luaState, -4);
				rlua_pcall(luaState, 2, 1, 0);
				rlua_pushstring(luaState, "Ice Sparkles");
				rlua_setfield(luaState, -2, "Name");
			}
			else {
				rlua_getService("Players");
				rlua_getfield(luaState, -1, In.at(1).c_str());
				rlua_getfield(luaState, -1, "Character");
				rlua_getfield(luaState, -1, "Torso");
				rlua_getfield(luaState, LUA_GLOBALSINDEX, "Instance");
				rlua_getfield(luaState, -1, "new");
				rlua_pushstring(luaState, "Sparkles");
				rlua_pushvalue(luaState, -4);
				rlua_pcall(luaState, 2, 1, 0);
				rlua_pushstring(luaState, "Ice Sparkles");
				rlua_setfield(luaState, -2, "Name");
			}
		}

		if (tolower(In.at(0)) == "criminal") {
			rlua_getService("Players");
			rlua_getfield(luaState, -1, "LocalPlayer");
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "HumanoidRootPart");
			rlua_getglobal(luaState, "CFrame");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, -222.339157);
			rlua_pushnumber(luaState, 17.9125443);
			rlua_pushnumber(luaState, 1575.82336);
			rlua_pcall(luaState, 3, 1, 0);
			rlua_setfield(luaState, -3, "CFrame");
		}


		if (tolower(In.at(0)) == "garage") {
			rlua_getService("Players");
			rlua_getfield(luaState, -1, "LocalPlayer");
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "HumanoidRootPart");
			rlua_getglobal(luaState, "CFrame");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, -342.130798);
			rlua_pushnumber(luaState, 19.3135223);
			rlua_pushnumber(luaState, 1182.73669);
			rlua_pcall(luaState, 3, 1, 0);
			rlua_setfield(luaState, -3, "CFrame");
		}


		if (tolower(In.at(0)) == "bank") {
			rlua_getService("Players");
			rlua_getfield(luaState, -1, "LocalPlayer");
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "HumanoidRootPart");
			rlua_getglobal(luaState, "CFrame");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, 1.1110189);
			rlua_pushnumber(luaState, 17.9213142);
			rlua_pushnumber(luaState, 782.103455);
			rlua_pcall(luaState, 3, 1, 0);
			rlua_setfield(luaState, -3, "CFrame");
		}


		if (tolower(In.at(0)) == "prison") {
			rlua_getService("Players");
			rlua_getfield(luaState, -1, "LocalPlayer");
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "HumanoidRootPart");
			rlua_getglobal(luaState, "CFrame");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, -1100.4469);
			rlua_pushnumber(luaState, 17.7500038);
			rlua_pushnumber(luaState, -1493.18286);
			rlua_pcall(luaState, 3, 1, 0);
			rlua_setfield(luaState, -3, "CFrame");
		}


		if (tolower(In.at(0)) == "nodoors") {
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Workspace");
			rlua_getfield(luaState, -1, "Doors");
			rlua_getfield(luaState, -1, "Destroy");
			rlua_pushvalue(luaState, -2);
			rlua_pcall(luaState, 1, 0, 0);
		}

		if (tolower(In.at(0)) == "banklazers") {
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Workspace");
			rlua_getfield(luaState, -1, "Banks");
			rlua_getfield(luaState, -1, "Bank");
			rlua_getfield(luaState, -1, "Lasers");
			rlua_getfield(luaState, -1, "Destroy");
			rlua_pushvalue(luaState, -2);
			rlua_pcall(luaState, 1, 0, 0);
		}

		if (tolower(In.at(0)) == "jewelrycameras") {
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Workspace");
			rlua_getfield(luaState, -1, "Jewelrys");
			rlua_getfield(luaState, -1, "Jewelry");
			rlua_getfield(luaState, -1, "Cameras");
			rlua_getfield(luaState, -1, "Destroy");
			rlua_pushvalue(luaState, -2);
			rlua_pcall(luaState, 1, 0, 0);
		}

		if (tolower(In.at(0)) == "jewelrylazers") {
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Workspace");
			rlua_getfield(luaState, -1, "Jewelrys");
			rlua_getfield(luaState, -1, "Jewelry");
			rlua_getfield(luaState, -1, "Lasers");
			rlua_getfield(luaState, -1, "Destroy");
			rlua_pushvalue(luaState, -2);
			rlua_pcall(luaState, 1, 0, 0);
		}

		if (tolower(In.at(0)) == "jewelryflazers") {
			rlua_getglobal(luaState, "game");
			rlua_getfield(luaState, -1, "Workspace");
			rlua_getfield(luaState, -1, "Jewelrys");
			rlua_getfield(luaState, -1, "Jewelry");
			rlua_getfield(luaState, -1, "FloorLasers");
			rlua_getfield(luaState, -1, "Destroy");
			rlua_pushvalue(luaState, -2);
			rlua_pcall(luaState, 1, 0, 0);
		}

		if (tolower(In.at(0)) == "jewelry") {
			rlua_getService("Players");
			rlua_getfield(luaState, -1, "LocalPlayer");
			rlua_getfield(luaState, -1, "Character");
			rlua_getfield(luaState, -1, "HumanoidRootPart");
			rlua_getglobal(luaState, "CFrame");
			rlua_getfield(luaState, -1, "new");
			rlua_pushnumber(luaState, 124);
			rlua_pushnumber(luaState, 17);
			rlua_pushnumber(luaState, 1317);
			rlua_pcall(luaState, 3, 1, 0);
			rlua_setfield(luaState, -3, "CFrame");
		}

		if (tolower(In.at(0)) == "rickroll") {
			rlua_getglobal(luaState, "Workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_pcall(luaState, 2, 0, 0);

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
			rlua_pcall(luaState, 1, 0, 0);
		}


		if (tolower(In.at(0)) == "ppap") {
			rlua_getglobal(luaState, "Workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_pcall(luaState, 2, 0, 0);

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
			rlua_pcall(luaState, 1, 0, 0);
		}


		if (tolower(In.at(0)) == "billnye") {
			rlua_getglobal(luaState, "Workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_pcall(luaState, 2, 0, 0);

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
			rlua_pcall(luaState, 1, 0, 0);
		}


		if (tolower(In.at(0)) == "illuminati") {
			rlua_getglobal(luaState, "Workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_pcall(luaState, 2, 0, 0);

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
			rlua_pcall(luaState, 1, 0, 0);
		}


		if (tolower(In.at(0)) == "rage") {
			rlua_getglobal(luaState, "Workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_pcall(luaState, 2, 0, 0);

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
			rlua_pcall(luaState, 1, 0, 0);
		}


		if (tolower(In.at(0)) == "cringe") {
			rlua_getglobal(luaState, "Workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_pcall(luaState, 2, 0, 0);

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
			rlua_pcall(luaState, 1, 0, 0);
		}

		if (tolower(In.at(0)) == "clearws") {
			rlua_getService("Workspace");
			rlua_getfield(luaState, -1, "ClearAllChildren");
			rlua_pushvalue(luaState, -2);
			rlua_pcall(luaState, 1, 0, 0);
		}

		if (tolower(In.at(0)) == "fecheck") {
			rlua_getglobal(luaState, "workspace");
			rlua_getfield(luaState, -1, "FilteringEnabled");
			rlua_getglobal(luaState, "print");
			rlua_pushvalue(luaState, -2);
			rlua_pcall(luaState, 1, 0, 0);
		}

		if (tolower(In.at(0)) == "play") {
			rlua_getglobal(luaState, "Workspace");
			rlua_getglobal(luaState, "Instance");
			rlua_getfield(luaState, -1, "new");
			rlua_pushstring(luaState, "Sound");
			rlua_pushvalue(luaState, -4);
			rlua_pcall(luaState, 2, 0, 0);

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
			rlua_pushstring(luaState, ("rbxassetid://" + In.at(1)).c_str());
			rlua_setfield(luaState, -2, "SoundId");

			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_getfield(luaState, -1, "Play");
			rlua_pushvalue(luaState, -2);
			rlua_pcall(luaState, 1, 0, 0);
		}

		if (tolower(In.at(0)) == "stopmusic") {
			rlua_getglobal(luaState, "Workspace");
			rlua_getfield(luaState, -1, "LuaC_Music");
			rlua_getfield(luaState, -1, "Destroy");
			rlua_pushvalue(luaState, -2);
			rlua_pcall(luaState, 1, 0, 0);
		}

		if (tolower(In.at(0)) == "insert") {
			/*
			ask void for it :wink:
			*/
		}

		/*
		snip tpclick 2op
		*/

		rlua_settop(luaState, 0);
	}
	else
	{
		return;
	}
}
