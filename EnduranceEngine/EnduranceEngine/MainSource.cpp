#include <windows.h>
#include "EnduranceEngine.h"

using namespace std;

EnduranceEngine enduranceEngine = EnduranceEngine();

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	enduranceEngine.Initialize();
	enduranceEngine.Start();	

	return 0;
}