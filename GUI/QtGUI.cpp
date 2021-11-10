//
// Created by Filip on 05-May-21.
//

#include "QtGUI.h"
#include <iostream>
#include <QDebug>
#include <Windows.h>
#include <shellapi.h>
#include <unistd.h>
#include <map>
#include <shellapi.h>


GUI::GUI(AdminService &given_admin_controller, UserController &given_user_controller, QWidget *parent)
        : program_controller{given_admin_controller}, user_program_controller{given_user_controller}, QWidget{parent} {
    this->program_controller.adminLoadDogsFromFile();
    this->initGUI();
    this->connectInitialSignalsAndSlots();


}

GUI::~GUI() {}

void GUI::initGUI() {

    QFont button_font("Arial", 25, 10);

    QGridLayout *gridLayout = new QGridLayout{this};

    // add some buttons
    this->admin_mode_button = new QPushButton("Admin mode");
    this->user_mode_button = new QPushButton("User mode");
    this->data_chart_button = new QPushButton("Data chart");
    this->admin_mode_button->setFont(button_font);
    this->user_mode_button->setFont(button_font);
    this->data_chart_button->setFont(button_font);


    gridLayout->addWidget(this->admin_mode_button, 0, 0);
    gridLayout->addWidget(this->user_mode_button, 1, 0);
    gridLayout->addWidget(this->data_chart_button, 2, 0);

    this->connectMenuButtons();
}

void GUI::connectInitialSignalsAndSlots() {
    // connect Signals to slots
    QObject::connect(this, &GUI::adminModeSignal, this, &GUI::initAdminMode);
    QObject::connect(this, &GUI::userModeSignal, this, &GUI::initUserMode);
    QObject::connect(this, &GUI::dataChartSignal, this, &GUI::dataChartSlot);
    QObject::connect(this, &GUI::listUpdateSignal, this, &GUI::displayDogList);
    QObject::connect(this, &GUI::backToMenuSignal, this, &GUI::initGUI);
    QObject::connect(this, SIGNAL(addNewDogSignal(const std::string &,const std::string &, int,const std::string &)), this, SLOT(addNewDogSlot(const std::string &,const std::string &, int,const std::string &)));
    QObject::connect(this, SIGNAL(deleteDogSignal(const std::string &)), this, SLOT(deleteDogSlot(const std::string &)));
    QObject::connect(this, SIGNAL(operationStatusSignal(const std::string &)), this, SLOT(updateOperationStatusSlot(const std::string &)));
    QObject::connect(this, SIGNAL(updateDogSignal(const std::string &, int, const ::std::string &)), this, SLOT(updateDogSlot(const std::string&, int, const::std::string&)));
    QObject::connect(this, &GUI::iterateDogsWindowSignal, this, &GUI::iterateDogsWindowSlot);
    QObject::connect(this, &GUI::currentDogUpdateSignal, this, &GUI::currentDogUpdateSlot);
    QObject::connect(this, &GUI::displayAdoptionListSignal, this, &GUI::displayAdoptionListSlot);
    QObject::connect(this, &GUI::backToUserMenuSignal, this, &GUI::initUserMode);
    QObject::connect(this, &GUI::filterMenuSignal, this, &GUI::filterMenuSlot);
    QObject::connect(this, &GUI::seeAdoptionListSignal, this, &GUI::seeAdoptionListSlot);
    QObject::connect(this, &GUI::seeAdoptionDisplayListSignal, this, &GUI::seeAdoptionDisplayListSlot);
    QObject::connect(this, &GUI::adminUndoSignal, this, &GUI::adminUndoSlot);
    QObject::connect(this, &GUI::adminRedoSignal, this, &GUI::adminRedoSlot);
    QObject::connect(this, &GUI::seeTableAdoptionListSignal, this, &GUI::seeTableAdoptionListSlot);

}

void GUI::connectMenuButtons() {
    QObject::connect(this->admin_mode_button, &QPushButton::clicked, this, &GUI::adminModeButtonHandler);
    QObject::connect(this->user_mode_button, &QPushButton::clicked, this, &GUI::userModeButtonHandler);
    QObject::connect(this->data_chart_button, &QPushButton::clicked, this, &GUI::dataChartButtonHandler);
}

