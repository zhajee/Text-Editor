//NewLine.hpp

#ifndef NEWLINE_HPP
#define NEWLINE_HPP

#include "Command.hpp"
#include <string>
class NewLine : public Command
{

public:

    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    int currentColumn;
    int currentLine;
    int currentLinesNum;
    std::string previousContents;

    void setVars(int column, int line);
    void process(EditorModel& model);


};

#endif