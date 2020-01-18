//
//  Hash.cpp
//  ds
//
//  Created by wang sure on 2020/1/12.
//  Copyright © 2020 wang sure. All rights reserved.
//

#include "Hash.hpp"


int Hash::hashFunction(string key){
    int sum=0;
    for (int i=0; i<key.length(); i++) {
        sum+=key[i];
    }
    return sum%size;
}
Hash::Hash(){
    for (int i=0; i<size; i++) {
        hashTable[i]=nullptr;
//        hashTable[i]->name="empty";
//        hashTable[i]->drink="empty";
//        hashTable[i]->next=nullptr;
    }
}
void Hash::addItem(string n,string d){
    int index=hashFunction(n);
    item* t=new item;
    t->name=n;
    t->drink=d;
    t->next=nullptr;
    if (hashTable[index] ==nullptr) {
        hashTable[index]=t;
    }else{
        item* p=hashTable[index];
        while (p->next!=nullptr) {
            p=p->next;
        }
        p->next=t;
    }
}
void Hash::findDrink(string n){
    int index=hashFunction(n);
    item* p=hashTable[index];
    string res="";
    while(p!=nullptr){
        if (p->name==n) {
            res=p->drink;
            break;
        }
        p=p->next;
    }
    if (res=="") {
        cout<<n<<"'s drink was not found"<<endl;
    }else{
        cout<<n<<"'s drink is "+res<<endl;
    }
}
int Hash::numberOfItemsInIndex(int index){
    int c=0;
    item* p=hashTable[index];
    while (p!=nullptr) {
        p=p->next;
        c++;
    }
    return c;
}
void Hash::print(){
    for (int i=0; i<size; i++) {
        cout<<i<<":"<<endl;
        cout<<"# of items:"<<numberOfItemsInIndex(i)<<endl;
        printItemInIndex(i);
        cout<<"------------\n";
    }
}
void Hash::printItemInIndex(int index){
    item* p=hashTable[index];
    while (p!=nullptr) {
        cout<<"("<<p->name<<","<<p->drink<<")"<<endl;
        p=p->next;
    }
}
void Hash::remove(string n){
    int index=hashFunction(n);
    item* p=hashTable[index];
    if (p==nullptr) {
        cout<<n<<" not found in my hash"<<endl;
        return;
    }else if (p->name==n){
        hashTable[index]=p->next;
        delete p;
        cout<<n<<" was delete from the hash"<<endl;
    }else{
        item* q=p->next;
        while (q!=nullptr&&q->name !=n) {
            q=q->next;
            p=p->next;
        }
        if (q!=nullptr) {
            p->next=q->next;
            delete q;
            cout<<n<<" was delete from the hash"<<endl;
        }else{
            cout<<n<<" not found in my hash"<<endl;
        }
    }
}
