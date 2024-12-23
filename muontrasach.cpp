#include <iostream>
#include <string.h>
#include "quanlisach.h"
#include "ngay.h"
#include "quanlidocgia.h"
#include "muontrasach.h"
#include "Botro.h"
using namespace std;
void muonsach(docgia* Docgia, sach* Sach, phieumuon* Phieumuon, const int& sosachhientai,const int& sodocgia, int &songuoimuon) {
	char* iddocgia_1 = new char[20];
	int tam;
	cout << ">>>MUON SACH<<" << endl;
	cout << "Nhap id doc gia :";
	cin.ignore();
	cin.getline(iddocgia_1, 20);
	if (kiemtradocgia(iddocgia_1, Docgia, sodocgia) == false) {
		cout << "Khong tim thay doc gia" << endl;
	}
	else if (kiemtratrasach(iddocgia_1, Phieumuon, songuoimuon))
	{
		cout << "Doc gia chua tra sach, vui long tra sach de duoc muon" << endl;
	}
	else {
		for (int i = 0; i < sodocgia; i++) {
			if (strcmp(iddocgia_1, Docgia[i].madocgia) == 0) {
				tam = i;
			}
		}
		char* isbn_tam = new char[20];
		Phieumuon[songuoimuon].Docgiamuon = Docgia[tam];
		cout << "Ngay muon :";
		cin >> Phieumuon[songuoimuon].ngaymuon[0] >> Phieumuon[songuoimuon].ngaymuon[1] >> Phieumuon[songuoimuon].ngaymuon[2];
		while (kiemtrangay(Phieumuon[songuoimuon].ngaymuon) == false || cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Loi du lieu ngay muon, vui long nhap lai ngay muon :";
			cin >> Phieumuon[songuoimuon].ngaymuon[0] >> Phieumuon[songuoimuon].ngaymuon[1] >> Phieumuon[songuoimuon].ngaymuon[2];
		}
		if (trungay(Phieumuon[songuoimuon].ngaymuon, Phieumuon[songuoimuon].Docgiamuon.ngayhethan) > 0) {
			cout << "THE MUON DA HET HAN" << endl;
		}
		else{
			cout << "Nhap so sach muon ( toi da 5 quyen ) :";
		cin >> Phieumuon[songuoimuon].sosachmuon;
		while (cin.fail() || Phieumuon[songuoimuon].sosachmuon <= 0||Phieumuon[songuoimuon].sosachmuon>=6) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Loi du lieu so sach muon, vui long nhap lai so sach muon :";
			cin >> Phieumuon[songuoimuon].sosachmuon;
		}
		cin.ignore();
		for (int i = 0; i < Phieumuon[songuoimuon].sosachmuon; i++) {
			cout << "Nhap ISBN sach thu " << i + 1 << " :";
			cin.getline(isbn_tam, 20);
			while (kiemtramasach(isbn_tam, Sach, sosachhientai) == false) {
				cout << "Khong ton tai ISBN sach, vui long nhap lai ma ISBN sach thu " << i + 1 << " :";
				cin.getline(isbn_tam, 20);
			}
			for (int j = 0; j < sosachhientai; j++) {
				if (strcmp(isbn_tam, Sach[j].masach) == 0) {
					if (Sach[j].soluongsach == 0) {
						cout << "So luong sach co ma " << Sach[j].masach << " da het, mong quy khach thong cam" << endl;
						break;
					}
					Phieumuon[songuoimuon].Sachmuon[i] = Sach[j];
					Sach[j].soluongsach--;
					Sach[j].solanmuon++;
				}
			}
		}
			congngay(Phieumuon[songuoimuon].ngaymuon, Phieumuon[songuoimuon].ngaytradukien, 7);
			Phieumuon[sodocgia].Docgiamuon = Docgia[tam];
			songuoimuon++;
			cout << "MUON SACH THANH CONG" << endl;
		}
	}
}
void trasach(docgia* Docgia, sach* &Sach, phieumuon* &Phieumuon, const int& sosachhientai, const int& sodocgia, int &songuoimuon) {
	cout << ">>TRA SACH<<" << endl;
	int ngaytam[3];
	int tam;
	char* id_tam = new char[20];
	cout << "Nhap ID doc gia :";
	cin.ignore();
	cin.getline(id_tam, 20);
	
	if (kiemtradocgia(id_tam,Docgia,sodocgia)==false) {
		cout << "Khong tim thay doc gia da muon sach" << endl;
	}
	else {
		for (int i = 0; i < songuoimuon; i++) {
			if (strcmp(id_tam,Phieumuon[i].Docgiamuon.madocgia) == 0) {
				tam = i;
			}
		}
		int matsach=3;
		int tien_boi_thuong = 0;
			cout << "Nhap ngay tra sach :";
			cin >> ngaytam[0] >> ngaytam[1] >> ngaytam[2];
			while (kiemtrangay(ngaytam) == false || cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Loi du lieu ngay tra, vui long nhap lai ngay tra :";
				cin >> ngaytam[0] >> ngaytam[1] >> ngaytam[2];
		}
			for (int i = 0; i <Phieumuon[tam].sosachmuon; i++){
				do {
					cout << "Ma sach " <<Phieumuon[tam].Sachmuon[i].masach << " nhap 1 neu tra sach,nhap 0 neu lam mat sach :";
					cin >> matsach;
				} while ((matsach != 0 )&&( matsach != 1));
				if (matsach == 0) {
					tien_boi_thuong = tien_boi_thuong +2 * Phieumuon[tam].Sachmuon[i].giasach;
				}
				else {
					for (int j = 0; j < sosachhientai; j++) {
						if (strcmp(Phieumuon[tam].Sachmuon[i].masach, Sach[j].masach)==0) {
							Sach[j].soluongsach++;
						}
					}
				}
			}
			if (trungay(ngaytam,Phieumuon[tam].ngaytradukien) > 0) {
				tien_boi_thuong = tien_boi_thuong + trungay(ngaytam, Phieumuon[tam].ngaytradukien) * 5000;
			}
			cout << "So tien boi thuong la :" << tien_boi_thuong << endl;
			for (int i = tam; i < songuoimuon-1; i++) {
				Phieumuon[tam] = Phieumuon[tam + 1];
			}
			songuoimuon--;
			cout << "TRA SACH THANH CONG" << endl;
		}
}
