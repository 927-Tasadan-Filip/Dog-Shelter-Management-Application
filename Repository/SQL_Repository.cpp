//
// Created by Filip on 19-Apr-21.
//

#include "SQL_Repository.h"
#include "../SQL_Source_files/sqlite3.h"

void SQLRepo::addDog(const Dog &new_dog) {

    for(auto & i : this->sql_record)
        if(i == new_dog)
            throw RepoException("There is another dog with the given name!");
    this->sql_record.push_back(new_dog);

    std::string sql_command;
    char *zErrMsg = 0;
    Dog copy_dog = new_dog;
    sql_command = "INSERT INTO DOGS ('BREED', 'NAME', 'AGE', 'PHOTO') VALUES ( ";
    sql_command += "'" +  copy_dog.getBreed() + "',";
    sql_command += "'" +  copy_dog.getName() + "',";
    sql_command += "'" +   std::to_string(copy_dog.getAge()) + "',";
    sql_command += "'" +  copy_dog.getPhotograph() + "'";
    sql_command += ");";
    sqlite3_exec(this->db_connection, sql_command.c_str(), SQLRepo::emptyCallback, 0, &zErrMsg);

}


int SQLRepo::updateDog(Dog given_dog, char mode) {
    int ok = 0;
    for(auto & i : this->sql_record)
        if(i == given_dog) {
            if(mode == 'a') {
                if(given_dog.getAge() != i.getAge()) {
                    ok = 1;
                }
                given_dog.setBreed(i.getBreed());
                given_dog.setPhotograph(i.getPhotograph());
                i = given_dog;

                std::string sql_command;
                char *zErrMsg = 0;
                sql_command = "UPDATE DOGS SET AGE = ";
                sql_command += std::to_string(given_dog.getAge());
                sql_command += " WHERE NAME = '";
                sql_command += given_dog.getName();
                sql_command += "';";
                sqlite3_exec(this->db_connection, sql_command.c_str(), SQLRepo::emptyCallback, 0, &zErrMsg);
            }
            if(mode == 'p') {
                if(given_dog.getPhotograph() != i.getPhotograph()) {
                    ok = 1;
                }
                given_dog.setBreed(i.getBreed());
                given_dog.setAge(i.getAge());
                i = given_dog;

                std::string sql_command;
                char *zErrMsg = 0;
                sql_command = "UPDATE DOGS SET PHOTO = '";
                sql_command += given_dog.getPhotograph();
                sql_command += "'";
                sql_command += " WHERE NAME = '";
                sql_command += given_dog.getName();
                sql_command += "';";
                sqlite3_exec(this->db_connection, sql_command.c_str(), SQLRepo::emptyCallback, 0, &zErrMsg);
            }
            return ok;
        }
    throw RepoException("There is no dog with the given name!");
}


void SQLRepo::deleteDog(const Dog &given_dog) {

    for(int i=0; i< this->sql_record.size(); i++)
        if(this->sql_record[i] == given_dog) {
            Dog copy_dog = given_dog;

            this->sql_record.erase(this->sql_record.begin() + i);

            std::string sql_command;
            char *zErrMsg = 0;
            sql_command = "DELETE FROM 'DOGS' WHERE NAME = '";
            sql_command += copy_dog.getName();
            sql_command += "';";
            sqlite3_exec(this->db_connection, sql_command.c_str(), SQLRepo::emptyCallback, 0, &zErrMsg);
            return;
        }
    throw RepoException("There is no dog with the given name!");
}


std::vector<Dog> SQLRepo::getRecord() {
    return this->sql_record;
}

void SQLRepo::setFileName(std::string file_name) {
    sqlite3_open(file_name.c_str(), &this->db_connection);
    this->db_name = file_name;
    this->createTable();
}

void SQLRepo::createTable() {
    std::string sql_command;
    char *zErrMsg = 0;

    sql_command = "CREATE TABLE DOGS ("  \
      "BREED           TEXT    NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE           INT    NOT NULL," \
      "PHOTO           TEXT    NOT NULL);";

    sqlite3_exec(this->db_connection, sql_command.c_str(), SQLRepo::emptyCallback, 0, &zErrMsg);
}

void SQLRepo::readRecordsFromFile() {
    std::string sql_command;
    char *zErrMsg = 0;

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(this->db_connection, "select BREED, NAME, AGE, PHOTO from DOGS", -1, &stmt, NULL);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Dog new_dog;
        new_dog.setBreed(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));
        new_dog.setName(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        std::string aux_string;
        aux_string = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        new_dog.setAge(stoi(aux_string));
        new_dog.setPhotograph(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)));

        this->sql_record.push_back(new_dog);
    }
    sqlite3_finalize(stmt);
}

std::string SQLRepo::repoGetFileName() {
    return this->db_name;
}

int SQLRepo::emptyCallback(void *NotUsed, int argc, char **argv, char **azColName) {
    return 0;
}

SQLRepo::~SQLRepo() {
    sqlite3_close(this->db_connection);
}

