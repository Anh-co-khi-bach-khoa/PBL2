#include "person.h"

#include<iostream>
#include<string.h>

using namespace std;

person::person(){
    ten="";
}

person::person (string ten){
    this->ten=ten;
}

// ostream& operator <<(ostream &out, const person& a){
//     out<<"Ten khach hang: "<<a.ten;
//     return out;
// }

// istream& operator >>(istream &in, person& a){
//     cout<<"Nhap ten khach hang: "; in>>a.ten;
//     return in;
// }