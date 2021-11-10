//
// Created by Filip on 18-Mar-21.
//

#include "UI.h"
#include <Windows.h>
#include <shellapi.h>
#include <unistd.h>


UserInterface::UserInterface(AdminService& given_admin_controller, UserController& given_user_controller): program_controller{given_admin_controller}, user_program_controller{given_user_controller} {}

void UserInterface::UIAddNewDog() {
    std::string new_breed, new_name, new_photo;
    int new_age;
    char empty_char;

    std::cout<<"Enter new dog's breed >> ";
    std::cin>>new_breed;
    std::cout<<"Enter new dog's name >> ";
    std::cin>>new_name;

    std::cout<<"Enter new dog's age >> ";
    std::cin>>new_age;
    if (!std::cin) {
        std::cin.clear();
        std::cout << "Error: The age should be an integer!!\n";
        std::cin.ignore(100, '\n');
        return;

    }

    std::cout<<"Enter new dog's photo >> ";
    std::cin>>new_photo;
    try {
        this->program_controller.serviceAddDog(new_breed, new_name,new_age, new_photo);
    }
    catch(RepoException& repo_exception) {
        std::cout<<"Error: "<< repo_exception.getInfo() <<"\n";
    }
    catch(ValidationException& validator_exception) {
        std::cout<<"Error: "<< validator_exception.getInfo() <<"\n";
    }


}

void UserInterface::UIRemoveDog() {
    std::string given_name;

    std::cout<<"Enter the dog's name >> ";
    std::cin>>given_name;


    try {
        this->program_controller.serviceDeleteDog(given_name);
    }
    catch(RepoException& repo_exception) {
        std::cout<<"Error: "<< repo_exception.getInfo() <<"\n";
    }
    catch(ValidationException& validator_exception) {
        std::cout<<"Error: "<< validator_exception.getInfo() <<"\n";
    }

}

void UserInterface::UIUpdateDogAge() {
    std::string dog_name;
    int new_age;
    std::cout<<"Enter the dog's name >> ";
    std::cin>>dog_name;

    std::cout<<"Enter new dog's age >> ";
    std::cin>>new_age;
    if (!std::cin) {
        std::cin.clear();
        std::cout << "Error: The age should be an integer!!\n";
        std::cin.ignore(100, '\n');
        return;

    }
    try {
        this->program_controller.serviceUpdateDogAge(dog_name, new_age);
    }
    catch(RepoException& repo_exception) {
        std::cout<<"Error: "<< repo_exception.getInfo() <<"\n";
    }
    catch(ValidationException& validator_exception) {
        std::cout<<"Error: "<< validator_exception.getInfo() <<"\n";
    }
}

void UserInterface::UIUpdateDogPhoto() {
    std::string dog_name, new_photo;

    std::cout<<"Enter the dog's name >> ";
    std::cin>>dog_name;

    std::cout<<"Enter new dog's photo >> ";
    std::cin>>new_photo;
    try {
        this->program_controller.serviceUpdateDogPhoto(dog_name, new_photo);
    }
    catch(RepoException& repo_exception) {
        std::cout<<"Error: "<< repo_exception.getInfo() <<"\n";
    }
    catch(ValidationException& validator_exception) {
        std::cout<<"Error: "<< validator_exception.getInfo() <<"\n";
    }
}

void UserInterface::getAllDogsList() {
    std::vector<Dog> dog_list = this->program_controller.getAllDogs();
    std::cout<<"List of all dogs currently in the shelter\n";
    this->printListOfDogs(dog_list);
}

void UserInterface::printListOfDogs(std::vector<Dog> given_list) {

    for(auto current_dog : given_list) {
        std::cout<<"Breed: "<<current_dog.getBreed()<<" | ";
        std::cout<<"Name: "<<current_dog.getName()<<" | ";
        std::cout<<"Age: "<<current_dog.getAge()<<" | ";
        std::cout<<"Photograph: "<<current_dog.getPhotograph()<<"\n";
    }
    std::cout<<"\n";
}

void UserInterface::printModeChoices() {
    std::cout<<"You have to choose the mode in which you want to start the app\n";
    std::cout<<"0 - exit application\n";
    std::cout<<"1 - admin mode\n";
    std::cout<<"2 - user mode\n";
    std::cout<<"Enter your desired mode >> ";
}


