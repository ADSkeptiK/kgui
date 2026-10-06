#include "CustomWindow.h"
#include "OpenGL/CustomOpenGLContext.h"
#ifndef K_RENDERER_WINDOW
#define K_RENDERER_WINDOW

//forward declaration
class K_Renderer_Context;
typedef K_Renderer_Context* RendererPtr;
class CustomOpenGLContext;
class RendererWindow :
    public CustomWindow
{
public:
    RendererWindow(int iCmdShow, HINSTANCE hInstance, PCTSTR TemplateName,
        PCTSTR windowTitle, WNDPROC wProcedure= RendererWindow::windowProc, DWORD type = WS_OVERLAPPEDWINDOW | CS_OWNDC, const int style = 3,
        int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, int size_x = CW_USEDEFAULT,
        int size_y = CW_USEDEFAULT, HWND parentHandleP = NULL, HMENU menuHandle = NULL, LPVOID param = NULL);
    void userfunction(void) override;
    void initiate(void);
protected:
    RendererPtr current_renderer;
    CustomOpenGLContext OpenGLRenderer;
    GraphicsAPIs chosen_API = GraphicsAPIs::OpenGL;
private:
    //Window Proc (MUST be static)
    static LRESULT CALLBACK windowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);



    //DX context to be implemented
};

#endif // !K_RENDERER_WINDOW