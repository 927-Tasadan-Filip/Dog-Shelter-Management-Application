//
// Created by Filip on 08-Apr-21.
//

#include "ProgramValidator.h"

void Validator::validateAge(int age) {
    if(age < 0 or age > 40)
        throw ValidationException("Invalid dog age!");
}

void Validator::validatePhoto(std::string photo) {
    if(photo.find("https://") == std::string::npos)
        throw ValidationException("Invalid photo link!");
}