//
// Created by Filip on 27-May-21.
//

#pragma once
#include <QTableView>
#include "../Entity/DogEntity.h"

class AdoptionListTableModel: public QAbstractTableModel {
    Q_OBJECT
private:
    std::vector<Dog> adoption_list_record;
public:
    explicit AdoptionListTableModel(std::vector<Dog> );
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};
