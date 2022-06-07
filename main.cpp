#include "PhongVe.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void get_input(vector<PhongVe> &p1, int n1) { // tạo số object của PhongVe = số lượng người dùng nhập vào
	string depart;//biến trung gian cho nơi đi
	string arrive;//biến trung gian cho nơi đến
    int price;//biến trung gian giá vé
	int ngay;
	int thang;
	int nam;
	static int i = 1;// biến tĩnh để lưu số tổng số máy bay đã thêm
	for (int j = 0; j < n1; j++)
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

		cout << "\n Nhap ngay : ";
		cin >> ngay;
		while (ngay < 1 || ngay > 31) {
			cout << "\n Vui long nhap lai : ";
			cin >> ngay;
		}
		cin >> thang;
		while (thang < 1 || thang > 12) {
			cout << "\n Vui long nhap lai : ";
			cin >> thang;
		}
		cin >> nam;
		while (nam < 1970 || nam > 2022) {
			cout << "\n Vui long nhap lai : ";
			cin >> nam;
		}
		

		p1.push_back(p);  
		i++;
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
	int m;
	int somaybay;
	int q;
	int x;
	int newprice;//  giá vé máy bay thay đổi
	string newdepart;// nơi đi thay đổi
	static string newarrive;//nơi đến thay đổi
	vector<PhongVe> p;
	displayoption();
	while (!(cin >> n)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Vui long nhap lai dung dinh dang.\n";
	}

	while (n == 1) {
		cout << "Vui long nhap so luong may bay ban muon them : \n";

		while (!(cin >> somaybay)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Vui long nhap lai dung dinh dang.\n";
		}

		get_input(p, somaybay);
		displayoption();

		while (!(cin >> n)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Vui long nhap lai dung dinh dang.\n";
		}

	}
	while (n == 2)
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


		while (m == 1) {
			for (int i = 0; i < p.size(); i++) {
				p.at(i).display();
			}
			cout << "Vui long chon so may bay ban muon sua :\n ";
			while (!(cin >> q)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
			cout << "Vui long nhap gia ve moi :\n ";
			while (!(cin >> newprice)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
			p.at(q - 1).setGiave(newprice);
			cout << "Thong tin moi la : " << endl;
			p.at(q - 1).display();
			while (!(cin >> m)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
		}
		while (m == 2)
		{
			for (int i = 0; i < p.size(); i++) {
				p.at(i).display();
			}
			cout << "Vui long chon so may bay ban muon sua :\n ";
			while (!(cin >> q)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
			cout << "Vui long nhap noi den moi :\n ";
			while (!(cin >> newarrive)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
			p.at(q - 1).setNoiden(newarrive);
			cout << "Thong tin moi la : " << endl;
			p.at(q - 1).display();
			while (!(cin >> m)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
		}
		while (m == 3)
		{
			for (int i = 0; i < p.size(); i++) {
				p.at(i).display();
			}
			cout << "Vui long chon so may bay ban muon sua :\n ";
			while (!(cin >> q)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
			cout << "Vui long nhap so noi di moi :\n ";
			while (!(cin >> newdepart)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
			p.at(q - 1).setNoidi(newdepart);
			cout << "Thong tin moi la : " << endl;
			p.at(q - 1).display();
			while (!(cin >> m)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
		}

		if (m == 4)
		{
			displayoption();
			while (!(cin >> n)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}

		}
	}
	while (n == 3) {
		cout << "Nhap so may bay ban muon xoa : " << endl;
		while (!(cin >> x)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Vui long nhap lai dung dinh dang.\n";
		}
		cout << "Danh sach may bay truoc khi xoa " << endl;
		for (int i = 0; i < p.size(); i++) {
			p.at(i).display();
		}
		while (x >= p.size()) {
			cout << "Vui long nhap lai so may bay " << endl;
			while (!(cin >> x)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
		}
		p.erase(p.begin() + x - 1);//do vector đầu tiên có index là 0
		cout << "Danh sach may bay sau khi xoa : " << endl;
		for (int i = 0; i < p.size(); i++) {
			p.at(i).display();
		}
		while (!(cin >> n)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Vui long nhap lai dung dinh dang.\n";
		}
	}
	while (n == 4) {

	}

}//kết thúc hàm main
