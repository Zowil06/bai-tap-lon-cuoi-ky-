#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include"hambosung.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#include "cauhoi.h"
#include "giaodien.h"

using namespace std;

void hoanVi(CauHoi& a, CauHoi& b) 
{
    CauHoi temp = a;
    a = b;
    b = temp;
}

int main() 
{
    bool quayLaiMenu = true;
    
    while (quayLaiMenu) 
	{
        
        system("cls");
        SetConsoleCP(437);
        SetConsoleOutputCP(437); 
        
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        
        
        SetConsoleTextAttribute(hConsole, 11);
        for (int i=0 ; i<=38 ;i++)
        {
        	gotoxy(40+i,2);
        	cout<<char(196);
        	gotoxy(40+i,5);
        	cout<<char(196); 	
		}
		for(int i=0 ; i<=1 ; i++)
		{
			gotoxy(40,3+i);
			cout<<char(179);
			gotoxy(78,3+i);
			cout<<char(179);
		}
		gotoxy(40,2);
		cout<<char(218);
		gotoxy(78,2);
		cout<<char(191);
		gotoxy(40,5);
		cout<<char(192);
		gotoxy(78,5);
		cout<<char(217);
        gotoxy(46,3);
        cout << "CHAO MUNG DEN VOI PHAN MEM" << endl;
        gotoxy(51,4);
        cout << "THI TRAC NGHIEM C++" << endl;
        gotoxy(45,8);
        cout << "Nhan phim bat ky de bat dau...\n";
        _getch();

        //menu hien thi 
        int luaChonMenu = hienThiMenu();
        string tenFile;
        switch (luaChonMenu) 
		{
            case 1: 
            	gotoxy(40,1);
				tenFile = "questions1.txt"; break;
            case 2: 
            	gotoxy(40,2);
				tenFile = "questions2.txt"; break;
			case 3: 
            	gotoxy(40,3);
				tenFile = "questions3.txt"; break;	
            default: return 0;
        }
        
        
        system("cls");
        SetConsoleTextAttribute(hConsole, 14);
        
        for( int i=0 ; i<40 ; i++)
        {
        	gotoxy(40+i,0);
        	cout<<char(196);
        	gotoxy(40+i,15);
        	cout<<char(196);
        	gotoxy(40+i,4);
        	cout<<char(196);
		}
		for(int i=0 ; i<15 ; i++)
		{
			gotoxy(40,0+i);
			cout<<char(179);
			gotoxy(80,0+i);
			cout<<char(179);
		}
		gotoxy(40,0);
		cout<<char(218);
		gotoxy(80,0);
		cout<<char(191);
		gotoxy(40,15);
		cout<<char(192);
		gotoxy(80,15);
		cout<<char(217);
		gotoxy(60,2);
		cout<<"LUU Y";
		gotoxy(45,5);
		cout<<"Bai thi co 10 cau hoi";
		gotoxy(45,7);
		cout<<"Moi cau dung duoc 1 diem";
		gotoxy(45,9);
		cout<<"Neu diem < 5: KHONG DAT";
		gotoxy(45,11);
		cout<<"Neu diem >= 5 :DAT";
		gotoxy(45,13);
		cout<<"Thoi gian lam bai :10 phut";
        SetConsoleTextAttribute(hConsole, 8); 
        gotoxy(40,20);
        cout << "Nhan phim bat ky de bat dau lam bai...\n";
        _getch();
		system("cls");
      
        CauHoi danhSach[MAX_CAU_HOI];
        int soLuong = 0;
        docCauHoiTuFile(tenFile, danhSach, soLuong);
        if (soLuong == 0) 
		{
            cout << "Khong co cau hoi nao!" << endl;
            Sleep(2000);
            continue; 
        }

        
        srand(time(0));
        for (int i = 0; i < soLuong; i++) 
		{
            int j = rand() % soLuong;
            hoanVi(danhSach[i], danhSach[j]);
        }

        
        const int soCauThi = min(soLuong, 10);
        int diem = 0;
        char dapAnNguoiDung[10];
        
        
        const int THOI_GIAN_THI = 600; //tinh theo giay, quy doi 600 giay = 10 phut
        time_t thoiGianBatDau = time(NULL);
        bool hetThoiGian = false;

        
        for (int i = 0; i < soCauThi && !hetThoiGian; i++) 
		{
            
            char luaChon = chonDapAnBangPhimMuiTen(danhSach[i], i + 1, thoiGianBatDau, THOI_GIAN_THI);
            
            
            if (luaChon == 'X') 
			{
                hetThoiGian = true;
                break;
            }
            
            
            dapAnNguoiDung[i] = luaChon;
            if (luaChon == danhSach[i].dapAnDung) 
			{
                
                diem++;
            } 
			else;

            
            time_t thoiGianHienTai = time(NULL);
            int thoiGianConLai = THOI_GIAN_THI - (thoiGianHienTai - thoiGianBatDau);
            if (thoiGianConLai <= 0) 
			{
                hetThoiGian = true;
                break;
            }

            
            cout << "\nNhan phim bat ky de tiep tuc...";
            _getch();
            system("cls");
        }
        
        // hien thi het gio
        if (hetThoiGian) 
		{
            system("cls");
            SetConsoleTextAttribute(hConsole, 12); 
            for (int i=0 ; i<50 ; i++)
            {
            	gotoxy(40+i,6);
            	cout<<char(196);
            	gotoxy(40+i,8);
            	cout<<char(196);
			}
			gotoxy(40,7);
			cout<<char(179);
			gotoxy(90,7);
			cout<<char(179);
            gotoxy(40,6);
            cout<<char(218);
            gotoxy(40,8);
            cout<<char(192);
            gotoxy(90,6);
            cout<<char(191);
            gotoxy(90,8);
            cout<<char(217);
            gotoxy(55,7);
            cout<<"HET THOI GIAN LAM BAI";
            SetConsoleTextAttribute(hConsole, 7); 
            PlaySound(TEXT("wrong.wav"), NULL, SND_FILENAME | SND_ASYNC);
            Sleep(2000); 
            
        }

        // tinh diem 
        float diemSo = (float)diem / soCauThi * 10;
        string trangThai = (diemSo >= 5.0) ? "Dat" : "Khong dat";

        // hien thi ket qua
        system("cls");
        SetConsoleTextAttribute(hConsole, 14);
        for (int i=0 ;i<40 ; i++)
        {
        	gotoxy(0+i , 0);
        	cout<<char(196);
        	gotoxy(0+i , 2);
        	cout<<char(196);
        	gotoxy(0+i,15);
        	cout<<char(196);
		}

		for( int i=0 ; i<15 ;i++)
		{
			gotoxy(0,0+i);
			cout<<char(179);
			gotoxy(40,0+i);
			cout<<char(179);
			
		}
		gotoxy(0,2);
		cout<<char(195);
		gotoxy(40,2);
		cout<<char(180);
		gotoxy(0,0);
		cout<<char(218);
		gotoxy(0,15);
		cout<<char(192);
		gotoxy(40,0);
		cout<<char(191);
		gotoxy(40,15);
		cout<<char(217);
		gotoxy(1,1);
        cout << "                KET QUA                " << endl;
        SetConsoleTextAttribute(hConsole, 7); 

        
        gotoxy(2,4);
        SetConsoleTextAttribute(hConsole, 15); 
        cout << "  So cau hoi:     ";
        SetConsoleTextAttribute(hConsole, 7);
        cout << soCauThi << endl << endl;
        gotoxy(2,6);
        SetConsoleTextAttribute(hConsole, 15);
        cout << "  So cau dung:    ";
        SetConsoleTextAttribute(hConsole, 10); 
        cout << diem << endl << endl;
        gotoxy(2,8);
        SetConsoleTextAttribute(hConsole, 15);
        cout << "  So cau sai:     ";
        SetConsoleTextAttribute(hConsole, 12); 
        cout << (soCauThi - diem) << endl << endl;
        gotoxy(2,10);
        SetConsoleTextAttribute(hConsole, 15);
        cout << "  Diem so:        ";
        SetConsoleTextAttribute(hConsole, 11); 
        cout << fixed << setprecision(2) << diemSo << endl << endl;
        gotoxy(2,12);
        SetConsoleTextAttribute(hConsole, 15);
        cout << "  Trang thai:     ";
        if (diemSo >= 5.0) 
		{
            SetConsoleTextAttribute(hConsole, 10); 
            cout << "DAT" << endl << endl;
        } 
		else 
		{
            SetConsoleTextAttribute(hConsole, 12);
            cout << "KHONG DAT" << endl << endl;
        }

        gotoxy(0,17);
      
        SetConsoleTextAttribute(hConsole, 11); 
        cout << "Nhan ESC de quay lai menu chon de thi"<<endl;
        gotoxy(0,18);
        SetConsoleTextAttribute(hConsole, 7); 
        cout << "Hoac phim bat ky khac de thoat..." << endl;
        
        
        int phim = _getch();
        if (phim == 27) 
		{ // 27 la ma ascii cua esc
            quayLaiMenu = true; // tro lai menu 
        } 
		else
     	{
     		quayLaiMenu = false;
		}
		
    }

    return 0;
}
