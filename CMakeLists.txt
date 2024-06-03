cmake_minimum_required(VERSION 3.28)
project(Clion)

set(CMAKE_CXX_STANDARD 20)

add_executable(Clion src/main.cpp
        src/1_Basics/1_reading_input.h
        src/1_Basics/2_data_type.h
        src/2_Intermediate/Test.h
        src/2_Intermediate/Arrays.h
        src/2_Intermediate/SmartPointers.h
        src/2_Intermediate/StringTest.h
        src/2_Intermediate/EnumTest.h
        src/2_Intermediate/Streams/StreamTest.h
        src/2_Intermediate/Streams/FileStreamTest.h
        src/2_Intermediate/Streams/StringStream.h
        src/3_Advanced/1_Classes/1_User.h
        src/3_Advanced/1_Classes/1_User.cpp
        src/3_Advanced/1_Classes/2_SmartPointer.h
        src/3_Advanced/1_Classes/2_SmartPointer.cpp
        "src/3_Advanced/2_Operator Overloading/Length.cpp"
        "src/3_Advanced/2_Operator Overloading/Length.h"
        "src/3_Advanced/2_Operator Overloading/SubScriptOverload.cpp"
        Utils/LinkedList/ll.h
        Utils/Test.hpp
        Utils/LinkedList/Doubly.h
        "Utils/Segment & Binary Indexed/SegmentTree.h"
        "Utils/Segment & Binary Indexed/Test.h"
        "Utils/Segment & Binary Indexed/BIT.h"
        stl/entry.h
        stl/VectorTest.h
)
