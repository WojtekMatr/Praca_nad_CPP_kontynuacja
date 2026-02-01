#pragma once
#include <iostream>
#include <fstream>

class przechowywaczPunktu;
class Punkt {
	int x;
	int y;
public:
	Punkt(int x, int y) {
		this->x = x;
		this->y = y;
	}
	friend std::ostream& operator<<(std::ostream& o, const Punkt& p);
	friend przechowywaczPunktu;


};
std::ostream& operator<<(std::ostream& o, const Punkt& p) {
	return o << std::endl << "Punkt(" << p.x << "," << p.y << ")";

}

//kiedy klasa Raii z smart ptr ma sens:
//gdy zarzadzasz file
//socket
//mutex z C API
//uchwyt systemowy
//pamiec z malloc
//polaczenie z baza

//bez sensu
class przechowywaczPunktu {


	std::unique_ptr<Punkt> b;
public:
	przechowywaczPunktu(int a, int b) :
		b(std::make_unique<Punkt>(a, b)) {
		std::cout << "Stworzylem Punkt" << std::endl;
	}
	
	//{
	//	std::cout << "Powstaje A z shared ptr B\n";
	//	b = std::make_unique<Punkt>(4, 4);
	//}
	~przechowywaczPunktu() {
		std::cout << "Zniszono przechowywaczPunktu\n";
	}
	Punkt& get() {
		return (*b);
	}

	friend std::ostream& operator<<(std::ostream& o, przechowywaczPunktu m);
};
//std::ostream& operator<<(std::ostream& o, przechowywaczPunktu m) {
//	return o <<    <<" ";
//}