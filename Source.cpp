#include "Header.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

PhongVe::PhongVe() {
	giave = 0;
	hoahong = 0;
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
int PhongVe::getHoahong() {
	return hoahong;
}
void PhongVe::display() {
	cout << "Ten khach hang : " << ten << "\n";
	cout << "Noi den : " << noiden << "\n";
	cout << "Noi di : " << noidi << "\n";
	cout << "Gia ve : " << giave << "\n";
}