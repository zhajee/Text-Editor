//DeleteLine.cpp

#include "DeleteLine.hpp"
#include <vector>
void DeleteLine::setVars(int column, int line)
{
    currentColumn = column;
    currentLine = line;
    //currentLineContents
}
void DeleteLine::execute(EditorModel& model)
{
    setVars(model.cursorColumn(), model.cursorLine());
    previousContents = model.line(currentLine);
    
    if (currentLine != 1 && previousContents == "")
    {
        model.decrementLine();
        model.decrementTotalLines();
        model.deleteLine(currentLine);
    }
    else
    {
        if (previousContents == "")
        {
        throw EditorException{"Already empty"};
        }
    
    if (currentLine == 1 && model.lineCount() == 1)
    {
        
        model.setLineContents("", currentLine);
        model.setColumn(1);
        
    }
    else
    {
        
        model.deleteLine(currentLine);

        model.decrementTotalLines();
        if (currentLine == 1)
        {
            model.setColumn(model.cursorColumn());    
        }
        else
        {
            model.decrementLine();
            if (previousContents.size() <= model.line(currentLine-1).size())
            {
                model.setColumn(previousContents.size()+1);
            }
            else
            {
                if (model.line(currentLine-1).size() == 0)
                {
                    model.setColumn(1);
                }
                else
                {
                    model.setColumn(model.line(currentLine-1).size());
                }
            }
        }
    
    }
    }
    
}

void DeleteLine::undo(EditorModel& model) 
{
    //increment linecount if there had been more than one line
    model.createLine(currentLine, previousContents);
    if (model.getVecLines().size() > 1)
    {
        model.incrementTotalLines();
    }
    //model.incrementTotalLines();
    model.setLine(currentLine);
    model.setColumn(currentColumn);
}