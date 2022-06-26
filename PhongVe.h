#pragma once
#include <string>
#include <vector>
#include "stdio.h"

class PhongVe {
private:
	int check;// check = 1 la ve noi dia, check = 2 la ve quoc te
	int giave;
	std::string ten;
	std::string noiden;
	std::string noidi;
	int ngay;
	int thang;
	int nam;
	int mergeNum;
public:
	
	PhongVe();
	PhongVe(std::string ten, std::string noiden, std::string noidi, int giave,int ngay, int thang, int nam);


	int getGiave();
	void setGiave(int giave);

	std::string getTen();
	void setTen(std::string ten);

	std::string getNoiden();
	void setNoiden(std::string noiden);

	std::string getNoidi();
	void setNoidi(std::string noidi);

	void setNgay(int ngay);
	int getNgay();

	void setThang(int thang);
	int getThang();

	void setNam(int ngay);
	int getNam();

	void setCheck(int check);
	int getCheck();

	int getMergeNum();

	
	
	void display();




};


class VeNoiDia : public PhongVe {
private:
	int hoahong;
public:
	VeNoiDia();
	VeNoiDia(std::string ten, std::string noiden, std::string noidi, int giave, int ngay, int thang, int nam,int hoahong) ;
	int getHoahong();
	void setHoahong(int hoahong);
	void display();
	
};


class VeQuocTe : public PhongVe {
private:
	int hoahong;
public:
	VeQuocTe();
	VeQuocTe(std::string ten, std::string noiden, std::string noidi, int giave, int ngay, int thang, int nam,int hoahong) ;
	int getHoahong();
	void setHoahong(int hoahong);
	void display();
};

