//
// Created by Filip on 08-Apr-21.
//

#pragma once
#include <exception>
#include <string>


class RepoException: public std::exception {
private:
    std::string info;

public:
    explicit RepoException(std::string given_info) {
        this->info = given_info;
    }
    std::string getInfo() { return this->info; }

};

class ValidationException: public std::exception {
private:
    std::string info;

public:
    explicit ValidationException(std::string given_info) {
        this->info = given_info;
    }
    std::string getInfo() { return this->info; }

};