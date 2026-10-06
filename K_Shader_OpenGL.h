#pragma once
//Shouldn't give error
#include "K_Shader.h"
class K_Shader_OpenGL
{
public:
    void openGLShaderDirSet(const TCHAR directory[]);
private:
    TCHAR current_directory[MAX_PATH];
};

