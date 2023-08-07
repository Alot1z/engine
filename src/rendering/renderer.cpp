#include "renderer.h"

Renderer::Renderer() : window(nullptr) {}

Renderer::~Renderer() {
    terminate();
}

void Renderer::init() {
    if (!glfwInit()) {
        // Initialisering mislykkedes
        return;
    }

    window = glfwCreateWindow(800, 600, "Vores Spilmotor", NULL, NULL);
    if (!window) {
        // Vindueoprettelse mislykkedes
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
}

void Renderer::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::swapBuffers() {
    glfwSwapBuffers(window);
}

bool Renderer::windowShouldClose() {
    return glfwWindowShouldClose(window);
}

void Renderer::terminate() {
    glfwTerminate();
}
