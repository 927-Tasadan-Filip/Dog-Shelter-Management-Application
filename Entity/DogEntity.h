//
// Created by Filip on 17-Mar-21.
//

#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <fstream>
#include "../StringFunctions/StringFunctions.h"

class Dog {
private:
    std::string breed;
    std::string name;
    int age;
    std::string photograph;

public:
    // About: This is the constructor of a new dog object.
    // breed - a string which contains the breed of the new  (type: std::string)
    // name -  a string which contains the nam of the new dog(type: std::string)
    // age - an integer number representing the age of the new dog (type: integer)
    // photograph -  a string which contains the photograph link of the new dog (type: std::string)
    Dog(std::string breed, std::string name, int age, std::string photograph);

    // About: This is the constructor of a new dog object (the fields which don't receive a value will be set as default).
    // name -  a string which contains the nam of the new country which will be created (type: std::string)
    Dog(std::string name);

    // About: This is the constructor of a new dog object (the fields which don't receive a value will be set as default).
    // name -  a string which contains the nam of the new country which will be created (type: std::string)
    // age - an integer number representing the age of the new dog (type: integer)
    Dog(std::string name, int age);

    // About: This is the constructor of a new dog object (the fields which don't receive a value will be set as default).
    // name -  a string which contains the nam of the new country which will be created (type: std::string)
    // photograph -  a string which contains the photograph link of the new dog which will be created (type: std::string)
    Dog(std::string name, std::string photograph);

    // About: This is the default constructor of a new dog object.
    Dog();

    // About: operator override method which will check if two dogs have the same name (this mean that they are the same dog)
    // Return: true if the dogs have the same name, false otherwise
    bool operator==(const Dog& dog);

    // About: operator override method which will return a copy of a given dog whenever we use the "=" operator with respect to the dog class
    // Returns a copy object of the given dog
    Dog& operator=(const Dog& dog);

    // These are the getters methods for different attributes of the dog class
    std::string getBreed() const;
    std::string getName() const;
    int getAge() const;
    std::string getPhotograph() const;

    // These are the setter methods for different attributes of the dog class
    void setBreed(std::string new_breed);
    void setName(std::string new_name);
    void setAge(int new_age);
    void setPhotograph(std::string new_photograph);

    bool isEmpty();

    std::string getCSV();
    std::string getHTML();
    std::string getFirstThreeAttributesCSV();

    friend std::istream& operator >>(std::istream& inputStream, Dog& dog);
    friend std::ostream& operator <<(std::ostream& outputStream, Dog& dog);

};

