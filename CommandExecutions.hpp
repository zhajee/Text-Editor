//CommandExecutions.hpp
#ifndef COMMANDEXECUTIONS_HPP
#define COMMANDEXECUTIONS_HPP

#include "Command.hpp"

#include <vector>
#include <memory>

class CommandExecutions
{
public:
    CommandExecutions();
    ~CommandExecutions();
    void incrementPosition();
    void decrementPosition();
    void addCommand(Command& command);
    void addCommandAt(Command& command, int position);
    void popback();

    void deleteVector();

    Command* getCommand(int pos);
    int capacity();
    void clear();
    int getSize() const;
    int getPosition() const;
private:
    std::vector<Command*> executions;
    // std::vector<std::unique_ptr<Command>>;

    // std::unique_ptr<Command> executions;
    int currentPosition;

};

#endif