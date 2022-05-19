#pragma once
#include <string>
#include <vector>
#include "stdio.h"

class PhongVe {
private:
	int giave;
	std::string ten;
	std::string noiden;
	std::string noidi;
public:
	PhongVe();
	PhongVe(std::string ten, std::string noiden, std::string noidi, int giave);

	int getGiave();
	void setGiave(int giave);

	std::string getTen();
	void setTen(std::string ten);

	std::string getNoiden();
	void setNoiden(std::string noiden);

	std::string getNoidi();
	void setNoidi(std::string noidi);

	void display();




};


class VeNoiDia : public PhongVe {
private:
	int hoahong;
public:
	VeNoiDia();
	VeNoiDia(std::string ten, std::string noiden, std::string noidi, int giave) : PhongVe(ten, noiden, noidi, giave){};
	int getHoahong();
	void setHoahong(int hoahong);
	void display();
};


class VeQuocTe : public PhongVe {
private:
	int hoahong;
public:
	VeQuocTe();
	VeQuocTe(std::string ten, std::string noiden, std::string noidi, int giave) : PhongVe(ten, noiden, noidi, giave) {};
	int getHoahong();
	void setHoahong(int hoahong);
	void display();
};

