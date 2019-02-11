#pragma once
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include "EventHandler.h"

class InputInterface
{
public:
	InputInterface();
	void GetInput(UINT uMsg, EventHandler eventHandler, LPARAM lParam);
	~InputInterface();
};