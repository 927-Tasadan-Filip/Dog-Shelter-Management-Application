//
// Created by Filip on 18-Mar-21.
//
#pragma once

#include <string>
#include "DogEntity.h"
#include "Repository.h"
#include "SQL_Repository.h"
#include "../Validator/ProgramValidator.h"
#include <stack>
#include <iostream>
#include <memory>

class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;
};

class AddCommand: public Command {
private:
    Repository* program_repo;
    Dog new_dog;
public:
    AddCommand(Repository* given_repo, const Dog& given_dog): program_repo{given_repo}, new_dog{given_dog} {}
    void execute() override { this->program_repo->addDog(this->new_dog); };
    void undo() override { this->program_repo->deleteDog(this->new_dog);};
    void redo() override { this->program_repo->addDog(this->new_dog); };
};

class DeleteCommand: public Command {
private:
    Repository *program_repo;
    Dog deleted_dog;
    Dog to_delete_dog;
public:
    DeleteCommand(Repository* given_repo, const Dog& del_dog, const Dog& to_del_dog): program_repo{given_repo}, deleted_dog{del_dog}, to_delete_dog{to_del_dog} {}
    void execute() override { this->program_repo->deleteDog(this->to_delete_dog); };
    void undo() override { this->program_repo->addDog(this->deleted_dog);};
    void redo() override { this->program_repo->deleteDog(this->to_delete_dog); };
};

class UpdateAgeCommand: public Command {
private:
    Repository *program_repo;
    Dog updated_dog;
    Dog to_update_dog;
public:
    UpdateAgeCommand(Repository* given_repo, const Dog& updt_dog, const Dog& to_updt_dog): program_repo{given_repo}, updated_dog{updt_dog}, to_update_dog{to_updt_dog} {}
    void execute() override { this->program_repo->updateDog(this->to_update_dog, 'a'); };
    void undo() override { this->program_repo->updateDog(this->updated_dog, 'a');};
    void redo() override { this->program_repo->updateDog(this->to_update_dog, 'a');};
};

class UpdatePhotoCommand: public Command {
private:
    Repository *program_repo;
    Dog updated_dog;
    Dog to_update_dog;
public:
    UpdatePhotoCommand(Repository* given_repo, const Dog& updt_dog, const Dog& to_updt_dog): program_repo{given_repo}, updated_dog{updt_dog}, to_update_dog{to_updt_dog} {}
    void execute() override { this->program_repo->updateDog(this->to_update_dog, 'p'); };
    void undo() override { this->program_repo->updateDog(this->updated_dog, 'p');};
    void redo() override { this->program_repo->updateDog(this->to_update_dog, 'p');};
};


typedef std::stack<std::shared_ptr<Command>> commandStack_t;

class CommandManager {
    commandStack_t mUndoStack;
    commandStack_t mRedoStack;

public:
    CommandManager() {}

    void executeCmd(std::shared_ptr<Command> command) {
        mRedoStack = commandStack_t(); // clear the redo stack
        command->execute();
        mUndoStack.push(command);
    }

    void undo() {
        if (mUndoStack.size() <= 0) {
            throw ValidationException("No more undos available!");
        }
        mUndoStack.top()->undo();          // undo most recently executed command
        mRedoStack.push(mUndoStack.top()); // add undone command to undo stack
        mUndoStack.pop();                  // remove top entry from undo stack
    }

    void redo() {
        if (mRedoStack.size() <= 0) {
            throw ValidationException("No more redos available!");
        }
        mRedoStack.top()->redo();          // redo most recently executed command
        mUndoStack.push(mRedoStack.top()); // add undone command to redo stack
        mRedoStack.pop();                  // remove top entry from redo stack
    }
};


class AdminService {
private:
    Repository& program_repo;
    std::vector<std::vector<Dog>> history_vector;
    CommandManager* command_manager;

public:

    AdminService();

    AdminService(Repository& given_repository);

    // About: add a new dog with the given attributes to the repository
    // breed - a string which contains the breed of the new  (type: std::string)
    // name -  a string which contains the name of the new dog(type: std::string)
    // age - an integer number representing the age of the new dog (type: integer)
    // photograph -  a string which contains the photograph link of the new dog (type: std::string)
    void serviceAddDog(std::string breed, std::string name, int age, std::string photograph);

    // About: delete a dog with the given name from the repository
    // name -  a string which contains the name of the dog which should be deleted(type: std::string)
    void serviceDeleteDog(std::string name);

    // About: update a dog's age with the given name from the repository
    // name -  a string which contains the name of the dog which should be updated (type: std::string)
    // age - an integer number representing the new age of the dog (type: integer)
    void serviceUpdateDogAge(std::string name, int new_age);

    // About: update a dog's photo with the given name from the repository
    // name -  a string which contains the name of the dog which should be updated (type: std::string)
    // photograph -  a string which contains the photograph link of the new dog (type: std::string)
    void serviceUpdateDogPhoto(std::string name, std::string new_photo);

    // About: add 10 Dog object in the repository
    void servicePopulateShelter();

    // Return: the list of all dogs from the repository
    std::vector<Dog> getAllDogs();

    void adminLoadDogsFromFile();

    void adminServiceSetFileName(std::string file_name);

    Dog searchForDogByName(std::string dog_name);

    void undoLastOperation();
    void redoLastOperation();
};

