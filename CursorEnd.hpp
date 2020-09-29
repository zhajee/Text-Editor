//CursorEnd.hpp
#ifndef CURSOREND_HPP
#define CURSOREND_HPP

#include "Command.hpp"
class CursorEnd : public Command 
{
public:
    // CursorEnd(); //testing
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
    void setVars(int column, int line);

    // std::string getName(EditorModel& model) override; //testing
private:
    int currentColumn;
    int currentLine;

    // std::string name; //testing


};

#endif