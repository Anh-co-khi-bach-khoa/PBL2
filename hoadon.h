#ifndef hoadon_h
#define hoadon_h

#include<iostream>
#include<string.h>

#include "sanpham.h"
#include "linkedlist.h"
#include "khachhang.h"

using namespace std; 

static int count_h=100;

typedef class hoadon* HD;


class hoadon{
    private:
        int maHD;
        linkedlist<node> sp;
        KH khach;
        long giatien;
        HD next;
        HD prev;
        date time;
    public:
        hoadon();
        ~hoadon(){ };
        hoadon( long, HD, HD, date);

        linkedlist<node> getsp();

        long getgiatien();
        void setgiatien(long);

        int getmaHD();
        void setmaHD(int);

        string gettenkh();
        void settenkh(string);

        // long getsodt();
        // void setsodt(long);

        HD getnext();
        void setnext(HD );

        date getdate();
        void setdate(date);

        HD getprev();
        void setprev(HD);
        friend ostream& operator <<(ostream&, HD );

        // static HD creatnode(string, int, long, date);
        static HD creatnode();
        static HD creatnode(string,string, string, date, ifstream&);
};

linkedlist<hoadon> hd;

#endif