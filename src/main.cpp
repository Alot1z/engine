#include "rendering/renderer.h"
#include "audio/audio_manager.h"

int main() {
    // Initialiser renderingssystemet
    Renderer renderer;
    renderer.initialize();

    // Initialiser lydsystemet
    AudioManager audioManager;
    audioManager.initialize();

    // Hovedspilsløjfen
    while (true) {
        renderer.update();
        audioManager.update();
        // Yderligere opdateringer og logik her
    }

    return 0;
}
