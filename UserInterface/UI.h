//
// Created by Filip on 18-Mar-21.
//

#pragma once

#include <string>
#include <iostream>


#include "AdminController.h"
#include "UserController.h"

class UserInterface {
private:
    AdminService& program_controller;
    UserController& user_program_controller;


public:
    UserInterface(AdminService& given_admin_controller, UserController& given_user_controller);

    void UIAddNewDog();

    void UIRemoveDog();

    void UIUpdateDogAge();

    void UIUpdateDogPhoto();

    void printListOfDogs(std::vector<Dog>);

    void getAllDogsList();

    void printModeChoices();

    void printAdminMenu();

    void runAdmin();

    void printIterationChoices();

    static void printCurrentDog(Dog current_dog);

    void UIIterateAllDogs();

    std::string askForSortBreed();

    int askForSortAge();

    void UIIterateSortedDogs();

    void displayAdoptionList();

    void displayProgramAdoptionList();

    void printUserMenu();

    void runUser();

    std::string chooseMode();

    std::string chooseAction();

    std::string getCurrentDir();

    void startProgram();

};
