#include "EventHandler.h"

EventHandler::EventHandler() {

}

void EventHandler::HandleKeyInputEvent(LPARAM lParam) {
	LPSTR tempString = new char[1];
	GetKeyNameText(lParam, tempString, 10);
	OutputDebugString(tempString);
	OutputDebugString("\n");
}

void EventHandler::HandleMouseInputEvent(int mouseButton) {
	switch (mouseButton) {
	case 0:
		OutputDebugString("LEFT MOUSE BUTTON");
		break;
	case 1:
		OutputDebugString("RIGHT MOUSE BUTTON");
		break;
	case 2:
		OutputDebugString("MIDDLE MOUSE BUTTON");
		break;
	}
}

EventHandler::~EventHandler() {

}