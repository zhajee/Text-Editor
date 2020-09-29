//Backspace.hpp

#ifndef BACKSPACE_HPP
#define BACKSPACE_HPP

#include "Command.hpp"
#include <string>

class Backspace : public Command
{
public:

    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    int currentColumn;
    int currentLine;
    std::string previousContents;
    std::string lineAbove;
    void setVars(int column, int line);


};

#endif