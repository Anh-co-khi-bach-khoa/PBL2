#ifndef linkedlist_h
#define linkedlist_h

#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
class linkedlist{
    private:
        T* head;
        T* tail;
    public:
    linkedlist();
    linkedlist(T*, T*);
    ~linkedlist(){};
    T* gethead();
    void sethead(T*);
    T* gettail();
    void settail(T*);
    void addlast();
    void addfirst();
    void addfirst(T*);
    void addlast(T*);
    void deletes(int);
    T* search(int);
    T* search(string,string);
    template<typename U>
    friend ostream& operator <<(ostream &out, linkedlist<U> &);
    
};

#endif