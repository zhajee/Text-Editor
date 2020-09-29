//DeleteLine.hpp

#ifndef DELETELINE_HPP
#define DELETELINE_HPP

#include "Command.hpp"
#include <string>
class DeleteLine : public Command
{

public:

    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    int currentColumn;
    int currentLine;
    std::string previousContents;

    void setVars(int column, int line);


};

#endif