#pragma once
#include "K_OpenGL_Context.h"
#include <string>
//Shouldn't give error

//Should be implemented by graphics programmer
class CustomOpenGLContext :
    public K_OpenGL_Context
{
public:
    using K_OpenGL_Context::K_OpenGL_Context;
    //void chooseGLversion(std::string);
    void renderW(void) override;
   
private:
 
};

