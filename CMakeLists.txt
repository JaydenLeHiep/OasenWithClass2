cmake_minimum_required(VERSION 3.23)
project(OsencrawlerMitKlassen)

set(CMAKE_CXX_STANDARD 14)

add_executable(OsencrawlerMitKlassen main.cpp robot.cpp robot.h position.h enemy.cpp enemy.h linkedlist.h felder.h generate.h)
