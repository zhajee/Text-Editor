//insertCharacter.hpp
#ifndef INSERTCHARACTER_HPP
#define INSERTCHARACTER_HPP

#include "Command.hpp"
#include <string>

class insertCharacter : public Command
{
public:

    // insertCharacter();
    void setChar(char ch);
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
    // std::string getName(EditorModel& model) override; //testing

private:
    int currentColumn;
    int currentLine;
    std::string previousLineContents;
    std::string newChar;
    
    void setVars(int column, int line, EditorModel& model);

    // std::string name; //testing
};

#endif