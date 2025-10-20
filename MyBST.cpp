#include "MyBST.h"

MyBST::MyBST(){
    this->root = nullptr;   
}

int MyBST::length(){
    return this->size; 
}

bool MyBST::isEmpty(){
    return size == 0; 
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
            current = current->left; 
        }else{
            if(current->right == nullptr){
                current->right = new MyNodeBST(data);
                return true;
            }
            current = current->right; 
        }
    }
    return false; 
}

bool MyBST::remove(int data){
    MyNodeBST *current = root; 
    MyNodeBST *currentatras; 
    MyNodeBST *currentatras2; 
    int cont {0};

    while(current != nullptr){
        cont = 0;
        if(current->data> data){
            currentatras = current; 
            current = current->left;
            cont += 1;  
        }else if(current->data<data){
            currentatras = current; 
            current = current->right;
        }else{
            break;
        }
    }
    //caso 0 hijos
    if(current->left == nullptr && current->right == nullptr){
        if(cont == 0){
            currentatras->right = nullptr; 
        }else{
            currentatras->left = nullptr; 
        }
        delete current;
        return true; 
    //Caso 1 Hijo
    }else if (current->left != nullptr && current->right == nullptr) {
        currentatras->left = current->left;  
        delete current; 
        return true;
    }else if (current->left == nullptr && current->right != nullptr) {
        currentatras->right = current->right;
        delete current; 
        return true;
    //Caso 2 hijos
    }else{
        current = current->left; 
        while(current->right != nullptr){
            currentatras2 = current; 
            current = current->right; 
        }
        currentatras2->right = nullptr; 
        if(cont == 0){
            currentatras->right->data = current->data; 
        }else{
            currentatras->left->data = current->data; 
        }
        delete current; 
        return true; 

    }
    return false; 
}



void MyBST::preorder(){
    MyNodeBST *current {root};
    preorder(current); 
}

void MyBST::preorder(MyNodeBST *current){
    cout<<current->data<<","; 
    if(current->left != nullptr){
        preorder(current->left);
    }if(current->right != nullptr){
        preorder(current->right);
    }
}

void MyBST::inorder(){
    MyNodeBST *current {root}; 
    inorder(current);
}

void MyBST::inorder(MyNodeBST *current){
    if(current->left != nullptr){
        inorder(current->left);
    }
    cout<<current->data<<","; 
    if(current->right != nullptr){
        inorder(current->right);
    }

}

void MyBST::postorder(){
    MyNodeBST *current {root};
    postorder(current); 
}

void MyBST::postorder(MyNodeBST *current){
    if(current->left != nullptr){
        postorder(current->left);
    }
    if(current->right != nullptr){
        postorder(current->right);
    }
    cout<<current->data<<","; 
}

void MyBST::level(){
    MyNodeBST* array = new MyNodeBST[size];
    MyNodeBST* current {root};

}