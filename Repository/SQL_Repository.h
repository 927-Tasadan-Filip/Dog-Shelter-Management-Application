//
// Created by Filip on 19-Apr-21.
//

#pragma once

#include <vector>
#include "Repository.h"
#include "../SQL_Source_files/sqlite3.h"

class SQLRepo: public Repository {
private:
    std::vector<Dog> sql_record;
    sqlite3 *db_connection;
    std::string db_name;
public:

    ~SQLRepo();

    // About: add a new dog object to the record dynamic array
    // new_dog - the new dog object that should be added in the record array (Type: Dog)
    // Throw: an exception if there is another dog with the same dog as this one in the array
    void addDog(const Dog &new_dog);

    // About: update an existing dog object from the record dynamic array
    // new_dog - the new dog object which contains the attributes that should be changed to the existing dog (Type: Dog)
    // mode - the update mode (if it's 'a' then the age of the dog should be updated, and if it's 'p' then the photograph of the dog should be updated)
    // Throw: an exception if there is no dog, in the record array, with the same name as the given dog
    int updateDog(Dog given_dog, char mode);

    // About: delete a dog from the array by it's name
    // given_dog: represent a dog object which have the same name as the dog from the record array which should be removed
    // Throw: an exception if there is no dog, in the record array, with the same name as the given dog
    void deleteDog(const Dog &given_dog);

    // Return: the list of all dogs currently in the record dynamic array
    std::vector<Dog> getRecord();

    void readRecordsFromFile();

    std::string repoGetFileName();

    void setFileName(std::string file_name);

    virtual void createTable();

    static int emptyCallback(void *NotUsed, int argc, char **argv, char **azColName);

    };


