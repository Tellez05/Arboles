#include "MyBST.h"

MyBST::MyBST(){
    this->root = nullptr; 
    size = 0; 
}
int MyBST::length(){
    return this->size; 
}
bool MyBST::isEmpty(){
    return size==0; 
}

bool MyBST::search(int data){
    MyNodeBST *current = root; 
    while(current != nullptr){
        if(current->data == data){
            return true;
        }
        if(data<root->data){
            current = current->left; 
        }else{
            current = current->right; 
        }
    }
    return false; 
}

bool MyBST::insert(int data){
    MyNodeBST *current = root; 
    while(current != nullptr){
        if(data<current->data){
            if(current->left == nullptr){
                current->left = new MyNodeBST(data);
                return true;
            } 
        }else{
            if(current->right == nullptr){
                current->right = new MyNodeBST(data);
                return true;
            }
        }
    }
    return false; 
}