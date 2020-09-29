// InteractionProcessor.cpp
//
// ICS 45C Spring 2020
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"

#include "BooEditLog.hpp" //testing

#include "CommandExecutions.hpp"
#include "RedoCommands.hpp"
#include <vector>

#include <string> //testing

// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
    view.refresh();

    CommandExecutions c;
    RedoCommands redoCommands;

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if (c.getSize() != 0)
            {
                Command* cmd = c.getCommand(c.getPosition()-1);
                try
                {
                        //change current position in vector, perform undo and add command to redo.
                        c.decrementPosition();
                        cmd->undo(model);
                        redoCommands.addCommand(*cmd);
                        c.popback();
                        delete interaction.command();
                        
                    }
                    
                
                catch (EditorException& e)
                {
                    model.setErrorMessage(e.getReason()); 
                    delete cmd;               
                }
                view.refresh();
                }
        
        }
        else if (interaction.type() == InteractionType::redo)
        {
            //as long as vector of redo commands is not empty, excute on command.
            if (!redoCommands.empty())
            {
                Command* cmd = redoCommands.back();
                cmd->execute(model); 
                c.addCommand(*cmd);
                c.incrementPosition();

                redoCommands.popback();                
                model.clearErrorMessage();
                view.refresh();
            }
            

        }
        else if (interaction.type() == InteractionType::command)
        {
            //increment position in vector, execute command, and add command to vector
            Command* command = interaction.command();
            try
            {
                c.incrementPosition();
                command->execute(model);
                if (c.getPosition() < c.getSize())
                {
                    c.addCommandAt(*command, c.getPosition()+1);
                }
                else
                {
                    c.addCommand(*command);
                }
                redoCommands.clear();                
                model.clearErrorMessage();
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
                c.decrementPosition();
                delete command;
                
            }
            view.refresh();

        }
    }
}

