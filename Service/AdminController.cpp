//
// Created by Filip on 18-Mar-21.
//

#include "AdminController.h"
#include <stack>
#include <memory>
#include <utility>
#include <algorithm>

AdminService::AdminService(Repository &given_repository): program_repo{given_repository} {
    this->command_manager = new CommandManager();
}


void AdminService::serviceAddDog(std::string breed, std::string name, int age, std::string photograph) {
    Validator::validateAge(age);
    Validator::validatePhoto(photograph);

    Dog new_dog{breed, name, age, photograph};
    std::shared_ptr<Command> add_cmd(new AddCommand(&this->program_repo, new_dog));
    this->command_manager->executeCmd(add_cmd);
}

void AdminService::serviceDeleteDog(std::string name) {
    Dog to_del_dog{name};
    Dog del_dog{};
    del_dog = this->searchForDogByName(name);
    std::shared_ptr<Command> del_cmd(new DeleteCommand(&this->program_repo, del_dog, to_del_dog));
    this->command_manager->executeCmd(del_cmd);
}

void AdminService::serviceUpdateDogAge(std::string name, int new_age) {
    Dog to_updt_dog{name, new_age};
    Dog updated_dog{};
    updated_dog = this->searchForDogByName(name);
    if(updated_dog.getAge() != new_age) {
        std::shared_ptr<Command> updt_cmd(new UpdateAgeCommand(&this->program_repo, updated_dog, to_updt_dog));
        this->command_manager->executeCmd(updt_cmd);
    }
}

void AdminService::serviceUpdateDogPhoto(std::string name, std::string new_photo) {

    Dog to_updt_dog{name, new_photo};
    Dog updated_dog{};
    updated_dog = this->searchForDogByName(name);
    if(updated_dog.getPhotograph() != new_photo) {
        std::shared_ptr<Command> updt_cmd(new UpdatePhotoCommand(&this->program_repo, updated_dog, to_updt_dog));
        this->command_manager->executeCmd(updt_cmd);
    }
}

std::vector<Dog> AdminService::getAllDogs() {
    return this->program_repo.getRecord();
}

void AdminService::servicePopulateShelter() {

    Dog new_dog_1{"Caucasian", "Beti", 6, "https://www.google.com/search?q=caucasian+shepherd+dog&rlz=1C1GCEA_enRO919RO919&source=lnms&tbm=isch&sa=X&ved=2ahUKEwjaidSH8NnvAhWZPewKHaW6DfgQ_AUoAXoECAEQAw&biw=1280&bih=881#imgrc=8IPZh03AOuVfIM"};
    this->program_repo.addDog(new_dog_1);

    Dog new_dog_2{"Akita", "Hachiko", 10, "https://www.google.com/search?q=hachiko&source=lnms&tbm=isch&sa=X&ved=2ahUKEwirsMa489nvAhVl-SoKHVrLBWQQ_AUoAXoECAEQAw&biw=1280&bih=881&dpr=1#imgrc=PCAuo7sgtnIe0M"};
    this->program_repo.addDog(new_dog_2);

    Dog new_dog_3{"Afgan", "Toby", 5, "https://en.wikipedia.org/wiki/Afghan_Hound#/media/File:Afghane.jpg"};
    this->program_repo.addDog(new_dog_3);

    Dog new_dog_4{"Husky", "Balto", 9, "https://en.wikipedia.org/wiki/Balto#/media/File:Gunnar_Kaasen_with_Balto.jpg"};
    this->program_repo.addDog(new_dog_4);

    Dog new_dog_5{"Siberian", "Laika", 8, "https://en.wikipedia.org/wiki/Laika#/media/File:Laika_(Soviet_dog).jpg"};
    this->program_repo.addDog(new_dog_5);

    Dog new_dog_6{"Collie", "Lassie", 3, "https://en.wikipedia.org/wiki/Lassie#/media/File:Lassie_and_Tommy_Rettig_1956.JPG"};
    this->program_repo.addDog(new_dog_6);

    Dog new_dog_7{"Cartoon", "Scooby-Doo", 12, "https://en.wikipedia.org/wiki/Scooby-Doo#/media/File:Scooby-gang-1969.jpg"};
    this->program_repo.addDog(new_dog_7);

    Dog new_dog_8{"Cartoon", "Snoopy", 5, "https://en.wikipedia.org/wiki/Snoopy#/media/File:Snoopy_Peanuts.png"};
    this->program_repo.addDog(new_dog_8);

    Dog new_dog_9{"Wolf", "TinTin", 4, "https://en.wikipedia.org/wiki/Wolfdog#/media/File:Llop.jpg"};
    this->program_repo.addDog(new_dog_9);

    Dog new_dog_10{"Rottweiler", "Jack", 9, "https://en.wikipedia.org/wiki/Rottweiler#/media/File:Rottweiler_standing_facing_left.jpg"};
    this->program_repo.addDog(new_dog_10);


}

void AdminService::adminLoadDogsFromFile() {
    this->program_repo.readRecordsFromFile();
}

void AdminService::adminServiceSetFileName(std::string file_name) {
    this->program_repo.setFileName(file_name);
}

void AdminService::undoLastOperation() {
    this->command_manager->undo();
}

void AdminService::redoLastOperation() {
    this->command_manager->redo();
}


Dog AdminService::searchForDogByName(std::string dog_name) {
    for(auto dog_entity: this->program_repo.getRecord()) {
        if(dog_entity.getName() == dog_name) {
            return dog_entity;
        }
    }
    Dog empty_dog{};
    return empty_dog;
}

