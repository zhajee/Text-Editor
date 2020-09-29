//CursorDown.cpp

#include "CursorDown.hpp"

void CursorDown::execute(EditorModel& model)
{
    currentLine = model.cursorLine();
    currentColumn = model.cursorColumn();
    if (currentLine == model.lineCount())
    {
        throw EditorException{"Already at bottom!"};
    }
    
    model.incrementLine();
    if (model.line(currentLine).size() > model.line(currentLine+1).size())
    {
        model.setColumn(model.line(currentLine+1).size()+1);
    }

}

void CursorDown::undo(EditorModel& model) 
{
    model.decrementLine();
}