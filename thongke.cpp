#include "thongke.h"
int thongkesoluongsachhientai(sach* Sach, const int& sosachhientai) {
	int sosach=0;
	for (int i = 0; i < sosachhientai; i++) {
		sosach = sosach + Sach[i].soluongsach;
	}
	return sosach;
}
int sosachdangmuon(phieumuon* Phieumuon, const int& songuoimuon) {
	int sosach = 0;
	for (int i = 0; i <songuoimuon; i++) {
		sosach = sosach + Phieumuon[i].sosachmuon;
	}
	return sosach;
}
void soluongdocgiatheogioitinh(docgia* Docgia, const int& sodocgia) {
	cout << ">>>THONG KE SO LUONG DOC GIA THEO GIOI TINH<<<" << endl;
	int nam = 0, nu = 0;
	for (int i = 0; i < sodocgia; i++) {
		if (strcmp(Docgia[i].gioitinh, "Nam") == 0) {
			nam++;
		}
		else {
			nu++;
		}
	}
	cout << "So doc gia nam la :" << nam << endl;
	cout << "So doc gia nu la :" << nu << endl;
}
void sodocgiatrehan(phieumuon* Phieumuon, const int& songuoimuon) {
	int ngayhomnay[3];
	cout << "Nhap ngay hom nay :";
	cin >> ngayhomnay[0] >> ngayhomnay[1] >> ngayhomnay[2];
	while (kiemtrangay(ngayhomnay) == false || cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Loi nhap du lieu ngay hom nay, nhap lai ngay hom nay :";
		cin >> ngayhomnay[0] >> ngayhomnay[1] >> ngayhomnay[2];
	}
	int dem = 0;
	for (int i = 0; i < songuoimuon; i++) {
		if (trungay(ngayhomnay,Phieumuon[i].ngaytradukien) >= 1) {
			dem++;
		}
	}
	cout << "So doc gia tre han la :" << dem << endl;
}
void sosachtheotheloai(sach* Sach, const int& sosachhientai) {
	cout << ">>>THONG KE SO LUONG SACH THEO THE LOAI<<<" << endl;
    const int MAX_THE_LOAI = 100;
    char* loaisach[MAX_THE_LOAI];
    int soluongsach[MAX_THE_LOAI];
    int demloaisach = 0;
    for (int i = 0; i < MAX_THE_LOAI; ++i) {
        loaisach[i] = new char[50];
    }
    for (int i = 0; i < sosachhientai; ++i) {
        bool found = false;
        for (int j = 0; j < demloaisach; ++j) {
            if (strcmp(Sach[i].theloai, loaisach[j]) == 0) {
                soluongsach[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            strcpy_s(loaisach[demloaisach],50, Sach[i].theloai);
            soluongsach[demloaisach] = 1;
            demloaisach++;
        }
    }
    for (int i = 0; i < demloaisach; ++i) {
        cout << loaisach[i] << " co " << soluongsach[i] << " sach" << endl;
    }
}
void sachmuonnhieunhat(sach* Sach, const int& sosachhientai) {
	int tam = 0;
	for (int i = 0; i < sosachhientai; i++) {
		if (tam < Sach[i].solanmuon) {
			tam = Sach[i].solanmuon;
		}
	}
	if (tam == 0) {
		cout << "Chua co sach nao duoc muon" << endl;
	}
	else{
		for (int i = 0; i < sosachhientai; i++) {
			if (tam ==Sach[i].solanmuon) {
				cout << "Sach duoc muon nhieu nhat co ma sach la " << Sach[i].masach << " voi so lan muon la " << tam << endl;
			}
		}
	}
}