#pragma once

#include<iostream>
#include <vector>
#include "SegmentTree.h"
#include "BIT.h"

using namespace std;


class TestingTrees {
public:
    static void test() {
//        testSegmentTree();
testBIT();
    }

private:
    static void testSegmentTree() {
        vector<int> vec = {1, 2, 3, 4, 5, 6};
        SegmentTree tree(vec);
        // tree.showTree();

        int query1 = tree.getQuerySum(0,5); // 21
        int query2 = tree.getQuerySum(3,5); // 15
        int query3 = tree.getQuerySum(3,3); // 4
        int query4 = tree.getQuerySum(2,4); // 12
        cout<<query1<<"\t"<<query2<<"\t"<<query3<<"\t"<<query4<<"\t"<<endl;

        // update query
        tree.update(3,14);
        tree.showTree();
    }
    static void testBIT(){
        vector<int> vec = {1,2,3,4,5,6};
        BIT obj{vec};

        cout<<"[Get Range Sum Test]"<<endl;
        cout << obj.getRangeSum(3)<<endl; //10
        cout << obj.getRangeSum(5)<<endl; //21

        cout<<"[Get Partial Range]"<<endl;
        cout<<obj.getRangeSum(5,2)<<endl; //15
        cout<<obj.getRangeSum(2,1)<<endl; //3

        cout<<"[Update and Test]"<<endl;
        obj.updateIndex(2,4);
        obj.updateIndex(3,5);
        cout<<obj.getRangeSum(5,1)<<endl;

        cout<<"[Show Entire BIT]"<<endl;
        obj.showBIT();



    }
};
