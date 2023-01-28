#ifndef sanpham_h
#define sanpham_h
#include<iostream>
#include<string.h>

#include "linkedlist.h"

using namespace std;

typedef class node* Node;

static int count=1;

struct date
{
    int day, month,year;
};

ostream& operator <<(ostream &, date&);
istream& operator >>(istream &, date&);

class node{
    private:
        int maso;
        string tensp;
        int soluong;
        double gianhap;
        double giaban;
        int tgbaohanh;
        date ngaybh;
        node* next;
        node* prev;
        
    public:
    node();
    ~node(){};
    node(string, int, double, double, int, date, Node, Node);

    int getmaso();
    void setmaso(int);

    string gettensp();
    void settensp(string );

    int getsoluong();
    void setsoluong(int);

    
    double getgianhap();
    void setgianhap(double);

    double getgiaban();
    void setgiaban(double);

    int gettgbaohanh();
    void settgbaohanh(int);

    date getngaybh();
    void setngaybh(date);
    void outngaybh();

    Node getnext();
    void setnext(Node );

    Node getprev();
    void setprev(Node);

    friend ostream& operator <<(ostream&, Node );
    // friend istream& operator >>(istream&, Node&);
    
    static Node creatnode(string, int, double, double, int);
    static Node creatnode();

    Node operator =(Node& a);
    void copy(Node);
    
    friend class hoadon;
    
    // friend class linkedlist;
};

linkedlist<node> hang;

#endif