#include "PhongVe.h"
#include <iostream>
#include <string>
using namespace std;

void get_input(vector<PhongVe> &p1, int n1) { // tạo số object của PhongVe = số lượng người dùng nhập vào
	string depart;//biến trung gian cho nơi đi
	string arrive;//biến trung gian cho nơi đến
	for (int i = 1; i <= n1; i++)
	{
		PhongVe p;
		cout << "\n Nhap noi di may bay " << i << ": ";
		cin >> depart;
		p.setNoidi(depart);
		cout << "\n Nhap noi den may bay " << i <<": ";
		cin >> arrive;
		p.setNoiden(arrive);
		p1.push_back(p);
	}
}
void displayoption() {
	cout << "Nhap tac vu ban muon dung\n ";
	cout << "1 : Them thong tin may bay\n";
	cout << "2 : Sua thong tin may bay\n";
	cout << "3 : Xoa thong tin may bay\n";
	cout << "4 : Tim kiem ve may bay theo thoi gian bay\n";
	cout << "5 : Tim kiem ve may bay theo noi di\n";
	cout << "5 : Tim kiem ve may bay theo noi den\n";
	cout << "6 : Thong ke ve may bay noi dia co thoi gian trong khoang thoi gian\n";
	cout << "7 : Tinh so tien hoa hong phong ve nhan duoc trong khoang thoi gian\n";
	cout << "8 : Thoat chuong trinh\n";
}
int main() {
	int n;
	int somaybay;
	displayoption();
	while (!(cin >> n)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Vui long nhap lai dung dinh dang.\n";
	}
	switch (n)
		case 1:
	{
		cout << "Vui long nhap so luong may bay ban muon them : \n";
		cin >> somaybay;
		vector<PhongVe> p;
		get_input(p, somaybay);
		
	}
	
	return 0;
}
