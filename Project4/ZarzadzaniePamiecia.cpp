#include "headerZarzadzeniePamiecia.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <string>
#include <memory>
int main() {
	//stary sposob new delete tragedia,
	// bez delete nie usuwa danych
	// wiec dochodzi do wycieku
	//NIEPOTRZEBNE

	try {
		std::vector<int> v = { 1,2,3 };
		
		int* liczba = new int(5);
		int* liczba1 = new int;
		std::cout << liczba1 << std::endl;
		std::cout << *liczba << std::endl;
		std::cout << *liczba1 << " Niezdefiniowana ale sie wyswietla, bo jest na stercie\n";
		std::cout << " Podaj liczbe \n";
		std::cin >> *liczba1;

		int k = v.at(4);
		std::cout << k;



		delete liczba;



		delete liczba1;

	}
	catch (std::out_of_range& e) {
		std::cout << "Wyjatek: " << e.what() << std::endl;
	}
	//std::cout << "Okej, wyskoczyl wyjatek wpisz adres co wyskoczyl na gorze a przekonasz sie ze zostaly tam dane\n";
	//std::string adres;
	//std::cin >> adres;
	//uintptr_t adresPtr;
	//std::stringstream ss;
	//ss << std::hex << adres;
	//ss >> adresPtr;
	//int* p = reinterpret_cast<int*>(adresPtr);
	//std::cout << "Twoj adres wskazywal na dana: " << *p;


	//RAII = Resource Acquisition Is Initialization
	//Najwazniejsza rzecz
	// tutaj RAII na zwyklym pointerze
	IntHolder j(10);
	// co tu sie dzieje.
	//na Stosie powstaje obiekt j 8 bajtowy, to jest wskaznik czyli adres na sterte
	// na stercie przechowujemy 4 bajtowy int 
	//jak by to byl duzo wiekszy obiekt to by sie nam oplacalo


	std::cout << j.get()<<"\n";
	//teraz zrobmy fajniej:
	std::unique_ptr<int> p = std::make_unique<int>(42);
	//auto b = p; //BLAD KOMPILACJI NIE DA SIE KOPIOWAC
	std::unique_ptr<int> a = std::make_unique<int>(5);
	std::unique_ptr<int> b = std::move(a);

	//if (!a) std::cout << "a jest: "<<*a << " \n";
	// po przeniesieniu move a nie ma smieci tylko wskazuje na lokalizacje 0x0000.. czyli jest puste


	//Lab 1 stworz klase Samochod i zobacz jak po move zachowa sie destruktor
	std::unique_ptr<Samochod> audi = std::make_unique<Samochod>("Audi");
	std::unique_ptr<Samochod> audi2 = std::move(audi);
	audi2->getNazwa(); //lub
	(*audi2).getNazwa(); //lub
	std::unique_ptr<Samochod> audi3 = std::move(audi);
	//niszczy dopiero po funkcji main w unique_ptr move nie dotyka obiektu Samochod tylko zabija ptr

	//std::shared_ptr
	//Gdy ostatni shared_ptr zniknie -> obiekt usuniety
	//shared ptr ma w sobie wskaznik na obiekt
	//licznik referencji (ile osob go uzywa, w momencie 0 umiera)
	
	std::shared_ptr<Samochod> s1 = std::make_shared<Samochod>("BMW");


	{  //blok w bloku mozna robic cos takiego
		std::shared_ptr<Samochod> s2 = s1;  // wspó³dzieli obiekt
		(*s2).getNazwa();
		std::cout << "use_count s1: " << s1.use_count() << "\n"; // 2
		
	}
	//s2
	std::cout << "s2 niezyje juz ale Samochod BMW istnieje\n";
	(*s1).getNazwa();
	auto a1 = std::make_shared<A>();
	auto b1= std::make_shared<B>(a1);
	(*a1).addsharedPtr(b1);

	//Powstaje sprzezenie i nie usuwa shared_ptr obiektu A ani nie usuwa obiektu B
	
	//dlatego powstal weak pointer dokladna kopia calego kodu tylko w jednym z obiektow
	//wykorzystujemy weak_ptr
	//weak_ptr nie jest wlasnicielem obiektu
	// obiekt moze zostac zniszony nawet jesli istnieje weak_ptr
	//aby uzyc trzeba go zlapac w shared_ptr przez .lock()
	auto a2 = std::make_shared<A>();
	auto b2 = std::make_shared<B_z_weak>(a2);
	(*a1).addsharedPtr(b1);



}