std::string UserInterface::chooseMode() {
    std::string mode;
    this->printModeChoices();
    std::cin>>mode;
    return mode;
}

std::string UserInterface::chooseAction() {
    std::string action;

    std::cout<<"Enter the desired action >> ";
    std::cin>>action;
    return action;
}

void UserInterface::printAdminMenu() {
    std::cout<<"This is the list of operations that you can do as an admin\n";
    std::cout<<"0 - exit mode\n";
    std::cout<<"1 - add new dog\n";
    std::cout<<"2 - delete a dog by name\n";
    std::cout<<"3 - update a dog's age\n";
    std::cout<<"4 - update a dog's photograph\n";
    std::cout<<"5 - get the list of dogs\n\n";
}


void UserInterface::runAdmin() {
    std::string action;
    for(;;) {
        this->printAdminMenu();

        action = this->chooseAction();

        if(action=="0")
            break;

        else if(action=="1") {
            this->UIAddNewDog();
        }

        else if(action=="2") {
            this->UIRemoveDog();
        }

        else if(action=="3") {
                this->UIUpdateDogAge();

        }

        else if(action=="4") {
                this->UIUpdateDogPhoto();
        }

        else if(action=="5")
            this->getAllDogsList();

        else {
            std::cout<<"Error: Invalid command!\n";
        }
    }
}

void UserInterface::printIterationChoices() {
    std::cout<<"This is the list of actions that you can do for seeing the dogs in the shelter\n";
    std::cout<<"0 - go back to operations menu \n";
    std::cout<<"1 - adopt current dog\n";
    std::cout<<"2 - go to the next dog in the list\n\n";
}

void UserInterface::printCurrentDog(Dog current_dog) {
    std::cout<<"The current dog in the list is:\n";
    std::cout<<"Breed: "<<current_dog.getBreed()<<" | ";
    std::cout<<"Name: "<<current_dog.getName()<<" | ";
    std::cout<<"Age: "<<current_dog.getAge()<<" | ";
    char link[200];
    for(int i=0; i<current_dog.getPhotograph().size(); i++)
        link[i] = current_dog.getPhotograph()[i];
    ShellExecuteA(NULL, NULL, "chrome.exe", link, NULL, SW_SHOWMAXIMIZED);

}

void UserInterface::UIIterateAllDogs() {
    std::string action;
    if(this->program_controller.getAllDogs().size() >= 1) {
        std::vector<Dog> aux_dog_list = this->program_controller.getAllDogs();
        auto dog_iterator = aux_dog_list.begin();

        for(;;) {
            this->printCurrentDog(*dog_iterator);
            this->printIterationChoices();

            action = this->chooseAction();
            if(action == "0") {
                break;
            }
            else if(action == "1") {
                try {
                    this->user_program_controller.addToAdoptionList(*dog_iterator);
                    std::string deleted_dog_name = (*dog_iterator).getName();
                }
                catch(RepoException& repo_exception) {
                    std::cout<<"Error: "<< repo_exception.getInfo() <<"\n";
                }
                ++dog_iterator;
            }
            else if(action == "2") {
                ++dog_iterator;
            }
            else {
                std::cout<<"Error: Invalid command!\n";
            }

            if(dog_iterator == aux_dog_list.end()) {
                if(this->program_controller.getAllDogs().size() >= 1) {
                    aux_dog_list = this->program_controller.getAllDogs();
                    dog_iterator = aux_dog_list.begin();
                }
                else {
                    std::cout<<"There are no more dogs in the shelter!"<<"\n";
                    break;
                }
            }

        }
    }

    else {
        std::cout<<"There are no more dogs in the shelter!"<<"\n";
    }
}

std::string UserInterface::askForSortBreed() {
    std::string sort_breed, answer;
    std::cout<<"Do you want to enter a specific breed of dogs? y/n \n";
    for(;;) {
        std::cout<<"Enter answer >>";
        std::cin>>answer;

        if(answer == "y") {
            std::cout<<"Enter the breed of dogs >> ";
            std::cin>>sort_breed;
            return sort_breed;
        }
        else if(answer == "n") {
            sort_breed = "";
            return sort_breed;
        }
        else {
            std::cout<<"Error: Invalid answer. Please try again!";
        }
    }
}

