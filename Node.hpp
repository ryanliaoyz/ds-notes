//
//  Node.hpp
//  ds
//
//  Created by wang sure on 2019/12/28.
//  Copyright © 2019 wang sure. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>


class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d):data(d){
        left=nullptr;
        right=nullptr;
    }
};


#endif /* Node_hpp */
