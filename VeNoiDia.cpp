#include "PhongVe.h"
#include<string>
#include<iostream>
using namespace std;

VeNoiDia::VeNoiDia() {
	hoahong = 0;
}
int VeNoiDia::getHoahong() {
	return PhongVe::getGiave() * 5 / 100; 
}
void VeNoiDia::setHoahong(int hoahong){
	this->hoahong = hoahong;
}
void VeNoiDia::display() {
	PhongVe::display();
	cout << "Hoa hong : " << getHoahong() << "\n";
}