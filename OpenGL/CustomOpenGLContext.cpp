#include "CustomOpenGLContext.h"
//Shouldn't give error
#include <gl/GL.h>
void CustomOpenGLContext::renderW(void)
{
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	SwapBuffers(deviceContextHandle);
}


