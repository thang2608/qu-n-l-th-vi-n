#include <iostream>
#include <string.h>
#include "quanlisach.h"
#include "ngay.h"
#include "quanlidocgia.h"
#include "muontrasach.h"
#include "Botro.h"
using namespace std;
void dsachsach(sach* Sach,int &sosachhientai,const int &sosachmax,const int &sosachmin) {
	cout << ">>>DANH SACH CAC SACH TRONG THU VIEN<<<" << endl;
	for (int i = 0; i < sosachhientai; i++) {
		cout << "Ma sach :" << Sach[i].masach << endl;
		cout << "Ten sach :" << Sach[i].tensach << endl;
		cout << "Tac gia :" << Sach[i].tacgia << endl;
		cout << "Nha san xuat :" << Sach[i].nhasanxuat << endl;
		cout << "Nam xuat ban :" << Sach[i].namxuatban << endl;
		cout << "The loai :" << Sach[i].theloai << endl;
		cout << "Gia sach :" << Sach[i].giasach << endl;
		cout << "So luong sach :" << Sach[i].soluongsach << endl << endl;
	}
	cout << endl;
}
void themsach(sach*Sach, int &sosachhientai, const int& sosachmax, const int& sosachmin) {
	cout << ">>>THEM SACH<<<" << endl;
	if (sosachhientai >= sosachmax) {
		cout << "Khong the them sach vi so sach hien tai da toi da" << endl << endl;
	}
	else{
		cin.ignore();
		cout << "Ma sach :";
		cin.getline(Sach[sosachhientai].masach, 50);
		while (kiemtramasach(Sach[sosachhientai].masach,Sach, sosachhientai) == true) {
			cin.clear();
			cout << "Ma sach da ton tai, vui long nhap lai ma sach :";
			cin.getline(Sach[sosachhientai].masach, 50);
		}
		cout << "Ten sach :";
		cin.getline(Sach[sosachhientai].tensach,50);
		cout << "Tac gia :";
		cin.getline(Sach[sosachhientai].tacgia, 50);
		cout << "Nha san xuat :";
		cin.getline(Sach[sosachhientai].nhasanxuat, 50);
		cout << "Nam xuat ban :";
		cin >>Sach[sosachhientai].namxuatban;
		while (cin.fail()||Sach[sosachhientai].namxuatban<=0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Loi du lieu nam xuat ban, vui long nhap lai nam xuat ban :";
			cin >> Sach[sosachhientai].namxuatban;
		}
		cin.ignore();
		cout << "The loai :";
		cin.getline(Sach[sosachhientai].theloai, 50);
		cout << "Gia sach :";
		cin >>Sach[sosachhientai].giasach;
		while (cin.fail() || Sach[sosachhientai].giasach <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Loi du lieu gia sach, vui long nhap lai gia sach :";
			cin >> Sach[sosachhientai].giasach;
		}
		cout << "So luong sach :";
		cin >>Sach[sosachhientai].soluongsach;
		while (cin.fail()||Sach[sosachhientai].soluongsach<=0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Loi du lieu so luong sach, vui long nhap lai so luong sach :";
			cin >>Sach[sosachhientai].soluongsach;
		}
		Sach[sosachhientai].solanmuon = 0;
		cout << endl;
		sosachhientai++;
		cout << "THEM SACH THANH CONG !" << endl;
	}
}
void xoathongtinsach(sach *Sach, int &sosachhientai, const int& sosachmax, const int& sosachmin) {
	cout << ">>>XOA THONG TIN SACH<<<" << endl;
	if (sosachhientai <= sosachmin) {
		cout << "Khong the xoa sach vi so sach hien tai dang o muc toi thieu" << endl;
	}
	else {
		int tam;
		char* masach_1 = new char[50];
		cin.ignore();
		cout << "Nhap ma sach muon xoa :";
		cin.getline(masach_1, 50);
		if (kiemtramasach(masach_1,Sach,sosachhientai)==true) {
			for (int i = 0; i < sosachhientai; i++) {
				if (strcmp(masach_1, Sach[i].masach) == 0) {
					tam = i;
				}
			}
			for (int i = tam; i < sosachhientai-1; i++) {
				Sach[i] = Sach[i + 1];
			}
			sosachhientai--;
			cout << "DA XOA THANH CONG !" << endl << endl;
		}
		else{
			cout << "KHONG TIM THAY SACH !" << endl << endl;
		}
	}
}
void timkiemsachtheoma(sach *Sach, int &sosachhientai, const int& sosachmax, const int& sosachmin) {
	char* masach_1 = new char[50];
	int tam;
	cout << ">>>TIM KIEM SACH THEO MA ISBN<<<" << endl;
	cout << "Nhap ma ISBN :";
	cin.ignore();
	cin.getline(masach_1, 50);
	if (kiemtramasach(masach_1,Sach,sosachhientai)==true) {
		for (int i = 0; i < sosachhientai; i++) {
			if (strcmp(masach_1, Sach[i].masach) == 0){
				tam = i;
			}
		}
		cout << "DA TIM THAY SACH" << endl;
		cout << "Ma sach :" << Sach[tam].masach << endl;
		cout << "Ten sach :" << Sach[tam].tensach << endl;
		cout << "Tac gia :" << Sach[tam].tacgia << endl;
		cout << "Nha san xuat :" << Sach[tam].nhasanxuat << endl;
		cout << "Nam xuat ban :" << Sach[tam].namxuatban << endl;
		cout << "The loai :" << Sach[tam].theloai << endl;
		cout << "Gia sach :" << Sach[tam].giasach << endl;
		cout << "So luong sach :" << Sach[tam].soluongsach << endl << endl;
	}
	else {
		cout << "KHONG TIM THAY SACH" << endl << endl;
	}
}
void timkiemsachtheoten(sach*Sach, int &sosachhientai, const int& sosachmax, const int& sosachmin) {
	char* tensach_1 = new char[50];
	int tam;
	cout << ">>>TIM KIEM SACH THEO TEN<<<" << endl;
	cout << "Nhap ten sach :";
	cin.ignore();
	cin.getline(tensach_1, 50);
	if (kiemtratensach(tensach_1,Sach,sosachhientai) == true) {
		for (int i = 0; i < sosachhientai; i++) {
			if (strcmp(tensach_1, Sach[i].tensach) == 0) {
				tam = i;
			}
		}
		cout << "DA TIM THAY SACH" << endl;
		cout << "Ma sach :" << Sach[tam].masach << endl;
		cout << "Ten sach :" << Sach[tam].tensach << endl;
		cout << "Tac gia :" << Sach[tam].tacgia << endl;
		cout << "Nha san xuat :" << Sach[tam].nhasanxuat << endl;
		cout << "Nam xuat ban :" << Sach[tam].namxuatban << endl;
		cout << "The loai :" << Sach[tam].theloai << endl;
		cout << "Gia sach :" << Sach[tam].giasach << endl;
		cout << "So luong sach :" << Sach[tam].soluongsach << endl << endl;
	}
	else {
		cout << "KHONG TIM THAY SACH !" << endl << endl;
	}
}
void chinhsuathongtinsach(sach*Sach, int& sosachhientai, const int& sosachmax, const int& sosachmin) {
	char* masach_tam = new char[50];
	int choice_chinhsuasach;
	int tam_sach;
	char* tam = new char[20];
	cout << ">>>CHINH SUA THONG TIN SACH<<<" << endl;
	cin.ignore();
	cout << "Nhap ma sach :";
	cin.getline(masach_tam, 50);
	while (kiemtramasach(masach_tam,Sach, sosachhientai) == false) {
		cin.clear();
		cout << "Ma sach khong ton tai, vui long nhap lai ma sach :";
		cin.getline(masach_tam, 50);
	}
	for (int i = 0; i < sosachhientai; i++) {
		if (strcmp(masach_tam, Sach[i].masach) == 0) {
			tam_sach = i;
		}
	}
	cout << "DA TIM THAY SACH" << endl;
	cout << "0.Quay lai" << endl;
	cout << "1.Ma sach" << endl;
	cout << "2.Ten sach" << endl;
	cout << "3.Tac gia" << endl;
	cout << "4.Nha san xuat" << endl;
	cout << "5.Nam xuat ban" << endl;
	cout << "6.The loai" << endl;
	cout << "7.Gia sach" << endl;
	cout << "8.So luong sach" << endl;
	cout << "Nhap choice :";
	cin >> choice_chinhsuasach;
	cin.ignore();
	switch (choice_chinhsuasach) {
	case 0:
		break;
	case 1:
		cout << "Ma sach moi :";
		cin.getline(tam, 50);
		while (kiemtramasach(tam,Sach, sosachhientai) == true||strcmp(tam,Sach[tam_sach].masach)!=0) {
			cin.clear();
			cout << "Ma sach da ton tai, vui long nhap lai ma sach :";
			cin.getline(tam, 50);
		}
		strcpy_s(Sach[tam_sach].masach, 50, tam);
		break;
	case 2:
		cout << "Ten sach moi :";
		cin.getline(Sach[tam_sach].tensach, 50);
		break;
	case 3:
		cout << "Tac gia moi :";
		cin.getline(Sach[tam_sach].tacgia, 50);
		break;
	case 4:
		cout << "Nha san xuat moi :";
		cin.getline(Sach[tam_sach].nhasanxuat, 50);
		break;
	case 5:
		cout << "Nam xuat ban moi :";
		cin >>Sach[tam_sach].namxuatban;
		while (cin.fail() || Sach[tam_sach].namxuatban <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Loi du lieu nam xuat ban, vui long nhap lai nam xuat ban :";
			cin >> Sach[tam_sach].namxuatban;
		}
		break;
	case 6:
		cout << "The loai moi :";
		cin.getline(Sach[tam_sach].theloai, 50);
		break;
	case 7:
		cout << "Gia sach moi :";
		cin >> Sach[tam_sach].giasach;
		while (cin.fail() || Sach[tam_sach].giasach <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Loi du lieu gia sach, vui long nhap lai gia sach :";
			cin >> Sach[tam_sach].giasach;
		}
		break;
	case 8:
		cout << "So luong sach moi :";
		cin >> Sach[tam_sach].soluongsach;
		while (cin.fail() ||Sach[tam_sach].soluongsach <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Loi du lieu so luong sach, vui long nhap lai so luong sach :";
			cin >> Sach[tam_sach].soluongsach;
		}
		break;
	default:
		break;
	}
	cout << "SUA THONG TIN SACH THANH CONG" << endl;
	cout << endl << endl;
}