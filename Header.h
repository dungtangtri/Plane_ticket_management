#pragma once
#include <string>

class PhongVe {
private:
	int giave;
	int hoahong;
	std::string ten;
	std::string noiden;
	std::string noidi;
public:
	PhongVe() {}
	PhongVe(std::string ten, std::string noiden, std::string noidi) {}

	int getGiave() {}
	void setGiave(int giave) {}

	int getHoahong() {}
	void setHoahong(int hoahong) {}

	std::string getTen() {}
	void setTen(std::string ten){}

	std::string getNoiden(){}
	void setNoiden(std::string noiden){}

	std::string getNoidi(){}
	void setNoidi(std::string noidi){}


};