void GUI::connectAdminButtons() {
    QObject::connect(this->admin_back_to_menu_button, &QPushButton::clicked, this, &GUI::adminBackToMenuButtonHandler);
    QObject::connect(this->add_new_dog_button, &QPushButton::clicked, this, &GUI::addNewDogButtonHandler);
    QObject::connect(this->delete_dog_button, &QPushButton::clicked, this, &GUI::deleteDogButtonHandler);
    QObject::connect(this->update_dog_button, &QPushButton::clicked, this, &GUI::updateDogButtonHandler);
    QObject::connect(this->dogs_list, &QListWidget::itemSelectionChanged, this, [this]() {this->changeElementListFields(); });
    QObject::connect(this->admin_undo_button, &QPushButton::clicked, this, &GUI::adminUndoButtonHandler);
    QObject::connect(this->admin_redo_button, &QPushButton::clicked, this, &GUI::adminRedoButtonHandler);

}

void GUI::adminModeButtonHandler() {
    this->admin_mode_button->close();
    this->user_mode_button->close();
    this->data_chart_button->close();
    delete this->layout();
    emit adminModeSignal();
}

void GUI::userModeButtonHandler() {
    this->admin_mode_button->close();
    this->user_mode_button->close();
    this->data_chart_button->close();
    delete this->layout();
    emit userModeSignal();
}

void GUI::dataChartButtonHandler() {
    this->admin_mode_button->close();
    this->user_mode_button->close();
    this->data_chart_button->close();
    delete this->layout();
    emit dataChartSignal();
}

void GUI::adminBackToMenuButtonHandler() {
    this->dogs_list->close();

    this->breed_edit->close();
    this->name_edit->close();
    this->age_edit->close();
    this->photo_edit->close();

    this->breed_label->close();
    this->name_label->close();
    this->age_label->close();
    this->photo_label->close();

    this->add_new_dog_button->close();
    this->delete_dog_button->close();
    this->update_dog_button->close();
    this->admin_back_to_menu_button->close();

    this->operation_status_label->close();
    this->operation_status_edit->close();

    this->admin_undo_button->close();
    this->admin_redo_button->close();

    delete this->layout();
    emit backToMenuSignal();
}

void GUI::addNewDogButtonHandler() {
    QString new_dog_breed = this->breed_edit->text();
    QString new_dog_name = this->name_edit->text();
    QString new_dog_age = this->age_edit->text();
    QString new_dog_photo = this->photo_edit->text();

    emit addNewDogSignal(new_dog_breed.toStdString(), new_dog_name.toStdString(), std::stoi(new_dog_age.toStdString()),
                         new_dog_photo.toStdString());

}

void GUI::deleteDogButtonHandler() {
    QString dog_name = this->name_edit->text();

    emit deleteDogSignal(dog_name.toStdString());
}

void GUI::updateDogButtonHandler() {
    QString dog_name = this->name_edit->text();
    QString dog_age = this->age_edit->text();
    QString dog_photo = this->photo_edit->text();

    emit updateDogSignal(dog_name.toStdString(), std::stoi(dog_age.toStdString()),
                         dog_photo.toStdString());
}

void GUI::adminUndoButtonHandler() {
    emit adminUndoSignal();
}

void GUI::adminRedoButtonHandler() {
    emit adminRedoSignal();
}

