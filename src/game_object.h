#pragma once
#include "rendering/renderer.h"

class GameObject {
public:
    virtual void update() = 0;
    virtual void render(Renderer& renderer) = 0;
};
