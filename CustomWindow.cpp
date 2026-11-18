#include "CustomWindow.h"
//#include "k_resource.h"
//Shouldn't give error


CustomizableWindow::CustomizableWindow(int iCmdShow, HINSTANCE hInstance,
PCTSTR TemplateName, PCTSTR windowTitle,WNDPROC wProcedure,
DWORD type, const int style, int x, int y, int size_x, int size_y,
HWND parentHandleP, HMENU menuHandle,LPVOID param) :K_Window( iCmdShow,
hInstance,TemplateName,windowTitle,wProcedure,type,
style, x, y, size_x,size_y,parentHandleP,menuHandle,param)
{
	//setIcon((LPCTSTR)ID_KLIFF_TEST);
	setCursor(IDC_CROSS);
	regClass();
	createWindow();
	showWindow();
	//Just run  the constructor with the right arguments
}
LPARAM CustomizableWindow::enterLoop(void)
{
	firstRender();
	startup();
	while (windowLoopState!=windowState::DEAD)
	{
		userfunction();
	}
	return message.wParam;
}

void CustomizableWindow::startup(void)
{
	//Empty default virtual
}

/*void CustomizableWindow::setUserfunction(EVALUATOR function)
{
	userfunction = function;
}
*/

/*LPARAM CustomizableWindow::enterLoop(void)
{
	
}
*/


