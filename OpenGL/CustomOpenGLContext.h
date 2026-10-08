#pragma once
//This entire header is merely for test
#include "K_OpenGL_Context.h"
#include <string>


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

