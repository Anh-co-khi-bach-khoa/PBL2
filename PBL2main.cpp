#include "sanpham.h"
#include "hoadon.h"
#include "linkedlist.h"
#include "khachhang.h"
#include "nhanvien.h"

#include "sanpham.cpp"
#include "hoadon.cpp"
#include "linkedlist.cpp"
#include "khachhang.cpp"
#include "nhanvien.cpp"

#include "person.h"
#include "person.cpp"

#include<string.h>
#include<fstream>


int main(){

    int loop;

    //nhap tu file lop san pham
    
    string tensp;
    int soluong;
    double gianhap;
    double giaban;
    int tgbaohanh;


    ifstream inp1("in1.txt");
    ifstream inp2("in2.txt");
    ofstream out("out.txt");
    inp2>>loop;

    for(int i=0; i<loop; i++){
        getline(inp1, tensp);
        inp2>>soluong;
        inp2>>gianhap;
        inp2>>giaban;
        inp2>>tgbaohanh;
        Node p=node::creatnode(tensp, soluong, gianhap, giaban, tgbaohanh);
        count++;
        hang.addlast(p);
    }

    // out<<hang;

    //nhap tu file lop nhan vien

    string ten;
    int tuoi;
    string diachinv;
    long tienluong;
    date ngayvaolam;

    ifstream inpnv1("innhanvien1.txt");
    ifstream inpnv2("innhanvien2.txt");
    ofstream outnv("outnhanvien.txt");
    inpnv2>>loop;

    for(int i=0; i<loop; i++){
        getline(inpnv1, ten);
        inpnv2>>tuoi;
        getline(inpnv1, diachinv);
        inpnv2>>tienluong;
        inpnv2>>ngayvaolam.day>>ngayvaolam.month>>ngayvaolam.year;
        NV p= nhanvien::creatnode(ten, tuoi, diachinv, tienluong, ngayvaolam);
        nv.addlast(p);
    }

    // outnv<<nv;

    //nhap tu file lop hoa don va khach hang

    string tenkh;
    string diachi;
    int soluongmua; 
    string sdt;
    date time;

    ifstream inphd1("inhd1.txt");
    ifstream inphd2("inhd2.txt");
    ifstream inphd3("inhd3.txt");
    ofstream outhd("outhd.txt");

    inphd2>>loop;

    for(int i=0; i<loop; i++){
       
        getline(inphd1, tenkh);
        getline(inphd1, sdt);
        getline(inphd1, diachi);
        inphd2>>time.day>>time.month>>time.year;
        HD p= hoadon::creatnode( tenkh, sdt, diachi, time, inphd3);
        hd.addlast(p);
    }

    // outhd<<hd;
    
    ofstream outkh("outkh.txt");
    // outkh<<kh;
    
    
    int p;

    do{
        cout<<"                         ~MENU~\n";
        cout<<"======================================================\n";
        cout<<"||1.San pham                                        ||\n";
        cout<<"||2.Hoa don                                         ||\n";
        cout<<"||3.Kiem tra thoi gian bao hanh may cua khach hang  ||\n";
        cout<<"||4.Nhan vien                                       ||\n";
        cout<<"||0.Ket thuc                                        ||\n";
        cout<<"======================================================\n";
        cout<<"Nhap so thu tu muon lam viec: ";cin>>p; system("cls");
        switch (p)
        {
            case 1:
                int n;
                do{
                    cout<<"                        ~MENU~\n";
                    cout<<"====================================================="<<endl;
                    cout<<"||1.Nhap moi mot san pham vao vi tri cuoi          ||"<<endl;
                    cout<<"||2.Hien thi toan bo danh sach                     ||"<<endl;
                    cout<<"||3.Xoa mot san phan theo ID                       ||"<<endl;
                    cout<<"||4.Tiem kiem mot san pham theo ma so              ||"<<endl;
                    cout<<"||0.Ket thuc                                       ||"<<endl;
                    cout<<"====================================================="<<endl;
                    cout<<"Nhap so thu tu cong viec muon thuc hien: "; cin>>n;

                    switch(n){
                        case 1: 
                            hang.addlast();
                            system("pause");
                            count++;
                            system("cls");
                            break;
                        case 2:
                            cout<<endl<<"~DANH SACH TAT CA CAC SAN PHAM~\n\n";
                            cout<<hang;
                            out<<hang;
                            system("pause"); 
                            system("cls");
                            break;
                        case 3:
                            int maso;
                            cout<<hang;
                            cout<<"Nhap ma so SP muon xoa: ";cin>>maso;
                            hang.deletes(maso);
                            system("cls");
                            break;
                        case 4:               
                            {
                            cout<<hang;
                            cout<<"Nhap ma so SP muon tim kiem: "; cin>>maso;
                            system("cls");
                            if(hang.search(maso)!=NULL){
                                cout<<hang.search(maso)<<endl;
                            }else{
                                cout<<"Khong tim thay san pham!"<<endl;
                            }
                            system("pause");
                            system("cls");
                            break;
                            }  
                        case 0:
                            cout<<"Ket thuc lam viec voi san pham!!\n";
                            system("pause");
                            system("cls");
                            break;

                        default: cout<<"Khong hop le\n"; system("pause"); system("cls");break;
                    }

                }while(n!=0);
                break;
            case 2:
                int m;
                do{
                    cout<<"                        ~MENU~\n";
                    cout<<"====================================================="<<endl;
                    cout<<"||1.Nhap them mot hoa don                             ||\n";
                    cout<<"||2.Xuat toan bo hoa don                              ||\n";
                    cout<<"||3.Xoa mot hoa don theo ma hoa don                   ||\n";
                    cout<<"||4.Tim kiem hoa don theo ma hoa don                  ||\n";
                    cout<<"||0.Ket thuc                                          ||\n";
                    cout<<"====================================================="<<endl;
                    cout<<"Nhap stt cong viec muon thuc hien: "; cin>>m;
                    switch(m){
                        case 0:
                            cout<<"Ket thuc lam viec voi hoa don!!\n\n";
                            system("pause");
                            system("cls");
                            break;
                        case 1:
                            hd.addlast();
                            system("cls");
                            break;
                        case 2:
                            cout<<endl<<"~DANH SACH CAC HOA DON~"<<endl<<endl;
                            cout<<hd;
                            outhd<<hd;
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            int mahd;
                            cout<<hd;
                            cout<<"Nhap ma hoa don muon xoa: "; cin>>mahd;
                            hd.deletes(mahd);
                            system("cls");
                            break;
                        case 4:
                            cout<<"Nhap ma so HD muon tim kiem: "; cin>>mahd;
                            if(hd.search(mahd)!=NULL){
                                cout<<hd.search(mahd)<<endl;
                            }else{
                                cout<<"Khong tim thay hoa don!"<<endl;
                            }
                            system("pause");
                            system("cls");
                            break;
                        default:
                            cout<<"\nERROR!!!!\n";
                            system("pause");

                            system("cls"); 
                            break; 
                    }
                }while(m!=0);
                break;
            case 3:
                cout<<kh;
                outkh<<kh;
                system("pause");
                system("cls");
                break;

            case 4:

                int q;

                do{
                    cout<<"                        ~MENU~\n";
                    cout<<"====================================================="<<endl;
                    cout<<"||1.Nhap them mot nhan vien                           ||\n";
                    cout<<"||2.Xuat toan bo danh sach nhan vien                  ||\n";
                    cout<<"||3.Xoa mot nhan vien theo ma nhan vien               ||\n";
                    cout<<"||4.Tim kiem nhan vien theo ma nhan vien              ||\n";
                    cout<<"||0.Ket thuc                                          ||\n";
                    cout<<"====================================================="<<endl;
                    cout<<"Nhap stt cong viec muon thuc hien: "; cin>>q;
                    switch(q){
                        case 0:
                            cout<<"Ket thuc lam viec voi nhan vien\n";
                            system("cls");
                            break;
                        case 1:
                            nv.addlast();
                            system("cls");
                            break;
                        case 2:
                            cout<<nv;
                            outnv<<nv;
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            int manv;
                            cout<<nv;
                            cout<<"Nhap ma nhan vien muon xoa: "; cin>>manv;
                            nv.deletes(manv);
                            system("cls");
                            break;
                        case 4:
                        {
                            cout<<"Nhap ma nhan vien muon tim kiem: "; cin>>manv;
                            NV p=new nhanvien;
                            p=nv.search(manv);
                            if(p!=NULL){
                                cout<<p;
                            }else{
                                cout<<"Khong tim thay nhan vien\n";
                            }
                            system("pause");
                            system("cls");
                            break;
                        }
                        default:
                            cout<<"Khong hop le\n";
                            system("cls");
                            break;
                    }
                }while(q!=0);
                
                break;

            case 0:
                cout<<"Ket thuc toan bo chuong trinh!!\n";
                break;

            default:
                cout<<"Khong hop le!\n";
                break;
        }
    }while (p!=0);
    

    return 0;
}

