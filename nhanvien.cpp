#include <iostream>
#include<string.h>

using namespace std;

#include "nhanvien.h"


nhanvien::nhanvien():person(){
    tuoi=0;
    ngayvaolam.day=ngayvaolam.month=ngayvaolam.year=0;
   
    tienluong=0;
    next=NULL;
    prev=NULL;
}

nhanvien::nhanvien(string tennv, int tuoi, int songayvaolam, date ngayvaolam, long tienluong, NV next, NV prev):person(tennv){

    
    this->tuoi=tuoi;

    this->ngayvaolam=ngayvaolam;
    this->tienluong=tienluong;
    this->next=next;
    this->prev=prev;

}

int nhanvien::getmaso(){
    return manv;
}

void nhanvien::setmaso(int manv){
    this->manv=manv;
}

string nhanvien::gettennv(){
    return this->ten;
}

void nhanvien::settennv(string tennv){
    this->ten=ten;
}

NV nhanvien::getnext(){
    return next;
}

void nhanvien::setnext(NV next){
    this->next=next;
}

NV nhanvien::getprev(){
    return prev;
}

void nhanvien::setprev(NV prev){
    this->prev=prev;
}

int nhanvien::gettuoi(){
    return tuoi;
}

void nhanvien::settuoi(int tuoi){
    this->tuoi=tuoi;
}

long nhanvien::gettienluong(){
    return tienluong;
}

void nhanvien::settienluong(long tienluong){
    this->tienluong=tienluong;
}

date nhanvien::getngayvaolam(){
    return ngayvaolam;
}

void nhanvien::setngayvaolam(date ngayvaolam){
    this->ngayvaolam=ngayvaolam;
}

string nhanvien::getdiachi(){
    return diachi;
}

void nhanvien::setdiachi(string diachi){
    this->diachi=diachi;
}

NV nhanvien::creatnode(){
        
        int tuoi;
        string diachi;
        int songaydilam;
        date ngayvaolam;
        

        NV p=new nhanvien;

        cout<<"Nhap ten nhan vien: "; fflush(stdin); getline(cin, p->ten);
        cout<<"Nhap tuoi cua nhan vien: "; cin>>p->tuoi;
        cout<<"Nhap dia chi cua nhan vien: "; fflush(stdin); getline(cin, p->diachi);
        cout<<"Nhap ngay vao lam: "; cin>>p->ngayvaolam;
        cout<<"Nhap tien luong: "; cin>>p->tienluong;
        p->next=NULL;
        p->prev=NULL;

        

        p->manv=count_nv;

        count_nv++;

        return p;
}

ostream& operator <<(ostream &out, NV& a){
    out<<"Ma nhan vien: "<<a->manv<<endl;
    out<<"Ten nhan vien: "<<a->ten<<endl;
    out<<"Tuoi cua nhan vien: "<<a->tuoi<<endl;
    out<<"Dia chi: "<<a->diachi<<endl;
    out<<"Ngay vao lam: "<<a->ngayvaolam<<endl;
    out<<"Tien luong cua nhan vien: "<<a->tienluong<<endl;

    return out;

}

NV nhanvien::creatnode( string ten, int tuoi, string diachi, long tienluong, date ngayvaolam ){
    NV p=new nhanvien;
    p->manv=count_nv;
    count_nv++;
    p->ten=ten;
    p->tuoi=tuoi;
    p->diachi=diachi;
    p->tienluong=tienluong;
    p->ngayvaolam=ngayvaolam;
    p->next=NULL;
    p->prev=NULL;
    return p;
}