#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "wininet")

#pragma once

#include "stdafx.h"
#include "lua.hpp"
#include "HTTPDownloader.h"
#include "Scanners.h"
#include "Address.h"
#include "RobloxStuff.h"
#include "SSC.h"
#include "Functions.h"
#include "Commands.h"
#include "Meme.h"
#include "Pipes.h"
#include "op.h"
#include "op2.h"
#include "Message.h"

int Main() {
	CreateThread(NULL, 0, CmdPipe, NULL, 0, NULL);
	CreateThread(NULL, 0, LuaCPipe, NULL, 0, NULL);
	CreateThread(NULL, 0, LuaPipe, NULL, 0, NULL);

	ShowForm();//duh if you dont know what this do you need to delete all sources you downloaded....

	return 0;
}