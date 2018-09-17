#include <windows.h> 
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
#include <string>

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;



int main() {

	CreateMutex(NULL, TRUE, "MyMutex");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{

		cout << "Stup";
		system("pause");
		return FALSE;


	}

	cout << "asda";
	system("pause");

}
