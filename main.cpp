#include <iostream>
#include "fmod.hpp"
#include "tempus-sbc.h"
#include "unistd.h"

#define SBC_AUD_SPEAKER 0x00000001
#define SBC_AUD_VOIP 0x00000004

int main() {

    iSbcInit();
    int pboOn, piPercentage = 10;
    iSbcSetAudioRouting(true, SBC_AUD_SPEAKER);
    iSbcSetAudioControl(true, SBC_AUD_SPEAKER);


    FMOD::System *system;
    FMOD::Sound *sound;
    FMOD::Channel *channel;

    // Initialize FMOD
    FMOD::System_Create(&system);
    system->init(32, FMOD_INIT_NORMAL, 0);

    // Load the MP3 file
    FMOD_RESULT res = system->createSound("../Somebody-That-I-Used-To-Know.mp3", FMOD_DEFAULT, 0, &sound);

    std::cout<<"CreateSound result code: "<<res<<std::endl;


    // Play the sound
    res = system->playSound(sound, 0, false, &channel);
    std::cout << "playSound result code: "<< res << std::endl;

    // Keep the program running until a key is pressed
    std::cout << "Press any key to stop playback..." << std::endl;
    std::cin.get();

    // Release resources
    sound->release();
    system->close();
    system->release();

    return 0;
}
