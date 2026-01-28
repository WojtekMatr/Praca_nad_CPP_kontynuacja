#pragma once
#include <string>
#include <memory>
#include <iostream>

class Samochod {
	std::string nazwa;
	int rok;
	double silnik;
	double przebieg;
	std::string kraj;
	//Zarzadzanie pamiecia:
	//STARA SZKOLA:
	//new dla pojedynczego obiektu
	// new[] dla tablicy 
	// rezerwujemy pamiec na stercie
	//Przypomnienie:
	//stos- szybki dostep, zaczadzany automatycznie, ograniczony rozmiar
	//strefa- duzo wiecej miejsca, wolniejsza, ryzyko wyciekow, czas zycia do delete lub zwolnienia smart pointera
	//Pamiec statyczna/globalna istnieje przez caly czas dzialania programu, nie sa niszczone, utrudnia testowanie i wielowatkowosc
	//S
public:
	Samochod(std::string nazwa) {
		std::cout << "Stworzyles: " << nazwa<<std::endl;
		this->nazwa = nazwa;
	}


	void getNazwa() {
		std::cout << "Nazywam sie: " << this->nazwa<<std::endl;
	}
	~Samochod() {
		std::cout << "Zniszczylem: " << this->nazwa<< std::endl;
	}



};
//RAII
class IntHolder {
	int* ptr; //nie idealny ale lepszy niz zwykly int*ptr w funkcji
public:
	IntHolder(int v) {
		ptr = new int(v);
	}

	~IntHolder() {
		delete ptr;  
	}
	int get() const { return *ptr; }
	void set(int v) { *ptr = v; }

};
//Przyjrzyjmy sie co tu sie dzieje
//new i delete automatyczne
// brak bezpieczenstwa w kopiowaniu
//przyklad:
//IntHolder a(5);
//IntHolder b=a;
//Co sie stanie jak skonczy sie funkcja delete na a ptr i delete na b ptr
// a to sa te same ptr wiec crash
//Jesli w konstruktorze cos sie popsuje, wyciek bo obiekt sie nie stworzyl wiec sie nie zniszczy

// Problem z shared_ptr:
class B;

class A {
	int c;
	std::shared_ptr<B> b;
public:
	A() {
		std::cout << "Powstaje A z shared ptr B\n";
	}
	void addsharedPtr(std::shared_ptr<B> b) {
		this->b = b;
	}
	~A() {
		std::cout << "Zniszono A\n";
	}

};
class B {
	int d;
	std::shared_ptr<A> a;
public:
	B(std::shared_ptr<A> a) {
		this->a = a;
		std::cout << "Powstaje B z shared ptr A\n";
	}
	~B() {
		std::cout << "Zniszono B\n";
	}

};

class B_z_weak {
	int d;
	std::weak_ptr<A> a;
public:
	B_z_weak(std::weak_ptr<A> a) {
		this->a = a;
		std::cout << "Powstaje B z shared ptr A\n";
	}
	~B_z_weak() {
		std::cout << "Zniszono B\n";
	}

};