void GUI::initAdminMode() {
    QHBoxLayout *admin_general_layout = new QHBoxLayout{};
    this->setLayout(admin_general_layout);

    // left side - the dogs list
    this->dogs_list = new QListWidget{};
    this->dogs_list->setSelectionMode(QAbstractItemView::SingleSelection);
    this->dogs_list->setMinimumWidth(375);
    admin_general_layout->addWidget(this->dogs_list);

    // right side - dog info + buttons
    QWidget *right_side = new QWidget{};
    QVBoxLayout *vertical_layout = new QVBoxLayout{right_side};

    // dog information
    QWidget *dog_info_widget = new QWidget{};
    QFormLayout *form_layout = new QFormLayout{dog_info_widget};

    this->breed_edit = new QLineEdit{};
    this->name_edit = new QLineEdit{};
    this->age_edit = new QLineEdit{};
    this->photo_edit = new QLineEdit{};

    this->breed_edit->setMinimumWidth(375);
    this->name_edit->setMinimumWidth(375);
    this->age_edit->setMinimumWidth(375);
    this->photo_edit->setMinimumWidth(375);

    QFont label_font("Helvetica", 20);

    this->breed_label = new QLabel{"&Breed: "};
    breed_label->setBuddy(this->breed_edit);

    this->name_label = new QLabel{"&Name: "};
    name_label->setBuddy(this->name_edit);

    this->age_label = new QLabel{"&Age: "};
    age_label->setBuddy(this->age_edit);

    this->photo_label = new QLabel{"&Photo: "};
    photo_label->setBuddy(this->photo_edit);

    breed_label->setFont(label_font);
    name_label->setFont(label_font);
    age_label->setFont(label_font);
    photo_label->setFont(label_font);

    this->breed_edit->setFont(label_font);
    this->name_edit->setFont(label_font);
    this->age_edit->setFont(label_font);
    this->photo_edit->setFont(label_font);

    form_layout->addRow(breed_label, this->breed_edit);
    form_layout->addRow(name_label, this->name_edit);
    form_layout->addRow(age_label, this->age_edit);
    form_layout->addRow(photo_label, this->photo_edit);

    vertical_layout->addWidget(dog_info_widget);

    // buttons
    QFont button_font("Arial", 20, 10);

    QWidget *button_widget = new QWidget();
    QGridLayout *grid_layout = new QGridLayout{button_widget};

    this->add_new_dog_button = new QPushButton{"Add dog"};
    this->delete_dog_button = new QPushButton{"Delete dog"};
    this->update_dog_button = new QPushButton{"Update dog"};
    this->admin_back_to_menu_button = new QPushButton{"Back to menu"};

    this->add_new_dog_button->setFont(button_font);
    this->delete_dog_button->setFont(button_font);
    this->update_dog_button->setFont(button_font);
    this->admin_back_to_menu_button->setFont(button_font);

    grid_layout->addWidget(this->add_new_dog_button, 0, 0);
    grid_layout->addWidget(this->delete_dog_button, 0, 1);
    grid_layout->addWidget(this->update_dog_button, 0, 2);

    this->operation_status_label = new QLabel{"Operation status: "};
    this->operation_status_edit = new QTextEdit{};
    this->operation_status_edit->setMinimumWidth(600);
    this->operation_status_edit->setMinimumHeight(100);
    this->operation_status_label->setBuddy(this->operation_status_edit);

    this->operation_status_label->setFont(label_font);
    this->operation_status_edit->setFont(label_font);

    grid_layout->addWidget(this->operation_status_label, 1, 0);
    grid_layout->addWidget(this->operation_status_edit, 1, 1);

    this->admin_undo_button = new QPushButton("Undo");
    this->admin_undo_button->setFont(button_font);
    this->admin_undo_button->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));
    grid_layout->addWidget(this->admin_undo_button, 2, 0, 1, 1);

    this->admin_redo_button = new QPushButton("Redo");
    this->admin_redo_button->setFont(button_font);
    this->admin_redo_button->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y));
    grid_layout->addWidget(this->admin_redo_button, 2, 1, 1, 1);

    grid_layout->addWidget(this->admin_back_to_menu_button, 3, 0, 1, 2);

    vertical_layout->addWidget(button_widget);

    admin_general_layout->addWidget(right_side);
    this->displayDogList();

    this->connectAdminButtons();

}

void GUI::connectUserButtons() {
    QObject::connect(this->user_back_to_menu_button, &QPushButton::clicked, this, &GUI::userBackToMenuButtonHandler);
    QObject::connect(this->see_all_dogs_button, &QPushButton::clicked, this, &GUI::seeAllDogsButtonHandler);
    QObject::connect(this->see_all_breed_button, &QPushButton::clicked, this, &GUI::seeAllBreedButtonHandler);
    QObject::connect(this->see_adoption_button, &QPushButton::clicked, this, &GUI::displayAdoptionListButtonHandler);
    QObject::connect(this->see_adoption_with_program_button, &QPushButton::clicked, this, &GUI::seeAdoptionWithProgramButtonHandler);
    QObject::connect(this->see_adoption_list_table_button, &QPushButton::clicked, this, &GUI::seeAdoptionListTableButtonHandler);
}

void GUI::connectIteratorButtons() {
    QObject::connect(this->adopt_dog_button, &QPushButton::clicked, this, &GUI::adoptDogButtonHandler);
    QObject::connect(this->go_next_dog_button, &QPushButton::clicked, this, &GUI::goNextDogButtonHandler);
    QObject::connect(this->back_to_user_menu_button, &QPushButton::clicked, this, &GUI::backToUserMenuButtonHandler);
}

void GUI::connectFilterButtons() {
    QObject::connect(this->filter_see_dogs_button, &QPushButton::clicked, this, &GUI::filterSeeDogsButtonHandler);
}

void GUI::connectSeeAdoptionButtons() {
    QObject::connect(this->see_adoption_back_to_user_menu, &QPushButton::clicked, this, &GUI::seeAdoptionBackToUserMenuButtonHandler);
}

