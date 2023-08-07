#pragma once
#include "rendering/renderer.h"
#include <vector>

class GameObject;

class ObjectManager {
public:
    ObjectManager();
    void init();
    void update();
    void render(Renderer& renderer);
    void addObject(GameObject* object);

private:
    std::vector<GameObject*> objects;
};
