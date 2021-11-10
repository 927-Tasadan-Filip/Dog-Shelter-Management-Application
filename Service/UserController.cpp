//
// Created by Filip on 22-Mar-21.
//

#include "UserController.h"

UserController::UserController(Repository &given_repository, char f_type): adoption_list{given_repository}, file_type{f_type} {}

void UserController::addToAdoptionList(const Dog& given_dog)   {
    this->adoption_list.addDog(given_dog);
}

std::vector<Dog> UserController::sortDogs(const std::vector<Dog> &dog_array, std::string breed, int max_age) {

    if(breed.empty()) {
        return dog_array;
    }

    std::vector<Dog> copy_dog_array = dog_array;
    std::vector<Dog> filtered_dog_array(dog_array.size());


    auto it = std::copy_if(copy_dog_array.begin(), copy_dog_array.end(), filtered_dog_array.begin(),
                           [breed, max_age](Dog &current_dog){ return ((current_dog.getAge() <= max_age) && (current_dog.getBreed() == breed));});
    filtered_dog_array.resize(std::distance(filtered_dog_array.begin(), it));
    return filtered_dog_array;
}

std::vector<Dog> UserController::getAdoptionList() {
    return this->adoption_list.getRecord();

}

bool UserController::isCSV() {
    if(this->file_type == 'C')
        return true;
    return false;
}

bool UserController::isHTML() {
    if(this->file_type == 'H')
        return true;
    return false;
}

std::string UserController::getFileName() {
    return this->adoption_list.repoGetFileName();
}
