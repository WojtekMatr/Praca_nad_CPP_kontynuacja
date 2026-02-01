#include "strumieniowanieHeader.h"
#include <iostream>//standardowa bibilioteka laczy 2 bib istream i ostream
#include <istream>//NIEPOTRZEBNE dane wchodza do programu
#include <ostream>//NIEPOTRZEBNE dane wychodza z programu
#include <fstream> //file stream do ofstream i ifstream
#include <sstream> // strumieniowanie w pamiecie na strinagach
#include <iomanip> //Do Manipulatorow
#include <vector>


constexpr int fib(int n)
{
	if (n <= 2)
		return 1;

	return  fib(n - 1) + fib(n - 2);
}




int main() {
	std::cout << "Okej teraz czas nauczyc sie strumieniowania naprawde, bez pomocny" << std::endl;
	//Podstawowe typy strumieni:
	//std::cin wejscie z konsoli
	//std::cout wyjscie na konsole
	//std::cerr wyjscie bledow
	//std::clog logi
	int x{};
	std::cin >> x;
	if (!std::cin) {
		std::cerr << "BLAD";
	}
	//co tu siedzieje cin>> zwraca strumien sam >> zwraca referencje do tego strumienia
	//jesli sie uda std::cin jest ture-good
	//jesli podano zly strumien zamienia std::cin na failbit
	//!std::cin konwersja na bool failbit 0, good 1
	//! 
	//std::cer mozemy wykorzystac do wysylania strumieni bledow do specjalnego pliku np error.txt
	// wysylamy to w shellu/teminalu linuxa 2> (w przeciwienstwie do zwyklego strumienia >>)

	//MANIPULATORY
	//wplywaja na zachowanie strumienia

	std::cout << std::endl;//endl nowa linia +flush (czysci strumien)
	std::cout << std::setw(12) << "Tomek"<< std::setw(12) << "Michal" << std::endl;
	std::cout << std::setprecision(2) << 1.31241412 << " " << 1.2312 << std::endl;
	std::cout << std::fixed << 1.31241412 << " " << 1.23 << std::endl;
	std::cout << std::left << std::setw(12)<< 1.2312 << std::right << std::setw(12) << 12.1 << std::endl << std::endl;
	std::cout << 3.14e+10<< " "<< std::scientific << 3.14e+10<<std::endl;
	std::cout << std::hex << 10932 << std::endl;
	std::cout << std::defaultfloat << 32.3000 << " " << std::noshowpoint << 32.3000<<std::endl;


	constexpr int fibonacii = fib(12);
	std::cout << std::dec<<"\n" << fibonacii;

	Punkt p{ 1,2 };
	std::cout << p;
	std::unique_ptr<Punkt> k = std::make_unique<Punkt>(3,2);
	std::cout << *k;
	przechowywaczPunktu przechow(4,2);
	std::cout << przechow.get()<<std::endl;
	std::ofstream f("tekst.txt");
	int i = 0;
	while (i < 100) {
		f << "siema "<< i<<std::endl;
		i++;
	}
	f.close();
	std::ifstream plik("tekst.txt");
	i = 0;
	while (plik) {
		
		std::string linia{};
		std::getline(plik, linia);
		std::cout << linia << "\n";
		i++;
	}

	plik.clear(); // kasuje bledy
	plik.seekg(0); // wraca na poczatek pliku
	while (plik) {
		std::string slowo{};
		plik >> slowo;
		std::cout << slowo << "\n";

	}
}