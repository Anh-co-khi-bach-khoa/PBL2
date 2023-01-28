#include "linkedlist.h"
#include <iostream>
#include<string.h>

using namespace std;

template<typename T>
linkedlist<T>::linkedlist(){
    head=NULL;
    tail=NULL;
}

template<typename T>
linkedlist<T>::linkedlist(T* head, T* tail){
    this->head=head;
    this->tail=tail;
}

template<typename T>
T* linkedlist<T>::gethead(){
    return this->head;
}

template<typename T>
void linkedlist<T>::sethead(T* head){
    // T a;
    // a=*head;
    // this->head=&a;
    this->head=head;
}

template<typename T>
T* linkedlist<T>::gettail(){
    return this->tail;
}

template<typename T>
void linkedlist<T>::settail(T* tail){
    // T a;
    // a=*tail;
    // this->tail=&a;
    this->tail=tail;
}

template<typename T>
void linkedlist<T>::addfirst(T* a){
    T* p= a;  
    if(head == NULL){
        head=tail=p;
    }else{
        p->setnext(head);
        head->setprev(p);
        head=p;
    } 
    
}

template<typename T>
void linkedlist<T>::addfirst(){
    T* p= T::creatnode();  
    if(head == NULL){
        head=tail=p;
    }else{
        p->setnext(head);
        head->setprev(p);
        head=p;
    }
}

template<typename T>
void linkedlist<T>::addlast(T* a){
    T* p= a;
    if(head==NULL){
        head=tail=p;
    }else{
        p->setprev(tail);
        tail->setnext(p);
        tail=p;
    }
   
}

template<typename T>
void linkedlist<T>::addlast(){
    T* p= T::creatnode();
    if(head==NULL){
        head=tail=p;
    }else{
        p->setprev(tail);
        tail->setnext(p);
        tail=p;
    }
    
}


template<typename T>
void linkedlist<T>::deletes(int maso){
    T* p;
    T* pb;T* pa;
    p=head;
    
    while(p!=NULL){
        if(p->getmaso()==maso){
            if(p==head && p==tail){
                head = tail = NULL;
                delete p;
            }else if(p==head && p!=tail){
                head=p->getnext();
                head->setprev(NULL);
                delete p;
            }else if(p==tail && p!=head){
                tail=p->getprev();
                tail->setnext(NULL);
                delete p;
            }else {
                pb=p->getprev();
                pa=p->getnext();
                delete p;
                pb->setnext(pa);
                pa->setprev(pb);
                
            }
        }
        p=p->getnext();
    }
}

template<typename T>
ostream& operator <<(ostream &out, linkedlist<T> &a){

    T* p;
    p=a.gethead();
    while(p != NULL){
        out<<p;
        p = p->getnext();
        out<<"\n***********************************************\n";
    }
    return out;
}

template<typename T>
T* linkedlist<T>::search(int maso){
    T* p;
    p=head;
    while(p!=NULL){
        if(p->getmaso()==maso){
            return p;
            break;
        }
        p=p->getnext();
    }
    return NULL;
}

template<typename T>
T* linkedlist<T>::search(string tenkh, string sdt){
    T* p;
    p=head;
    while(p!=NULL){
        if(p->getten()==tenkh && p->getsdt()==sdt){
            return p;
        }
        p=p->getnext();
    }
    return NULL;
}