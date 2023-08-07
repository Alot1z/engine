#pragma once
#include <GLFW/glfw3.h>

class InputManager {
public:
    InputManager();
    void init(GLFWwindow* window);
    void pollEvents();
    void terminate();

private:
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};
