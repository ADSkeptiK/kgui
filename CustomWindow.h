#pragma once
#include "K_Window.h"
//Shouldn't give error
enum class windowState {DEAD,WAITING,ACTIVE,UNSELECTED};
class CustomWindow :
	public K_Window
{
public:

	CustomWindow(int iCmdShow, HINSTANCE hInstance, PCTSTR TemplateName,
		PCTSTR windowTitle, WNDPROC wProcedure, DWORD type = CS_OWNDC, const int style = 3,
		int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, int size_x = CW_USEDEFAULT,
		int size_y = CW_USEDEFAULT, HWND parentHandleP = NULL, HMENU menuHandle = NULL, LPVOID param = NULL);
	LPARAM enterLoop(void) override;
	virtual void userfunction(void)=0;
protected:
	windowState windowLoopState = windowState::WAITING;

//	CustomWindow* abstractcall = this;

};

