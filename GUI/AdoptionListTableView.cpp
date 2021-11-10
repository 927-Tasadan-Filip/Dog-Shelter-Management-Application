//
// Created by Filip on 27-May-21.
//

#include "AdoptionListTableView.h"

AdoptionListTableModel::AdoptionListTableModel(std::vector<Dog> program_adoption_list): adoption_list_record{program_adoption_list} {}

QVariant AdoptionListTableModel::data(const QModelIndex &index, int role) const {
    int data_row, data_column;
    data_row = index.row();
    data_column = index.column();

    if(role == Qt::DisplayRole) {
        if(data_column == 0) {
            return QString::fromStdString(this->adoption_list_record[data_row].getBreed());
        }
        else if(data_column == 1) {
            return QString::fromStdString(this->adoption_list_record[data_row].getName());
        }
        else if(data_column == 2) {
            return QString::fromStdString(std::to_string(this->adoption_list_record[data_row].getAge()));
        }
        else if(data_column == 3) {
            return QString::fromStdString(this->adoption_list_record[data_row].getPhotograph());
        }
    }

    return QVariant();
}

QVariant AdoptionListTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return QString("Breed");
                case 1:
                    return QString("Name");
                case 2:
                    return QString("Age");
                case 3:
                    return QString("Photograph");
            }
        }
    }

    return QVariant();
}

int AdoptionListTableModel::rowCount(const QModelIndex &parent) const {
    return this->adoption_list_record.size();
}

int AdoptionListTableModel::columnCount(const QModelIndex &parent) const {
    return 4;
}
