#pragma once

/*
 * list : doubly LL => #include<list>
 *          begin,end
 *          push_back,push_front,(value=>back, front),( void => pop_back,pop_front),
 *          new node=>insert(it,val),advance(it,num_of_jumps),erase(it_to_delete)
 * forward_list : singly LL => #include<forward_list>
 *                  begin, end , before_begin : iterator pointing before begin
 *                  push_front ,(we can iterate from start to end : logSinglyLL)
 *                  pop_front :void ,advance(it,jumps), iterator_to_new=>insert_after(it,val)
 *                  iterator_to_deleted=> delete_after(it)
 *
 * */
#include<iostream>
#include<list>
#include<forward_list>
#include<sstream>

using namespace std;


class LLTest {

public :
    static void test() {
        cout << "->> Linked List Testing." << endl;
        createDoubly();
//createSinglyLL();
    }

private :
    static void logDoublyLL(list<int> l, string message) {


        stringstream ss;
        ss << "[ " << message << "] " << endl;
        ss << "[";

        auto it = l.begin();
        while (it != l.end()) {
            ss << *it << " ";
            it++;
        }

        ss << "]";

        cout << "list: " << ss.str() << endl;


    }

    static void logSinglyLL(forward_list<int> &l, string message) {
        stringstream ss;
        ss << "[ " << message << "] " << endl;
        ss << "[";

        auto it = l.begin();
        while (it != l.end()) {
            ss << *it << " ";
            it++;
        }

        ss << "]";

        cout << "Singly LL: " << ss.str() << endl;
    }


    static void createDoubly() {
        list<int> myList = {1, 2, 3, 4, 5};
        myList.push_back(10);
        myList.push_front(5);
        myList.push_back(20);


        logDoublyLL(myList, "Printing List");

        cout << myList.back() << " ";
        cout << myList.front() << endl;

        auto it = myList.cbegin();
        advance(it, 2);
        cout << "Advance operation result: " << *it << endl;

        myList.insert(it, 15);
        cout << "Insert Operation Result: " << *it << endl;
        logDoublyLL(myList, "Inert Operation");

        // going back and forth.
        auto backForthIt = myList.begin();
        cout << "Next value: " << *(++backForthIt) << endl;
        cout << "Previous value: " << *(--backForthIt) << endl;


    }

    static void createSinglyLL() {
        forward_list<int> myForwardList = {1, 2, 3, 4};
        myForwardList.push_front(10);

        logSinglyLL(myForwardList, "Default Singly LL");

        myForwardList.pop_front();
        logSinglyLL(myForwardList, "Pop Result");

        // iterating , like normal iteration.
        auto it = myForwardList.begin();
        while (it != myForwardList.end()) {
            *it = (*it) + 10;
            it++;
        }
        logSinglyLL(myForwardList, "After iterating.");

        // inserting element.
        auto newIt = myForwardList.begin();
        advance(newIt, 2);
        cout << "Advance Result :  " << *newIt << endl;
        auto insert = myForwardList.insert_after(newIt, 1000);
        cout << "Inserted value : " << *insert << endl;
        logSinglyLL(myForwardList, "New Node Inserted Result");

        // deleting element
        auto deleted = myForwardList.erase_after(newIt);
        cout << "Deleted value :  " << *deleted << endl;
        logSinglyLL(myForwardList, "After Delete Operation");

        // deleting range of values
        /*auto rangeItDel = myForwardList.begin()++;
        auto rangeDeleted=myForwardList.erase_after(rangeItDel,myForwardList.end());
        logSinglyLL(myForwardList,"Range Delete Operation");*/

        // going back and forth.
        auto backForthIt = myForwardList.begin();
        cout << "Next value: " << *(++backForthIt) << endl;
//        cout<<"Previous value: " << *(--backForthIt) <<endl; // Error : Can't go back which is obvious






    }

};