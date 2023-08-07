#pragma once
#include "rendering/renderer.h"
#include "input/input_manager.h"
#include "audio/audio_manager.h"
#include "object_manager.h"

class GameLoop {
public:
    GameLoop();
    ~GameLoop();
    void run();

private:
    Renderer renderer;
    InputManager inputManager;
    AudioManager audioManager;
    ObjectManager objectManager;
};
