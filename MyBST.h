#pragma once 
#include <iostream>
using namespace std; 
struct MyNodeBST{
    int Data;
    MyNodeBST *Left, *Right;  
    
    MyNodeBST(int data, MyNodeBST* left, MyNodeBST* right){
        this->Data = data; 
        this->Left = left; 
        this->Right = right; 
    }
    MyNodeBST(int data):MyNodeBST(data, nullptr, nullptr){}
};

class MyBST{
    public: 
    int size; 
    MyNodeBST* root; 
    MyBST(); 
    int length(); 
    bool isEmpty(); 
    bool search(int data);
    bool searchRec(int data, MyNodeBST* current); 
    bool searchRec(int data);
    bool insert(int data); 
    bool remove(int data); 



};