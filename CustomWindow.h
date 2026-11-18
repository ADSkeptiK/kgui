#pragma once
#include "K_Window.h"
//Shouldn't give error
#ifdef K_CUSTOMWINDOW_DEV
#define K_CUSTOMWINDOW_API __declspec(dllexport)
#else
#define K_CUSTOMWINDOW_API __declspec(dllimport)
#endif // K_LOGSYSTEM_API


enum class windowState {DEAD,WAITING,ACTIVE,UNSELECTED};
class  K_CUSTOMWINDOW_API CustomizableWindow : public K_Window
{
public:

	CustomizableWindow(int iCmdShow, HINSTANCE hInstance, PCTSTR TemplateName,
		PCTSTR windowTitle, WNDPROC wProcedure, DWORD type = CS_OWNDC, const int style = 3,
		int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, int size_x = CW_USEDEFAULT,
		int size_y = CW_USEDEFAULT, HWND parentHandleP = NULL, HMENU menuHandle = NULL, LPVOID param = NULL);
	LPARAM enterLoop(void) override;
	virtual void startup(void);
	virtual void userfunction(void)=0;
	windowState windowLoopState = windowState::WAITING;
protected:


//	CustomizableWindow* abstractcall = this;

};

