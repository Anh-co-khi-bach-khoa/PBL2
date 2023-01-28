#include "hoadon.h"


#include<string.h>
#include <iomanip>
#include<fstream>


using namespace std;

hoadon::hoadon():maHD(count_h),sp(){
   
    khach=NULL;
    next=NULL;
    prev=NULL;
    time.day=0;
    time.month=0;
    time.year=0;
    giatien=0;
}

hoadon::hoadon(  long giatien, HD next, HD prev, date a){
    
    this->giatien=giatien;
    this->next=next;
    this->prev=prev;
    time.day=a.day;
    time.month=a.month;
    time.year=a.year;
}

linkedlist<node> hoadon::getsp(){
    return this->sp;
}

long hoadon::getgiatien(){
    return this->giatien;
}

void hoadon::setgiatien(long giatien){
    this->giatien=giatien;
}

int hoadon::getmaHD(){
    return this->maHD;
}

void hoadon::setmaHD(int maHD){
    this->maHD=maHD;
}


HD hoadon::getnext(){
    return this->next;
}

void hoadon::setnext(HD next){
    this->next=next;
}

HD hoadon::getprev(){
    return this->prev;
}

void hoadon::setprev(HD prev){
    this->prev=prev;
}

date hoadon::getdate(){
    return time;
}

void hoadon::setdate(date a){
    time.day=a.day;
    time.month=a.month;
    time.year=a.year;
}

ostream& operator <<(ostream& out, HD a){

    out<<"Ma hoa don: "<<a->maHD<<endl;
    out<<"Ma khach hang: "<<a->khach->getmaso()<<endl;
    out<<"Ten khach hang: "<<a->khach->getten()<<endl;
    out<<"Ngay mua hang: "<<a->time<<endl<<endl;
    out<<"~Danh sach cac mat hang ma khach hang da mua~"<<endl<<endl;
    
    Node s=a->sp.gethead();
    while(s!=NULL){

        out<<"================================"<<endl;
        out<<"Ma san pham: "<<setw(3)<<setfill('0')<<s->getmaso()<<endl;
        out<<"Ten san pham: "<<s->gettensp()<<endl;
        out<<"Gia cua mot san pham: "<<(long)s->getgiaban()<<endl;
        out<<"So luong san pham khach hang da mua: "<< s->getsoluong()<<endl;
        out<<"Thoi gian bao hanh cua san pham: "<< s->gettgbaohanh()<<" thang"<<endl;
        out<<"Thoi gian het bao hanh: "<<s->getngaybh().day<<"/"<<s->getngaybh().month<<"/"<<s->getngaybh().year;out<<endl;
        s=s->getnext();
    }

    
    out<<"================================"<<endl;

    out<<"So dien thoai lien lac cua khach hang: "<<setw(10)<<setfill('0')<<a->khach->getsdt()<<endl;
    out<<"Tong thanh tien: "<<a->giatien<<" dong"<<endl;
    return out;
}

HD hoadon::creatnode(){
    HD v= new hoadon;
    bool success;
    int tl1,tl2=0;
    string tenkh,sdt,diachi;
    cout<<"Nhap ten khach hang: ";fflush(stdin); getline(cin,tenkh);
    cout<<"Nhap sdt: ";fflush(stdin); cin>>sdt;
    cout<<"Nhap dia chi: ";fflush(stdin); getline(cin,diachi);
    do{
     success=true;
    try{
        cout<<"Ngay tao hoa don: ";  cin>>v->time;
     }
    catch(string &s){
        cout<<s;
        success=false;
    };
    }while(success==false);

    v->khach=kh.search(tenkh,sdt);
    if(v->khach==NULL){
        v->khach= new khachhang(tenkh,sdt,diachi);
        tl2=1;
    }

    do{
        Node p,q,t;
        p=new node;
        q=new node;
        int masp;
        do{
            success=true;
            cout<<"Ma san pham khach mua : ";cin>>masp;
            t=hang.search(masp);
            try{
                if(t==NULL) throw string("Khong tim thay san pham! \n");
            }
            catch(string &s){
                cout<<s;
                success=false;
            };
        }while(success==false);
            do{
            success=true;
            cout<<"So Luong: "; cin>>p->soluong;
            try{
                if(t->soluong < p->soluong) throw string("So luong trong kho khong du !\n");
            }
            catch(string &s){
                cout<<s;
                success=false;
            };
        }while(success==false);
        p->ngaybh=v->time;
        q->soluong=p->soluong;
        t->soluong = t->soluong - p->soluong;
        if(t->gettgbaohanh()==12) p->ngaybh.year+=1;
        if(t->gettgbaohanh()==24) p->ngaybh.year+=2;
        q->ngaybh=p->ngaybh;
        p->copy(t);
        q->copy(p);
        v->giatien+= p->soluong * p->giaban;
        v->sp.addlast(p);
        v->khach->addhdkh(q);
        cout<<"san pham tiep theo (1=co / 0=Khong): ";cin>>tl1;
    }while(tl1);
    if(tl2) kh.addlast(v->khach);
    count_h++;
    return v;

}

HD hoadon::creatnode( string tenkh,string sdt,  string diachi, date time, ifstream& a){

    HD v= new hoadon;
    int tl2=0;
    v->time=time;
    v->khach=kh.search(tenkh,sdt);
    if(v->khach==NULL){
        v->khach= new khachhang(tenkh,sdt,diachi);
        tl2=1;
    }

    int loop;
    a>>loop;

    for(int i=0; i<loop; i++){
        Node p,q,t;
        int masp;
        a>>masp;
        t=hang.search(masp);
        // if(t==NULL){cout<<"Nhap sai!!\n";continue;} ;
        p=new node;
        q=new node;
        p->ngaybh=v->time;
        a>>p->soluong;
        
        q->soluong=p->soluong;
        t->soluong=t->soluong - p->soluong;
        if(t->gettgbaohanh()==12) p->ngaybh.year+=1;
        if(t->gettgbaohanh()==24) p->ngaybh.year+=2;
        q->ngaybh=p->ngaybh;
        p->copy(t);
        q->copy(p);
        v->giatien+= p->soluong * p->giaban;
        v->sp.addlast(p);
        v->khach->addhdkh(q);
        // cout<<"san pham tiep theo (1=co / 0=Khong): ";cin>>tl1;
    }
    if(tl2) kh.addlast(v->khach);
    count_h++;
    return v;
    
}

template<>
void linkedlist<hoadon>::deletes(int maHD){
    HD p;
    HD pb;HD pa;
    p=head;
    
    while(p!=NULL){
        if(p->getmaHD()==maHD){
            if(p==head && p==tail){
                head = tail = NULL;
                delete p;
            }else if(p==head && p!=tail){
                head=p->getnext();
                head->setprev(NULL);
                delete p;
            }else if(p==tail && p!=head){
                tail=p->getprev();
                tail->setnext(NULL);
                delete p;
            }else {
                pb=p->getprev();
                pa=p->getnext();
                delete p;
                pb->setnext(pa);
                pa->setprev(pb);
                
            }
        }
        p=p->getnext();
    }
}

template<>
HD linkedlist<hoadon>::search(int maHD){
    HD p;
    p=head;
    while(p!=NULL){
        if(p->getmaHD()==maHD){
            return p;
            break;
        }
        p=p->getnext();
    }
    return NULL;
}


