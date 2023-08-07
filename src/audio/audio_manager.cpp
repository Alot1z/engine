#include "audio_manager.h"
#include <fstream>
#include <vector>

AudioManager::AudioManager() : device(nullptr), context(nullptr) {}

AudioManager::~AudioManager() {
    terminate();
}

void AudioManager::init() {
    device = alcOpenDevice(NULL);
    context = alcCreateContext(device, NULL);
    alcMakeContextCurrent(context);
}

void AudioManager::loadSound(const std::string& name, const std::string& filename) {
    // Indlæs lydfil (WAV-format) - dette er en forenklet eksempelkode
    std::ifstream file(filename, std::ios::binary);
    // Læs WAV-header og data her...

    ALuint buffer;
    alGenBuffers(1, &buffer);
    // alBufferData(buffer, format, data, size, frequency);

    sounds[name] = buffer;
}

void AudioManager::playSound(const std::string& name) {
    ALuint source;
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, sounds[name]);
    alSourcePlay(source);
}

void AudioManager::stopSound(const std::string& name) {
    ALuint source = 0;
    if (sounds.find(name) != sounds.end()) {
        source = sounds[name];
    }
    alSourceStop(source);
}

void AudioManager::pauseSound(const std::string& name) {
    ALuint source = 0;
    if (sounds.find(name) != sounds.end()) {
        source = sounds[name];
    }
    alSourcePause(source);
}

void AudioManager::setSoundPosition(const std::string& name, float x, float y, float z) {
    ALuint source = 0;
    if (sounds.find(name) != sounds.end()) {
        source = sounds[name];
    }
    alSource3f(source, AL_POSITION, x, y, z);
}

void AudioManager::setListenerPosition(float x, float y, float z) {
    alListener3f(AL_POSITION, x, y, z);
}

void AudioManager::setListenerOrientation(float forwardX, float forwardY, float forwardZ, float upX, float upY, float upZ) {
    ALfloat orientation[6] = { forwardX, forwardY, forwardZ, upX, upY, upZ };
    alListenerfv(AL_ORIENTATION, orientation);
}

void AudioManager::terminate() {
    for (auto& sound : sounds) {
        alDeleteBuffers(1, &sound.second);
    }
    alcDestroyContext(context);
    alcCloseDevice(device);
}
