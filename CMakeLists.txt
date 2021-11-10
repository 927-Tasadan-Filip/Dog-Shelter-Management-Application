cmake_minimum_required(VERSION 3.17)
project(a89_917_Tasadan_Filip)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:/Qt6/6.1.0/mingw81_64/lib/cmake")
set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets)

include_directories(Entity)
include_directories(Repository)
include_directories(Service)
include_directories(Tests)
include_directories(UserInterface)

find_package(Qt6Charts REQUIRED)

add_executable(a89_917_Tasadan_Filip
        Entity/DogEntity.cpp
        Entity/DogEntity.h
        Repository/Repository.cpp
        Repository/Repository.h
        Service/AdminController.cpp
        Service/AdminController.h
        Service/UserController.cpp
        Service/UserController.h
        Tests/Test.cpp
        Tests/Test.h
        UserInterface/UI.cpp
        SQL_Source_files/sqlite3.h
        SQL_Source_files/sqlite3.c
        UserInterface/UI.h
        main.cpp StringFunctions/StringFunctions.cpp StringFunctions/StringFunctions.h Exceptions/ProgramExceptions.h Validator/ProgramValidator.cpp Validator/ProgramValidator.h Repository/CSV_Repository.cpp Repository/CSV_Repository.h Repository/HTML_Repository.cpp Repository/HTML_Repository.h Repository/SQL_Repository.cpp Repository/SQL_Repository.h GUI/QtGUI.cpp GUI/QtGUI.h GUI/AdoptionListTableView.cpp GUI/AdoptionListTableView.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

target_link_libraries(${PROJECT_NAME} Qt6::Charts)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
