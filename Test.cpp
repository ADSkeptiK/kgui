#include <windows.h>
#include <stdio.h>
#include "k_resource.h"
#include "K_RendererWindow.h"

#ifndef ENTRY
#define ENTRY int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,\
    PSTR szCmdLine, int iCmdShow) \
{
#endif
#ifndef END
#define END }
#endif

// Okay so I unfucked the K_Renderer_Context and OpenGL side of the things to a noticable extent It's kinda
// coming together gotta implement a new member function for the "Modern way" of
// creating the context and then create an  object of that in the  custom window class as composition
//HALT

//Unfuck the K_Window






//Left mid implementing the RendererWindow we could either implement OpengGL
// as a virtual of KWindow or as a part of the render loop the choice is yours...
//



//Entry point
ENTRY

RendererWindow renderer = { iCmdShow,hInstance,TEXT("Window Class Name"),TEXT("[YOUR WINDOW TITLE]") };
renderer.initiate();

 END
 
        /*
        We left off at the Custom Class you were considering:
        1- Adding some functions to the Window class
        2- Changing the existing class into a one called RendererWindow 
        3- Adding a new class  called renderer window 
        and figuring out where to define virtuals to mandate the user to
        create an inheriting class and define the virtuals.
        
        */


/*
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szWindowClassName[] = TEXT("yo");
    HWND         hwnd;
    MSG          msg;
    WNDCLASS     wndclass;
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(ID_KLIFF_TEST));
    wndclass.hCursor = LoadCursor(NULL, IDC_CROSS);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szWindowClassName;
    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("This program requires Windows NT!"),
            szWindowClassName, MB_ICONERROR);
        return 0;
    }
    hwnd = CreateWindow(szWindowClassName,                  // window class name
        TEXT("Genesis Engine"), // window caption
        WS_OVERLAPPEDWINDOW,        // window style
        CW_USEDEFAULT,              // initial x position
        CW_USEDEFAULT,              // initial y position
        CW_USEDEFAULT,              // initial x size
        CW_USEDEFAULT,              // initial y size
        NULL,                       // parent window handle
        NULL,                       // window menu handle
        hInstance,                  // program instance handle
        NULL);                     // creation parameters
    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC         hdc;
    PAINTSTRUCT ps;
    RECT        rect;
    switch (message)
    {
    case WM_CREATE:
        PlaySound(TEXT("hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC);
        return 0;
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);
    
            DrawText(hdc, TEXT("TEXT"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
            EndPaint(hwnd, &ps);
            return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}

*/
















/*
CustomWindow window{ iCmdShow,hInstance,(PCTSTR)TEXT("MainWindow"),(PCTSTR)TEXT("Genesis Engine") };
    window.setWinProc();
    window.setIcon((LPCTSTR)ID_KLIFF_TEST);
    window.setCursor(IDC_CROSS);
    window.regClass();
    window.createWindow();
    window.firstRender();
    K_OpenGL_Context ogl_renderer{ &window };
    window.enterLoop();
    */










/*
int CDECL MessageBoxPrintf(TCHAR* szCaption, TCHAR* szFormat, ...)
{
    TCHAR   szBuffer[1024];
    va_list pArgList;
    // The va_start macro (defined in STDARG.H) is usually equivalent to:
    // pArgList = (char *) &szFormat + sizeof (szFormat) ;
    va_start(pArgList, szFormat);
    // The last argument to wvsprintf points to the arguments
    _vsntprintf(szBuffer, sizeof(szBuffer) / sizeof(TCHAR),
        szFormat, pArgList);
    // The va_end macro just zeroes out pArgList for no good reason
    va_end(pArgList);
    return MessageBox(NULL, szBuffer, szCaption, 0);
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR szCmdLine, int iCmdShow)
{
    int cxScreen, cyScreen;
    cxScreen = GetSystemMetrics(0);
    cyScreen = GetSystemMetrics(1);
    MessageBoxPrintf(TEXT("ScrnSize"),
        TEXT("The screen is %i pixels wide by %i pixels high."),
        cxScreen, cyScreen);
    return 0;
}

*/