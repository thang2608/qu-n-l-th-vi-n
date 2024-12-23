#pragma once
struct docgia {
	char* madocgia = new char[30];
	char* hoten = new char[30];
	char* cmnd = new char[20];
	int* ngaysinh = new int[3];
	char* gioitinh = new char[10];
	char* email = new char[30];
	char* diachi = new char[70];
	int* ngaylapthe = new int[3];
	int* ngayhethan = new int[3];
};
/*
Hàm dsachdocgia thực hiện chức năng lưu trữ danh sách các độc giả
Tham số truyền vào gồm mảng lưu trữ id độc giả, tên độc giả, chứng minh nhân dân, địa chỉ email, địa chỉ, ngày sinh, giới tính, ngày lập thẻ, số độc giả hiện tại, số độc giả tối đa, số độc giả tối thiểu.
*/
void dsachdocgia(docgia *Docgia, int& sodocgia, const int& docgiamax, const int& docgia_min);
/*
Hàm themdocgia thực hiện chức năng thêm 1 độc giả vào danh sách độc giả
Tham số truyền vào gồm mảng lưu trữ id độc giả, tên độc giả, chứng minh nhân dân, địa chỉ email, địa chỉ, ngày sinh, giới tính, ngày lập thẻ, số độc giả hiện tại, số độc giả tối đa, số độc giả tối thiểu.
*/
void themdocgia(docgia *Docgia, int& sodocgia, const int& docgiamax, const int& docgia_min);
/*
Hàm timkiemtheocmnd thực hiện chức năng tìm kiếm độc giả theo số chứng minh nhân dân
Tham số truyền vào gồm mảng lưu trữ id độc giả, tên độc giả, chứng minh nhân dân, địa chỉ email, địa chỉ, ngày sinh, giới tính, ngày lập thẻ, số độc giả hiện tại, số độc giả tối đa, số độc giả tối thiểu.
*/
void timkiemtheocmnd(docgia *Docgia, int& sodocgia, const int& docgiamax, const int& docgia_min);
/*
Hàm xoadocgia thực hiện chức năng xoá 1 độc giả ra khỏi danh sách độc giả
Tham số truyền vào gồm mảng lưu trữ id độc giả, tên độc giả, chứng minh nhân dân, địa chỉ email, địa chỉ, ngày sinh, giới tính, ngày lập thẻ, số độc giả hiện tại, số độc giả tối đa, số độc giả tối thiểu.
*/
void xoadocgia(docgia* Docgia, int& sodocgia, const int& docgiamax, const int& docgia_min);
/*
Hàm timkiemtheoten thực hiện chức năng tìm kiếm độc giả theo tên
Tham số truyền vào gồm mảng lưu trữ id độc giả, tên độc giả, chứng minh nhân dân, địa chỉ email, địa chỉ, ngày sinh, giới tính, ngày lập thẻ, số độc giả hiện tại, số độc giả tối đa, số độc giả tối thiểu.
*/
void timkiemtheoten(docgia *Docgia, int& sodocgia, const int& docgiamax, const int& docgia_min);
/*
Hàm chinhsuathongtin thực hiện chức năng chỉnh sửa thông tin cho độc giả
Tham số truyền vào gồm mảng lưu trữ id độc giả, tên độc giả, chứng minh nhân dân, địa chỉ email, địa chỉ, ngày sinh, giới tính, ngày lập thẻ, số độc giả hiện tại, số độc giả tối đa, số độc giả tối thiểu.
*/
void chinhsuathongtindocgia(docgia *Docgia,const int& sodocgia, const int& docgiamax, const int& docgia_min);
/*
Hàm chuoitoanso thực hiện chức năng kiểm tra các thành phần của chuỗi có toàn là số không
Tham số truyền vào gồm chuỗi cần xét
Giá trị trả về là true nếu chuỗi chỉ chứa số, là false nếu chuỗi chứa kí tự
*/
bool chuoitoanso(char* chuoi);