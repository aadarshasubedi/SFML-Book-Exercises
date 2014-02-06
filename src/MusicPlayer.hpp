#ifndef MUSICPLAYER_HPP
#define MUSICPLAYER_HPP

#include <map>
#include <string>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/Music.hpp>

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

class MusicPlayer : private sf::NonCopyable {
    private:
        sf::Music mMusic;
        std::map<Music::ID, std::string> mFilenames;
        float mVolume;
        
    public:
        MusicPlayer();

        void play(Music::ID theme);
        void stop();

        void setPaused(bool paused);
        void setVolume(float volume);
};

#endif // MUSICPLAYER_HPP
