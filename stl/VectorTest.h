#pragma  once

#include<iostream>
#include<algorithm>
#include <sstream>
#include<vector>

using namespace std;

struct MyPair{
    int first, second;

    bool operator<(const MyPair& other) const{
        return first < other.first;
    }
};

class DescendingSort {
public:
    bool operator()(int first, int second) { return first > second; }
};

class VectorTest {

public :
    static void test() {

        cout << "->> Vector Test Running ..." << endl;
//        create();

//        sortThem();
        boundTest();
        boundTestOnCustom();
    }

private:
    static void log(vector<int>& vec, string message) {


        stringstream ss;
        ss << "[ " << message << "] " << endl;
        ss << "[";

        ss << *vec.cbegin();

        for (auto it = vec.cbegin() + 1; it != vec.cend(); it++) ss << "," << *it;

        ss << "]";
        ss << "(" << vec.size() << ")";
        cout << "->> " << ss.str() << endl;

    }

    static void create() {
        vector<int> v(10);
        log(v, "Initial Value Test");

        vector<int> v2(10, 1);
        log(v2, "With default value");

        vector<int> v3(100, -1);
        log(v3, "Just having fun");

//        Iterating over vector

// Way-1
        cout << "[Iterating over vector]" << endl;
        for (int num: v) cout << num << ",";
        cout << endl;
        // way-2

        for (auto it = v.cbegin(); it != v.cend(); it++) { cout << *it << ","; }
        cout << endl;

        // manipulating while iterating

        auto iterator = v2.begin();
        do {
            (*iterator) += 1;
            cout << *iterator << ",";
        } while (++iterator != v2.end());
        cout << endl;


    }

    static bool comparator(const int first, const int second) { return first > second; }


    static void sortThem() {
        vector<int> vec = {4, 3, 1, 2, 5};
        log(vec, "Before sorting");
        // sort(vec.begin(),vec.end()) // sorts ascending order/ non-decreasing order

        // Sort : Decreasing order
        // way-1
        /*sort(vec.begin(), vec.end(),
             [](int first, int second) { return first>second; });*/

        // way-2
//        sort(vec.begin(), vec.end(), comparator);

        // way-3
        sort(vec.begin(), vec.end(), DescendingSort());
        log(vec, "After sorting");
    }

    static void boundTest() {
        vector<int> vec = {1, 2, 3, 4, 5, 6};
        int upperBoundOf = 5;
        int lowerBoundOf = 2;
        cout << "Upper bound of " << upperBoundOf << " : " << *upper_bound(vec.cbegin(), vec.cend(), upperBoundOf)
             << endl; // val > x or vec.end()
        cout << "Lower bound of " << lowerBoundOf << " : " << *lower_bound(vec.cbegin(), vec.cend(), lowerBoundOf)
             << endl; // val <= x or  vec.begin
    }

    static void boundTestOnCustom() {
        vector<MyPair> vec = {{1,2},{3,4},{5,6}};
        auto upper = upper_bound(vec.begin(),vec.end(),MyPair{2,3});
        auto lower = lower_bound(vec.begin(),vec.end(),MyPair{-1,-2});
        cout<<upper->first << "and" << upper->second <<endl;
        cout<<lower->first << "and" << lower->second <<endl;
    }


};

