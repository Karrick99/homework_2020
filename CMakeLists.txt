cmake_minimum_required(VERSION 3.15)
project(homework_4_0)

set(CMAKE_CXX_STANDARD 11)

add_executable(homework_4.0 main.cpp Database.cpp Table.cpp Field.cpp Converters.hpp Field.cpp FieldTemplate.hpp IntField.cpp FloatField.cpp CharField.cpp TextField.cpp DateField.cpp TimeField.cpp data.cpp Time.cpp)