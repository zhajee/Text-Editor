// EditorModel.cpp
//
// ICS 45C Spring 2020
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"


#include <iostream> //testing
#include "BooEditLog.hpp" //testing

#include <string>
EditorModel::EditorModel()
{
    vecLines.push_back("");
    cursorCol = 1;
    cursorLn = 1;
    totalLines = 1;
    currErrorMessage = "";
}

std::vector<std::string>& EditorModel::getVecLines()  
{
    return vecLines;
}

int EditorModel::cursorLine() const
{
    return cursorLn;
}


int EditorModel::cursorColumn() const
{
    return cursorCol;
}

void EditorModel::incrementColumn() 
{
    cursorCol += 1;
}

void EditorModel::decrementColumn() 
{
    cursorCol -= 1;
}

void EditorModel::setColumn(int newCol) 
{
    cursorCol = newCol;
}

void EditorModel::setLine(int newLine) 
{
    cursorLn = newLine;
}

void EditorModel::incrementLine() 
{
    cursorLn += 1;
}

void EditorModel::decrementLine() 
{
    cursorLn -= 1;
}

int EditorModel::lineCount() const
{
    // int count = 1;
    // if (vecLines.size() > 1)
    // {
    //     count = vecLines.size();
    // }
    // return count;
    return totalLines;
}

void EditorModel::incrementTotalLines()
{
    totalLines += 1;
}

void EditorModel::decrementTotalLines()
{
    totalLines -= 1;
}

void EditorModel::deleteLine(int lineNum)
{
    vecLines.erase(vecLines.begin() + lineNum - 1);
    if (vecLines.size() == 0)
    {
        vecLines.push_back(""); //initialized state if size is 0
    }
}

void EditorModel::createLine(int lineNum, std::string lineContents)
{
    vecLines.insert(vecLines.begin() + lineNum-1, lineContents);
}

void EditorModel::addLineToVector()
{
    vecLines.push_back("");
}


void EditorModel::setLineContents(const std::string& contents, int lineNumber)
{
    vecLines.at(lineNumber -1) = contents;
}


const std::string& EditorModel::line(int lineNumber) const
{

    return vecLines.at(lineNumber-1);
}


const std::string& EditorModel::currentErrorMessage() const
{
    // static std::string removeThis = "";
    // removeThis = currErrorMessage;
    // return removeThis;
    return currErrorMessage;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
    currErrorMessage = errorMessage;
}


void EditorModel::clearErrorMessage()
{
    currErrorMessage = "";
}



