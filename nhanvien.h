#ifndef nhanvien_h
#define nhanvien_h

#include <iostream>
#include<string.h>
#include<conio.h>

#include "hoadon.h"
#include "sanpham.h"
#include "person.h"
#include "linkedlist.h"
#include "khachhang.h"

using namespace std;

static int count_nv=300;

typedef class nhanvien* NV;

class nhanvien:public person{
    private:
        int manv;
        int tuoi;
        string diachi;
        long tienluong;
        date ngayvaolam;
        
        NV next;
        NV prev;
    public:
        nhanvien();
        ~nhanvien(){ };
        nhanvien(string, int, int, date, long, NV, NV);

        int getmaso();
        void setmaso(int);

        string gettennv();
        void settennv(string);

        NV getnext();
        void setnext(NV);

        NV getprev();
        void setprev(NV);

        int gettuoi();
        void settuoi(int);

        int getsongaydilam();
        void setsongaydilam(int songayvaolam);

        date getngayvaolam();
        void setngayvaolam(date);

        long gettienluong();
        void settienluong(long);

        string getdiachi();
        void setdiachi(string);

        friend ostream& operator <<(ostream& , NV& );

        static NV creatnode();
        static NV creatnode(string, int, string, long, date);
};

linkedlist<nhanvien> nv;

#endif