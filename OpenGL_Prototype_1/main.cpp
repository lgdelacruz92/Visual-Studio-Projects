// OpenGL_Prototype_1.cpp : Defines the entry point for the console application.
//

#include <Windows.h>
#include <iostream>
#include "Display.h"
#include "Mesh.h"
#include "Shaders.h"
#include "Texture.h"
#include "Transform.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    Display display(400, 400, "Hello world!");


    Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0, 0)),
                          Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
                          Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0)), };

    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
    Shader shader("./basicShader");
    Texture texture("bricks.jpg");
    Transform transform;

    float counter = 0.0f;
    while (!display.isClosed())
    {
        display.Clear(0.0f, 0.0f, 0.3f, 1.0f);

        transform.GetPos().x = sinf(counter);
        transform.GetRot().z = counter * 10;
        transform.GetScale() *= cosf(counter * 0.01);

        shader.Bind();
        texture.Bind(0);
        shader.Update(transform);
        mesh.Draw();
        display.Update();
        counter += 0.01f;
    }
    return 0;
}

