//CursorHome.cpp

#include "CursorHome.hpp"

void CursorHome::execute(EditorModel& model)
{
    currentColumn = model.cursorColumn();

    model.setColumn(1);

}

void CursorHome::undo(EditorModel& model) 
{
    model.setColumn(currentColumn);
}

