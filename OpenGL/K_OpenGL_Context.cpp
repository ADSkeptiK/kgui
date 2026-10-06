#include "K_OpenGL_Context.h"
#include <gl/GL.h>
#include <gl/wglext.h>
//Shouldn't give error
K_OpenGL_Context::K_OpenGL_Context(K_WindowPtr windowAddress, int mainVersion, int subVersion) :K_Renderer_Context(windowAddress)
{
	contextsetting();
    setOpenGLVersion(mainVersion, subVersion);
}

void K_OpenGL_Context::contextsetting(void)
{
    PIXELFORMATDESCRIPTOR temppixelFormatStructure = {
    sizeof(PIXELFORMATDESCRIPTOR),   // size of this pfd  
    1,                     // version number  
    PFD_DRAW_TO_WINDOW |   // support window  
    PFD_SUPPORT_OPENGL |   // support OpenGL  
    PFD_DOUBLEBUFFER,      // double buffered  
    PFD_TYPE_RGBA,         // RGBA type  
    24,                    // 24-bit color depth  
    0, 0, 0, 0, 0, 0,      // color bits ignored  
    0,                     // no alpha buffer  
    0,                     // shift bit ignored  
    0,                     // no accumulation buffer  
    0, 0, 0, 0,            // accum bits ignored  
    32,                    // 32-bit z-buffer  
    0,                     // no stencil buffer  
    0,                     // no auxiliary buffer  
    PFD_MAIN_PLANE,        // main layer  
    0,                     // reserved  
    0, 0, 0                // layer masks ignored  
    };
    pixelFormatStructure = temppixelFormatStructure;
	int iPixelFormat = ChoosePixelFormat(deviceContextHandle, &pixelFormatStructure);
	SetPixelFormat(deviceContextHandle, iPixelFormat, &pixelFormatStructure);
	renderingContext = wglCreateContext(deviceContextHandle);
	wglMakeCurrent(deviceContextHandle, renderingContext);
    
}
void K_OpenGL_Context::setOpenGLVersion(const int majorversion, const int subversion)
{
    //Version
    K_OPENGL_CREATE_VERSION_AR(versionarray, majorversion, subversion);
    const  PFNWGLCREATECONTEXTATTRIBSARBPROC functionLoc= (PFNWGLCREATECONTEXTATTRIBSARBPROC) wglGetProcAddress("wglCreateContextAttribsARB");
    if (!functionLoc)
        MessageBoxA(nullptr, "Context Not found nigga", "OpenGL Version", MB_OK);
    
    HGLRC newContext = functionLoc(deviceContextHandle, nullptr, versionarray);
    if (newContext)
    {
        wglMakeCurrent(deviceContextHandle, newContext);
        wglDeleteContext(renderingContext);
        renderingContext = newContext;
        const GLubyte* version = glGetString(GL_VERSION);
        MessageBoxA(nullptr, reinterpret_cast<const char*>(version), "OpenGL Version", MB_OK);
    }
    else
    {
        DWORD error = GetLastError();
        MessageBoxA(nullptr, "Context Not found nigga", "OpenGL Version", MB_OK);
    }
    }
/*



*/
