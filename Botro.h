#pragma once
#include <iostream>
#include "quanlidocgia.h"
#include "quanlisach.h"
#include "ngay.h"
#include "muontrasach.h"
#include <string.h>
bool kiemtradocgia(char* cankiemtra, docgia* Docgia, int n);
bool kiemtracmnd(char* cankiemtra, docgia* Docgia, int n);
bool kiemtramasach(char* cankiemtra, sach* Sach, int n);
bool kiemtratensach(char* cankiemtra, sach* Sach, int n);
bool kiemtratrasach(char* cankiemtra,phieumuon* Phieumuon, int n);
int chuyenchuoiveso(char* a);