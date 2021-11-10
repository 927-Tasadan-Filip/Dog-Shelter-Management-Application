//
// Created by Filip on 15-Apr-21.
//

#include "HTML_Repository.h"

void HTMLRepository::addDog(const Dog &new_dog) {

    for(auto & i : this->html_record)
        if(i == new_dog)
            throw RepoException("There is another dog with the given name!");

    this->html_record.push_back(new_dog);
    this->writeRecordsToFile();
}

std::vector<Dog> HTMLRepository::getRecord() {
    return this->html_record;
}

void HTMLRepository::setFileName(std::string file_name) {
    this->html_file_name = file_name;
}

void HTMLRepository::writeRecordsToFile() {
    if(this->html_file_name.empty())
        return;

    std::string htmlString{};

    htmlString += "<!DOCTYPE html>\n";
    htmlString += "\t<html>\n";
    htmlString += "\t\t<head>\n";
    htmlString += "\t\t\t<title>Dogs adoption list</title>\n";
    htmlString += "\t\t</head>\n";
    htmlString += "\t<body>\n";
    htmlString += "\t<table border=\"1\">\n";
    htmlString += "\t<tr>\n";
    htmlString += "\t\t<th>Breed</th>\n";
    htmlString += "\t\t<th>Name</th>\n";
    htmlString += "\t\t<th>Age</th>\n";
    htmlString += "\t\t<th>Photograph link</th>\n";
    htmlString += "\t</tr>\n";



    for(auto & current_dog : this->html_record)
        htmlString += current_dog.getHTML();

    htmlString += "\t</table>\n";
    htmlString += "\t</body>\n";
    htmlString += "\t</html>\n";

    std::ofstream outputStream(this->html_file_name);
    outputStream << htmlString;

    outputStream.close();
}

std::string HTMLRepository::repoGetFileName() {
    return this->html_file_name;
}
