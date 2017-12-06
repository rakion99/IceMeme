#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "wininet")

#pragma once

#include "stdafx.h"
#include "SkId5.h"
#include "Skid6.h"
#include "SkId4.h"
#include "SkId3.h"
#include "SkId2.h"
#include "SkId1.h"

using namespace std;
//Command pipe
DWORD WINAPI SkidPipe(PVOID lvpParameter)
{
	//Pipe handle
	HANDLE hSkid;
	//Bytes to write to
	char SkIdEr[1024];
	//How many bytes were read
	DWORD SkIdRead;
	//Create the pipe
	hSkid = CreateNamedPipe(TEXT("\\\\.\\pipe\\IceSkidCmd"),//IceSkidCmd is the name of the command pipe
		PIPE_ACCESS_DUPLEX | PIPE_TYPE_BYTE | PIPE_READMODE_BYTE,
		PIPE_WAIT,
		1,
		1024 * 16,
		1024 * 16,
		NMPWAIT_USE_DEFAULT_WAIT,
		NULL);
	//While the pipe is open, accept requests
	while (hSkid != INVALID_HANDLE_VALUE)
	{
		//Await a connection
		if (ConnectNamedPipe(hSkid, NULL) != FALSE)
		{
			//Read input
			while (ReadFile(hSkid, SkIdEr, sizeof(SkIdEr) - 1, &SkIdRead, NULL) != FALSE)
			{
				SkIdEr[SkIdRead] = '\0';
				try {
					//Attempt to execute the command
					ExecuteSkId(SkIdEr);
				}
				catch (std::exception e) {
					//Catch known errors
					MessageBox(NULL, e.what(), "SKID ICE - Uh Oh", MB_OK);
				}
				catch (...) {
					//Catch unknown errors
					MessageBox(NULL, "An Unhandled Error Has Occured!", "SKID ICE- Uh Oh", MB_OK);
					cout << "ERROR: An Unexpected Error Has Occured!" << endl;
				}
			}
		}
		//Disconnect the client once we are done
		DisconnectNamedPipe(hSkid);
	}
}
//Lua C pipe
DWORD WINAPI SkidCPipe(PVOID lvpParameter)
{
	//Pipe handle
	HANDLE hSkid;
	//Bytes to write to
	char SkIdEr[1024];
	//How many bytes were read
	DWORD SkIdRead;
	//Create the pipe
	hSkid = CreateNamedPipe(TEXT("\\\\.\\pipe\\IceSkidC"),//IceSkidCmd is the name of the command pipe
		PIPE_ACCESS_DUPLEX | PIPE_TYPE_BYTE | PIPE_READMODE_BYTE,
		PIPE_WAIT,
		1,
		1024 * 16,
		1024 * 16,
		NMPWAIT_USE_DEFAULT_WAIT,
		NULL);
	//While the pipe is open, accept requests
	while (hSkid != INVALID_HANDLE_VALUE)
	{
		//Await a connection
		if (ConnectNamedPipe(hSkid, NULL) != FALSE)
		{
			//Read input
			while (ReadFile(hSkid, SkIdEr, sizeof(SkIdEr) - 1, &SkIdRead, NULL) != FALSE)
			{
				SkIdEr[SkIdRead] = '\0';
				try {
					//Attempt to execute the command
					ExecuteSkId(SkIdEr);
				}
				catch (std::exception e) {
					//Catch known errors
					MessageBox(NULL, e.what(), "SKID ICE - Uh Oh", MB_OK);
				}
				catch (...) {
					//Catch unknown errors
					MessageBox(NULL, "An Unhandled Error Has Occured!", "SKID ICE- Uh Oh", MB_OK);
					cout << "ERROR: An Unexpected Error Has Occured!" << endl;
				}
			}
		}
		//Disconnect the client once we are done
		DisconnectNamedPipe(hSkid);
	}
}

int SKid() {
	//Create the pipes
	CreateThread(NULL, 0, SkidPipe, NULL, 0, NULL);//Command pipe
	CreateThread(NULL, 0, SkidCPipe, NULL, 0, NULL);//Lua c pipe
	//Auth(); //uncomment this function to enable the whitelist
	//Scan lua state
	SKID();
	//Announce the finishing of the scan
	MessageBox(NULL, "Ice for SKIDS has loaded Correctly!\nSKID now you can use Ice!\nUpdated and improved by rakion99\nIce Made by Josh()", "Ice-Skid Version", MB_OK | MB_TOPMOST);//Messagebox so we can know when scan finished
	return 0;
}
