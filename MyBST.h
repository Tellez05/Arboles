#pragma once 
#include <iostream>
using namespace std; 

struct MyNodeBST{
    int data;
    MyNodeBST *left,
              *right;
    MyNodeBST(int data){
        this->data=data;
        this->left=this->right=nullptr;
    }
};

class MyBST{
    private:
        int size; 
        MyNodeBST* root; 
    public: 
        MyBST(); 
        int length(); 
        bool isEmpty(); 
        bool search(int data);
        bool insert(int data); 
        bool remove(int data); 
        void preorder(); 
        void inorder(); 
        void level(); 
        void visit(int type);
        int height(); 
        void ancestors(int data);
        int whatLevelIAmI(int data); 



};