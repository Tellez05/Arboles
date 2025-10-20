/*
Andres Tellez Bermudez Matricula: A01640907\
Fecha: 20/10/2025
Tarea 3.1
*/
#include "MyBST.h"
//O(1)
MyBST::MyBST(){
    this->root = nullptr;   
}
//O(1)
int MyBST::length(){
    return this->size; 
}
//O(1)
bool MyBST::isEmpty(){
    return size == 0; 
}
//O(1)
bool MyBST::search(int data){
    MyNodeBST *current = root; 
    return search(data,current);
}
//O(n)
bool MyBST::search(int data, MyNodeBST *current){
    if(current == nullptr){
        return false;
    }
    if(current->data == data){
        return true; 
    }else if(current->data<data){
        return search(data, current->right);
    }else if(current->data>data){
        return search(data,current->left);
    }
    return false; 
}
//O(log(n))
bool MyBST::insert(int data){
    if(root == nullptr){
        root = new MyNodeBST(data);
        size++; 
        return true; 
    }
    MyNodeBST *current = root; 
    while(current != nullptr){
        if(data<current->data){
            if(current->left == nullptr){
                current->left = new MyNodeBST(data);
                size++;
                return true;
            } 
            current = current->left; 
        }else if(data > current->data){
            if(current->right == nullptr){
                current->right = new MyNodeBST(data);
                size++; 
                return true;
            }
            current = current->right; 
        }else{
            return false; 
        }
    }
    return false; 
}
//O(n)
bool MyBST::remove(int data){
    MyNodeBST *current = root; 
    MyNodeBST *currentatras; 
    int cont {0};

    while(current != nullptr){
        if(current->data> data){
            currentatras = current; 
            current = current->left;
            cont = 1;  
        }else if(current->data<data){
            currentatras = current; 
            current = current->right;
            cont = 0; 
        }else{
            break;
        }
    }
    if(current == nullptr){
        return false; 
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
    //Caso 1 Hijo (izquierdo)
    }else if (current->left != nullptr && current->right == nullptr) {
        if(cont == 1){
            currentatras->left = current->left;  
        }else{
            currentatras->right = current->left; 
        }
        delete current; 
        return true;
    //Caso 1 Hijo (Derecho)
    }else if (current->left == nullptr && current->right != nullptr) {
        if(cont == 1){
            currentatras->left = current->right;            
        }else{
            currentatras->right = current->right; 
        }
        delete current; 
        return true;
    //Caso 2 hijos
    }else{
        MyNodeBST* predPapa {current};
        MyNodeBST* pred {current->left};
        while(pred->right != nullptr){
            predPapa = pred; 
            pred = pred->right; 
        }
        current->data = pred->data; 
        if(predPapa->right == pred){
            predPapa->right = pred->left; 
        }else{
            predPapa->left = pred->left; 
        }  
        delete pred; 
        return true; 
    }
    
    return false; 
}


//O(1)
void MyBST::preorder(){
    MyNodeBST *current = root ;
    preorder(current); 
}
//O(n)
void MyBST::preorder(MyNodeBST *current){
    cout<<current->data<<","; 
    if(current->left != nullptr){
        preorder(current->left);
    }if(current->right != nullptr){
        preorder(current->right);
    }
}
//O(1)
void MyBST::inorder(){
    MyNodeBST *current {root}; 
    inorder(current);
}
//O(n)
void MyBST::inorder(MyNodeBST *current){
    if(current->left != nullptr){
        inorder(current->left);
    }
    cout<<current->data<<","; 
    if(current->right != nullptr){
        inorder(current->right);
    }

}
//O(1)
void MyBST::postorder(){
    MyNodeBST *current {root};
    postorder(current); 
}
//O(n)
void MyBST::postorder(MyNodeBST *current){
    if(current->left != nullptr){
        postorder(current->left);
    }
    if(current->right != nullptr){
        postorder(current->right);
    }
    cout<<current->data<<","; 
}

//O(n)
void MyBST::level(){
    MyNodeBST* current {root};
    vector<MyNodeBST*> lista; 
    lista.push_back(current); 
    while(!lista.empty()){
        current = lista[0];
        cout<<current->data<<",";
        lista.erase(lista.begin());
        if(current->left != nullptr){
            lista.push_back(current->left);
        }
        if(current->right != nullptr){
            lista.push_back(current->right);
        }

    }
}
//O(log(n))
void MyBST::ancestors(int data){
    MyNodeBST * current = root; 
    if(search(data)){
       while(current->data != data){
            cout<<current->data<<","; 
            if(current->data < data){
                current = current->right; 
            }else{
                current = current->left; 
            }
       } 
    } 
    
}
//O(1)
void MyBST::visit(int type){
    if(type == 1){
        preorder(); 
    }else if(type ==2){
        inorder(); 
    }else if(type==3){
        postorder();
    }else if(type ==4){
        level(); 
    }else{
        cout<<"Error"<<endl;
    }
}
//O(log(n))
int MyBST::whatLevelAmI(int data){
    if(!search(data)){
        return -1; 
    }
    int count {0};
    MyNodeBST* current {root};
    while(current != nullptr){
        if(current->data == data){
            return count;
        }
        count++; 
        if(current->data<data){
            current = current->right; 
        }else{
            current = current->left; 
        }
    }
    return -1; 
}
//O(1)
int MyBST::height(){
    if(isEmpty()){
        return -1; 
    }
    MyNodeBST* current {root};
    return (height(current));
}
//O(n)
int MyBST::height(MyNodeBST* current){
    if(current == nullptr){
        return -1; 
    }
    int left = height(current->left);
    int right = height(current->right);
    if(left <= right){
        return right+1; 
    }else{
        return left+1; 
    }
}