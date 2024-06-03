//
// Created by Suman on 11-05-2024.
//

#ifndef FILESTREAMTEST_H
#define FILESTREAMTEST_H
#include<iostream>
#include<string>  // for getline function
#include<fstream> // for working with files stream.
#include<iomanip>  // for formatting our data.Which goes in stream.

using namespace std;


class TestFileStream {

private:

	static void testReading() {
		ofstream file;

		// if file exists it will overwrite the content of that file
		file.open("data.txt");
		const size_t clmWidth = 20;
		if (file.is_open()) {

			// also it recommend to use \n in end of string , instead of <<endl due to performance reasons.
			file << setw(clmWidth) << "Hello" << setw(clmWidth) << "World" << endl;

			// alway close the file once we have done what we want to do with the file.
			// so that os resources allocated for working with this file can be release.
			file.close();;

		}
	}

	static void createCsvFile() {
		ofstream file;
		file.open("movies.csv");

		if (file.is_open()) {

			file << "Title,Year\n";

			// we can also use chaining: more preferred.
			file << "Title-1,2000\n"
				<< "Title-2,2001\n"
				<< "Title-3,2002\n";

			file.close();
		}


	}

	// read from file
	static void readFile() {
		ifstream file;
		file.open("movies.csv");

		if (file.is_open()) {
			string str;
			//file >> str; // it will read till delimeter and which is (white space or \n)

			getline(file, str);

			// read the file till there is no content to read
			while (!file.eof())
			{



				// default delimeter is \n, but we have provided ','
				// and str will be used as buffer so one line read, then next will overwrite over that and so on.
				getline(file, str,',');

				// check for extra empty line
				if (str.empty()) continue;
				cout << str <<endl;
			}
				file.close();
		}
	}


	// writing data to file as in binary format.
	static void writeBinaryData() {
		int numbers[] = { 1'000'000,2'000'000 ,3'000'000 };
		ofstream file("numbers2.dat", ios::binary);

		if (file.is_open()) {

			// this is syntex we have to go for.size(bytes we want to read from memory and write them to disk)
			file.write(reinterpret_cast<char*>(&numbers), sizeof(numbers));
			file.close();
		}

	}

	// reading binary files
	static void readBinaryData() {
		ifstream file("numbers.dat", ios::binary);
		if (file.is_open()) {
			int number;

			// here sizeof operator tell that how many bytes need to be put in number , next our interpreter know how to convert to decimal
			while (file.read(reinterpret_cast<char*>(&number), sizeof(number))) {

				cout << number << endl;
			}
			file.close();
		}
	}

	// reading and writing to files
	static void testRW() {

		fstream file;
		// | => apply all these operations,  means in for input and out for output. app => append.
		file.open("file.txt", ios::in | ios::out | ios::app | ios::binary);
		if (file.is_open()) {
			file.close();
		}
	}

public:

	static void test() {
		writeBinaryData();
	}




};


#endif //FILESTREAMTEST_H
