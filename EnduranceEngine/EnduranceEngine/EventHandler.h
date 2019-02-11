#pragma once
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

class EventHandler {
public:
	EventHandler();
	void HandleKeyInputEvent(LPARAM lParam);
	void HandleMouseInputEvent(int mouseButton);
	~EventHandler();
};