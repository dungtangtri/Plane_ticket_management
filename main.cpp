
#include "PhongVe.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
void quickSort(vector<int>&a, int l, int r) {
	int p = a[(l + r) / 2];// phần tử chốt
	int i = l, j = r;
	while (i < j) {
		while (a[i] < p) {
			i++;
		}
		while (a[j] > p) {
			j--;
		}
		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r) {
		quickSort(a, i, r);
	}
	if (l < j) {
		quickSort(a, l, j);
	}
}
bool BinSearch(vector<int> &a, int n, int x) {
	int l = 0, r = n - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (a[mid] < x) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	if (a[l] == x) {
		return true;
	}
	else {
		return false;
	}
}

int getIntInput(int from, int to) { /* code nhằm kiểm tra đầu vào của dữ liệu có thuộc 1 khoảng nào không*/

	string input;
	bool isValidInput = false;
	int validinput;

	while (!isValidInput) {
		try {
			cout << "\nNhap gia tri trong khoang  " << from << " va " << to << ":\t";
			cin >> input;

			size_t takenChars;
			validinput = stoi(input, &takenChars);
			if (validinput >= from && validinput <= to && takenChars == input.size()) isValidInput = true;
		}
		catch (...) {
		}
	}

	return validinput;
}
int getMergeNum1(int d, int m, int y) {
	string a;
	if (d < 10 && m >= 10) {
		a = to_string(y) + to_string(m) + '0' + to_string(d);
	}
	else if (m < 10 && d >= 10) {
		a = to_string(y) + '0' + to_string(m) + to_string(d);
	}
	else if (m < 10 && d < 10) {
		a = to_string(y) + '0' + to_string(m) + '0' + to_string(d);
	}
	else {
		a = to_string(y) + to_string(m) + to_string(d);
	}
	int b = stoi(a);
	return b;
}

void get_input(vector<PhongVe> &p1, int n1) { // tạo số object của PhongVe = số lượng người dùng nhập vào
	string depart;//biến trung gian cho nơi đi
	string arrive;//biến trung gian cho nơi đến
    int price;//biến trung gian giá vé
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

		cout << "\n Nhap ngay di may bay " << i << ": ";
		p.setNgay(getIntInput(1, 31));
		

		cout << "\n Nhap thang di may bay " << i << ": ";
		p.setThang(getIntInput(1,12));

		cout << "\n Nhap nam di may bay " << i << ": ";
		p.setNam(getIntInput(1900, 2022));

		cout << "\n Nhap loai ve may bay cho may bay so " << i << ": ";
		cout << "\n 1 la ve noi dia, 2 la ve quoc te ";
		p.setCheck(getIntInput(1, 2));
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
	cout << "6 : Tim kiem ve may bay theo noi den\n";
	cout << "7 : Thong ke ve may bay noi dia co thoi gian trong khoang thoi gian\n";
	cout << "8 : Tinh so tien hoa hong phong ve nhan duoc trong khoang thoi gian\n";
	cout << "9 : Thoat chuong trinh\n";
}
void fixingoption() {
	cout << "Ban muon sua thong tin nao ?\n";
	cout << "1: Gia ve\n";
	cout << "2: Noi den\n";
	cout << "3: Noi di\n";
	cout << "4: Ngay di\n ";
	cout << "5: Thang di\n";
	cout << "6: Nam di\n";
	cout << "7: Thoat\n";
}

