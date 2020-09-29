//CursorEnd.cpp

#include "CursorEnd.hpp"
// CursorEnd::CursorEnd() //testing
// {
//     name = "cursorEnd";
// }
// std::string CursorEnd::getName(EditorModel& model)
// {
//     return name;
// }

void CursorEnd::setVars(int column, int line)
{
    currentColumn = column;
    currentLine = line;
}
void CursorEnd::execute(EditorModel& model)
{
    setVars(model.cursorColumn(), model.cursorLine());
    model.setColumn(model.line(model.cursorLine()).size()+1);

}

void CursorEnd::undo(EditorModel& model) 
{
    model.setColumn(currentColumn);
    model.setLine(currentLine);
}
