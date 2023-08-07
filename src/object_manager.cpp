#include "object_manager.h"
#include "game_object.h"

ObjectManager::ObjectManager() {}

void ObjectManager::init() {
    // Initialiser objekter her
}

void ObjectManager::update() {
    for (auto object : objects) {
        object->update();
    }
}

void ObjectManager::render(Renderer& renderer) {
    for (auto object : objects) {
        object->render(renderer);
    }
}

void ObjectManager::addObject(GameObject* object) {
    objects.push_back(object);
}
