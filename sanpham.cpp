#include "sanpham.h"
#include<iostream>
#include<string.h>
#include<iomanip>
#include<conio.h>

ostream& operator<<(ostream &out, date& a){
    out<<a.day<<"/"<<a.month<<"/"<<a.year;
    return out;
}

istream& operator >>(istream &in, date& a){
    int top;
    // cout<<"Nhap lan luot ngay thang nam mua san pham cua khach hang (dd/mm/yyyy): ";
    in>>a.day>>a.month>>a.year;
    if(a.month<1||a.month>12) throw string("Thang Khong hop le !\n");
    switch(a.month){
        case 4:case 6: case 9: case 11: top=30; break;
        case 2: top=28 + ((a.year%4==0 && a.year%100 )|| a.year % 4000==0);break;
        default: top=31;
    }
    if( a.day < 1 || a.day>top ) throw string("Ngay Khong Hop Le !\n");

    return in;
}


node::node():maso(count){
    tensp="";
    soluong=0; 
    giaban=0;
    gianhap=0;
    tgbaohanh=0;
    prev=NULL;
    next=NULL;
}

node::node(string tensp, int soluong, double giaban, double gianhap, int tgbaohanh, date ngaybh, Node next, Node prev){
    this->tensp=tensp;
    this->soluong=soluong;
    this->giaban=giaban;
    this->gianhap=gianhap;
    this->tgbaohanh=tgbaohanh;
    this->ngaybh=ngaybh;
    this->next=next;
    this->prev=prev;
}

int node::getmaso(){
    return this->maso;
}

void node::setmaso(int maso){
    this->maso=maso;
}

date node::getngaybh(){
    return this->ngaybh;
}

void node::setngaybh(date ngaybh){
    this->ngaybh=ngaybh;
}

void node::outngaybh(){
    cout<<this->ngaybh.day<<"/"<<this->ngaybh.month<<"/"<<this->ngaybh.year;
}

string node::gettensp(){
    return this->tensp;
}

void node::settensp(string tensp){
    this->tensp=tensp;
}

int node::getsoluong(){
    return this->soluong;
}

void node::setsoluong(int soluong){
    this->soluong=soluong;
}


double node::getgianhap(){
    return this->gianhap;
}

void node::setgianhap(double gianhap){
    this->gianhap=gianhap;
}

double node::getgiaban(){
    return this->giaban;
}

void node::setgiaban(double giaban){
    this->giaban=giaban;
}

int node::gettgbaohanh(){
    return this->tgbaohanh;
}

void node::settgbaohanh(int tgbaohanh){
    this->tgbaohanh=tgbaohanh;
}

Node node::getnext(){
    return this->next;
}

void node::setnext(Node next){
    this->next=next;
}

Node node::getprev(){
    return this->prev;
}

void node::setprev(Node prev){
    
    this->prev=prev;
}

ostream& operator <<(ostream &out, Node a){
    out<<"Ma san pham: "<<setw(4)<<setfill('0')<<a->getmaso()<<endl;
    out<<"Ten san pham: "<<a->gettensp()<<endl;
    out<<"So luong san pham con lai: "<<a->getsoluong()<<endl;
    out<<"Gia nhap vao: "<<(long)a->getgianhap()<<endl;
    out<<"Gia ban: "<<(long)a->getgiaban()<<endl;
    out<<"Thoi gian bao hanh: "<<a->gettgbaohanh()<<" thang"<<endl;
    return out;
}


Node node::creatnode(){
    string tensp; int soluong; double giaban; double gianhap; int tgbaohanh;
    cout<<"Nhap ten san pham: ";cin.ignore();getline(cin, tensp);
    cout<<"Nhap so luong san pham hien co: "; cin>>soluong;
    cout<<"Nhap gia nhap vao: "; cin>>gianhap;
    cout<<"Nhap gia ban ra : "; cin>>giaban;
    cout<<"Nhap thoi gian bao hanh (thang): "; cin>>tgbaohanh;
    node *p=new node;
    p->tensp=tensp;
    p->soluong=soluong;
    p->giaban=giaban;
    p->gianhap=gianhap;
    p->tgbaohanh=tgbaohanh;
    p->next=NULL;
    p->prev=NULL;
    // count++;

    return p;

}

Node node::creatnode(string tensp, int soluong, double gianhap, double giaban, int tgbaohanh){
    Node p=new node;
    p->tensp=tensp;
    p->soluong=soluong;
    p->giaban=giaban;
    p->gianhap=gianhap;
    p->tgbaohanh=tgbaohanh;
    p->next=NULL;
    p->prev=NULL;
    // count++;

    return p;

}

Node node::operator=(Node& a){
    

    this->tensp=a->tensp;
    this->giaban=a->giaban;
    this->gianhap=a->gianhap;
    this->maso=a->maso;
    this->soluong=a->soluong;
    this->tgbaohanh=a->tgbaohanh;
    this->next=a->getnext();
    this->prev=a->getprev();
    return this;
}

void node::copy(Node a){
    
    this->maso=a->maso;
    this->tensp=a->tensp;
    this->giaban=a->giaban;
    this->gianhap=a->gianhap;
    this->maso=a->maso;
    // this->soluong=a->soluong;
    this->tgbaohanh=a->tgbaohanh;
    // this->ngaybh=b.ngaybh;
    this->next=NULL;
    this->prev=NULL;
}


template <>
void linkedlist<node>::addfirst(){
    string s="Khong the them san pham vi san pham da ton tai!\n";
    Node p= node::creatnode();
    Node q=head;
    int c=0;
    while(q!=NULL){
        try{
            if(q->gettensp() == p->gettensp()){
                delete p;
                // cout<<"Khong the them san pham vi san pham da ton tai!\n";
                throw s;
                
                break;
            }
            
        }
        catch(string s){
            cout<<s;
        }
        q=q->getnext();
        c++;
    }
    if(c==0){
        Node f= p;  
        if(head == NULL){
            head=tail=f;
        }else{
            f->setnext(head);
            head->setprev(f);
            head=f;
        } 
        cout<<"Nhap them san pham thanh cong!"<<endl; 
    }
}

template <>
void linkedlist<node>::addlast(){
    Node p= node::creatnode();
    Node q=head;
    int c=0;
    while(q!=NULL){
        if(q->gettensp() == p->gettensp()){
            delete p;
            cout<<"Khong the them san pham vi san pham da ton tai!\n";
            c++;
            break;
        }
        q=q->getnext();
    }
    if(c==0){
         
        if(head == NULL){
            head=tail=p;
        }else{
            p->setprev(tail);
            tail->setnext(p);
            tail=p;
        }
        cout<<"Nhap them san pham thanh cong!"<<endl; 
    }
}

