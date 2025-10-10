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
    MyNodeBST *Current = root; 

    while(Current != nullptr){
        if(Current->Data == data){
            return true;
        }
        if(data<root->Data){
            Current = Current->Left; 
        }else{
            Current = Current->Right; 
        }
    
    }
    return false; 
    


}