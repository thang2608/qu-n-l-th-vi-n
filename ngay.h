#pragma once
/*
Hàm namnhuan thực hiện chức năng kiểm tra năm đưa vào có phải là năm nhuận không
Tham số truyền vào là năm
Giá trị trả về sẽ là true nếu năm đó là năm nhuận còn ngược lại thì nó sẽ trả về false
*/
bool namnhuan(int nam);
/*
Hàm songaytrongthang thực hiện chức năng trả về số ngày trong tháng đưa vào
Tham số truyền vào là tháng và năm
Giá trị trả về là số ngày trong tháng mà ta đưa vào
*/
int songaytrongthang(int thang,int nam);
/*
Hàm kiemtrangay thực hiện chức năng kiểm tra ngày mà ta đưa vào có hợp lệ không 
Tham số truyền vào là mảng chứa ngày, tháng, năm
Giá trị trả về sẽ là true nếu ngày ta đưa vào là hợp lệ, ngược lại sẽ trả về false nếu ngày đưa vào là không hợp lệ
*/
bool kiemtrangay(int ngay[3]);
/*
Hàm congngay thực hiện chức năng cộng ngày từ ngày và số ngày cộng có sẳn
Tham số truyền vào là mảng chứa ngày trước khi cộng,mảng ngày sau khi cộng và số ngày cộng
*/
void congngay(int ngay[3], int ngaysaukhicong[3], int songaycong);
/*
Hàm trungay thực hiện chức năng trừ 2 ngày 
Tham số truyền vào là mảng chứa ngày trừ và mảng chứa ngày bị trừ
Giá trị trả về là kết quả sau khi trừ 2 ngày với đơn vị là ngày
*/
int trungay(int ngaytru[3], int ngaybitru[3]);