#ifndef PARALLELTASK_HPP
#define PARALLELTASK_HPP

#include <SFML/System/Thread.hpp>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Lock.hpp>
#include <SFML/System/Clock.hpp>

class ParallelTask {
    private:
        sf::Thread mThread;
        bool mFinished;
        sf::Clock mElapsedTime;
        sf::Mutex mMutex;
        
    public:
        ParallelTask();
        void execute();
        bool isFinished();
        float getCompletion();

    private:
        void runTask();
};

#endif // PARALLELTASK_HPP