#include "K_Shader_OpenGL.h"
//Shouldn't give error
#include <tchar.h>
void K_Shader_OpenGL::openGLShaderDirSet(const TCHAR directory[])
{
	_tcscpy_s(current_directory, MAX_PATH, TEXT("shaders/OpenGL"));
}
