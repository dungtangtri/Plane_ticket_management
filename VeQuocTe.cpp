#include "PhongVe.h"
#include<string>
#include<iostream>
using namespace std;

VeQuocTe::VeQuocTe() {
	hoahong = 0;
}
VeQuocTe::VeQuocTe(string ten, string noiden, string noidi, int giave, int ngay, int thang, int nam, int hoahong) : PhongVe(ten, noiden, noidi, giave, ngay, thang, nam) {
	this->hoahong = hoahong;
}
int VeQuocTe::getHoahong() {
	return VeQuocTe::getGiave() * 7 / 100 + 100000;
}
void VeQuocTe::setHoahong(int hoahong) {
	this->hoahong = hoahong;
}
void VeQuocTe::display() {
	PhongVe::display();
	cout << "Hoa hong : " << getHoahong() << "\n";
}