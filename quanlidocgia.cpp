#include <iostream>
#include <string.h>
#include "quanlidocgia.h"
#include "ngay.h"
#include "muontrasach.h"
#include "Botro.h"
using namespace std;
void dsachdocgia(docgia* Docgia, int& sodocgia, const int& docgiamax, const int& docgia_min) {
	cout << ">>>DANH SACH DOC GIA<<<" << endl;
	for (int i = 0; i < sodocgia; i++) {
		cout << "Id :" << Docgia[i].madocgia << endl;
		cout << "Ten :" << Docgia[i].hoten << endl;
		cout << "CMND :" << Docgia[i].cmnd << endl;
		cout << "Email: " << Docgia[i].email << endl;
		cout << "Dia chi: " << Docgia[i].diachi << endl;
		cout << "Ngay sinh :" << Docgia[i].ngaysinh[0] << "/" << Docgia[i].ngaysinh[1] << "/" << Docgia[i].ngaysinh[2] << endl;
		cout << "Gioi tinh :" << Docgia[i].gioitinh << endl;
		cout << "Ngay lap the :" << Docgia[i].ngaylapthe[0] << "/" << Docgia[i].ngaylapthe[1] << "/" << Docgia[i].ngaylapthe[2] << endl;
		cout << "Ngay het han the :" << Docgia[i].ngayhethan[0] << "/" << Docgia[i].ngayhethan[1] << "/" << Docgia[i].ngayhethan[2] << endl << endl;
	}
}
void themdocgia(docgia* Docgia, int& sodocgia, const int& docgiamax, const int& docgia_min) {
	cout << ">>>THEM DOC GIA<<<" << endl;
	if (sodocgia == docgiamax) {
		cout << "Khong the them doc gia vi so doc gia da toi da" << endl;
	}
	else {
		cin.ignore();
		cout << "Nhap id doc gia :";
		cin.getline(Docgia[sodocgia].madocgia, 30);
		while (kiemtradocgia(Docgia[sodocgia].madocgia,Docgia, sodocgia) == true||chuoitoanso(Docgia[sodocgia].madocgia)==false) {
			if (kiemtradocgia(Docgia[sodocgia].madocgia, Docgia, sodocgia) == true) {
				cin.clear();
				cout << "Id doc gia da ton tai, vui long nhap lai id doc gia :";
				cin.getline(Docgia[sodocgia].madocgia, 30);
			}
			else {
				cin.clear();
				cout << "ID doc gia khong duoc chua ki tu, vui long nhap lai ID doc gia :";
				cin.getline(Docgia[sodocgia].madocgia, 30);
			}
		}
		cout << "Nhap ten doc gia :";
		cin.getline(Docgia[sodocgia].hoten, 30);
		cout << "Nhap CMND :";
		cin.getline(Docgia[sodocgia].cmnd, 20);
		while (chuoitoanso(Docgia[sodocgia].cmnd) == false || kiemtracmnd(Docgia[sodocgia].cmnd,Docgia, sodocgia) == true) {
			cin.clear();
			if (chuoitoanso(Docgia[sodocgia].cmnd) == false) {
				cout << "CMND khong duoc co ki tu, vui long nhap lai :";
				cin.getline(Docgia[sodocgia].cmnd, 20);
			}
			else {
				cout << "Da ton tai CMND, vui long nhap lai :";
				cin.getline(Docgia[sodocgia].cmnd, 20);
			}
		}
		cout << "Email :";
		cin.getline(Docgia[sodocgia].email, 30);
		cout << "Dia chi :";
		cin.getline(Docgia[sodocgia].diachi, 70);
		cout << "Ngay sinh :";
		cin >>Docgia[sodocgia].ngaysinh[0] >> Docgia[sodocgia].ngaysinh[1] >> Docgia[sodocgia].ngaysinh[2];
		while (kiemtrangay(Docgia[sodocgia].ngaysinh) == false||cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Loi nhap du lieu ngay sinh khong ton tai,nhap lai ngay sinh :";
			cin >> Docgia[sodocgia].ngaysinh[0] >> Docgia[sodocgia].ngaysinh[1] >> Docgia[sodocgia].ngaysinh[2];
		}
		cin.ignore();
		cout << "Gioi tinh ( Nam hoac Nu ) :";
		cin.getline(Docgia[sodocgia].gioitinh, 10);
		while (strcmp(Docgia[sodocgia].gioitinh, "Nam") != 0 && strcmp(Docgia[sodocgia].gioitinh, "Nu") != 0) {
			cout << "Loi nhap du lieu gioi tinh, vui long nhap lai gioi tinh ( Nam hoac Nu ) :";
			cin.getline(Docgia[sodocgia].gioitinh, 10);
		}
		cout << "Ngay lap the: ";
		cin >> Docgia[sodocgia].ngaylapthe[0] >> Docgia[sodocgia].ngaylapthe[1] >> Docgia[sodocgia].ngaylapthe[2];
		while (kiemtrangay(Docgia[sodocgia].ngaylapthe) == false||cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Loi ngay lap the khong ton tai, nhap lai ngay nhap the :";
			cin >> Docgia[sodocgia].ngaylapthe[0] >> Docgia[sodocgia].ngaylapthe[1] >> Docgia[sodocgia].ngaylapthe[2];
		}
		congngay(Docgia[sodocgia].ngaylapthe, Docgia[sodocgia].ngayhethan, 1461);
		sodocgia++;
	}
	cout << "THEM DOC GIA THANH CONG !" << endl;
}

