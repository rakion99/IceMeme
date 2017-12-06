#pragma once

using namespace Rlua;
//Split by delimiter
std::vector<std::string> SkIdT(std::string str, char Delim) {
	std::vector<std::string> SkIds;
	std::stringstream skids(str);
	std::string SkId;
	while (getline(skids, SkId, Delim))
		SkIds.push_back(SkId);
	return SkIds;
}
//Convert string to lowercase
std::string toSkId(std::string str)
{
	std::string reSkId("");
	for (size_t i = 0; i < str.length(); i++)
	{
		int aSkId = (int)str.at(i);
		if (aSkId >= (int)'a' && aSkId <= (int)'z')
			reSkId += (char)aSkId;
		else
			reSkId += (char)(aSkId + ((int)'a' - (int)'A'));
	}
	return reSkId;
}
//Getservice
void getSKID(std::string service)
{
	using namespace Rlua;
	SKID_getSkId(SkidState, LUA_GLOBALSKID, "game");
	SKID_getSkId(SkidState, -1, "GetService");
	SKID_SkIdvalue(SkidState, -2);
	SKID_pushSkId(SkidState, service.c_str());
	SKID_SkId(SkidState, 2, 1);
}
//Set identity
int *OPSKIDLeVeL() {
	int *Level = SKIDLeVeL();
	if (*Level == 0)
		*Level = 69;
	return Level;
}
//Scan
void SKID() {
	SKIDD();
	OPSKIDLeVeL();
}
