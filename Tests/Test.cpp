//
// Created by Filip on 22-Mar-21.
//

#include <iostream>
#include "Test.h"
#include "../Exceptions/ProgramExceptions.h"

void Test::testAll() {
    this->testManualAdminFunctionalities();
    this->testAutoAdminFunctionalities();
//    this->testSQLRepo();
}

void Test::testManualAdminFunctionalities() {
    Repository test_repo;
    AdminService test_service(test_repo);

    test_service.serviceAddDog("Caucasian", "Toby", 15, "https://www.google.com/");
    try {
        test_service.serviceAddDog("Caucasian", "Toby", 15, "https://www.google.com/");
    }
    catch(...) {
        assert(true);
    }

    assert(test_service.getAllDogs()[0].getName() == "Toby");

    test_service.serviceAddDog("Caucasian", "Bob", 12, "https://www.google.com/");
    test_service.serviceAddDog("Caucasian", "asdf", 13, "https://www.google.com/");

    assert(test_service.getAllDogs()[1].getName() == "Bob");

    test_service.serviceDeleteDog("Bob");

    try {
        test_service.serviceDeleteDog("Bob");
    }
    catch(...) {
        assert(true);
    }

    try {
        test_service.serviceUpdateDogAge("Bob", 22);
    }
    catch(...) {
        assert(true);
    }

    try {
        test_service.serviceUpdateDogPhoto("Bob", "eee");
    }
    catch(...) {
        assert(true);
    }

    assert(test_service.getAllDogs()[1].getName() == "asdf");

    test_service.serviceUpdateDogPhoto("asdf", "https://www.google.com/");
    assert(test_service.getAllDogs()[1].getPhotograph() == "https://www.google.com/");

    test_service.serviceUpdateDogAge("asdf", 101);
    assert(test_service.getAllDogs()[1].getAge() == 101);

}

void Test::testAutoAdminFunctionalities() {
    Repository test_repo;
    AdminService test_service(test_repo);
    test_service.servicePopulateShelter();
    test_service.serviceAddDog("Caucasian", "Bob", 12, "https://www.google.com/");
    test_service.serviceAddDog("Caucasian", "asdf", 13, "https://www.google.com/");
    assert(test_service.getAllDogs()[11].getName() == "asdf");
    Dog new_dog;
    new_dog.setName("eee");
    assert(new_dog.getName() == "eee");


    try {
        Validator::validatePhoto("asdads");
    }
    catch (...) {
        assert(true);
    }


}

//void Test::testSQLRepo() {
//
//    Repository* base_repo = new SQLRepo;
//
//    base_repo->setFileName("test.db");
//
//    std::vector<Dog> test_dog_record = base_repo->getRecord();
//    for(auto dog: test_dog_record)
//        std::cout<<dog.getName() << " "<<(int) dog.getAge()<< " " << dog.getPhotograph()<<"\n";
//
//    delete base_repo;
//
//}