void xoadocgia(docgia* Docgia, int& sodocgia, const int& docgiamax, const int& docgia_min) {
	cout << ">>>XOA DOC GIA<<<" << endl;
	if (sodocgia == docgia_min) {
		cout << "Khong the xoa doc gia vi so doc gia dang o muc toi thieu" << endl;
	}
	else {
		int sothutu=-1;
		char* cmnd_1 = new char[20];
		cin.ignore();
		cout << "Nhap CMND doc gia muon xoa :";
		cin.getline(cmnd_1, 20);
		while (chuoitoanso(cmnd_1) == false) {
			cin.clear();
			cout << "CMND khong duoc co ki tu, vui long nhap lai CMND :";
			cin.getline(cmnd_1, 20);
		}
		for (int i = 0; i < sodocgia; i++) {
			if (strcmp(Docgia[i].cmnd,cmnd_1) == 0) {
				sothutu = i;
			}
		}
		if (sothutu >= 0) {
			for (int i = sothutu; i < sodocgia; i++) {
				Docgia[i] = Docgia[i + 1];
			}
			cout << "XOA DOC GIA THANH CONG !" << endl;
			sodocgia--;
		}
		else {
			cout << "KHONG TIM THAY DOC GIA" << endl;
		}
	}
}
void timkiemtheocmnd(docgia *Docgia, int& sodocgia, const int& docgiamax, const int& docgia_min) {
	cout << ">>>TIM KIEM DOC GIA THEO CMND<<<" << endl;
	char* cmnd_1 = new char[20];
	bool timkiem = false;
	cin.ignore();
	cout << "Nhap CMND doc gia muon tim: ";
	cin.getline(cmnd_1, 20);
	while (chuoitoanso(cmnd_1) == false) {
		cin.clear();
		cout << "CMND khong duoc co ki tu, vui long nhap lai CMND :";
		cin.getline(cmnd_1, 20);
	}
	for (int i = 0; i < sodocgia; i++) {
		if (strcmp(Docgia[i].cmnd, cmnd_1) == 0) {
			timkiem = true;
			cout << "DA TIM THAY DOC GIA" << endl;
			cout << "Id :" << Docgia[i].madocgia << endl;
			cout << "Ten :" << Docgia[i].hoten << endl;
			cout << "CMND :" << Docgia[i].cmnd << endl;
			cout << "Email: " << Docgia[i].email << endl;
			cout << "Dia chi: " << Docgia[i].diachi << endl;
			cout << "Ngay sinh :" << Docgia[i].ngaysinh[0] << "/" << Docgia[i].ngaysinh[1] << "/" << Docgia[i].ngaysinh[2] << endl;
			cout << "Gioi tinh :" << Docgia[i].gioitinh << endl;
			cout << "Ngay lap the :" << Docgia[i].ngaylapthe[0] << "/" << Docgia[i].ngaylapthe[1] << "/" << Docgia[i].ngaylapthe[2] << endl;
			cout << "Ngay het han the :" << Docgia[i].ngayhethan[0] << "/" << Docgia[i].ngayhethan[1] << "/" << Docgia[i].ngayhethan[2] + 4 << endl;
		}
	}
	if (timkiem == false) {
		cout << "KHONG TIM THAY DOC GIA" << endl;
	}
}
void timkiemtheoten(docgia* Docgia, int& sodocgia, const int& docgiamax, const int& docgia_min) {
	cout << ">>>TIM KIEM DOC GIA THEO TEN<<<" << endl;
	char* ten = new char[20];
	bool timkiem = false;
	cin.ignore();
	cout << "Nhap ho va ten doc gia muon tim: ";
	cin.getline(ten, 20);
	for (int i = 0; i < sodocgia; i++) {
		if (strcmp(ten,Docgia[i].hoten) == 0) {
			timkiem = true;
			cout << "Id :" << Docgia[i].madocgia << endl;
			cout << "Ten :" << Docgia[i].hoten << endl;
			cout << "CMND :" << Docgia[i].cmnd << endl;
			cout << "Email: " << Docgia[i].email << endl;
			cout << "Dia chi: " << Docgia[i].diachi << endl;
			cout << "Ngay sinh :" << Docgia[i].ngaysinh[0] << "/" << Docgia[i].ngaysinh[1] << "/" << Docgia[i].ngaysinh[2] << endl;
			cout << "Gioi tinh :" << Docgia[i].gioitinh << endl;
			cout << "Ngay lap the :" << Docgia[i].ngaylapthe[0] << "/" << Docgia[i].ngaylapthe[1] << "/" << Docgia[i].ngaylapthe[2] << endl;
			cout << "Ngay het han the :" << Docgia[i].ngayhethan[0] << "/" << Docgia[i].ngayhethan[1] << "/" << Docgia[i].ngayhethan[2] + 4 << endl << endl;
		}
	}
	if (timkiem == false) {
		cout << "KHONG TIM THAY DOC GIA";
	}
}
void chinhsuathongtindocgia(docgia* Docgia,const int& sodocgia, const int& docgiamax, const int& docgia_min){
	int choice_docgia;
	int tam_docgia;
	char* cmnd_tam = new char[20];
	char* tam = new char[20];
	cout << ">>>CHINH SUA THONG TIN DOC GIA<<<" << endl;
	cin.ignore();
	cout << "Nhap cmnd: ";
	cin.getline(cmnd_tam, 20);
	while (kiemtracmnd(cmnd_tam,Docgia, sodocgia) == false||chuoitoanso(cmnd_tam)==false) {
		cin.clear();
		if (kiemtracmnd(cmnd_tam, Docgia, sodocgia) == false) {
			cout << "Khong ton tai CMND, vui long nhap lai CMND :";
			cin.getline(cmnd_tam, 20);
		}
		else {
			cout << "CMND khong duoc co ki tu, vui long nhap lai CMND :";
			cin.getline(cmnd_tam, 20);
		}
	}
	for (int i = 0; i < sodocgia; i++) {
		if (strcmp(cmnd_tam,Docgia[i].cmnd) == 0) {
			tam_docgia = i;
		}
	}
	cout << "Da tim thay doc gia, vui long chon thong tin can sua" << endl;
	cout << "0.Quay lai" << endl;
	cout << "1.ID doc gia" << endl;
	cout << "2.Ten doc gia" << endl;
	cout << "3.CMND doc gia" << endl;
	cout << "4.Email doc gia" << endl;
	cout << "5.Ngay sinh doc gia" << endl;
	cout << "6.Dia chi doc gia" << endl;
	cout << "7.Gioi tinh doc gia" << endl;
	cout << "8.Ngay lap the" << endl;
	cout << "Nhap choice:";
	cin >> choice_docgia;
	cin.ignore();
	switch (choice_docgia) {
	case 0:
		break;
	case 1:
		cout << "Nhap id doc gia: ";
		cin.getline(tam, 30);
		while ((kiemtradocgia(tam,Docgia, sodocgia) == true&&strcmp(tam,Docgia[tam_docgia].madocgia)!=0) || chuoitoanso(tam) == false) {
			cin.clear();
			if (kiemtradocgia(tam, Docgia, sodocgia) == true) {
				cout << "Id doc gia da ton tai, vui long nhap lai id doc gia :";
				cin.getline(tam, 30);
			}
			else {
				cout << "ID doc gia khong duoc chua ki tu, vui long nhap lai ID doc gia :";
				cin.getline(tam, 30);
			}
		}
		strcpy_s(Docgia[tam_docgia].madocgia, 30, tam);
		break;
	case 2:
		cout << "Nhap ten doc gia: ";
		cin.getline(Docgia[tam_docgia].hoten, 30);
		break;
	case 3:
		cout << "Nhap CMND doc gia: ";
		cin.getline(tam, 20);
		while ((kiemtracmnd(tam, Docgia, sodocgia) == true && strcmp(tam, Docgia[tam_docgia].cmnd) != 0) || chuoitoanso(tam) == false) {
			cin.clear();
			if (chuoitoanso(tam) == false) {
				cout << "CMND khong duoc co ki tu, vui long nhap lai CMND :";
				cin.getline(tam, 20);
			}
			else {
				cout << "CMND da ton tai, vui long nhap lai CMND :";
				cin.getline(tam, 20);
			}
		}
		strcpy_s(Docgia[tam_docgia].cmnd, 20, tam);
		break;
	case 4:
		cout << "Nhap Email doc gia: ";
		cin.getline(Docgia[tam_docgia].email, 30);
		break;
	case 5:
		cout << "Ngay sinh :";
		cin >> Docgia[tam_docgia].ngaysinh[0] >> Docgia[tam_docgia].ngaysinh[1] >> Docgia[tam_docgia].ngaysinh[2];
		while (kiemtrangay(Docgia[tam_docgia].ngaysinh) == false || cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Loi nhap du lieu ngay sinh khong ton tai,nhap lai ngay sinh :";
			cin >> Docgia[tam_docgia].ngaysinh[0] >> Docgia[tam_docgia].ngaysinh[1] >> Docgia[tam_docgia].ngaysinh[2];
		}
		break;
	case 6:
		cout << "Nhap dia chi doc gia: ";
		cin.getline(Docgia[tam_docgia].diachi, 70);
		break;
	case 7:
		cout << "Gioi tinh ( Nam hoac Nu ) :";
		cin.getline(Docgia[tam_docgia].gioitinh, 10);
		while (strcmp(Docgia[tam_docgia].gioitinh, "Nam") != 0 && strcmp(Docgia[tam_docgia].gioitinh, "Nu") != 0) {
			cout << "Loi nhap du lieu gioi tinh, vui long nhap lai gioi tinh ( Nam hoac Nu ) :";
			cin.getline(Docgia[tam_docgia].gioitinh, 10);
		}
		break;
	case 8:
		cout << "Ngay lap the: ";
		cin >> Docgia[tam_docgia].ngaylapthe[0] >> Docgia[tam_docgia].ngaylapthe[1] >> Docgia[tam_docgia].ngaylapthe[2];
		while (kiemtrangay(Docgia[tam_docgia].ngaylapthe) == false || cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Loi ngay lap the khong ton tai, nhap lai ngay nhap the :";
			cin >> Docgia[tam_docgia].ngaylapthe[0] >> Docgia[tam_docgia].ngaylapthe[1] >> Docgia[tam_docgia].ngaylapthe[2];
		}
	default:
		break;
	}
	cout << "CHINH SUA THANH CONG !" << endl;
}
bool chuoitoanso(char* chuoi) {
	for (int i = 0;chuoi[i]!='\0'; i++) {
		if (chuoi[i] < '0' || chuoi[i]>'9') {
			return false;
		}
	}
	return true;
}
