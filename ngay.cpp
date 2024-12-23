#include "ngay.h"
#include <iostream>
bool namnhuan(int nam) {
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0) {
		return true;
	}
	return false;
}
int songaytrongthang(int thang,int nam) {
	switch (thang) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		if (namnhuan(nam) == true) {
			return 29;
		}
		else {
			return 28;
		}
	default:
		return 0;
	}
}
bool kiemtrangay(int ngay[3]) {
	if (ngay[2] > 0 && ngay[0] <= songaytrongthang(ngay[1],ngay[2]) && ngay[1] > 0 && ngay[1] <= 12 && ngay[0] > 0) {
		return true;
	}
	return false;
}
void congngay(int ngay[3], int ngaysaukhicong[3], int songaycong) {
	ngaysaukhicong[0]= songaycong+ ngay[0];
	ngaysaukhicong[1] = ngay[1];
	ngaysaukhicong[2] = ngay[2];
	for(;ngaysaukhicong[0]>songaytrongthang(ngaysaukhicong[1],ngaysaukhicong[2]);)
	{
		ngaysaukhicong[0] = ngaysaukhicong[0] - songaytrongthang(ngaysaukhicong[1],ngaysaukhicong[2]);
		ngaysaukhicong[1]++;
		if (ngaysaukhicong[1] > 12) {
			ngaysaukhicong[1] = 1;
			ngaysaukhicong[2]++;
		}
	}
}
int trungay(int ngaytru[3], int ngaybitru[3]) {
	if ((ngaytru[2] < ngaybitru[2]) ||
		(ngaytru[2] == ngaybitru[2] && ngaytru[1] < ngaybitru[1]) ||
		(ngaytru[2] == ngaybitru[2] && ngaytru[1] == ngaybitru[1] && ngaytru[0] < ngaybitru[0])) {
		return -trungay(ngaybitru, ngaytru);
	}
	int ngay = 0;
	for (int i = ngaybitru[2] + 1; i < ngaytru[2]; i++) {
		if (namnhuan(i) == true) {
			ngay = ngay + 366;
		}
		else {
			ngay = ngay + 365;
		}
	}
	if (ngaybitru[2] != ngaytru[2]) {
		ngay += songaytrongthang(ngaybitru[1], ngaybitru[2]) - ngaybitru[0];
		for (int i = ngaybitru[1] + 1; i <= 12; i++) {
			ngay = ngay + songaytrongthang(i, ngaybitru[2]);
		}
	}
	if (ngaybitru[2] != ngaytru[2]) {
		for (int i = 1; i < ngaytru[1]; i++) {
			ngay = ngay + songaytrongthang(i, ngaytru[2]);
		}
		ngay = ngay + ngaytru[0];
	}
	else {
		if (ngaybitru[1] == ngaytru[1]) {
			ngay = ngay + ngaytru[0] - ngaybitru[0];
		}
		else {
			ngay += songaytrongthang(ngaybitru[1], ngaybitru[2]) - ngaybitru[0];
			for (int i = ngaybitru[1] + 1; i < ngaytru[1]; i++) {
				ngay = ngay + songaytrongthang(i, ngaytru[2]);
			}
			ngay = ngay + ngaytru[0];
		}
	}
	return ngay;
}