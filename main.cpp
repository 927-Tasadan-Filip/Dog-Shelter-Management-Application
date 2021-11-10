//
// Created by Filip on 18-Mar-21.
//

#include "UI.h"
#include "Tests/Test.h"
#include "Repository.h"
#include "GUI/QtGUI.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    Test test_object;
    test_object.testAll();

    std::string admin_repo_type;
    std::string user_repo_type;
    char file_type;

    std::cout<<"Enter the admin repo type ( TXT / SQL ) >> ";
    std::cin>>admin_repo_type;
    Repository* admin_repo;

    if(admin_repo_type == "TXT") {
        admin_repo = new Repository;
        admin_repo->setFileName("records.txt");
    }
    else if(admin_repo_type == "SQL") {

        admin_repo = new SQLRepo;
        admin_repo->setFileName("sql_records.db");
    }

    std::cout<<"Enter the user repo type ( CSV / HTML ) >> ";
    std::cin>>user_repo_type;

    Repository* user_repo;

    if(user_repo_type == "CSV") {
        user_repo = new CSVRepo;
        user_repo->setFileName("adoption_list.csv");
        file_type ='C';
    }
    else if(user_repo_type == "HTML") {

        user_repo = new HTMLRepository;
        user_repo->setFileName("adoption_list.html");
        file_type ='H';
    }

    AdminService program_service(*admin_repo);
    UserController user_controller(*user_repo, file_type);

    std::string interface_type;
    std::cout<<"Enter the user interface mode ( CUI / GUI ) >> ";
    std::cin>>interface_type;

    if(interface_type == "CUI") {
        UserInterface program_ui(program_service, user_controller);

        program_ui.startProgram();

        delete user_repo;
        delete admin_repo;
    }
    else if(interface_type == "GUI") {
        QApplication a(argc, argv);
        GUI program_gui(program_service, user_controller);
        program_gui.show();

        return a.exec();
    }


    return 0;
}