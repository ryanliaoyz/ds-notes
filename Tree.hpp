//
//  Tree.hpp
//  ds
//
//  Created by wang sure on 2019/12/28.
//  Copyright © 2019 wang sure. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp
#include "Node.hpp"

#include <stdio.h>
#include <vector>
using namespace std;

class Tree{
public:
    Tree():root(nullptr),size(0){
    }
    ~Tree();
    
    void build(vector<int> dd);
    vector<int> inorder();
    int height();
    Node* root;
    
    int countEven();
    
    int sum();
    int max();
    
private:
    
    int size;
    
    void build_help(vector<int> dd,Node* root,int& count);
    Node* build_help2(vector<int> dd,int& count);
    void inorder(Node* root,vector<int>& data);
    int height(Node* root);
    int countEven(Node* root);
    int sum(Node* root);
    int max(Node* root);
    
};

#endif /* Tree_hpp */
