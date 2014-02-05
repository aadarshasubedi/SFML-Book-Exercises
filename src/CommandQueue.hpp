#ifndef COMMANDQUEUE_HPP
#define COMMANDQUEUE_HPP

#include <queue>

#include "Command.hpp"

class CommandQueue {
    private:
        std::queue<Command> mQueue;
        
    public:
        void push(const Command& command);
        Command	pop();
        bool isEmpty() const;
};

#endif // COMMANDQUEUE_HPP
