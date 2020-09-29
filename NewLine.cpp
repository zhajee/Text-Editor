//NewLine.cpp

#include "NewLine.hpp"
#include <string>

void NewLine::setVars(int column, int line)
{
    currentColumn = column;
    currentLine = line;
    
}

void NewLine::process(EditorModel& model)
{
    model.createLine(currentLine+1,""); 
    model.incrementLine();
    model.setColumn(1);
    model.incrementTotalLines();
}

void NewLine::execute(EditorModel& model)
{
    //else if size of current line string = or > currentColumn, 
        //cursorLine + 1 and cursorColumn = 1 and current Line Contents = a substring to that point - 1
        // and next Line Contents (vector position + 1) = rest of substring
    //else : (size of current line string < current Column)
        //cursorLine + 1 and cursorColumn = 1

    setVars(model.cursorColumn(), model.cursorLine());
    currentLinesNum = model.lineCount();
    previousContents = model.line(currentLine);
    if (model.cursorColumn() == 1 && previousContents.size() != 0)
    {
        process(model);
        model.setLineContents("", currentLine);
        model.setLineContents(previousContents, currentLine+1);
    }
    else if (previousContents.size() >= currentColumn )
    {
        std::string previousContentsSliced = previousContents.substr(0,currentColumn-1);
        std::string newContents = previousContents.substr(currentColumn-1,previousContents.size()-currentColumn+1);
        process(model);
        model.setLineContents(newContents, currentLine+1);

    }
    else
    {
        process(model);
        model.setLineContents("", currentLine+1);


    }
    
}

void NewLine::undo(EditorModel& model) 
{
    model.deleteLine(currentLine + 1);
    model.decrementTotalLines(); //set line count to previous value
    model.setLineContents(previousContents, currentLine);
    model.setColumn(currentColumn);
    model.setLine(currentLine);

}