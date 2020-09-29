// KeypressInteractionReader.cpp
//
// ICS 45C Spring 2020
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include <iostream> //testing

#include "KeypressInteractionReader.hpp"

#include "Command.hpp"
//#include "EditorModel.hpp"
#include "insertCharacter.hpp"
#include "NewLine.hpp"
#include "CursorLeft.hpp"
#include "CursorRight.hpp"
#include "CursorUp.hpp"
#include "CursorDown.hpp"
#include "CursorHome.hpp"
#include "CursorEnd.hpp"
#include "Backspace.hpp"
#include "DeleteLine.hpp"

#include "CommandExecutions.hpp"

#include <vector>

// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    // CommandExecutions c;
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
            case 'X':
                return Interaction::quit();
            case 'J':
            case 'M':
            {
                booEditLog("New Line");
                NewLine *n = new NewLine();
                Command *command = n;
                return Interaction::command(command);

            }
            case 'U':
            {
                booEditLog("Cursor Left");
                CursorLeft *n = new CursorLeft();
                Command *command = n;
                return Interaction::command(command);

            }
            case 'O':
            {
                booEditLog("Cursor Right");
                CursorRight *n = new CursorRight();
                Command *command = n;
                return Interaction::command(command);
            }
            case 'I':
            {
                booEditLog("Cursor Up");
                CursorUp *n = new CursorUp();
                Command *command = n;
                return Interaction::command(command);

            }
            case 'K':
            {
                booEditLog("Cursor Down");
                CursorDown *n = new CursorDown();
                Command *command = n;
                return Interaction::command(command);
            }
            case 'Y':
            {
                booEditLog("Cursor Home");
                CursorHome *n = new CursorHome();
                Command *command = n;
                return Interaction::command(command);
            }
            case 'P':
            {
                booEditLog("Cursor End");
                CursorEnd *n = new CursorEnd();
                Command *command = n;
                return Interaction::command(command);
            }
            case 'H':
            {
                booEditLog("Backspace");
                // Backspace *n = new Backspace();
                Command *command = new Backspace();;
                return Interaction::command(command);
            }
            case 'D':
            {
                booEditLog("Delete Line");
                DeleteLine *n = new DeleteLine();
                Command *command = n;
                return Interaction::command(command);
            }
            case 'Z':
            {
                booEditLog("Undo");
                return Interaction::undo();
            }
            case 'A':
            {
                booEditLog("Redo");
                return Interaction::redo();
            }
            }
            
            

        }
        else
        {
            booEditLog("insert Character");
            insertCharacter *n = new insertCharacter();
            n->setChar(keypress.code());
            Command *command = n;
            return Interaction::command(command);



        }
    }
}

