#include "PhongVe.h"
#include<string>
#include<iostream>
using namespace std;

VeQuocTe::VeQuocTe() {
	hoahong = 0;
}
int VeQuocTe::getHoahong() {
	return PhongVe::getGiave() * 7 / 100 + 100000;
}
void VeQuocTe::setHoahong(int hoahong) {
	this->hoahong = hoahong;
}
void VeQuocTe::display() {
	PhongVe::display();
	cout << "Hoa hong : " << getHoahong() << "\n";
}