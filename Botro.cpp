#include <iostream>
#include "Botro.h"
#include "quanlidocgia.h"
#include "quanlisach.h"
#include "ngay.h"
#include "muontrasach.h"
#include "math.h"
#include <string.h>
bool kiemtradocgia(char* cankiemtra, docgia* Docgia, int n) {
	for (int i = 0; i < n; i++) {
		if (strcmp(cankiemtra, Docgia[i].madocgia) == 0) {
			return true;
		}
	}
	return false;
}
bool kiemtracmnd(char* cankiemtra, docgia* Docgia, int n) {
	for (int i = 0; i < n; i++) {
		if (strcmp(cankiemtra, Docgia[i].cmnd) == 0) {
			return true;
		}
	}
	return false;
}
bool kiemtramasach(char* cankiemtra, sach* Sach, int n) {
	for (int i = 0; i < n; i++) {
		if (strcmp(cankiemtra, Sach[i].masach) == 0) {
			return true;
		}
	}
	return false;
}
bool kiemtratensach(char* cankiemtra, sach* Sach, int n) {
	for (int i = 0; i < n; i++) {
		if (strcmp(cankiemtra, Sach[i].tensach) == 0) {
			return true;
		}
	}
	return false;
}
bool kiemtratrasach(char* cankiemtra,phieumuon* Phieumuon, int n) {
	for (int i = 0; i < n; i++) {
		if (strcmp(cankiemtra,Phieumuon[i].Docgiamuon.madocgia) == 0) {
			return true;
		}
	}
	return false;
}
int chuyenchuoiveso(char* a) {
	int* b = new int[strlen(a) - 1];
	int ketqua = 0;
	for (int i = 0; i < strlen(a); i++) {
		b[i] = a[i] - 48;
		ketqua = ketqua + b[i] * pow(10, strlen(a)-i-1);
	}
	return ketqua;
}
