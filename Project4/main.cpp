#include "header1.h" // praca na wlasnych funkcjach
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <random>
#include <iostream>
#include <set>
#include <iomanip>

int main() {
	//Na start chcialbym przeanalizowac wszystkie struktury danych i czym sie roznia:


	std::random_device rd;					// Ÿród³o losowosci
	std::mt19937 gen(rd());					// silnik tworzacy liczby losowe
	std::normal_distribution<double> rozkl(50, 100); // rozklad normalny ze srednia 10 i odchyleniem 7



	//Kontenery Sekwencyjne - przechowuja elementy w scisle okreslonej kolejnosci
	std::cout << "Kontenery sekwencyjne\n\n\n";
	std::vector<int> vec; //zmienny rozmiar, Elementy sa w ciaglym obszarze pamieci, Szybki dostep do srodka
	for (int i = 0; i < 10; i++) {
		vec.push_back(rozkl(gen));

	}
	for (int x : vec) {
		std::cout << x << " ";
	}
	std::cout << "\n";

	vec.resize(15, 0);// zwiekszam rozmiar o 5 (zupelnie nie potrzebne poniewaz rozmiar vectora jest dynamiczny) powstale miejsca sa zajete przez 0 
	vec.pop_back(); // usuwa ostatni
	vec.erase(vec.begin() + 1); // zmazuje
	
	vec.insert(vec.begin()+5,4);// dodaje 4 na 6 element
	vec.erase(vec.begin(), vec.begin() + 1); //usuwa przedzial
	for (int x : vec) {
		std::cout << x << " ";
	}
		std::cout << "\n";


	std::array<int, 10> ar; // rozmiar deklarowany nie do zmienienia, bezpieczniejsza wersja standardowej tablicy
	std::array<int, 10> ar2;
	for (int i = 0; i < ar.size(); i++) {
		ar[i] = rozkl(gen);// dostep bez sprawdzania zakresu

	}
	for (int i = 0; i < ar2.size(); i++) {
		ar2[i] = rozkl(gen);// dostep bez sprawdzania zakresu

	}
	//  ar[ar.size()] = 4;   blad bo nie sprawdz zakresu
	ar.front() = 1;
	ar.back() = 10;
	int* p = ar.data(); //data() wskaznik na dane


	for (int x : ar) { //  mozna uzyc auto
		std::cout << x << " ";
	}
	std::cout << "\n";
	for (int x : ar2) {
		std::cout << x << " ";
	}
	std::cout << "\n"<< "Po swap() array\n";
	ar.swap(ar2);//nie dziala na rozne rozmiary 
	for (int x : ar) {
		std::cout << x << " ";
	}
	std::cout << "\n";
	for (int x : ar2) {
		std::cout << x << " ";
	}
	std::cout << "\n";
	
	std::deque<int> deq; // kolejka 2 stronna, mozna dodawac, usunac przed
	for (auto i = 0; i < 10; i++) {
		deq.push_back(rozkl(gen));
		deq.push_front((int)rozkl(gen) %5);// bedzie 2x wiecej bo jednoczesnie pcham do tylu i do przodu
	}
	for (auto x : deq) {
		std::cout << x << " ";
	}
	std::cout << "\n";
	deq.pop_back();// usuwam z przodu
	deq.pop_front(); //usuwam z tylu
	deq.erase(deq.begin() + 5, deq.end() - 5);
	std::cout<<("Po usunieciu: \n");
	for (auto x : deq) {
		std::cout << x << " ";
	}
	std::cout << "\n";


	std::list<int> li; // elementy sa rozproszone w pamiecie, lista dwukierunkowa, dostep tylko sekwencyjny
	for (auto i = 0; i < 10; i++) { //mozesz dodac w kazdym miejscu listy ale nie mozesz wywolac danego elementu
		li.push_back(rozkl(gen));
	}
	auto it = li.begin();
	
	std::advance(it, 2);
	li.insert(it, 99);
	for (auto x : li) {
		std::cout << x << " ";
	}




	li.clear();
	



	std::forward_list<int> forw_lis(11,10); // Lista jednokierunkowa
	std::cout << "\n";
	forw_lis.push_front(1); // najpierw tworzysz obiekt, potem kopiujesz obiekt
	forw_lis.emplace_front(2); // tworzy obiekt bezposrednio w kontenerze nie ma kopii do przeniesienia
	//emplace szybszy, zazwyczaj lepszy
	forw_lis.pop_front();
	auto it1 = forw_lis.begin();
	advance(it1, 5);
	forw_lis.insert_after(it1, 4);

	for (auto x : forw_lis) {
		std::cout << x << " ";
	}

	for (auto it2 = forw_lis.begin(); it2 != forw_lis.end(); it2++) {
		*it2 = rozkl(gen);

	}
	std::cout << "\nNadpisane wartosci w forward list\n";
	//forw_lis.insert_after(it1, 3);
	for (auto x : forw_lis) {
		std::cout << x << " ";
	}

	//auto it = next(forw_lis.begin(), 2);

	int j=0;
	std::cout << "\nOkej, Kontenery Asocjacyjne, wcisnij przycisk";
	std::cin.get();

	system("cls");	 //Windows
	//system("clear"); //Linux/mac
	//KONTENERY ASOCJACYJNE
	Punkt a{1.0,2.0};
	//std::set<Punkt> przestrzen;
	std::set<Punkt> zbiorPunktow;
	
	while (j < 10) {
		zbiorPunktow.insert({rozkl(gen),rozkl(gen)});
		j++;
	}

	for (auto i : zbiorPunktow) {
		std::cout << "P(" <<std::fixed<<std::setprecision(5)<< i.a << "," << i.b << ") \n";
	}


}