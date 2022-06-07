#include "PhongVe.h"
#include <iostream>
#include <string>
using namespace std;

PhongVe::PhongVe() {
	giave = 0;
	ten = " ";
	noiden = " ";
	noidi = " ";
	thoigian = " ";
}
PhongVe::PhongVe(string ten, string noiden, string noidi,int giave) {
	this->ten = ten;
	this->noiden = noiden;
	this->noidi = noidi;
	this->giave = giave;
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
string PhongVe::getThoigian() {
	return thoigian;
}
void PhongVe::setThoigian(time_t thoigians) {
	tm* t = localtime(&thoigians);
	char* time = asctime(t);
	thoigian = time;
}
void PhongVe::display() {
	cout << "Ten khach hang : " << getTen() << "\n";
	cout << "Noi den : " << getNoiden() << "\n";
	cout << "Noi di : " << getNoidi() << "\n";
	cout << "Gia ve : " << getGiave() << "\n";
	cout << "Thoi gian : " << getThoigian() << "\n";
}