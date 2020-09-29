//CursorRight.cpp

#include "CursorRight.hpp"
#include "BooEditLog.hpp"

#include <string> //testing

// CursorRight::CursorRight()
// {
//     name = "cursorRight";
// }

// std::string CursorRight::getName(EditorModel& model)
// {
//     return name;
// }

void CursorRight::execute(EditorModel& model)
{
    currentColumn = model.cursorColumn();
    currentLine = model.cursorLine();
    //model.incrementColumn();
    int size = model.line(currentLine).size();
    if (currentColumn == size+1 && currentLine == model.lineCount())
    {
        throw EditorException{"Already at end"};
    }

    if (currentColumn == size+1 && currentLine != model.lineCount())
    {
        model.incrementLine();
        model.setColumn(1);
    }
    else
    {
        model.setColumn(currentColumn+1);
    }

}

void CursorRight::undo(EditorModel& model) 
{

    booEditLog("cursor Column: "); //testing
    //model.decrementColumn();    
    model.setColumn(currentColumn);


}