#pragma once
#include <GLFW/glfw3.h>

class Renderer {
public:
    Renderer();
    ~Renderer();
    void init();
    void clear();
    void swapBuffers();
    bool windowShouldClose();
    void terminate();

private:
    GLFWwindow* window;
};
