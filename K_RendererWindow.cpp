#include "K_RendererWindow.h"

RendererWindow::RendererWindow(int iCmdShow, HINSTANCE hInstance, PCTSTR TemplateName,
  PCTSTR windowTitle, WNDPROC wProcedure,DWORD type,
  const int style, int x, int y, int size_x, int size_y, HWND parentHandleP,
  HMENU menuHandle, LPVOID param):
CustomWindow(iCmdShow,
    hInstance, TemplateName, windowTitle, wProcedure, type,
    style, x, y, size_x, size_y, parentHandleP, menuHandle, param),OpenGLRenderer{this,4,5}
{
    current_renderer = &OpenGLRenderer;
}
void RendererWindow::userfunction(void)
{

    BOOL windowstatus = GetMessage(&message, NULL, 0, 0);
    TranslateMessage(&message);
    DispatchMessage(&message);
    if (windowstatus)
    {
        
        current_renderer->renderW();
    }
    else
    {
        windowLoopState = windowState::DEAD;
    }
}
void RendererWindow::initiate(void)
{
    enterLoop();
}

LRESULT RendererWindow::windowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC         hdc;
    PAINTSTRUCT ps;
    RECT        rect;
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 1;

    case WM_CLOSE:
        DestroyWindow(hwnd);
        return 1;
       
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}







