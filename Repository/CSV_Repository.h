//
// Created by Filip on 15-Apr-21.
//

#pragma once
#include "Repository.h"
class CSVRepo: public Repository {
private:
    std::vector<Dog> csv_record;
    std::string csv_file_name;


public:
    // About: add a new dog object to the record dynamic array
    // new_dog - the new dog object that should be added in the record array (Type: Dog)
    // Throw: an exception if there is another dog with the same dog as this one in the array
    void addDog(const Dog &new_dog);

    void setFileName(std::string file_name);

    // Return: the list of all dogs currently in the record dynamic array
    std::vector<Dog> getRecord();

    void writeRecordsToFile();

    std::string repoGetFileName();

};