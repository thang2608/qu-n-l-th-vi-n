#pragma once
struct sach {
	char* masach = new char[50];
	char* tensach = new char[50];
	char* tacgia = new char[50];
	char* nhasanxuat = new char[50];
	int namxuatban;
	char* theloai=new char[50];
	int giasach;
	int soluongsach;
	int solanmuon;
};
/*
Hàm dsachsach thực hiện chức năng lưu trữ các sách có trong thư viện
Tham số truyền vào gồm các mảng lưu trữ mã sách, tên sách, tác giả, nhà sản xuất, năm xuất bản, thể loại, giá sách, số lượng sách từng loại sách, số loại sách hiện tại, số loại sách tối đa, số loại sách tối thiểu
*/
void dsachsach(sach *Sach, int &sosachhientai, const int& sosachmax, const int& sosachmin);
/*
Hàm themsach thực hiện chức năng thêm 1 loại sách vào thư viện
Tham số truyền vào gồm các mảng lưu trữ mã sách, tên sách, tác giả, nhà sản xuất, năm xuất bản, thể loại, giá sách, số lượng sách từng loại sách, số loại sách hiện tại, số loại sách tối đa, số loại sách tối thiểu
*/
void themsach(sach* Sach, int &sosachhientai, const int& sosachmax, const int& sosachmin);
/* 
Hàm xoathongtinsach thực hiện chức năng xoá thông tin 1 loại sách
Tham số truyền vào gồm các mảng lưu trữ mã sách, tên sách, tác giả, nhà sản xuất, năm xuất bản, thể loại, giá sách, số lượng sách từng loại sách, số loại sách hiện tại, số loại sách tối đa, số loại sách tối thiểu
*/
void xoathongtinsach(sach*Sach, int &sosachhientai, const int& sosachmax, const int& sosachmin);
/*
Hàm timkiemsachtheoma thực hiện chức năng tìm kiếm sách theo mã ISBN
Tham số truyền vào gồm các mảng lưu trữ mã sách, tên sách, tác giả, nhà sản xuất, năm xuất bản, thể loại, giá sách, số lượng sách từng loại sách, số loại sách hiện tại, số loại sách tối đa, số loại sách tối thiểu
*/
void timkiemsachtheoma(sach*Sach, int &sosachhientai, const int& sosachmax, const int& sosachmin);
/*
Hàm timkiemsachtheoten thực hiện chức năng tìm kiếm sách theo tên
Tham số truyền vào gồm các mảng lưu trữ mã sách, tên sách, tác giả, nhà sản xuất, năm xuất bản, thể loại, giá sách, số lượng sách từng loại sách, số loại sách hiện tại, số loại sách tối đa, số loại sách tối thiểu
*/
void timkiemsachtheoten(sach*Sach, int &sosachhientai, const int& sosachmax, const int& sosachmin);
/*
chinhsuathongtinsach thực hiện chức năng chỉnh sửa thông tin bất kì nào của sách
Tham số truyền vào gồm các mảng lưu trữ mã sách, tên sách, tác giả, nhà sản xuất, năm xuất bản, thể loại, giá sách, số lượng sách từng loại sách, số loại sách hiện tại, số loại sách tối đa, số loại sách tối thiểu
*/
void chinhsuathongtinsach(sach*Sach, int& sosachhientai, const int& sosachmax, const int& sosachmin);
