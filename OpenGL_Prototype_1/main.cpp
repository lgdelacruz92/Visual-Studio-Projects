// OpenGL_Prototype_1.cpp : Defines the entry point for the console application.
//

#include <Windows.h>
#include <iostream>
#include "Display.h"
#include "Shaders.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    Display display(400, 400, "Hello world!");
    Shader shader("./basicShader");
    while (!display.isClosed())
    {
        display.Clear(0.0f, 0.0f, 0.3f, 1.0f);
        display.Update();
    }
    return 0;
}

