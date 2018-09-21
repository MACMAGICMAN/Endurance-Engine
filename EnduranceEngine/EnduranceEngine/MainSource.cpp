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

bool CheckInstance()
{

	CreateMutex(NULL, TRUE, "MyMutex");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{

		cout << "An instance is already running!" << endl;
		system("pause");
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
		return false;
	}

	if (status.ullAvailVirtual < virtualRAMNeeded) {

		cout << ("CheckMemory Failure: Not enough virtual memory.");
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


int main() {

	CheckInstance();

	CheckStorage(300 * 1024 * 1024);

	CheckMemory(69, 420);

	ReadCPUSpeed();

	return 0;
}