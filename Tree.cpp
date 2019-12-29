//
//  Tree.cpp
//  ds
//
//  Created by wang sure on 2019/12/28.
//  Copyright © 2019 wang sure. All rights reserved.
//

#include "Tree.hpp"


void Tree::build(vector<int> dd){
    int c=0;
    root=build_help2(dd,c);
}
void Tree::build_help(vector<int> dd,Node* root,int& count){
    if (count>=dd.size()) {
        return;
    }
    if (dd[count]==-1) {
        return;
    }
    root->left=new Node(dd[count]);
    count++;
    
    if (count>=dd.size()) {
        return;
    }
    root->right=new Node(dd[count]);
    count++;
    build_help(dd, root->left, count);
    build_help(dd, root->right, count);
}
vector<int> Tree::inorder(){
    vector<int> res;
    inorder(root,res);
    return res;
}
void Tree::inorder(Node* root,vector<int>& data){
    if (root==nullptr) {
        return;
    }
    inorder(root->left,data);
    data.push_back(root->data);
    inorder(root->right,data);
}
Node* Tree::build_help2(vector<int> dd,int& count){
    if (count>=dd.size()) {
        return nullptr;
    }
    if (dd[count]==-1) {
        return nullptr;
    }
    Node* t=new Node(dd[count]);
    count++;
    t->left=build_help2(dd,count);
    count++;
    t->right=build_help2(dd,count);
    return t;
}

Tree::~Tree(){
    
}

int Tree::height(){
    return height(root);
}

int Tree::height(Node* root){
    if (root==nullptr) {
        return -1;
    }
    int l=height(root->left);
    int r=height(root->right);
    if (l>r) {
        return l+1;
    }else{
        return r+1;
    }
}

int Tree::countEven(){
    return countEven(root);
}
int Tree::countEven(Node* root){
    if (root==nullptr) {
        return 0;
    }
    
    int count=0;
    if (root->data%2==0) {
        count=1;
    }
    int l=countEven(root->left);
    int r=countEven(root->right);
    
    return count+l+r;
}
int Tree::sum(){
    return sum(root);
}
int Tree::sum(Node* root){
    if (root==nullptr) {
        return 0;
    }
    return root->data+sum(root->left)+sum(root->right);
}

int Tree::max(){
    if (root==nullptr) {
        return -1;
    }
    return max(root);
}
int Tree::max(Node* root){
    int m=root->data;
    if (root->left!=nullptr) {
        int temp=max(root->left);
        if (m < temp) {
               m=temp;
           }
    }
    if (root->right!=nullptr) {
        int temp=max(root->right);
        if (m < temp) {
               m=temp;
           }
    }
    return m;
}

