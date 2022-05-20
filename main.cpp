#include "PhongVe.h"
#include <iostream>
#include <string>
using namespace std;

void get_input(vector<PhongVe> &p1, int n1) { // tạo số object của PhongVe = số lượng người dùng nhập vào
	string depart;//biến trung gian cho nơi đi
	string arrive;//biến trung gian cho nơi đến
    int price;//biến trung gian giá vé
	for (int i = 1; i <= n1; i++)
	{
		PhongVe p;
		cout << "\n Nhap noi di may bay " << i << ": ";
		getline(cin >> ws, depart);
		// dùng getline để nhập có khoảng trắng 
		// Usage of std::ws will extract
        // all  the whitespace character
		// https://www.geeksforgeeks.org/problem-with-getline-after-cin/
		p.setNoidi(depart);

		cout << "\n Nhap noi den may bay " << i <<": ";
		getline(cin >> ws, arrive);
		p.setNoiden(arrive);

		cout << "\n Nhap gia ve may bay " << i << ": ";
		cin >> price;
		p.setGiave(price);

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
	int n, m, somaybay, q ;
	int newprice;
	vector<PhongVe> p;
	displayoption();
	while (!(cin >> n)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Vui long nhap lai dung dinh dang.\n";
	}
	
	switch (n) {
	case 1:
	{
		cout << "Vui long nhap so luong may bay ban muon them : \n";
		
		while (!(cin >> somaybay)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Vui long nhap lai dung dinh dang.\n";
		}

		get_input(p, somaybay);
	}
	case 2:
	{
		cout << "Ban muon sua thong tin nao ?\n";
		cout << "1: Gia ve\n";
		cout << "2: Noi den\n";
		cout << "3: Noi di\n";
		cout << "4: Thoat\n";
		
		while (!(cin >> m)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Vui long nhap lai dung dinh dang.\n";
		}
		

		switch (m)
		{
		case 1:
		{
			for (int i = 0; i < somaybay; i++) {
				p.at(i).display();
			}
			cout << "Vui long chon so may bay ban muon sua :\n ";
			while (!(cin >> q)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
			cout << "Vui long nhap so ban muon sua lai :\n ";
			while (!(cin >> newprice)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
			p.at(q - 1).setGiave(newprice);
			for (int i = 0; i < somaybay; i++) {
				p.at(i).display();
			}
		}
		}
		}
	}
	return 0;
}