int UserInterface::askForSortAge() {
    int sort_age;
    std::cout<<"Enter the maximum age of dogs >> ";
    std::cin>>sort_age;
    return sort_age;

}

void UserInterface::UIIterateSortedDogs() {
    std::string action, sort_breed;
    int sort_age;

    sort_breed = this->askForSortBreed();
    sort_age = this->askForSortAge();

    if(this->user_program_controller.sortDogs(this->program_controller.getAllDogs(), sort_breed, sort_age).size() >= 1) {
        std::vector<Dog> aux_dog_list = this->user_program_controller.sortDogs(this->program_controller.getAllDogs(), sort_breed, sort_age);
        auto dog_iterator = aux_dog_list.begin();

        for(;;) {
            this->printCurrentDog(*dog_iterator);
            this->printIterationChoices();

            action = this->chooseAction();
            if(action == "0") {
                break;
            }
            else if(action == "1") {
                try {
                    this->user_program_controller.addToAdoptionList(*dog_iterator);
                    std::string deleted_dog_name = (*dog_iterator).getName();

                }
                catch(RepoException& repo_exception) {
                    std::cout<<"Error: "<< repo_exception.getInfo() <<"\n";
                }

                ++dog_iterator;
            }
            else if(action == "2") {
                ++dog_iterator;
            }
            else {
                std::cout<<"Error: Invalid command!\n";
            }

            if(dog_iterator == aux_dog_list.end()) {
                if(this->user_program_controller.sortDogs(this->program_controller.getAllDogs(), sort_breed, sort_age).size() >= 1) {
                    aux_dog_list = this->user_program_controller.sortDogs(this->program_controller.getAllDogs(), sort_breed, sort_age);
                    dog_iterator = aux_dog_list.begin();
                }
                else {
                    std::cout<<"There are no more dogs in the shelter!"<<"\n";
                    break;
                }
            }

        }
    }

    else {
        std::cout<<"There are no more dogs in the shelter!"<<"\n";
    }
}

void UserInterface::displayAdoptionList() {
    std::cout<<"All dogs currently in the adoption list\n";
    this->printListOfDogs(this->user_program_controller.getAdoptionList());
}

void UserInterface::displayProgramAdoptionList() {
    if(this->user_program_controller.isCSV()) {
        std::string file = "\"" +  this->user_program_controller.getFileName()  + "\"";
        ShellExecuteA(NULL, NULL, "C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE", file.c_str(), NULL, SW_SHOWMAXIMIZED);
    }
    else {
        ShellExecuteA(NULL, NULL, "chrome.exe", "C:\\Users\\Filip\\Documents\\GitHub\\a89-917-Tasadan-Filip\\cmake-build-release\\adoption_list.html", NULL, SW_SHOWMAXIMIZED);

    }
}

void UserInterface::printUserMenu() {
    std::cout<<"This is the list of operations that you can do as an user\n";
    std::cout<<"0 - exit mode\n";
    std::cout<<"1 - see all dogs in the shelter\n";
    std::cout<<"2 - see all the dogs of a given breed, having an age less than a given number\n";
    std::cout<<"3 - see adoption list in console\n";
    std::cout<<"4 - see adoption list with proper program\n";
}



void UserInterface::runUser() {
    std::string action;
    std::string repo_type;

    for(;;) {
        this->printUserMenu();

        action = this->chooseAction();

        if(action == "0") {
            break;
        }

        else if(action == "1") {
            this->UIIterateAllDogs();
        }

        else if(action == "2") {
            this->UIIterateSortedDogs();
        }

        else if(action == "3") {
            this->displayAdoptionList();
        }

        else if(action == "4") {
            this->displayProgramAdoptionList();
        }

        else {
            std::cout<<"Invalid action. Please try again!";
        }

    }
}

std::string UserInterface::getCurrentDir()  {
    char buffer[300];
    getcwd(buffer, 300);
    return std::string(buffer);
}

void UserInterface::startProgram() {

    std::string mode;

    this->program_controller.adminLoadDogsFromFile();
    for(;;) {
        mode = this->chooseMode();
        if(mode == "0") {
            break;
        }
        if(mode == "1") {
            this->runAdmin();
        }
        else if(mode == "2") {
            this->runUser();
        }
        else {
            std::cout<<"Error: Invalid mode!\n";
        }
    }
}