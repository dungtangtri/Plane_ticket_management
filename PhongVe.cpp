// Nguyễn Minh Phúc - 20203823 coded this file
#include "PhongVe.h"
#include <iostream>
#include <string>
using namespace std;

PhongVe::PhongVe() {
	giave = 0;
	ten = " ";
	noiden = " ";
	noidi = " ";
	ngay = 1;
	thang = 1;
	nam = 1900;
	check = 1;
}
PhongVe::PhongVe(string ten, string noiden, string noidi,int giave,int ngay, int thang, int nam) {
	this->ten = ten;
	this->noiden = noiden;
	this->noidi = noidi;
	this->giave = giave;
	this->ngay = ngay;
	this->thang = thang;
	this->nam = nam;
}

void PhongVe::setNgay(int ngay) {
	this->ngay = ngay;
}
int PhongVe::getNgay() {
	return ngay;
}
int PhongVe::getThang() {
	return thang;
}

void PhongVe::setThang(int thang) {
	this->thang = thang;
}
int PhongVe::getNam() {
	return nam;
}
void PhongVe::setNam(int nam) {
	this->nam = nam;
}

string PhongVe::getTen() {
	return ten;
}
void PhongVe::setTen(string ten) {
	this->ten = ten;
}
string PhongVe::getNoiden() {
	return noiden;
}
void PhongVe::setNoiden(string noiden) {
	this->noiden = noiden;
}
string PhongVe::getNoidi() {
	return noidi;
}
void PhongVe::setNoidi(string noidi) {
	this->noidi = noidi;
}
int PhongVe::getGiave() {
	return giave;
}
void PhongVe::setGiave(int giave) {
	this->giave = giave;
}
int PhongVe::getCheck() {
	return check;
}
void PhongVe::setCheck(int check) {
	this->check = check;
}
int PhongVe::getMergeNum() {
	string a;
	if (getNgay() < 10 && getThang() >= 10) {
		a = to_string(getNam()) + to_string(getThang()) + '0' + to_string(getNgay());
	}
	else if (getThang() < 10 && getNgay() >= 10) {
		a = to_string(getNam()) + '0' + to_string(getThang())  + to_string(getNgay());
	}
	else if (getThang() < 10 && getNgay() < 10) {
		a = to_string(getNam()) + '0' + to_string(getThang()) + '0' + to_string(getNgay());
	}
	else {
		a = to_string(getNam())  + to_string(getThang()) + to_string(getNgay());
	}
	int b = stoi(a);
	return b;
 }



void PhongVe::display() {
	cout << "Ten khach hang : " << getTen() << "\n";
	cout << "Noi den : " << getNoiden() << "\n";
	cout << "Noi di : " << getNoidi() << "\n";
	cout << "Gia ve : " << getGiave() << "\n";
	cout << "Ngay di : " << getNgay() << endl;
	cout << "Thang di : " << getThang() << endl;
	cout << "Nam di : " << getNam() << endl;
	if (check = 1) {
		cout << "Ve noi dia " << endl;
	}
	else {
		cout << "Ve quoc te " << endl;
	}
}