void GUI::connectDataChartButtons() {
    QObject::connect(this->data_chart_back_to_menu, &QPushButton::clicked, this, &GUI::dataChartBackToMenuButtonHandler);
}

void GUI::connectSeeTableButtons() {
    QObject::connect(this->see_table_back_to_user_menu_button, &QPushButton::clicked, this, &GUI::seeTableBackToUserMenuButtonHandler);
}


void GUI::userBackToMenuButtonHandler() {
    this->see_all_dogs_button->close();
    this->see_all_breed_button->close();
    this->see_adoption_button->close();
    this->see_adoption_with_program_button->close();
    this->user_back_to_menu_button->close();
    this->see_adoption_list_table_button->close();
    delete this->layout();

    emit backToMenuSignal();
}

void  GUI::seeAllDogsButtonHandler() {
    this->see_all_dogs_button->close();
    this->see_all_breed_button->close();
    this->see_adoption_button->close();
    this->see_adoption_with_program_button->close();
    this->see_adoption_list_table_button->close();
    this->user_back_to_menu_button->close();
    delete this->layout();

    this->iterator_dog_vector = this->program_controller.getAllDogs();

    emit iterateDogsWindowSignal();
}

void GUI::seeAllBreedButtonHandler() {
    this->see_all_dogs_button->close();
    this->see_all_breed_button->close();
    this->see_adoption_button->close();
    this->see_adoption_with_program_button->close();
    this->see_adoption_list_table_button->close();
    this->user_back_to_menu_button->close();
    delete this->layout();

    emit filterMenuSignal();
}

void GUI::displayAdoptionListButtonHandler() {
    this->see_all_dogs_button->close();
    this->see_all_breed_button->close();
    this->see_adoption_button->close();
    this->see_adoption_with_program_button->close();
    this->see_adoption_list_table_button->close();
    this->user_back_to_menu_button->close();
    delete this->layout();

    emit seeAdoptionListSignal();
}

void GUI::seeAdoptionListTableButtonHandler() {
    this->see_all_dogs_button->close();
    this->see_all_breed_button->close();
    this->see_adoption_button->close();
    this->see_adoption_with_program_button->close();
    this->see_adoption_list_table_button->close();
    this->user_back_to_menu_button->close();
    delete this->layout();

    emit seeTableAdoptionListSignal();
}


void GUI::seeAdoptionWithProgramButtonHandler() {

    if(this->user_program_controller.isCSV()) {
        std::string file = "\"" +  this->user_program_controller.getFileName()  + "\"";
        ShellExecuteA(NULL, NULL, "C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE", file.c_str(), NULL, SW_SHOWMAXIMIZED);
    }
    else {
    ShellExecuteA(NULL, NULL, "chrome.exe", "C:\\Users\\Filip\\Documents\\GitHub\\a89-917-Tasadan-Filip\\cmake-build-release\\adoption_list.html", NULL, SW_SHOWMAXIMIZED);

    }
}

void GUI::adoptDogButtonHandler() {
    if(!this->current_dog_entity.isEmpty()) {
        this->user_program_controller.addToAdoptionList(this->current_dog_entity);
        this->filterIteratorVectorByAdoptionList();
        emit currentDogUpdateSignal();
        emit displayAdoptionListSignal();
    }
}

void GUI::goNextDogButtonHandler() {
    emit currentDogUpdateSignal();
    emit displayAdoptionListSignal();
}

void GUI::backToUserMenuButtonHandler() {
    this->adoption_label->close();
    this->adoption_list->close();
    this->current_dog_label->close();
    this->current_dog_attributes_edit->close();
    this->adopt_dog_button->close();
    this->go_next_dog_button->close();
    this->back_to_user_menu_button->close();

    delete this->layout();

    emit backToUserMenuSignal();
}

void GUI::filterSeeDogsButtonHandler() {
    QString filter_dog_breed_qstring = this->filter_breed_edit->text();
    QString filter_dog_age_qstring  = this->filter_age_edit->text();

    std::string filter_dog_breed_string;
    std::string filter_dog_age_string;
    int filter_dog_age_int = 0;

    if(!filter_dog_breed_qstring.isEmpty()) {
        filter_dog_breed_string = filter_dog_breed_qstring.toStdString();
    }

    if(!filter_dog_age_qstring.isEmpty()) {
        filter_dog_age_string = filter_dog_age_qstring.toStdString();
    }

    if(!filter_dog_age_string.empty()) {
        filter_dog_age_int = std::stoi(filter_dog_age_string);
    }

    std::vector<Dog> shelter_dogs_vector = this->program_controller.getAllDogs();
    this->iterator_dog_vector = this->user_program_controller.sortDogs(shelter_dogs_vector, filter_dog_breed_string, filter_dog_age_int);

    this->filter_breed_label->close();
    this->filter_breed_edit->close();

    this->filter_age_label->close();
    this->filter_age_edit->close();

    this->filter_see_dogs_button->close();

    delete this->layout();

    emit iterateDogsWindowSignal();

}

