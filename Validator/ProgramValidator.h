//
// Created by Filip on 08-Apr-21.
//

#pragma once
#include <string>
#include "../Exceptions/ProgramExceptions.h"

class Validator {
public:
    static void validateAge(int age);
    static void validatePhoto(std::string photo);
};
