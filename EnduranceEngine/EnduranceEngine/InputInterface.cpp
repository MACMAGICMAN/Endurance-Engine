#include "InputInterface.h"

InputInterface::InputInterface()
{
	/*class IKeyboardHandler {
		virtual bool VOnKeyDown(unsigned int const kcode) = 0;
		virtual bool VOnKeyUp(unsigned int const kcode) = 0;
	};*/
}


InputInterface::~InputInterface()
{

}

void InputInterface::GetInput(UINT uMsg, EventHandler eventHandler, LPARAM lParam) {
	switch (uMsg) {
	case WM_KEYDOWN:
		eventHandler.HandleKeyInputEvent(lParam);
		break;
	case WM_LBUTTONDOWN:
		eventHandler.HandleMouseInputEvent(0);
		break;
	case WM_RBUTTONDOWN:
		eventHandler.HandleMouseInputEvent(1);
		break;
	case WM_MBUTTONDOWN:
		eventHandler.HandleMouseInputEvent(2);
		break;
	}
}