#pragma once
HWND MainWindowHWND;
HMENU hMenu;
HMENU hMenuPopupFile;
HMENU hMenuPopupAbout;
HMODULE hInstance;
HWND ScriptTextBoxHWND;
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

#define JOINBTN (WM_APP + 200)
#define ACCEPTBTN (WM_APP + 201)
#define EXITBTN (WM_APP + 202)

LRESULT CALLBACK DLLWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect = { 20, 20, 450, 350 };
	/*2 lazy to make a better message credits*/
	std::string credits1 = "Credits:\nrakion99\nRoblox\nAfricaus for pcall bypass\nVOID for getobjects\ntepig for Memehax\n";
	std::string credits2 = "DOGGO bypass/workaround for setting values on non-fe games\nEternal for RetCheck\nAutisticBobby\nPowered by Lua\nPowered by cURL\nICE By: Josh() and Cosmology";
	std::string credits3 = "\nThis Exploit is FREE if you paid for this ask for a refund!!!\nClick ACCEPT to share this to public in the discord:\nIP, Country, Roblox Username and ScreenShot\nClick EXIT to refuse and exit";
	std::string MsgCredits = credits1 + credits2 + credits3;

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		DrawText(hdc, MsgCredits.c_str(), _tcslen(MsgCredits.c_str()), &rect, DT_CENTER);

		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_COMMAND:
		switch (wParam)
		{
		case JOINBTN:
			ShellExecute(NULL, "open", "http://discord.gg/K2A2Xhv", NULL, NULL, SW_HIDE);//here the url to ur discord invite or whatever
			break;
		case ACCEPTBTN:
			ScanScriptContext();
			UglyToolBar();
			postmain();
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)op2stuff, NULL, NULL, NULL);
			SendMessage(hwnd, WM_CLOSE, 0, 0);
			break;
		case EXITBTN:
			exit(0);
			break;
		default:
			break;
		}
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
		break;
	}

	return 0;
}

BOOL RegisterDLLWindowClass(char *szClassName)
{
	WNDCLASSEX wc;
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpszClassName = szClassName;
	wc.lpfnWndProc = DLLWindowProc;
	wc.style = CS_DBLCLKS;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszMenuName = "";
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	if (!RegisterClassEx(&wc))
		return 0;
	return 1;
}

void CreateFWindows()
{
	CreateWindow(
		"BUTTON",  // Predefined class; Unicode assumed
		"Join Discord",        // Text will be defined later
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
		60,        // x position 
		350,         // y position 
		100,        // Button width
		50,        // Button height
		MainWindowHWND,     // Parent window
		(HMENU)JOINBTN,       // No menu
		(HINSTANCE)GetWindowLong(MainWindowHWND, GWL_HINSTANCE),
		NULL);      // Pointer not needed

	CreateWindow(
		"BUTTON",  // Predefined class; Unicode assumed
		"ACCEPT",        // Text will be defined later
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
		210,        // x position 
		350,         // y position 
		100,        // Button width
		50,        // Button height
		MainWindowHWND,     // Parent window
		(HMENU)ACCEPTBTN,       // No menu
		(HINSTANCE)GetWindowLong(MainWindowHWND, GWL_HINSTANCE),
		NULL);      // Pointer not needed

	CreateWindow(
		"BUTTON",  // Predefined class; Unicode assumed
		"EXIT",        // Text will be defined later
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
		360,        // x position 
		350,         // y position 
		100,        // Button width
		50,        // Button height
		MainWindowHWND,     // Parent window
		(HMENU)EXITBTN,       // No menu
		(HINSTANCE)GetWindowLong(MainWindowHWND, GWL_HINSTANCE),
		NULL);      // Pointer not needed
}

void ShowForm()
{
	hInstance = GetModuleHandle(NULL);
	RegisterDLLWindowClass("DLLWindowClass");
	MainWindowHWND = CreateWindowEx(WS_EX_TOPMOST,
		"DLLWindowClass",
		"Powered by ICEMEME G.D.P.R Compliance",
		WS_EX_TOOLWINDOW, 
		GetSystemMetrics(SM_CXSCREEN)/3, GetSystemMetrics(SM_CYSCREEN)/3,
		500, 440, 
		NULL,
		hMenu,
		hInstance,
		NULL);
	CreateFWindows();
	ShowWindow(MainWindowHWND, SW_SHOWNORMAL);

	MSG messages;
	while (GetMessage(&messages, NULL, 0, 0))
	{
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}
}