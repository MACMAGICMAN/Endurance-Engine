#include <windows.h> 
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
#include <string>
#include <stdio.h>  
#include <direct.h>  
#include <stdlib.h>  
#include <ctype.h>  

#include <windows.h>
#include <tchar.h>

#include "EnduranceEngine.h"
#include "InputInterface.h"
#include "EventHandler.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

InputInterface inputInterface = InputInterface();
EventHandler eventHandler = EventHandler();

EnduranceEngine::EnduranceEngine()
{

}
EnduranceEngine::~EnduranceEngine()
{

}

bool CheckInstance()
{

	CreateMutex(NULL, TRUE, "MyMutex");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{

		cout << "An instance is already running!" << endl;
		system("pause");
		exit(0);
		return false;


	}

	cout << "No other instances are running." << endl;
	return true;
}

bool CheckStorage(const DWORDLONG diskSpaceNeeded)
{
	int const drive = _getdrive();
	struct _diskfree_t diskfree;

	_getdiskfree(drive, &diskfree);

	unsigned __int64 const neededClusters = diskSpaceNeeded / (diskfree.sectors_per_cluster*diskfree.bytes_per_sector);

	if (diskfree.avail_clusters < neededClusters)
	{
		cout << "You don't have enough disk space!" << endl;
		system("pause");
		exit(0);
		return false;

	}
	cout << "You have enough space." << endl;
	return true;
}

bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded) {
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);
	if (status.ullTotalPhys < physicalRAMNeeded) {

		cout << ("CheckMemory Failure: Not enough physical memory.");
		system("pause");
		exit(0);
		return false;
	}

	if (status.ullAvailVirtual < virtualRAMNeeded) {

		cout << ("CheckMemory Failure: Not enough virtual memory.");
		system("pause");
		exit(0);
		return false;
	}
	char *buff = new char[virtualRAMNeeded];
	if (buff)
		delete[] buff;

	cout << "Ram is available." << endl;
	cout << "You have this much RAM: " << status.ullTotalPhys << endl;
	cout << "You have this much vRAM: " << status.ullAvailVirtual << endl;
	return true;
}

DWORD ReadCPUSpeed() {
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz;
	DWORD type = REG_DWORD;
	HKEY hKey;
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
		0,
		KEY_READ,
		&hKey);
	if (lError == ERROR_SUCCESS) {
		RegQueryValueEx(hKey,
			"MHz",
			NULL,
			&type,
			(LPBYTE)&dwMHz,
			&BufSize);

	}
	cout << "CPU in Hertz: " << dwMHz << endl;
	system("pause");
	return dwMHz;
}

void EnduranceEngine::Initialize()
{
	CheckInstance();
	CheckStorage(300 * 1024 * 1024);
	CheckMemory(69, 420);
	ReadCPUSpeed();
}

static TCHAR szWindowClass[] = _T("win32app");
static TCHAR szTitle[] = _T("Win32 Guided Tour Application");
HINSTANCE hInst;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int EnduranceEngine::Start(_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	hInst = hInstance;

	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		1024, 768,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
	}

	return (int)msg.wParam;
}

const int Size = 200;
TCHAR greeting[Size] = _T("");
LRESULT CALLBACK WndProc(_In_ HWND hWnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;
	LPSTR tempString = new char[1];

	inputInterface.GetInput(uMsg, eventHandler, lParam);

	switch (uMsg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 5, 5, greeting, _tcslen(greeting));
		EndPaint(hWnd, &ps);
		break;

		///LAB 5 SUBMISSION
		/*case WM_KEYDOWN:
			GetKeyNameText(lParam, tempString, 2);
			_tcscat_s(greeting, Size, TEXT(tempString));
			_tcscat_s(greeting, Size, TEXT(" "));
			break;
		case WM_LBUTTONDOWN:
			_tcscat_s(greeting, Size, TEXT("LEFT MOUSE BUTTON "));
			break;
		case WM_RBUTTONDOWN:
			_tcscat_s(greeting, Size, TEXT("RIGHT MOUSE BUTTON "));
			break;
		case WM_MBUTTONDOWN:
			_tcscat_s(greeting, Size, TEXT("MIDDLE MOUSE BUTTON "));
			break;*/
			///LAB 5 SUBMISSION

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}

	return 0;
}