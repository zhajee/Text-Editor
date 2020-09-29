//CommandExecutions.cpp

#include "CommandExecutions.hpp"
#include "BooEditLog.hpp"
#include <vector>
CommandExecutions::CommandExecutions()
{
    currentPosition = 0;
}

CommandExecutions::~CommandExecutions()
{
    for (int i = 0; i < executions.size(); i++)
    {
        delete executions[i];
    }
    executions.clear();
}

void CommandExecutions::clear()
{
    executions.clear();
}
int CommandExecutions::capacity()
{
    return executions.capacity();
}
int CommandExecutions::getSize() const
{
    return executions.size();
}

int CommandExecutions::getPosition() const
{
    return currentPosition;
}

Command* CommandExecutions::getCommand(int pos)
{
    return executions.at(pos);
    
}
void CommandExecutions::addCommand(Command& command)
{
    executions.push_back(&command);
}

void CommandExecutions::addCommandAt(Command& command, int position)
{
    //executions.push_back(&command);
    auto itPos = executions.begin() + position;
    executions.insert(itPos, &command);
}

void CommandExecutions::incrementPosition()
{
    currentPosition += 1;
}

void CommandExecutions::decrementPosition()
{
    currentPosition -= 1;
}

void CommandExecutions::popback()
{
    executions.pop_back();
}

void CommandExecutions::deleteVector()
{
    for (int i = 0; i < executions.size(); i++)
    {
        delete executions.at(i);
    }
}