void GUI::seeAdoptionBackToUserMenuButtonHandler() {
    this->see_adoption_label->close();
    this->see_adoption_list_widget->close();
    this->see_adoption_back_to_user_menu->close();

    delete this->layout();

    emit backToUserMenuSignal();

}

void GUI::dataChartBackToMenuButtonHandler() {
    this->data_chart_back_to_menu->close();
    this->breed_chart->close();
    delete this->layout();

    emit backToMenuSignal();
}

void GUI::seeTableBackToUserMenuButtonHandler() {
    this->adoption_table->close();
    this->see_table_back_to_user_menu_button->close();
    delete this->layout();

    emit backToUserMenuSignal();
}


void GUI::initUserMode() {
    this->admin_mode_button->close();
    this->user_mode_button->close();

    QFont button_font("Arial", 20, 10);

    QGridLayout* user_general_layout = new QGridLayout{};
    this->setLayout(user_general_layout);

    this->see_all_dogs_button = new QPushButton{"See all dogs"};
    this->see_all_dogs_button->setFont(button_font);

    this->see_all_breed_button = new QPushButton{"See all dogs of a given breed"};
    this->see_all_breed_button->setFont(button_font);

    this->see_adoption_button = new QPushButton{"See adoption list"};
    this->see_adoption_button->setFont(button_font);

    this->see_adoption_with_program_button = new QPushButton{"See adoption list with program"};
    this->see_adoption_with_program_button->setFont(button_font);

    this->see_adoption_list_table_button = new QPushButton{"See adoption list table"};
    this->see_adoption_list_table_button->setFont(button_font);

    this->user_back_to_menu_button = new QPushButton{"Back to menu"};
    this->user_back_to_menu_button->setFont(button_font);

    user_general_layout->addWidget(this->see_all_dogs_button,0,0);
    user_general_layout->addWidget(this->see_all_breed_button,0,1);

    user_general_layout->addWidget(this->see_adoption_button,1,0);
    user_general_layout->addWidget(this->see_adoption_with_program_button,1,1);

    user_general_layout->addWidget(this->see_adoption_list_table_button,2,0, 1, 2);
    user_general_layout->addWidget(this->user_back_to_menu_button,3,0, 1, 2);

    this->connectUserButtons();
}


void GUI::dataChartSlot() {
    std::map<std::string,int> dogs_breed_map;
    std::map<std::string,int>::iterator it;
    std::vector<Dog> dogs_vector = this->program_controller.getAllDogs();
    std::string current_breed;
    this->breed_chart = new QChart();

    for(auto dog_entity:dogs_vector) {
        current_breed = dog_entity.getBreed();
        it = dogs_breed_map.find(current_breed);
        if(it != dogs_breed_map.end()) {
            dogs_breed_map[current_breed] += 1;
        }
        else {
            dogs_breed_map.insert(std::pair<std::string,int>(current_breed, 1));
        }
    }
    QBarSeries *chart_series = new QBarSeries();
    for(it = dogs_breed_map.begin(); it != dogs_breed_map.end(); it++) {
        QBarSet *chart_set = new QBarSet(QString::fromStdString(it->first));
        *chart_set<<it->second;
        chart_series->append(chart_set);
    }

    this->breed_chart->addSeries(chart_series);
    this->breed_chart->setTitle("Dog breeds chart");
    this->breed_chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList breed_categories;
    breed_categories<<"Breeds";

    QBarCategoryAxis *x_axis = new QBarCategoryAxis();
    x_axis->append(breed_categories);
    this->breed_chart->addAxis(x_axis, Qt::AlignBottom);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setRange(0, 10);
    y_axis->applyNiceNumbers();
    this->breed_chart->addAxis(y_axis, Qt::AlignLeft);
    chart_series->attachAxis(y_axis);

    this->breed_chart->legend()->setVisible(true);
    this->breed_chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView* chart_view = new QChartView(this->breed_chart);
    chart_view->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout* chart_layout = new QVBoxLayout();
    this->setLayout(chart_layout);

    chart_layout->addWidget(chart_view);

    QFont button_font("Arial", 20, 10);
    this->data_chart_back_to_menu = new QPushButton("Back to menu");
    this->data_chart_back_to_menu->setFont(button_font);
    chart_layout->addWidget(this->data_chart_back_to_menu);

    this->resize(800, 500);

    this->connectDataChartButtons();

}

