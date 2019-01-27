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

EnduranceEngine enduranceEngine = EnduranceEngine();

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	enduranceEngine.Initialize();
	enduranceEngine.Start(hInstance, hPrevInstance, lpCmdLine, nCmdShow);

	return 0;
}