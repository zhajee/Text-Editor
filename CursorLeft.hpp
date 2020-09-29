//CursorLeft.hpp

#ifndef CURSORLEFT_HPP
#define CURSORLEFT_HPP

#include "Command.hpp"
class CursorLeft : public Command 
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
private:
    int currentColumn;
    int currentLine;
};

#endif