void GUI::displayDogList() {
    QFont element_font{"Agency",15};

    if(this->dogs_list->count() > 0)
        this->dogs_list->clear();

    std::vector<Dog> dog_vector = this->program_controller.getAllDogs();

    for(auto dog_entity: dog_vector) {

        QString list_element = QString::fromStdString(dog_entity.getCSV());
        QListWidgetItem* element = new QListWidgetItem{list_element};
        element->setFont(element_font);

        this->dogs_list->addItem(element);
    }

    if (this->dogs_list->count() > 0)
        this->dogs_list->setCurrentRow(0);
}

int GUI::getSelectedIndex() {
    if(this->dogs_list->count() == 0) {
        return -1;
    }
    QModelIndexList list_index = this->dogs_list->selectionModel()->selectedIndexes();

    if(list_index.size() == 0) {
        this->breed_edit->clear();
        this->name_edit->clear();
        this->age_edit->clear();
        this->photo_edit->clear();
        return -1;
    }

    int element_index = list_index.at(0).row();
    return element_index;
}

void GUI::changeElementListFields() {
    int element_index = this->getSelectedIndex();
    std::vector<Dog> dog_vector = this->program_controller.getAllDogs();

    if(element_index == -1 || element_index >= dog_vector.size()) {
        return;
    }

    Dog selected_dog = dog_vector[element_index];

    this->breed_edit->setText(QString::fromStdString(selected_dog.getBreed()));
    this->name_edit->setText(QString::fromStdString(selected_dog.getName()));
    this->age_edit->setText(QString::fromStdString(std::to_string(selected_dog.getAge())));
    this->photo_edit->setText(QString::fromStdString(selected_dog.getPhotograph()));
}

void GUI::filterIteratorVectorByAdoptionList() {
    std::vector<Dog> aux_iterator_dog_vector;
    bool is_in_adoption_flag;
    for(auto iterator_dog_entity: this->iterator_dog_vector) {
        is_in_adoption_flag = false;
        for(auto adopted_dog_entity: this->user_program_controller.getAdoptionList()) {
            if(iterator_dog_entity == adopted_dog_entity) {
                is_in_adoption_flag = true;
            }
        }
        if(!is_in_adoption_flag) {
            aux_iterator_dog_vector.push_back(iterator_dog_entity);
        }
    }
    this->iterator_dog_vector = aux_iterator_dog_vector;
}

std::string GUI::getCurrentDir()  {
    char buffer[300];
    getcwd(buffer, 300);
    return std::string(buffer);
}

void GUI::updateOperationStatusSlot(const std::string& status_string) {
    this->operation_status_edit->setText(QString::fromStdString(status_string));
}

void GUI::addNewDogSlot(const std::string &breed, const std::string &name, int age, const std::string &photo) {
    std::string status_string;
    try {
        this->program_controller.serviceAddDog(breed, name, age, photo);
        status_string = "Operation was successful";
    }
    catch(RepoException& repo_exception) {
        status_string = "Error: " + repo_exception.getInfo();
    }
    catch(ValidationException& validator_exception) {
        status_string = "Error: "+ validator_exception.getInfo();
    }
    emit listUpdateSignal();
    emit operationStatusSignal(status_string);
}

void GUI::deleteDogSlot(const std::string &name) {
    std::string status_string;
    try {
        this->program_controller.serviceDeleteDog(name);
        status_string = "Operation was successful";
    }
    catch(RepoException& repo_exception) {
        status_string = "Error: " + repo_exception.getInfo();
    }
    catch(ValidationException& validator_exception) {
        status_string = "Error: "+ validator_exception.getInfo();
    }
    emit listUpdateSignal();
    emit operationStatusSignal(status_string);

}

void GUI::updateDogSlot(const std::string &name, int age, const std::string &photo) {
    std::string status_string;
    try {
        this->program_controller.serviceUpdateDogAge(name, age);
        this->program_controller.serviceUpdateDogPhoto(name, photo);
        status_string = "Operation was successful";
    }
    catch(RepoException& repo_exception) {
        status_string = "Error: " + repo_exception.getInfo();
    }
    catch(ValidationException& validator_exception) {
        status_string = "Error: "+ validator_exception.getInfo();
    }
    emit listUpdateSignal();
    emit operationStatusSignal(status_string);
}

