//RedoCommands.cpp

#include "RedoCommands.hpp"
#include "BooEditLog.hpp"

RedoCommands::RedoCommands()
{
}

RedoCommands::~RedoCommands()
{
    for (int i = 0; i < commands.size(); i++)
    {
        delete commands[i];
    }
    commands.clear();
}

bool RedoCommands::empty()
{
    return commands.empty();
}

void RedoCommands::clear()
{
    commands.clear();
}

Command* RedoCommands::getCommand(int pos)
{
    return commands.at(pos);
    
}
Command* RedoCommands::back()
{
    return commands.back();
}
void RedoCommands::addCommand(Command& command)
{
    commands.push_back(&command);
}

void RedoCommands::addCommandAt(Command& command, int position)
{
    //executions.push_back(&command);
    auto itPos = commands.begin() + position;
    commands.insert(itPos, &command);
}

// void RedoCommands::incrementPosition()
// {
//     currentPosition += 1;
// }

// void RedoCommands::decrementPosition()
// {
//     currentPosition -= 1;
// }

void RedoCommands::popback()
{
    commands.pop_back();
}

void RedoCommands::deleteVector()
{
    for (int i = 0; i < commands.size(); i++)
    {
        delete commands.at(i);
    }
}