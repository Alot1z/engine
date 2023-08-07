#include "input_manager.h"

InputManager::InputManager() {}

void InputManager::init(GLFWwindow* window) {
    glfwSetKeyCallback(window, keyCallback);
}

void InputManager::pollEvents() {
    glfwPollEvents();
}

void InputManager::terminate() {
    // Oprydning af inputressourcer
}

void InputManager::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
    // Tilføj yderligere tastaturhåndtering her
}