void GUI::adminUndoSlot() {
    std::string status_string;
    try {
        this->program_controller.undoLastOperation();
        status_string = "Operation was successful";
    }
    catch(ValidationException& validator_exception) {
        status_string = "Error: "+ validator_exception.getInfo();
    }
    emit listUpdateSignal();
    emit operationStatusSignal(status_string);
}

void GUI::adminRedoSlot() {
    std::string status_string;
    try {
        this->program_controller.redoLastOperation();
        status_string = "Operation was successful";
    }
    catch(ValidationException& validator_exception) {
        status_string = "Error: "+ validator_exception.getInfo();
    }
    emit listUpdateSignal();
    emit operationStatusSignal(status_string);
}

void GUI::iterateDogsWindowSlot() {

    this->current_iterator_position = -1;
    this->filterIteratorVectorByAdoptionList();

    QFont label_font("Helvetica", 20);
    QFont button_font("Arial", 20, 10);

    QHBoxLayout* iteration_general_layout = new QHBoxLayout{this};


        // right side
        QWidget* right_side = new QWidget{};
        QVBoxLayout* right_side_layout = new QVBoxLayout{right_side};

        this->adoption_list = new QListWidget{};
        this->adoption_list->setSelectionMode(QAbstractItemView::SingleSelection);
        this->adoption_list->setFont(label_font);
        this->adoption_list->setMinimumWidth(375);
        this->adoption_list->setMinimumHeight(400);

        this->adoption_label = new QLabel{"Adoption list"};
        this->adoption_label->setFont(label_font);

        right_side_layout->addWidget(this->adoption_label);
        right_side_layout->addWidget(this->adoption_list);

        iteration_general_layout->addWidget(right_side);

        // left side
        QWidget* left_side = new QWidget{};
        QGridLayout* left_side_layout = new QGridLayout{left_side};

        this->current_dog_label = new QLabel{"Current dog: "};
        this->current_dog_label->setFont(label_font);

        this->current_dog_attributes_edit = new QLineEdit{};
        this->current_dog_attributes_edit->setFont(label_font);
        this->current_dog_attributes_edit->setMinimumWidth(375);
        this->current_dog_label->setBuddy(this->current_dog_attributes_edit);


        left_side_layout->addWidget(this->current_dog_label, 0, 0);
        left_side_layout->addWidget(this->current_dog_attributes_edit, 0, 1);

        this->adopt_dog_button = new QPushButton{"Adopt dog"};
        this->adopt_dog_button->setFont(button_font);

        this->go_next_dog_button = new QPushButton{"Go to next dog"};
        this->go_next_dog_button->setFont(button_font);

        this->back_to_user_menu_button = new QPushButton{"Back to user menu"};
        this->back_to_user_menu_button->setFont(button_font);

        left_side_layout->addWidget(this->adopt_dog_button, 1, 0);
        left_side_layout->addWidget(this->go_next_dog_button, 1, 1);
        left_side_layout->addWidget(this->back_to_user_menu_button, 2, 0, 1, 2);

        iteration_general_layout->addWidget(left_side);

        emit currentDogUpdateSignal();
        emit displayAdoptionListSignal();

        this->connectIteratorButtons();
}

void GUI::filterMenuSlot() {

    QFont label_font("Helvetica", 20);
    QFont button_font("Arial", 20, 10);

    QGridLayout* filter_layout = new QGridLayout{this};

    this->filter_breed_label = new QLabel{"Filter breed: "};
    this->filter_breed_label->setFont(label_font);

    this->filter_breed_edit = new QLineEdit{};
    this->filter_breed_edit->setFont(label_font);
    this->filter_breed_edit->setMinimumWidth(250);

    this->filter_breed_label->setBuddy(this->filter_breed_edit);

    filter_layout->addWidget(this->filter_breed_label, 0, 0);
    filter_layout->addWidget(this->filter_breed_edit, 0, 1);

    this->filter_age_label = new QLabel{"Filter age: "};
    this->filter_age_label->setFont(label_font);

    this->filter_age_edit = new QLineEdit{};
    this->filter_age_edit->setFont(label_font);
    this->filter_age_edit->setMinimumWidth(250);

    this->filter_age_label->setBuddy(this->filter_age_edit);

    filter_layout->addWidget(this->filter_age_label, 1, 0);
    filter_layout->addWidget(this->filter_age_edit, 1, 1);

    this->filter_see_dogs_button = new QPushButton{"See dogs filtered"};
    this->filter_see_dogs_button->setFont(button_font);

    filter_layout->addWidget(this->filter_see_dogs_button, 2, 0, 1, 2);

    this->connectFilterButtons();
}

