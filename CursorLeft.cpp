//CursorLeft.cpp

#include "CursorLeft.hpp"

#include "BooEditLog.hpp" //testing

void CursorLeft::execute(EditorModel& model)
{
    currentColumn = model.cursorColumn();
    currentLine = model.cursorLine();
    //model.decrementColumn();
    if (currentColumn == 1 && currentLine == 1)
    {
        throw EditorException{"Already at beginning"};
    }
    else
    {
        if (currentColumn == 1 && currentLine != 1)
        {
            model.decrementLine();
            model.setColumn(model.line(currentLine-1).size() + 1);
        }
        else
        {
            model.setColumn(currentColumn-1);
        }
    }


    
    

    



}

void CursorLeft::undo(EditorModel& model) 
{
    //model.incrementColumn();
    model.setColumn(currentColumn);

}