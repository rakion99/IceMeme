#pragma once
//Command pipe
DWORD WINAPI CmdPipe(PVOID lvpParameter)
{
	HANDLE hPipe;
	char buffer[1024];
	DWORD dwRead;
	hPipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\IceCmd"),//IceCmd is the name of the command pipe
		PIPE_ACCESS_DUPLEX | PIPE_TYPE_BYTE | PIPE_READMODE_BYTE,
		PIPE_WAIT,
		1,
		1024 * 16,
		1024 * 16,
		NMPWAIT_USE_DEFAULT_WAIT,
		NULL);
	while (hPipe != INVALID_HANDLE_VALUE)
	{
		if (ConnectNamedPipe(hPipe, NULL) != FALSE)
		{
			while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE)
			{
				buffer[dwRead] = '\0';
				try {
					Commands(buffer);
				}
				catch (std::exception e) {
					IceMemebox(e.what());
				}
				catch (...) {
					IceMemebox("An Unhandled Error Has Occured!");
				}
			}
		}
		DisconnectNamedPipe(hPipe);
	}
}
//Lua C pipe
DWORD WINAPI LuaCPipe(PVOID lvpParameter)
{
	HANDLE hPipe;
	char buffer[999999];
	DWORD dwRead;
	hPipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\IceLuaC"),//IceLuaC is the name of the lua c pipe
		PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
		PIPE_UNLIMITED_INSTANCES,
		999999,
		999999,
		NMPWAIT_USE_DEFAULT_WAIT,
		NULL);
	while (hPipe != INVALID_HANDLE_VALUE)
	{
		if (ConnectNamedPipe(hPipe, NULL) != FALSE)
		{
			while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE)
			{
				buffer[dwRead] = '\0';
				try {
					if (strlen(buffer) != NULL) {
						std::istringstream meme(buffer);
						std::string line;
						while (std::getline(meme, line))
							LuaCExecute(line);
					}
				}
				catch (std::exception e) {
					IceMemebox(e.what());
				}
				catch (...) {
					IceMemebox("An Unhandled Error Has Occured!");
				}
			}
		}
		DisconnectNamedPipe(hPipe);
	}
}
//Lua pipe
DWORD WINAPI LuaPipe(PVOID lvpParameter)
{
	HANDLE hPipe;
	char buffer[999999];
	DWORD dwRead;
	hPipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\MemeLua"),//MemeLua is the name of the lua pipe
		PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
		PIPE_UNLIMITED_INSTANCES,
		999999,
		999999,
		NMPWAIT_USE_DEFAULT_WAIT,
		NULL);
	while (hPipe != INVALID_HANDLE_VALUE)
	{
		if (ConnectNamedPipe(hPipe, NULL) != FALSE)
		{
			while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE)
			{
				buffer[dwRead] = '\0';
				try {
					if (strlen(buffer) != NULL) {
						Exe(buffer);
					}
				}
				catch (std::exception e) {
					IceMemebox(e.what());
				}
				catch (...) {
					IceMemebox("An Unhandled Error Has Occured!");
				}
			}
		}
		DisconnectNamedPipe(hPipe);
	}
}