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

#include "InputInterface.h"
#include "EventHandler.h"
#include "EnduranceEngine.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

InputInterface inputInterface = InputInterface();
EventHandler eventHandler = EventHandler();
EnduranceEngine enduranceEngine = EnduranceEngine();


static TCHAR szWindowClass[] = _T("win32app");
static TCHAR szTitle[] = _T("Win32 Guided Tour Application");
HINSTANCE hInst;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {

	//WNDCLASSEX wcex;

	enduranceEngine.Initialize();
	enduranceEngine.Start(hInstance, hPrevInstance, lpCmdLine, nCmdShow);

	/*wcex.cbSize = sizeof(WNDCLASSEX);
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

	return (int)msg.wParam;*/

	

	return 0;

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