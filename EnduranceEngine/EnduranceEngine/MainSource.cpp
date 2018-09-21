#include <windows.h> 
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
#include <string>
#include <stdio.h>  
#include <direct.h>  
#include <stdlib.h>  
#include <ctype.h>  

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

bool CheckStorage(const DWORDLONG diskSpaceNeeded)
{
	int const drive = _getdrive();
	struct _diskfree_t diskfree;

	_getdiskfree(drive, &diskfree);

	unsigned __int64 const neededClusters = diskSpaceNeeded / (diskfree.sectors_per_cluster*diskfree.bytes_per_sector);

	if (diskfree.avail_clusters < neededClusters)
	{
		cout << "check";
		return false;

	}
	return true;
}

