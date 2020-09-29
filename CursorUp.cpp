//CursorUp.cpp

#include "CursorUp.hpp"

void CursorUp::execute(EditorModel& model)
{
    currentLine = model.cursorLine();
    currentColumn = model.cursorColumn();

    if (currentLine == 1)
    {
        booEditLog("here");
        throw EditorException{"Already at top!"};
    }



    model.decrementLine();
    if (model.line(currentLine).size() > model.line(currentLine-1).size())
    {
        model.setColumn(model.line(currentLine-1).size()+1);
    }

}

void CursorUp::undo(EditorModel& model) 
{
    model.setLine(currentLine);
    model.setColumn(currentColumn);
}