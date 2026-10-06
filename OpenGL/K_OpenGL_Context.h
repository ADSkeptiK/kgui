#include "../K_Renderer_Context.h"

#ifndef K_OPENGLCONTEXT_H
#define K_OPENGLCONTEXT_H

//A temporary way of setting the version,,, get to learn it later.
//Automates a custom array for creating your openGL version
#define K_OPENGL_CREATE_VERSION_AR(AR,MAJORVERSION,MINORVERSION) int AR[] ={WGL_CONTEXT_MAJOR_VERSION_ARB,MAJORVERSION,\
WGL_CONTEXT_MINOR_VERSION_ARB,MINORVERSION,WGL_CONTEXT_PROFILE_MASK_ARB,WGL_CONTEXT_CORE_PROFILE_BIT_ARB,0}
//The OpenGL Renderer Abstraction
//The Constructor DOES invoke contextsetting in it
//
class K_OpenGL_Context  : public K_Renderer_Context
{
public:
    //implements
    //using K_Renderer_Context::K_Renderer_Context;
    K_OpenGL_Context(K_WindowPtr windowAddress,int mainVersion,int subVersion);
    //Sets classic OpenGL context, choosing a default preferred version
    void   contextsetting(void)override;

    void setOpenGLVersion(const int majorversion, const int subversion);
    //virtual void chooseGLversion();
	//void setFormat(PPIXELFORMATDESCRIPTOR pixelFormatStructure);
protected:
	//A pixel format descriptor
};
#endif // !



