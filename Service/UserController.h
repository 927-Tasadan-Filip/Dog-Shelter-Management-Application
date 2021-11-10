//
// Created by Filip on 22-Mar-21.
//

#pragma once

#include "DogEntity.h"
#include "Repository.h"
#include "CSV_Repository.h"
#include "HTML_Repository.h"
#include <string>

class UserController {
private:
    Repository& adoption_list;
    char file_type;

public:
    UserController(Repository& given_repository, char f_type);


    // About: add the given_dog to the adoption list
    // given_dog: the Dog object which should be added to the adoption list (type: Dog)
    void addToAdoptionList(const Dog &given_dog);

    // About: filter the dogs of the dog_array by keeping only those who have a given breed and their age is lower than the max_age
    // Return: a dynamic array containing the filtered dogs (type: DynamicArray<Dog>)
    std::vector<Dog> sortDogs(const std::vector<Dog> &dog_array, std::string breed, int max_age);

    // Return: the adoption list (type: DynamicArray<Dog>)
    std::vector<Dog> getAdoptionList();

    bool isCSV();
    bool isHTML();

    std::string getFileName();


};

