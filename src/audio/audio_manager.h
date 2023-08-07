#pragma once
#include <AL/al.h>
#include <AL/alc.h>
#include <string>
#include <map>

class AudioManager {
public:
    AudioManager();
    ~AudioManager();
    void init();
    void loadSound(const std::string& name, const std::string& filename);
    void playSound(const std::string& name);
    void terminate();

private:
    ALCdevice* device;
    ALCcontext* context;
    std::map<std::string, ALuint> sounds;
};
