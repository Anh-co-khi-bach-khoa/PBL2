#ifndef khachhang_h
#define khachhang_h

#include "person.h"
#include "hoadon.h"
#include "linkedlist.h"
#include "sanpham.h"

#include<string.h>
#include<iostream>

using namespace std;

typedef class khachhang* KH;
static int count_k = 1;

linkedlist<khachhang> KhachHang;

class khachhang:public person{

    private:
        int maKH;
        linkedlist<node> hdkh;
        string diachi;
        string sdt;
        KH next;
        KH prev;
    public:
        khachhang();
        ~khachhang(){ };
        khachhang(string, string, string);

        string getsdt();
        void setsdt(string);

        KH getnext();
        void setnext(KH);

        KH getprev();
        void setprev(KH);

        linkedlist<node> gethdkh();
        void addhdkh(Node);

        int getmaso();
        void setmaKH(int);

        string getten();
        void setten(string);

        string getdiachi();
        void setdiachi(string);

        // KH creatnode(linkedlist<hoadon> );

        friend ostream& operator << (ostream& , KH);
        friend istream& operator >> (istream &, KH);

};

linkedlist<khachhang> kh;

#endif