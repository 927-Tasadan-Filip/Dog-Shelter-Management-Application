//
// Created by Filip on 18-Mar-21.
//

#pragma once

#include "DogEntity.h"
#include <vector>
#include "../Validator/ProgramValidator.h"

class Repository {
private:
    std::vector<Dog> record;
    std::string file_name;

public:

    Repository();

    virtual ~Repository();

    // About: add a new dog object to the record dynamic array
    // new_dog - the new dog object that should be added in the record array (Type: Dog)
    // Throw: an exception if there is another dog with the same dog as this one in the array
    virtual void addDog(const Dog &new_dog);

    // About: update an existing dog object from the record dynamic array
    // new_dog - the new dog object which contains the attributes that should be changed to the existing dog (Type: Dog)
    // mode - the update mode (if it's 'a' then the age of the dog should be updated, and if it's 'p' then the photograph of the dog should be updated)
    // Throw: an exception if there is no dog, in the record array, with the same name as the given dog
    virtual int updateDog(Dog given_dog, char mode);

    // About: delete a dog from the array by it's name
    // given_dog: represent a dog object which have the same name as the dog from the record array which should be removed
    // Throw: an exception if there is no dog, in the record array, with the same name as the given dog
    virtual void deleteDog(const Dog &given_dog);

    // Return: the list of all dogs currently in the record dynamic array
    virtual std::vector<Dog> getRecord();

    virtual void setFileName(std::string file_name);

    virtual void readRecordsFromFile();

    virtual void writeRecordsToFile();

    virtual std::string repoGetFileName();

};


