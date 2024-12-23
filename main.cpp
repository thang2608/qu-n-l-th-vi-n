#include <iostream>
#include "Botro.h"
#include "quanlidocgia.h"
#include "quanlisach.h"
#include "muontrasach.h"
#include "ngay.h"
#include "thongke.h"
using namespace std;
int main() {
	int sodocgia=0;
	int sosachhientai=0;
	int songuoimuon=0;
	const int docgiamax = 20;
	const int docgiamin = 1;
	const int sosachmax = 20;
	const int sosachmin = 1;
	docgia* Docgia = new docgia[20];
	sach* Sach = new sach[20];
	phieumuon* Phieumuon = new phieumuon[20];
	FILE* f1;
	errno_t err =fopen_s(&f1, "quanlidocgia.txt", "r");
	if (err != 0) {
		cout << "Loi file quan li doc gia" << endl;
		return 1;
	}
	fscanf_s(f1, "%d\n", &sodocgia);
	for (int i = 0; i < sodocgia; i++) {
		char* tam = new char[1000];
		fgets(tam, 1000, f1);
		Docgia[i].madocgia = strtok_s(tam, ",", &tam);
		Docgia[i].hoten = strtok_s(tam, ",", &tam);
		Docgia[i].cmnd = strtok_s(tam, ",", &tam);
		char* ngaysinh = strtok_s(tam, ",", &tam);
		char* ngaysinh0 = strtok_s(ngaysinh, " ", &ngaysinh);
		Docgia[i].ngaysinh[0] = chuyenchuoiveso(ngaysinh0);
		char* ngaysinh1 = strtok_s(ngaysinh, " ", &ngaysinh);
		Docgia[i].ngaysinh[1] = chuyenchuoiveso(ngaysinh1);
		Docgia[i].ngaysinh[2] = chuyenchuoiveso(ngaysinh);
		Docgia[i].gioitinh = strtok_s(tam, ",", &tam);
		Docgia[i].email = strtok_s(tam, ",", &tam);
		Docgia[i].diachi = strtok_s(tam, ",", &tam);
		char* ngaylapthe = strtok_s(tam, ",", &tam);
		char* ngaylapthe0 = strtok_s(ngaylapthe, " ", &ngaylapthe);
		Docgia[i].ngaylapthe[0] = chuyenchuoiveso(ngaylapthe0);
		char* ngaylapthe1 = strtok_s(ngaylapthe, " ", &ngaylapthe);
		Docgia[i].ngaylapthe[1] = chuyenchuoiveso(ngaylapthe1);
		Docgia[i].ngaylapthe[2] = chuyenchuoiveso(ngaylapthe);
		char* ngayhethan = strtok_s(tam, ",", &tam);
		char* ngayhethan0 = strtok_s(ngayhethan, " ", &ngayhethan);
		Docgia[i].ngayhethan[0] = chuyenchuoiveso(ngayhethan0);
		char* ngayhethan1 = strtok_s(ngayhethan, " ", &ngayhethan);
		Docgia[i].ngayhethan[1] = chuyenchuoiveso(ngayhethan1);
		char* ngayhethan2 = new char[10];
		ngayhethan2=strtok_s(ngayhethan, "\n", &ngayhethan);
		Docgia[i].ngayhethan[2] = chuyenchuoiveso(ngayhethan2);
	}
	fclose(f1);
	FILE* f2;
	err =fopen_s(&f2, "quanlisach.txt", "r");
	if (err!=0) {
		cout << "Loi file quan li sach" << endl;
		return 1;
	}
	fscanf_s(f2, "%d\n", &sosachhientai);
	for (int i = 0; i < sosachhientai; i++) {
		char* tam = new char[1000];
		fgets(tam, 999, f2);
		Sach[i].masach = strtok_s(tam, ",", &tam);
		Sach[i].tensach = strtok_s(tam, ",", &tam);
		Sach[i].tacgia = strtok_s(tam, ",", &tam);
		Sach[i].nhasanxuat = strtok_s(tam, ",", &tam);
		char* namxuatban = new char[10];
		namxuatban = strtok_s(tam, ",", &tam);
		Sach[i].namxuatban = chuyenchuoiveso(namxuatban);
		Sach[i].theloai = strtok_s(tam, ",", &tam);
		char* giasach = new char[20];
		giasach = strtok_s(tam, ",", &tam);
		Sach[i].giasach = chuyenchuoiveso(giasach);
		char* soluongsach = new char[10];
		soluongsach = strtok_s(tam, ",", &tam);
		Sach[i].soluongsach = chuyenchuoiveso(soluongsach);
		char* solanmuon = new char[10];
		solanmuon = strtok_s(tam, "\n", &tam);
		Sach[i].solanmuon = chuyenchuoiveso(solanmuon);
	}
	fclose(f2);
	FILE* f3;
	err=fopen_s(&f3, "phieumuon.txt", "r");
	if (err!=0) {
		cout << "Loi file phieu muon" << endl;
		return 1;
	}
	fscanf_s(f3, "%d\n", &songuoimuon);
	for (int i = 0; i < songuoimuon; i++) {
		char* tam = new char[1000];
		fgets(tam, 999, f3);
		Phieumuon[i].Docgiamuon.madocgia = strtok_s(tam, ",", &tam);
		Phieumuon[i].Docgiamuon.hoten = strtok_s(tam, ",", &tam);
		Phieumuon[i].Docgiamuon.cmnd = strtok_s(tam, ",", &tam);
		char* ngaysinh = strtok_s(tam, ",", &tam);
		char* ngaysinh0 = strtok_s(ngaysinh, " ", &ngaysinh);
		Phieumuon[i].Docgiamuon.ngaysinh[0] = chuyenchuoiveso(ngaysinh0);
		char* ngaysinh1 = strtok_s(ngaysinh, " ", &ngaysinh);
		Phieumuon[i].Docgiamuon.ngaysinh[1] = chuyenchuoiveso(ngaysinh1);
		Phieumuon[i].Docgiamuon.ngaysinh[2] = chuyenchuoiveso(ngaysinh);
		Phieumuon[i].Docgiamuon.gioitinh = strtok_s(tam, ",", &tam);
		Phieumuon[i].Docgiamuon.email= strtok_s(tam, ",", &tam);
		Phieumuon[i].Docgiamuon.diachi = strtok_s(tam, ",", &tam);
		char* ngaylapthe = strtok_s(tam, ",", &tam);
		char* ngaylapthe0 = strtok_s(ngaylapthe, " ", &ngaylapthe);
		Phieumuon[i].Docgiamuon.ngaylapthe[0] = chuyenchuoiveso(ngaylapthe0);
		char* ngaylapthe1 = strtok_s(ngaylapthe, " ", &ngaylapthe);
		Phieumuon[i].Docgiamuon.ngaylapthe[1] = chuyenchuoiveso(ngaylapthe1);
		Phieumuon[i].Docgiamuon.ngaylapthe[2] = chuyenchuoiveso(ngaylapthe);
		char* ngayhethan = strtok_s(tam, ",", &tam);
		char* ngayhethan0 = strtok_s(ngayhethan, " ", &ngayhethan);
		Phieumuon[i].Docgiamuon.ngayhethan[0] = chuyenchuoiveso(ngayhethan0);
		char* ngayhethan1 = strtok_s(ngayhethan, " ", &ngayhethan);
		Phieumuon[i].Docgiamuon.ngayhethan[1] = chuyenchuoiveso(ngayhethan1);
		Phieumuon[i].Docgiamuon.ngayhethan[2] = chuyenchuoiveso(ngayhethan);
		char* sosachmuon = new char[5];
		sosachmuon = strtok_s(tam, ",", &tam);
		Phieumuon[i].sosachmuon = chuyenchuoiveso(sosachmuon);
		for (int j = 0; j < Phieumuon[i].sosachmuon; j++) {
			Phieumuon[i].Sachmuon[j].masach = strtok_s(tam, ",", &tam);
			Phieumuon[i].Sachmuon[j].tensach = strtok_s(tam, ",", &tam);
			Phieumuon[i].Sachmuon[j].tacgia = strtok_s(tam, ",", &tam);
			Phieumuon[i].Sachmuon[j].nhasanxuat = strtok_s(tam, ",", &tam);
			char* namxuatban = new char[10];
			namxuatban = strtok_s(tam, ",", &tam);
			Phieumuon[i].Sachmuon[j].namxuatban = chuyenchuoiveso(namxuatban);
			Phieumuon[i].Sachmuon[j].theloai = strtok_s(tam, ",", &tam);
			char* giasach = new char[20];
			giasach = strtok_s(tam, ",", &tam);
			Phieumuon[i].Sachmuon[j].giasach = chuyenchuoiveso(giasach);
			char* soluongsach = new char[10];
			soluongsach = strtok_s(tam, ",", &tam);
			Phieumuon[i].Sachmuon[j].soluongsach = chuyenchuoiveso(soluongsach);
			char* solanmuon = new char[10];
			solanmuon = strtok_s(tam, ",", &tam);
			Phieumuon[i].Sachmuon[j].solanmuon = chuyenchuoiveso(solanmuon);
		}
		char* ngaymuon = new char[15];
		ngaymuon = strtok_s(tam, ",", &tam);
		char* ngaymuon0 = new char[5];
		ngaymuon0 = strtok_s(ngaymuon, " ", &ngaymuon);
		Phieumuon[i].ngaymuon[0] = chuyenchuoiveso(ngaymuon0);
		char* ngaymuon1 = new char[5];
		ngaymuon1 = strtok_s(ngaymuon, " ", &ngaymuon);
		Phieumuon[i].ngaymuon[1] = chuyenchuoiveso(ngaymuon1);
		Phieumuon[i].ngaymuon[2] = chuyenchuoiveso(ngaymuon);
		char* ngaytradukien = new char[15];
		ngaytradukien = strtok_s(tam, "\n", &tam);
		char* ngaytradukien0 = new char[5];
		ngaytradukien0 = strtok_s(ngaytradukien, " ", &ngaytradukien);
		Phieumuon[i].ngaytradukien[0] = chuyenchuoiveso(ngaytradukien0);
		char* ngaytradukien1 = new char[5];
		ngaytradukien1 = strtok_s(ngaytradukien, " ", &ngaytradukien);
		Phieumuon[i].ngaytradukien[1] = chuyenchuoiveso(ngaytradukien1);
		Phieumuon[i].ngaytradukien[2] = chuyenchuoiveso(ngaytradukien);
	}
	fclose(f3);
	int choice_menuchinh, choice_qldg, choice_qls, choice_muonsach, choice_thongke;
	do {
		cout << "=====================================" << endl;
		cout << "|>>>CHUONG TRINH QUAN LI THU VIEN<<<|" << endl;
		cout << "=====================================" << endl;
		cout << "|0.Quay lai                         |" << endl;
		cout << "|1.Quan li doc gia                  |" << endl;
		cout << "|2.Quan li sach                     |" << endl;
		cout << "|3.Tao phieu muon sach              |" << endl;
		cout << "|4.Tao phieu tra sach               |" << endl;
		cout << "|5.Cac thong ke co ban              |" << endl;
		cout << "=====================================" << endl;
		cout << "Nhap choice :";
		cin >> choice_menuchinh;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Loi nhap du lieu, vui long nhap lai choice :";
			cin >> choice_menuchinh;
		}
		cout << endl << endl;
		switch (choice_menuchinh) {
		case 0:
			break;
		case 1:
		{
			do {
				cout << "====================================" << endl;
				cout << "|>>>CHUONG TRINH QUAN LI DOC GIA<<<|" << endl;
				cout << "====================================" << endl;
				cout << "|0.Quay lai                        |" << endl;
				cout << "|1.Danh sach doc gia               |" << endl;
				cout << "|2.Them doc gia                    |" << endl;
				cout << "|3.Chinh sua thong tin doc gia     |" << endl;
				cout << "|4.Xoa mot doc gia                 |" << endl;
				cout << "|5,Tim kiem doc gia theo cmnd      |" << endl;
				cout << "|6,Tim kiem doc gia theo ten       |" << endl;
				cout << "====================================" << endl;
				cout << "Nhap choice: ";
				cin >> choice_qldg;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Loi nhap du lieu, vui long nhap lai choice :";
					cin >> choice_qldg;
				}
				cout << endl << endl;
				switch (choice_qldg) {
				case 0:
					break;
				case 1:
					dsachdocgia(Docgia, sodocgia, docgiamax, docgiamin);
					break;
				case 2:
					themdocgia(Docgia, sodocgia, docgiamax, docgiamin);
					break;
				case 3:
					chinhsuathongtindocgia(Docgia, sodocgia, docgiamax, docgiamin);
					break;
				case 4:
					xoadocgia(Docgia, sodocgia, docgiamax, docgiamin);
					break;
				case 5:
					timkiemtheocmnd(Docgia, sodocgia, docgiamax, docgiamin);
					break;
				case 6:
					timkiemtheoten(Docgia, sodocgia, docgiamax, docgiamin);
					break;
				default:
					break;
				}
				cout << endl << endl;
			} while (choice_qldg);
			break;
		}
		case 2: {
			do {
				cout << "=====================================" << endl;
				cout << "|  >>>CHUONG TRINH QUAN LI SACH<<<  |" << endl;
				cout << "=====================================" << endl;
				cout << "|0.Quay lai                         |" << endl;
				cout << "|1.Danh sach cac sach trong thu vien|" << endl;
				cout << "|2.Them sach                        |" << endl;
				cout << "|3.Chinh sua thong tin sach         |" << endl;
				cout << "|4.Xoa thong tin sach               |" << endl;
				cout << "|5.Tim kiem sach theo ma            |" << endl;
				cout << "|6.Tim kiem sach theo ten           |" << endl;
				cout << "=====================================" << endl;
				cout << "Nhap choice :";
				cin >> choice_qls;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Loi nhap du lieu, vui long nhap lai choice :";
					cin >> choice_qls;
				}
				cout << endl << endl;
				switch (choice_qls) {
				case 0:
					break;
				case 1:
					dsachsach(Sach, sosachhientai, sosachmax, sosachmin);
					break;
				case 2:
					themsach(Sach, sosachhientai, sosachmax, sosachmin);
					break;
				case 3:
					chinhsuathongtinsach(Sach, sosachhientai, sosachmax, sosachmin);
							break;
				case 4:
					xoathongtinsach(Sach, sosachhientai, sosachmax, sosachmin);
					break;
				case 5:
					timkiemsachtheoma(Sach, sosachhientai, sosachmax, sosachmin);
					break;
				case 6:
					timkiemsachtheoten(Sach, sosachhientai, sosachmax, sosachmin);
					break;
				default:
					break;
				}
			} while (choice_qls);
			cout << endl << endl;
			break;
		}
		case 3:
		{
			cout<< ">>>LAP PHIEU MUON SACH<<<" << endl;
			muonsach(Docgia,Sach,Phieumuon, sosachhientai,sodocgia, songuoimuon);
			cout << endl << endl;
			break;
		}
		case 4:
			cout<< ">>>LAP PHIEU TRA SACH<<<" << endl;
			trasach(Docgia,Sach,Phieumuon,sosachhientai,sodocgia,songuoimuon);
			cout << endl << endl;
			break;
		case 5:
			do {
				cout << "============================================" << endl;
				cout << "|        >>>CAC THONG KE CO BAN<<<         |" << endl;
				cout << "============================================" << endl;
				cout << "|0.Quay lai                                |" << endl;
				cout << "|1.So luong sach trong thu vien            |" << endl;
				cout << "|2.Thong ke so luong sach theo the loai    |" << endl;
				cout << "|3.Thong ke so luong doc gia               |" << endl;
				cout << "|4.Thong ke so luong doc gia theo gioi tinh|" << endl;
				cout << "|5.Thong ke so sach dang duoc muon         |" << endl;
				cout << "|6.Thong ke so doc gia tre han             |" << endl;
				cout << "|7.Sach duoc muon nhieu nhat               |" << endl;
				cout << "============================================" << endl;
				cout << "Nhap choice :";
				cin >> choice_thongke;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Loi nhap du lieu, vui long nhap lai choice :";
					cin >> choice_thongke;
				}
				cout << endl << endl;
				switch (choice_thongke) {
				case 0:
					break;
				case 1:
					cout << "So luong sach trong thu vien la :" << thongkesoluongsachhientai(Sach, sosachhientai) << endl;
					break;
				case 2:
					sosachtheotheloai(Sach,sosachhientai);
					break;
				case 3:
					cout << "So luong doc gia la :" << sodocgia << endl;
					break;
				case 4:
					soluongdocgiatheogioitinh(Docgia, sodocgia);
					break;
				case 5:
					cout << "So sach dang muon la :" << sosachdangmuon(Phieumuon,songuoimuon) << endl;
					break;
				case 6:
					sodocgiatrehan(Phieumuon, songuoimuon);
					break;
				case 7:
					sachmuonnhieunhat(Sach,sosachhientai);
					break;
				default:
					break;
				}
				cout << endl << endl;
			} while (choice_thongke);
		default:
			break;
		}
		} while (choice_menuchinh);
		FILE* fp1;
		err = fopen_s(&fp1, "quanlidocgia.txt", "w");
		if (err != 0) {
			cout << "Loi file quanlidocgia.txt";
			return 1;
		}
		fprintf_s(fp1, "%d\n",sodocgia);
			for (int i = 0; i < sodocgia; i++) {
				char* tam = new char[1000];
				sprintf_s(tam, 999, "%s,%s,%s,%d %d %d,%s,%s,%s,%d %d %d,%d %d %d\n",
					Docgia[i].madocgia,
					Docgia[i].hoten,
					Docgia[i].cmnd,
					Docgia[i].ngaysinh[0],
					Docgia[i].ngaysinh[1],
					Docgia[i].ngaysinh[2],
					Docgia[i].gioitinh,
					Docgia[i].email,
					Docgia[i].diachi,
					Docgia[i].ngaylapthe[0],
					Docgia[i].ngaylapthe[1],
					Docgia[i].ngaylapthe[2],
					Docgia[i].ngayhethan[0],
					Docgia[i].ngayhethan[1],
					Docgia[i].ngayhethan[2]
					);
				fprintf_s(fp1, "%s", tam);
				delete[] tam;
			}
			fclose(fp1);
		FILE* fp2;
		err = fopen_s(&fp2, "quanlisach.txt", "w");
		if (err != 0) {
			cout << "Loi file quanlisach.txt";
			return 1;
		}
		fprintf_s(fp2, "%d\n", sosachhientai);
		for (int i = 0; i < sosachhientai; i++) {
			char* tam = new char[1000];
			sprintf_s(tam, 999, "%s,%s,%s,%s,%d,%s,%d,%d,%d\n",
				Sach[i].masach,
				Sach[i].tensach,
				Sach[i].tacgia,
				Sach[i].nhasanxuat,
				Sach[i].namxuatban,
				Sach[i].theloai,
				Sach[i].giasach,
				Sach[i].soluongsach,
				Sach[i].solanmuon
				);
			fprintf_s(fp2, "%s", tam);
			delete[] tam;
		}
		fclose(fp2);
		FILE* fp3;
		err = fopen_s(&fp3, "phieumuon.txt", "wb");
		if (err != 0) {
			cout << "Loi file phieumuon.txt";
			return 1;
		}
		fprintf_s(fp3, "%d\n", songuoimuon);
		for (int i = 0; i < songuoimuon; i++) {
			char* tam = new char[1000];
			sprintf_s(tam, 999, "%s,%s,%s,%d %d %d,%s,%s,%s,%d %d %d,%d %d %d,%d,",
				Phieumuon[i].Docgiamuon.madocgia,
				Phieumuon[i].Docgiamuon.hoten,
				Phieumuon[i].Docgiamuon.cmnd,
				Phieumuon[i].Docgiamuon.ngaysinh[0],
				Phieumuon[i].Docgiamuon.ngaysinh[1],
				Phieumuon[i].Docgiamuon.ngaysinh[2],
				Phieumuon[i].Docgiamuon.gioitinh,
				Phieumuon[i].Docgiamuon.email,
				Phieumuon[i].Docgiamuon.diachi,
				Phieumuon[i].Docgiamuon.ngaylapthe[0],
				Phieumuon[i].Docgiamuon.ngaylapthe[1],
				Phieumuon[i].Docgiamuon.ngaylapthe[2],
				Phieumuon[i].Docgiamuon.ngayhethan[0],
				Phieumuon[i].Docgiamuon.ngayhethan[1],
				Phieumuon[i].Docgiamuon.ngayhethan[2],
				Phieumuon[i].sosachmuon
			);
				for (int j = 0; j < Phieumuon[i].sosachmuon; j++) {
					sprintf_s(tam + strlen(tam), 999, "%s,%s,%s,%s,%d,%s,%d,%d,%d,",
						Phieumuon[i].Sachmuon[j].masach,
						Phieumuon[i].Sachmuon[j].tensach,
						Phieumuon[i].Sachmuon[j].tacgia,
						Phieumuon[i].Sachmuon[j].nhasanxuat,
						Phieumuon[i].Sachmuon[j].namxuatban,
						Phieumuon[i].Sachmuon[j].theloai,
						Phieumuon[i].Sachmuon[j].giasach,
						Phieumuon[i].Sachmuon[j].soluongsach,
						Phieumuon[i].Sachmuon[j].solanmuon
						);
				}
				sprintf_s(tam + strlen(tam), 999, "%d %d %d,%d %d %d",
					Phieumuon[i].ngaymuon[0],
					Phieumuon[i].ngaymuon[1],
					Phieumuon[i].ngaymuon[2],
					Phieumuon[i].ngaytradukien[0],
					Phieumuon[i].ngaytradukien[1],
					Phieumuon[i].ngaytradukien[2]
					);
				fprintf_s(fp3, "%s", tam);
		}
		fclose(fp3);
		return 0;
	}