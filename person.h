#ifndef person_h
#define person_h

#include <iostream>
#include <string.h>
#include "linkedlist.h"
#include "sanpham.h"
#include "hoadon.h"
using namespace std;

class person{

    protected:
        string ten;
    public: 
        person();
        ~person(){ };
        person(string);

        virtual string getdiachi()=0;

        // virtual linkedlist<node> gethdkh()=0;

        // ostream& operator <<(ostream &, const person&)=0;
        // friend istream& operator >>(istream&, person&);

};

#endif