int main() {
	int n;
	int m;
	int somaybay;
	int q;

	int newprice;//  giá vé máy bay thay đổi
	string newdepart;// nơi đi thay đổi
	string newarrive;//nơi đến thay đổi
	int newday;// ngày đi mới
	int newmonth; // tháng đi mới
	int newyear; // năm đi mới
	vector<PhongVe> p;
	displayoption();
	while (!(cin >> n)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Vui long nhap lai dung dinh dang.\n";
	}

	while (n == 1)/*thêm thông tin máy bay*/ {
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
	while (n == 2)/*sửa thông tin máy bay*/
	{
		fixingoption();

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
			fixingoption();
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
			fixingoption();
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
			cout << "Vui long nhap noi di moi :\n ";
			while (!(cin >> newdepart)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
			p.at(q - 1).setNoidi(newdepart);
			cout << "Thong tin moi la : " << endl;
			p.at(q - 1).display();
			fixingoption();
			while (!(cin >> m)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
		}
		while (m == 4)
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
			cout << "Vui long nhap ngay di moi :\n ";
			while (!(cin >> newday)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
			p.at(q - 1).setNgay(newday);
			cout << "Thong tin moi la : " << endl;
			p.at(q - 1).display();
			fixingoption();
			while (!(cin >> m)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
		}
		while (m == 5)
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
			cout << "Vui long nhap thang di moi :\n ";
			while (!(cin >> newmonth)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
			p.at(q - 1).setThang(newmonth);
			cout << "Thong tin moi la : " << endl;
			p.at(q - 1).display();
			fixingoption();
			while (!(cin >> m)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
		}
		while (m == 6)
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
			cout << "Vui long nhap nam di moi :\n ";
			while (!(cin >> newyear)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
			p.at(q - 1).setNam(newyear);
			cout << "Thong tin moi la : " << endl;
			p.at(q - 1).display();
			fixingoption();
			while (!(cin >> m)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}
		}
		if (m == 7)
		{
			displayoption();
			while (!(cin >> n)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Vui long nhap lai dung dinh dang.\n";
			}

		}
	}
	while (n == 3)/*xóa máy bay*/ {
		int x;
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
		while (x > p.size()) {
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

		displayoption();
		while (!(cin >> n)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Vui long nhap lai dung dinh dang.\n";
		}
	}
	while (n == 4) /*tìm kiếm máy bay theo thời gian bay*/ {
		int d;
		int m;
		int y;
		cout << "Nhap ngay may bay di : " << endl;
		cin >> d;
		cout << "Nhap thang may bay di : " << endl;
		cin >> m;
		cout << "Nhap nam may bay di : " << endl;
		cin >> y;
		for (int i = 0; i < p.size(); i++) {
			if (d == p.at(i).getNgay() && m == p.at(i).getThang() && y == p.at(i).getNam()) {
				p.at(i).display();
				displayoption();
				cin >> n;
			}
			else {
				displayoption();
				while (!(cin >> n)) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Vui long nhap lai dung dinh dang.\n";
				}
			}
		}
	}
	while (n == 5)/*tim kiem may bay theo noi di*/ {
		string noidi;
		cout << "Nhap noi di may bay muon tim : " << endl;
		getline(cin >> ws, noidi);
		for (int i = 0; i < p.size(); i++) {
			if (noidi == p.at(i).getNoidi()) {
				p.at(i).display();
			}
		}
		displayoption();
		while (!(cin >> n)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Vui long nhap lai dung dinh dang.\n";
		}
	}
	while (n == 6)/*tim kiem may bay theo noi den*/ {
		string noiden;
		cout << "Nhap noi di may bay muon tim : " << endl;
		getline(cin >> ws, noiden);
		for (int i = 0; i < p.size(); i++) {
			if (noiden == p.at(i).getNoiden()) {
				p.at(i).display();
			}
		}
		displayoption();
		while (!(cin >> n)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Vui long nhap lai dung dinh dang.\n";
		}
	}
	while (n == 7) {/*thong ke ve may bay noi dia trong khoang thoi gian*/
		int count = 0;
		int d1;
		int m1;
		int y1;
		cout << "Nhap ngay bat dau tinh : " << endl;
		cin >> d1;
		cout << "Nhap thang bat dau tinh : " << endl;
		cin >> m1;
		cout << "Nhap nam bat dau tinh : " << endl;
		cin >> y1;
		int a = getMergeNum1(d1, m1, y1);

		int d2;
		int m2;
		int y2;
		cout << "Nhap ngay ket thuc tinh : " << endl;
		cin >> d2;
		cout << "Nhap thang ket thuc tinh : " << endl;
		cin >> m2;
		cout << "Nhap nam ket thuc tinh : " << endl;
		cin >> y2;
		int c = getMergeNum1(d2, m2, y2);




		for (int i = 0; i < p.size(); i++) {
			if (p.at(i).getCheck() == 1) {
					if (p.at(i).getMergeNum() <= c && p.at(i).getMergeNum() >= a) {

						count++;
					}
				}
			}
		cout << "So may bay noi dia co trong thoi gian da nhap la : " << count << endl;
		displayoption();
		while (!(cin >> n)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Vui long nhap lai dung dinh dang.\n";
		}
	}
	while (n == 8) { /* thong ke hoa hong phong ve nhan duoc trong khoang thoi gian*/
		
		int tong = 0;
		int d1;
		int m1;
		int y1;
		cout << "Nhap ngay bat dau tinh : " << endl;
		cin >> d1;
		cout << "Nhap thang bat dau tinh : " << endl;
		cin >> m1;
		cout << "Nhap nam bat dau tinh : " << endl;
		cin >> y1;
		int a = getMergeNum1(d1, m1, y1);


		int d2;
		int m2;
		int y2;
		cout << "Nhap ngay ket thuc tinh : " << endl;
		cin >> d2;
		cout << "Nhap thang ket thuc tinh : " << endl;
		cin >> m2;
		cout << "Nhap nam ket thuc tinh : " << endl;
		cin >> y2;
		int c = getMergeNum1(d2, m2, y2);


		for (int i = 0; i < p.size(); i++) {
			if (p.at(i).getCheck() == 1) {
				if (p.at(i).getMergeNum() <= c && p.at(i).getMergeNum() >= a) {
					tong += p.at(i).getGiave() * 5 / 100;
				}
			}
			else {
				if (p.at(i).getMergeNum() <= c && p.at(i).getMergeNum() >= a) {
					tong += p.at(i).getGiave() * 7 / 100 + 100000;
				}
			}
		}
		cout << "Tong so hoa hong phong ve thu duoc trong thoi gian ban da nhap la : " << tong << endl;
		displayoption();
		while (!(cin >> n)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Vui long nhap lai dung dinh dang.\n";
		}
	}
	while (n == 9) {
		exit(0);
	}

}//kết thúc hàm main

