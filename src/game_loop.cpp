#include "game_loop.h"

GameLoop::GameLoop() {
    renderer.init();
    inputManager.init(renderer.getWindow());
    audioManager.init();
    objectManager.init();
}

GameLoop::~GameLoop() {
    renderer.terminate();
    inputManager.terminate();
    audioManager.terminate();
}

void GameLoop::run() {
    while (!renderer.windowShouldClose()) {
        inputManager.pollEvents();
        renderer.clear();

        objectManager.update();
        objectManager.render(renderer);

        renderer.swapBuffers();
    }
}
