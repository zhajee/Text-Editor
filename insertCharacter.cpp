//insertCharacter.cpp

#include "insertCharacter.hpp"
#include <string>

// insertCharacter::insertCharacter()
// {
//     name = "insertChar";
// }

//testing
// std::string insertCharacter::getName(EditorModel& model)
// {
//     return name;
// }

void insertCharacter::setChar(char ch)
{
    newChar = ch;
}

void insertCharacter::setVars(int column, int line, EditorModel& model)
{
    currentColumn = column;
    currentLine = line;
    previousLineContents = model.line(currentLine);
}

void insertCharacter::execute(EditorModel& model) 
{
    setVars(model.cursorColumn(), model.cursorLine(), model);

    if (model.getVecLines().size() == 0)
    {
        model.setLineContents(newChar, currentLine);
    }
    else
    {
        int s = previousLineContents.size();
        if (model.cursorColumn() == s + 1)
        {
            std::string newStr = previousLineContents + newChar;
            model.setLineContents(newStr, currentLine);
        }
        else
        {
            std::string newStr = previousLineContents.substr(0, currentColumn-1) + newChar + previousLineContents.substr(currentColumn-1,s-currentColumn+1);
            model.setLineContents(newStr, currentLine);
        }
        
        //std::string previousContents = model.line(currentLine);

    }
    model.incrementColumn();
}

void insertCharacter::undo(EditorModel& model) 
{
    model.setLineContents(previousLineContents, currentLine);
    model.decrementColumn();

}