void GUI::seeAdoptionListSlot() {
    QFont label_font("Helvetica", 20);
    QFont button_font("Arial", 20, 10);

    QVBoxLayout* adoption_layout = new QVBoxLayout{this};

    this->see_adoption_label = new QLabel{"Adoption list"};
    this->see_adoption_label->setFont(label_font);

    this->see_adoption_list_widget = new QListWidget{};
    this->see_adoption_list_widget->setFont(label_font);
    this->see_adoption_list_widget->setMinimumWidth(375);
    this->see_adoption_list_widget->setMinimumHeight(200);

    this->see_adoption_back_to_user_menu = new QPushButton{"Back to user menu"};
    this->see_adoption_back_to_user_menu->setFont(button_font);

    adoption_layout->addWidget(this->see_adoption_label);
    adoption_layout->addWidget(this->see_adoption_list_widget);
    adoption_layout->addWidget(this->see_adoption_back_to_user_menu);

    emit seeAdoptionDisplayListSignal();
    this->connectSeeAdoptionButtons();
}

void GUI::seeTableAdoptionListSlot() {
    QFont button_font("Arial", 20, 10);

    std::vector<Dog> adoption_lst_vector =  this->user_program_controller.getAdoptionList();
    QVBoxLayout* adoption_table_layout = new QVBoxLayout{this};

    AdoptionListTableModel* adoption_table_model = new AdoptionListTableModel{adoption_lst_vector};
    this->adoption_table = new QTableView{};

    this->adoption_table->setModel(adoption_table_model);


    this->adoption_table->setColumnWidth(0, 150);
    this->adoption_table->setColumnWidth(1, 150);
    this->adoption_table->setColumnWidth(2, 150);
    this->adoption_table->setColumnWidth(3, 150);

    this->adoption_table->setEditTriggers(QTableView::AllEditTriggers);
    this->adoption_table->horizontalHeader()->setStretchLastSection(true);

    adoption_table_layout->addWidget(this->adoption_table);

    this->see_table_back_to_user_menu_button = new QPushButton{"Back to user menu"};
    this->see_table_back_to_user_menu_button->setFont(button_font);
    adoption_table_layout->addWidget(this->see_table_back_to_user_menu_button);

    this->connectSeeTableButtons();

}

void GUI::currentDogUpdateSlot() {
    this->current_iterator_position++;

    if(this->current_iterator_position >= this->iterator_dog_vector.size()) {
        this->current_iterator_position = 0;
    }
    this->current_dog_entity = this->iterator_dog_vector[this->current_iterator_position];
    this->current_dog_attributes_edit->setText(QString::fromStdString(this->current_dog_entity.getFirstThreeAttributesCSV()));

    if(this->iterator_dog_vector.empty()) {
        Dog empty_dog{};
        this->current_dog_entity = empty_dog;
        this->current_dog_attributes_edit->clear();
    }
    else {
        char link[200];
        for(int i=0; i<this->current_dog_entity.getPhotograph().size(); i++)
            link[i] = this->current_dog_entity.getPhotograph()[i];
        ShellExecuteA(NULL, NULL, "chrome.exe", link, NULL, SW_SHOWMAXIMIZED);
    }
}

void GUI::displayAdoptionListSlot() {
    QFont element_font{"Agency",15};

    if(this->adoption_list->count() > 0)
        this->adoption_list->clear();

    std::vector<Dog> dog_vector = this->user_program_controller.getAdoptionList();

    for(auto dog_entity: dog_vector) {

        QString list_element = QString::fromStdString(dog_entity.getCSV());
        QListWidgetItem* element = new QListWidgetItem{list_element};
        element->setFont(element_font);

        this->adoption_list->addItem(element);
    }
}

void GUI::seeAdoptionDisplayListSlot() {
    QFont element_font{"Agency",15};

    if(this->see_adoption_list_widget->count() > 0)
        this->see_adoption_list_widget->clear();

    std::vector<Dog> dog_vector = this->user_program_controller.getAdoptionList();

    for(auto dog_entity: dog_vector) {

        QString list_element = QString::fromStdString(dog_entity.getCSV());
        QListWidgetItem* element = new QListWidgetItem{list_element};
        element->setFont(element_font);

        this->see_adoption_list_widget->addItem(element);
    }
}




