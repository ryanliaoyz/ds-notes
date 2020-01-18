//
//  Hash.hpp
//  ds
//
//  Created by wang sure on 2020/1/12.
//  Copyright © 2020 wang sure. All rights reserved.
//

#ifndef Hash_hpp
#define Hash_hpp

#include <iostream>
using namespace std;


struct item{
    string name;
    string drink;
    struct item* next;
};
typedef struct item  item;


class Hash{
public:
    int hashFunction(string key);
    Hash();
    void addItem(string n,string d);
    void findDrink(string n);
    int numberOfItemsInIndex(int index);
    void print();
    void printItemInIndex(int index);
    void remove(string n);
private:
    static const int size=10;
    item* hashTable[size];
};






#endif /* Hash_hpp */
