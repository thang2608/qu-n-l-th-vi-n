#pragma once
#include <iostream>
#include <string.h>
#include "quanlisach.h"
#include "ngay.h"
#include "quanlidocgia.h"
#include "muontrasach.h"
struct phieumuon {
	docgia Docgiamuon;
	int sosachmuon;
	sach* Sachmuon = new sach[5];
	int *ngaymuon = new int[3];
	int* ngaytradukien = new int[3];
};
/*
Hàm muonsach thực hiện chức năng tạo phiếu mượn sách cho độc giả
Tham số truyền vào gồm mảng chứa id độc giả, số độc giả hiện có trong thư viện, số lượng sách từng loại, số loại sách hiện tại, giá sách của từng loại sách, số người đang mượn, danh sách các sách mượn của độc giả, ngày mượn, ngày trả
*/
void muonsach(docgia* Docgia, sach* Sach, phieumuon* Phieumuon, const int& sosachhientai,const int& sodocgia,int &songuoimuon);
/*
Hàm trasach thực hiện chức năng tạo phiếu trả sách cho độc giả
Tham số truyền vào gồm mảng chứa id độc giả, số độc giả hiện có trong thư viện, số lượng sách từng loại, số loại sách hiện tại, giá sách của từng loại sách, số người đang mượn, danh sách các sách mượn của độc giả, ngày mượn, ngày trả
*/
void trasach(docgia *Docgia,sach* &Sach, phieumuon* &Phieumuon,const int&sosachhientai,const int&sodocgia,int &songuoimuon);
/*
Hàm kiemtratontaikieuint thực hiện chức năng kiểm tra số cho trước có thuộc mảng không
Tham số truyền vào gồm số cần kiểm tra, mảng cần kiểm tra và số lượng phần tử của mảng
*/
