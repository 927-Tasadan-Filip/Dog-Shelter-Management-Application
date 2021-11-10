//
// Created by Filip on 05-May-21.
//

#pragma once

#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QGraphicsWidget>
#include <QShortcut>

#include <QPushButton>
#include <QLabel>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QHeaderView>

#include <QTableWidgetItem>

#include "AdminController.h"
#include "UserController.h"
#include "AdoptionListTableView.h"

class GUI: public QWidget {
    Q_OBJECT

private:
    AdminService& program_controller;
    UserController& user_program_controller;

    QWidget* main_widget;
    QPushButton* admin_mode_button;
    QPushButton* user_mode_button;
    QPushButton* data_chart_button;

    // admin mode attributes
        QListWidget* dogs_list;

        QLabel *breed_label;
        QLabel *name_label;
        QLabel *age_label;
        QLabel *photo_label;

        QLineEdit* breed_edit;
        QLineEdit* name_edit;
        QLineEdit* age_edit;
        QLineEdit* photo_edit;

        QPushButton* add_new_dog_button;
        QPushButton* delete_dog_button;
        QPushButton* update_dog_button;

        QLabel *operation_status_label;
        QTextEdit* operation_status_edit;

        QPushButton* admin_back_to_menu_button;

        QPushButton* admin_undo_button;
        QPushButton* admin_redo_button;

    // user mode menu attributes
        QPushButton* see_all_dogs_button;
        QPushButton* see_all_breed_button;
        QPushButton* see_adoption_button;
        QPushButton* see_adoption_with_program_button;
        QPushButton* see_adoption_list_table_button;
        QPushButton* user_back_to_menu_button;
        // Iteration menu attributes
        QLabel* adoption_label;
        QListWidget* adoption_list;
        QLabel* current_dog_label;
        QLineEdit* current_dog_attributes_edit;
        QPushButton* adopt_dog_button;
        QPushButton* go_next_dog_button;
        QPushButton* back_to_user_menu_button;
        int current_iterator_position;
        Dog current_dog_entity;
        std::vector<Dog> iterator_dog_vector;
        // Filter menu attributes
        QLabel* filter_breed_label;
        QLineEdit* filter_breed_edit;
        QLabel* filter_age_label;
        QLineEdit* filter_age_edit;
        QPushButton* filter_see_dogs_button;
        // See adoption list attributes
        QLabel* see_adoption_label;
        QListWidget* see_adoption_list_widget;
        QPushButton* see_adoption_back_to_user_menu;
        // Table see adoption list attributes
        QTableView* adoption_table;
        QPushButton* see_table_back_to_user_menu_button;

    // breed chart attributes
        QChart* breed_chart;
        QPushButton* data_chart_back_to_menu;

    void connectInitialSignalsAndSlots();
    void connectMenuButtons();
    void connectAdminButtons();
    void connectUserButtons();
        void connectIteratorButtons();
        void connectFilterButtons();
        void connectSeeAdoptionButtons();
    void connectDataChartButtons();
    void connectSeeTableButtons();


    // button handlers
        // admin mode button handlers
        void adminModeButtonHandler();
        void userModeButtonHandler();
        void dataChartButtonHandler();
        void adminBackToMenuButtonHandler();
        void addNewDogButtonHandler();
        void deleteDogButtonHandler();
        void updateDogButtonHandler();
        void adminUndoButtonHandler();
        void adminRedoButtonHandler();
        // user mode button handlers
        void userBackToMenuButtonHandler();
        void seeAllDogsButtonHandler();
        void seeAllBreedButtonHandler();
        void displayAdoptionListButtonHandler();
        void seeAdoptionListTableButtonHandler();
        void seeAdoptionWithProgramButtonHandler();
            // iterator button handlers
            void adoptDogButtonHandler();
            void goNextDogButtonHandler();
            void backToUserMenuButtonHandler();
            // filter button handlers
            void filterSeeDogsButtonHandler();
            // see adoption button handlers
            void seeAdoptionBackToUserMenuButtonHandler();
            // data chart button handlers
            void dataChartBackToMenuButtonHandler();
            // see table button handler
            void seeTableBackToUserMenuButtonHandler();


    // admin mode operations
    void changeElementListFields();
    int getSelectedIndex();
    // user mode operations
    void filterIteratorVectorByAdoptionList();

    std::string getCurrentDir();


signals:
    void adminModeSignal();
    void userModeSignal();
    void dataChartSignal();
        // admin mode signals
        void listUpdateSignal();
        void backToMenuSignal();
        void addNewDogSignal(const std::string& breed,const std::string& name, int age,const std::string& photo);
        void deleteDogSignal(const std::string& name);
        void updateDogSignal(const std::string& name, int age, const::std::string& photo);
        void operationStatusSignal(const std::string& status_string);
        void adminUndoSignal();
        void adminRedoSignal();
        // user mode signals
        void userBackToMenuSignal();
        void backToUserMenuSignal();
        void filterMenuSignal();
        void seeAdoptionListSignal();
        void seeTableAdoptionListSignal();
            // iterator signals
            void iterateDogsWindowSignal();
            void currentDogUpdateSignal();
            void displayAdoptionListSignal();
            // see adoption signals
            void seeAdoptionDisplayListSignal();

public:
    GUI(AdminService& given_admin_controller, UserController& given_user_controller, QWidget *parent = 0);
    ~GUI();

public slots:
    void initGUI();
    void initAdminMode();
    void initUserMode();
    void dataChartSlot();
        // admin mode slots
        void displayDogList();
        void updateOperationStatusSlot(const std::string& status_string);
        void addNewDogSlot(const std::string& breed,const std::string& name, int age,const std::string& photo);
        void deleteDogSlot(const std::string& name);
        void updateDogSlot(const std::string& name, int age, const::std::string& photo);
        void adminUndoSlot();
        void adminRedoSlot();
        // user mode slots
        void iterateDogsWindowSlot();
        void filterMenuSlot();
        void seeAdoptionListSlot();
        void seeTableAdoptionListSlot();
            // iterator slots
            void currentDogUpdateSlot();
            void displayAdoptionListSlot();
            // see adoption slots
            void seeAdoptionDisplayListSlot();
};
