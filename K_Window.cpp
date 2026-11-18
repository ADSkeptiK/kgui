#include "K_Window.h"

#include <tchar.h>
#include <string.h>
//Shouldn't give error
K_Window::K_Window(int iCmdShow, HINSTANCE hInstance, PCTSTR TemplateName,
	PCTSTR windowTitle, WNDPROC wProcedure, DWORD type, const int style,
	int x, int y, int size_x,
	int size_y, HWND parentHandleP, HMENU menuHandle, LPVOID param) : szWindowClassName{ TemplateName }
	, parentHandle{ parentHandleP }, windowMenuHandle{ menuHandle }, creationParameters{ param }, dwStyle{ type }, x{ x }, y{ y }, size_x{ size_x }, size_y{ size_y }
{

	this->icmdshow = iCmdShow;
	//Do the initializations
	windowStructure.hInstance = hInstance;
	windowStructure.lpszClassName = TemplateName;
	windowStructure.style = style;
	this->windowTitle = windowTitle;
	windowStructure.cbClsExtra = 0;
	windowStructure.cbWndExtra = 0;
	windowStructure.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	windowStructure.lpszMenuName = NULL;
	windowStructure.lpfnWndProc = wProcedure;


}
void K_Window::setIcon(LPCTSTR iconId)
{
	windowStructure.hIcon=LoadIcon(windowStructure.hInstance , MAKEINTRESOURCE(iconId));
}
void K_Window::setCursor(LPCTSTR iconId)
{
	windowStructure.hCursor=LoadCursor(NULL, MAKEINTRESOURCE(iconId));
}
void K_Window::setExtraByteForClass(const int count)
{
	windowStructure.cbClsExtra = count;
}
void K_Window::setExtraByteForWindow(const int count)
{
	windowStructure.cbWndExtra = count;

}
void K_Window::setBackgroundStock(const int color)
{
	windowStructure.hbrBackground=(HBRUSH)GetStockObject(color);
}
void K_Window::setMenuName(LPCTSTR menu)
{
	windowStructure.lpszMenuName = menu;
}
void K_Window::regClass(void)
{
	//Register
	if (!RegisterClass(&windowStructure))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"),
			szWindowClassName, MB_ICONERROR);
	}

}
void K_Window::setRenderingStyle(DWORD window_type)
{
	dwStyle = window_type;
}
/*
void K_Window::setWindowName(LPCTSTR name)
{
	windowTitle = name;
}
*/
void K_Window::setWindowInX(int x)
{
	this->x = x;
}
void K_Window::setWindowInY(int y)
{
	this->y = y;

}
void K_Window::setWindowInSizeX(int size_x)
{
	this->size_x = size_x;
}
void K_Window::setWindowInSizeY(int size_y)
{
	this->size_y = size_y;
}
void K_Window::setParentWindowHandle(HWND parentHandle)
{
	this->parentHandle = parentHandle;
}
void K_Window::setWindowMenuHandle(HMENU menu_Handle)
{
	windowMenuHandle = menu_Handle;
}
void K_Window::setIcmdShow(int icmdShow)
{
	this->icmdshow = icmdShow;
}
void K_Window::createWindow(void)
{
	windowHandle=CreateWindow(szWindowClassName, windowTitle, dwStyle, x, y, size_x, size_y, parentHandle, windowMenuHandle, (windowStructure.hInstance), creationParameters);

}
void K_Window::showWindow(void)
{
	ShowWindow(windowHandle, this->icmdshow);
}
void K_Window::firstRender(void)
{
	ShowWindow(windowHandle, this->icmdshow);
	UpdateWindow(windowHandle);
}
HWND K_Window::getWindowHandle(void)
{
	return HWND((*this).windowHandle);
}
MSG* K_Window::getterMessage(void)
{
	return &message;
	// TODO: insert return statement here
}
WNDPROC* K_Window::getterWindowProc(void)
{
	return &windowStructure.lpfnWndProc;
}
void K_Window::initialization(void)
{
	// do nothing
}
/*LPARAM K_Window::enterLoop(void) {
	while (GetMessage(getterMessage(), NULL, 0, 0))
	{

		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return message.lParam;

}
*/
