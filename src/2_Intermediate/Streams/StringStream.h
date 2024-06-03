#pragma once

#include<iostream>
#include<sstream> // working with string stream.
#include<iomanip> // stream manipulator , for controlling the format of our output.

using namespace std;


/*
String streams : used for manipulate the string as they are stream , like we manipulate the input output streams.
                 And they work on in-memory and expand if needed more memory.So very efficient.
[String stream classes]
istringstream => reading stream.
ostringstream => writing stream.
stringstream => both read and write.
*/

class StringStreamTest {

    private :
        // see , the problem with to_string
        static void problem() {
        double number = 12.34;
        cout << to_string(number) << endl;  // we'll extra 0 added in precision
    }

    static void solveAboveProblem() {
        double number = 12.34;
        stringstream stream;

        // fixed : used for setting the output as fixed point notation like we see in decimal.
        stream << fixed << setprecision(1) << number;

        string str = stream.str();
        cout << str;
    }

    // parsing strings
    static void parseString() {
        string str = "10 20";

        // remember the buffer concept , while reading data from commnd line.
        stringstream stream;
        stream.str(str);

        int first;
        stream >> first; // this way will read until space or new line delimeter is found.

        // if want to read_entire line use below one.
        // getline(stream,some_str_variable);

        int second;
        stream >> second;

        cout << "Sum:" << first + second << endl;
    }


    public :
        static void test() {
        parseString();
    }



};




