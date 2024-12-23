#pragma once
#include <iostream>
#include <string.h>
#include "ngay.h"
#include "muontrasach.h"
#include "quanlisach.h"
#include "quanlidocgia.h"
using namespace std;
/*
Hàm thongkesoluongsachhientai thực hiện chức năng trả về tổng số lượng sách của tất cả các loại sách hiện đang có trong thư viện
Tham số truyền vào gồm số lượng sách của từng loại và số loại sách
Giá trị trả về là tổng số lượng của tất cả loại sách hiện đang có trong thư viện
*/
int thongkesoluongsachhientai(sach* Sach, const int& sosachhientai);
/*
Hàm sosachdangmuon thực hiện chức năng trả về tổng số lượng sách đang được mượn
Tham số truyền vào gồm số người mượn và mảng số sách mượn của từng người
*/
int sosachdangmuon(phieumuon* Phieumuon,const int& songuoimuon);
/*
Hàm soluongdocgiatheogioitinh thực hiện chức năng thống kê số lượng độc giả theo giới tính Nam hoặc Nữ
Tham số truyền vào gồm mảng chứa giới tính của độc giả và số độc giả
*/
void soluongdocgiatheogioitinh(docgia*Docgia, const int& sodocgia);
/*
Hàm sodocgiatrehan thực hiện chức năng thống kê số lượng độc giả trễ hạn 
Tham số truyền vào gồm mảng chứa ngày trả và số người mượn
*/
void sodocgiatrehan(phieumuon*Phieumuon, const int& songuoimuon);
/*
Hàm sosachtheotheloai thực hiện chức năng thống kê số lượng sách theo từng thể loại 
Tham số truyền vào gồm mảng chứa thông tin thể loại và số loại sách hiện tại
Giá trị in ra sẽ là số lượng loại sách theo từng thể loại ví dụ thể loại kinh dị thì có 2 loại sách là zombie và ma da
*/
void sosachtheotheloai(sach*Sach, const int& sosachhientai);
/*
Hàm sachmuonnhieunhat thực hiện chức năng thống kê ra loại sách được mượn nhiều nhất
Tham số truyền vào gồm mảng chứa số sách hiện tai, mảng chứa mã sách và số lần mượn của từng loại sách
*/
void sachmuonnhieunhat(sach*Sach,const int&sosachhientai);