//RedoCommands.hpp
#ifndef REDOCOMMANDS_HPP
#define REDOCOMMANDS_HPP

#include "Command.hpp"

#include <vector>

class RedoCommands
{
public:
    RedoCommands();
    ~RedoCommands();
    // void incrementPosition();
    // void decrementPosition();
    void addCommand(Command& command);
    void addCommandAt(Command& command, int position);
    void popback();

    void deleteVector();

    Command* getCommand(int pos);

    Command* back();
    bool empty();
    void clear();

    int getSize() const;
    int getPosition() const;
private:
    std::vector<Command*> commands;
    int currentPosition;

};

#endif