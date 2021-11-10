//
// Created by Filip on 15-Apr-21.
//

#include "CSV_Repository.h"

void CSVRepo::addDog(const Dog &new_dog) {


    for(auto & i : this->csv_record)
        if(i == new_dog)
            throw RepoException("There is another dog with the given name!");

    this->csv_record.push_back(new_dog);
    this->writeRecordsToFile();
}

std::vector<Dog> CSVRepo::getRecord() {
    return this->csv_record;
}

void CSVRepo::setFileName(std::string file_name) {
    this->csv_file_name = file_name;
}

void CSVRepo::writeRecordsToFile() {
    if(this->csv_file_name.empty())
        return;

    std::string csv_data_string = "";

    for(auto & current_dog : this->csv_record)
        csv_data_string += current_dog.getCSV() + "\n";

    std::ofstream outputStream(this->csv_file_name);
    outputStream<<csv_data_string;
    outputStream.close();
}

std::string CSVRepo::repoGetFileName() {
    return this->csv_file_name;
}