//
// Created by Filip on 17-Mar-21.
//

#include "DogEntity.h"


Dog::Dog(std::string breed, std::string name, int age, std::string photograph) {
    this->breed = breed;
    this->name = name;
    this->age = age;
    this->photograph = photograph;
}

Dog::Dog(std::string name) {
    this->breed = "";
    this->name = name;
    this->age = 0;
    this->photograph = "";
}

Dog::Dog(std::string name, int age) {
    this->breed = "";
    this->name = name;
    this->age = age;
    this->photograph = "";
}

Dog::Dog(std::string name, std::string photograph) {
    this->breed = "";
    this->name = name;
    this->age = 0;
    this->photograph = photograph;
}

Dog::Dog() {
    this->breed = "";
    this->name = "";
    this->age = 0;
    this->photograph = "";
}

bool Dog::operator==(const Dog& dog) {
    if(this->name == dog.name)
        return true;
    return false;
}

Dog& Dog::operator=(const Dog& dog) {
    this->breed = dog.breed;
    this->name = dog.name;
    this->age = dog.age;
    this->photograph = dog.photograph;
    return *this;
}

std::string Dog::getBreed() const {
    return this->breed;
}

std::string Dog::getName() const {
    return this->name;
}

int Dog::getAge() const {
    return this->age;
}

std::string Dog::getPhotograph() const {
    return this->photograph;
}

void Dog::setBreed(std::string new_breed) {
    this->breed = new_breed;
}

void Dog::setName(std::string new_name) {
    this->name = new_name;
}

void Dog::setAge(int new_age) {
    this->age = new_age;
}

void Dog::setPhotograph(std::string new_photograph) {
    this->photograph = new_photograph;
}

bool Dog::isEmpty() {
    if(this->breed == "") {
        if(this->name =="") {
            if(this->age == 0) {
                if(this->photograph == "") {
                    return true;
                }
            }
        }
    }
    return false;
}

std::string Dog::getCSV() {
    std::string csv_string;
    csv_string += this->getBreed() + ",";
    csv_string += this->getName() + ",";
    csv_string +=  std::to_string(this->getAge()) + ",";
    csv_string += this->getPhotograph();
    return csv_string;
}

std::string Dog::getHTML() {
    std::string html_string;
    html_string =  "\t<tr>\n";
    html_string +=  "\t\t<td>" + this->getBreed() + "</td>\n";
    html_string +=  "\t\t<td>" + this->getName() + "</td>\n";
    html_string +=  "\t\t<td>" + std::to_string(this->getAge()) + "</td>\n";
    html_string +=  "\t\t<td><a href=\"" + this->getPhotograph() + "\">Link</a></td>\n";

    return html_string;
}

std::string Dog::getFirstThreeAttributesCSV() {
    std::string csv_string;
    csv_string += this->getBreed() + ",";
    csv_string += this->getName() + ",";
    csv_string +=  std::to_string(this->getAge());
    return csv_string;
}

std::istream& operator >>(std::istream& inputStream, Dog& dog) {
    std::string line;
    std::getline(inputStream, line);
    std::vector<std::string> tokens = splitLineByDelimiter(line, ",");
    if(tokens.size() != 4)
        return inputStream;

    dog.setBreed(tokens[0]);
    dog.setName(tokens[1]);
    dog.setAge(std::stoi(tokens[2]));
    dog.setPhotograph(tokens[3]);

    return inputStream;
}

std::ostream& operator <<(std::ostream& outputStream, Dog& dog) {
    outputStream << dog.getCSV();
    return outputStream;
}