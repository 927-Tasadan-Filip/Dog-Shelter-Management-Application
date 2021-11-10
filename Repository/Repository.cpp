//
// Created by Filip on 18-Mar-21.
//

#include "Repository.h"
#include <iostream>
#include <string>

Repository::Repository() {
    this->file_name = "";
}


void Repository::addDog(const Dog& new_dog) {
    this->readRecordsFromFile();
    for(auto & i : this->record)
        if(i == new_dog)
            throw RepoException("There is another dog with the given name!");
    this->record.push_back(new_dog);
    this->writeRecordsToFile();
}

int Repository::updateDog(Dog given_dog, char mode) {
    this->readRecordsFromFile();
    int ok = 0;
    for(auto & i : this->record)
        if(i == given_dog) {
            if(mode == 'a') {
                if(given_dog.getAge() != i.getAge()) {
                    ok = 1;
                }
                given_dog.setBreed(i.getBreed());
                given_dog.setPhotograph(i.getPhotograph());
                i = given_dog;
            }
            if(mode == 'p') {
                if(given_dog.getPhotograph() != i.getPhotograph()) {
                    ok = 1;
                }
                given_dog.setBreed(i.getBreed());
                given_dog.setAge(i.getAge());
                i = given_dog;
            }
            this->writeRecordsToFile();
            return ok;
        }
    throw RepoException("There is no dog with the given name!");
}
void Repository::deleteDog(const Dog& given_dog) {
    this->readRecordsFromFile();
    for(int i=0; i< this->record.size(); i++)
        if(this->record[i] == given_dog) {
            this->record.erase(this->record.begin() + i);
            this->writeRecordsToFile();
            return;
        }
    throw RepoException("There is no dog with the given name!");

}

std::vector<Dog> Repository::getRecord() {
    this->readRecordsFromFile();;
    return this->record;
}

void Repository::setFileName(std::string file_name) {
    this->file_name = file_name;
    this->readRecordsFromFile();
}

void Repository::readRecordsFromFile() {
    if(this->file_name.empty())
        return;

    std::ifstream inputStream(this->file_name);

    std::vector<Dog> file_dog_records;
    file_dog_records.clear();
    Dog current_dog;
    while (inputStream >> current_dog) {
        file_dog_records.push_back(current_dog);
    }

    this->record = file_dog_records;

    inputStream.close();

}

void Repository::writeRecordsToFile() {
    if(this->file_name.empty())
        return;

    std::ofstream outputStream(this->file_name);

    for(auto & current_dog : this->record)
        outputStream<<current_dog<<"\n";

    outputStream.close();
}

std::string Repository::repoGetFileName() {
    return this->file_name;
}

Repository::~Repository() = default;

