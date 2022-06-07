#pragma once
#include <string>
#include <vector>
#include "stdio.h"
#include <ctime>
class PhongVe {
private:
	int giave;
	std::string ten;
	std::string noiden;
	std::string noidi;
	std::time_t thoigians;// thời gian tính theo giây , tính từ 0 giờ 0 phút 1 tháng 1 năm 1970
	std::string thoigian;
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

	std::string getThoigian();
	void setThoigian(time_t thoigian );

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

