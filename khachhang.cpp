#include <iostream>
#include<string.h>
#include "khachhang.h"

using namespace std;

khachhang::khachhang():person(),maKH(count_k){
    diachi="";
    prev=NULL;
    next=NULL;
    count_k++;// sua
}

khachhang::khachhang(string ten,string sdt , string diachi):person(ten),maKH(count_k){
    this->diachi=diachi;
    this->sdt=sdt;
    prev=NULL;
    next=NULL;
    count_k++;//s
}


string khachhang::getsdt(){
    return sdt;
}

void khachhang::setsdt(string sdt){
    this->sdt=sdt;
}

KH khachhang::getnext(){
    return this->next;
}

void khachhang::setnext(KH next){
    this->next=next;
}

KH khachhang::getprev(){
    return this->prev;
}

void khachhang::setprev(KH prev){
    this->prev=prev;
}

linkedlist<node> khachhang::gethdkh(){
    return hdkh;
}

string khachhang::getten(){
    return ten;
}

void khachhang::setten(string ten){
    this->ten=ten;
}

int khachhang::getmaso(){
    return maKH;
}

void khachhang::setmaKH(int maKH){
    this->maKH=maKH;
}

string khachhang::getdiachi(){
    return this->diachi;
}

void khachhang::setdiachi(string diachi){
    this->diachi=diachi;
}

ostream& operator << (ostream& out,KH a){
    out<<"Ten khach hang: "<<a->ten<<endl;
    out<<"Ma khach hang: "<<a->maKH<<endl;
    out<<"Dia chi cua khach hang: "<<a->diachi<<endl;
    out<<"Danh sach cac san pham ma khach hang da mua "<<endl;
    Node s=a->hdkh.gethead();
    while(s!=NULL){
        out<<"Ma san pham: "<<s->getmaso()<<endl;
        out<<"Ten san pham: "<<s->gettensp()<<endl;
        out<<"Gia cua mot san pham: "<<(long)s->getgiaban()<<endl;
        out<<"So luong ma khach hang da mua: "<<s->getsoluong()<<endl;
        out<<"Thoi gian het bao hanh: "<<s->getngaybh().day<<"/"<<s->getngaybh().month<<"/"<<s->getngaybh().year;out<<endl;
        out<<"============================================="<<endl<<endl;
        s=s->getnext();
    }
    return out;
}

istream& operator >>(istream& in, KH a){
    cout<<"Nhap ten khach hang: "; fflush(stdin); getline(in, a->ten);
    cout<<"Nhap sdt: ";fflush(stdin); getline(in,a->sdt);
    cout<<"Nhap dia chi khach hang: "; fflush(stdin); getline(in,a->diachi);
    return in;
}

void khachhang::addhdkh(Node a){
    hdkh.addlast(a);
}

