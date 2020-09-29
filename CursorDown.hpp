//CursorDown.hpp

#ifndef CURSORDOWN_HPP
#define CURSORDOWN_HPP

#include "Command.hpp"
class CursorDown : public Command 
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
private:
    int currentLine;
    int currentColumn;
};

#endif