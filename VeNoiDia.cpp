#include "PhongVe.h"
#include<string>
#include<iostream>
using namespace std;

	VeNoiDia::VeNoiDia() : PhongVe() {
		hoahong = 0;
	}
	VeNoiDia::VeNoiDia(string ten, string noiden, string noidi, int giave, int ngay, int thang, int nam, int hoahong) : PhongVe(ten, noiden, noidi, giave, ngay, thang, nam) {
		this->hoahong = hoahong;
	}
	int VeNoiDia::getHoahong() {
		return (VeNoiDia::getGiave()) * 5 / 100;
	}
	void VeNoiDia::setHoahong(int hoahong) {
		this->hoahong = hoahong;
	}
	void VeNoiDia::display() {
		PhongVe::display();
		cout << "Hoa hong : " << getHoahong() << "\n";
	}
