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
#include <string>
#include <map>
#include <iomanip> //wyrownuje cout'y
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include "nlohmann/json.hpp" // biblioteka zewnetrzna do obslugi json
#include <fstream>
#include <clocale>// slaby sposob na tworzenie znakow polskich w terminalu (lepszy to Windows.h) i kodowanie wyjscia na UTF-8 SetConsoleOutputCP(65001); 
#include <Windows.h>
#include <algorithm>
#include <utility>//swap
int main() {
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
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
	std::vector<int> a{ 1,2,3,4 };// dziala bo ma w sobie initializer_list
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
	// 
	std::set<Punkt1> zbiorPunktow1;
	
	while (j < 10) {
		zbiorPunktow1.insert({rozkl(gen),rozkl(gen)});
		j++;
	}
	std::cout << "Zbior punktow w set upozatkowanych w kolejnosci punktu A\n";
	for (auto i : zbiorPunktow1) {
		std::cout << "P(" <<std::fixed<<std::setprecision(1)<< i.a << "," << i.b << ") \n";
	}
	std::set<Punkt2> zbiorPunktow2;
	j = 0;
	while (j < 10) {
		zbiorPunktow2.insert({ rozkl(gen),rozkl(gen) });
		j++;
	}
	std::cout << "Zbior punktow w set upozatkowanych w kolejnosci punktu B\n";
	for (auto i : zbiorPunktow2) {
		std::cout << "P(" << std::fixed << std::setprecision(1) << i.a << "," << i.b << ") \n";
	}
	OperatorowySet<int, std::set> liczby1{10, 9, 8, 4, 6, 2, 4, 1, 6, 2, 2, 4, 1};
	OperatorowySet<int> liczby2;
	for (int i = -20; i < 20; i += 4) {
		liczby2.add(i);
	}
	
	OperatorowySet<std::string, std::set> imiona{"Ola", "Michal", "Maciek", "Kamil", "Krystian", "Anna"};
	std::cout << liczby1<<"\n";
	std::cout << liczby2 << "\n";
	auto liczby3 = liczby1+liczby2;// suma zbiorow
	std::cout << liczby3 << "\n";
	auto liczby4 = liczby1 += liczby2; // zabawa z operatorem += w moim programie pracuje on jako suma po kolei elementow setu, nie powinno sie wykorzystywac setu do takich zadan
	std::cout << liczby4 << "\n"; //ani takiego operatora jednak ciekawy bylem czy tak sie da;
	std::cout << imiona<<"\n";


	std::map<std::string, int> wzrost; // map ma indeks 1 po ktorym sortuje i 2 element to zawartosc po ktorej nie sortuje
	std::cout << "Map string int: \n";
	
	wzrost["Ala"] = 150;
	wzrost["Alan"] = 149;
	wzrost["Aaron"] = 151;//aron bedzie 1 bo jest najnizej w slowniku 
	//std map 
	
	//for (const auto& [klucz, wartosc] : wzrost) { Mapowanie standard C++17
	//	std::cout << klucz << ": " << wartosc << '\n';
	//}

	for (const auto& elem : wzrost) { // elem to taki struct z elemtami w naszym wypadku 2 first secound (1 indeks, 2 obiekt)
		std::cout << elem.first << " " << elem.second << '\n';
	}
	std::map< int,Punkt1> punkty;
	//Punkt1 b{ rozkl(gen), rozkl(gen) };
	for (auto i = 10; i > 0; i--) {
		punkty[i] = { rozkl(gen), rozkl(gen) };

	}
	std::cout << "Map <int, struct Punkt(double, double)>: \n";
	for (const auto& elem : punkty) { // elem to taki struct z elemtami w naszym wypadku 2 first secound (1 indeks, 2 obiekt)
		std::cout << elem.first << " " << elem.second.a << " "<< elem.second.b <<'\n';
	}

	std::map< Punkt1, int> punkty2;
	for (auto i = 10; i > 0; i--) {
		punkty2[{ rozkl(gen), rozkl(gen) }] = i;

	}
	std::cout << "Map <struct Punkt1(double, double),int, sortowanie po 1 double>: \n";
	for (const auto& elem : punkty2) { // elem to taki struct z elemtami w naszym wypadku 2 first secound (1 indeks, 2 obiekt)
		std::cout << elem.first.a << " " << elem.first.b << " " << elem.second<< '\n';
	}

	std::map< Punkt2, int> punkty3;
	for (auto i = 10; i > 0; i--) {
		punkty3[{ rozkl(gen), rozkl(gen) }] = i;

	}
	std::cout << "Map <struct Punkt2(double, double),int, sortowanie po 2 double>: \n";
	for (const auto& elem : punkty3) { // elem to taki struct z elemtami w naszym wypadku 2 first secound (1 indeks, 2 obiekt)
		std::cout << elem.first.a << " " << elem.first.b << " " << elem.second << '\n';
	}
	//STD::MULTIMAP i STD::MULTISET
	
	//std::multiset Kontener podobny do set, przechowuje elementy w kolejnosci rosnacej
	//glowna roznica - moze miec duplikaty
	// 
	//multiset przekopiowane z set'a ale inny wynik
	OperatorowySet<int, std::multiset> liczby5{ 10, 9, 8, 4, 6, 2, 4, 1, 6, 2, 2, 4, 1 };
	OperatorowySet<int, std::multiset> liczby6;
	for (int i = -20; i < 20; i+= 4) {
		liczby6.add(i);
	}
	std::cout << liczby5 << "\n";
	std::cout << liczby6 << "\n";
	auto liczby7 = liczby5 + liczby6;// suma zbiorow
	std::cout << liczby7 << "\n";
	auto liczby8 = liczby5 += liczby6; // zabawa z operatorem += w moim programie pracuje on jako suma po kolei elementow setu, nie powinno sie wykorzystywac setu do takich zadan
	std::cout << liczby8 << "\n";

	//multimap
	std::multimap<std::string, int> wzrostmultimap; // map ma indeks 1 po ktorym sortuje i 2 element to zawartosc po ktorej nie sortuje
	std::cout << "Map string int: \n";

	//wzrostmultimap["Ala"] = 150; nie - dziala to tylko dla map
	wzrostmultimap.insert({ "Ala", 150 });
	wzrostmultimap.insert({ "Ala", 151 });
	wzrostmultimap.insert({ "Ala", 152 });
	wzrostmultimap.insert({ "Ala", 150 });
	wzrostmultimap.insert({ "Aaron", 151 });

	//std map 
	
	for (auto i : wzrostmultimap) {
		std::cout << std::left << "Indeks: " << std::setw(8)<< i.first << " Wartosc: " << i.second << "\n";
	}
	//Kontenery Asocjacyjne Nieuporz¹dkowane
	//Dzialaja w oparciu o hash tables. Nie gwarantuja kolejnosci ale oferuja srednio najszybszy dostep
	
	std::cout << "\n Kontenery Asocjacyjne Nieuporzadkowane, wcisnij przycisk";
	std::cin.get();
	system("cls");

	std::unordered_map<int, int> licz1 = { {1,1},{1,1}, { 1,2 },{2,3},{4,1}, {4,2},{6,5}, {5,5}, {4,8}, {9,1} };
	licz1[-2] = 7;
	licz1.insert({ 6,3 });
	int l = 4;

	for (const auto& i : licz1) {
		std::cout << "P(" << i.first << "," << i.second<<") ";

	}
	std::cout << "\n";
	for (const auto& elem : punkty) { 
		std::cout << elem.first << " " << elem.second.a << " " << elem.second.b << '\n';
	}

		if (licz1.find(l) != licz1.end()) {
			std::cout << "Liczbie : " << l << " odpowiada: " << licz1[l] << "\n";
		
		}



		std::cout << "No to co czas na Adapterty kontenerow \n";
		
		std::cin.get();
		system("cls");
		
		std::cout << "Kontener stack-stos jest to kontener bez iteratorow tylko z 3 glownymi funkcjami \n";
		std::cout << "pop()- wyrzuca z gory, top()- zwraca element z gory, push()- dodaje na gore\n";
		std::cout << "czyli dzieje sie tu Lifo - last Last in, First Out (dotyczy jednego elementu- jak jest ostatni 1 zwrocimy\n)";

		std::stack<std::string> stosStringow;
		stosStringow.push("Adam");
		stosStringow.push("Tomek");
		for (int i = 97; i < 123; i++) {
			stosStringow.push(std::string(3,(char)i));

		}
		auto kopia = stosStringow;
		while (!kopia.empty()) {
			std::cout << kopia.top() << std::endl;
			kopia.pop();
		}

		std::uniform_int_distribution<> rozkNat(0, 533);

		std::ifstream f("imiona.json");
		nlohmann::json data = nlohmann::json::parse(f);
		std::cout << data[1] << data[2]<< std::endl;
		std::cout << data.size() << std::endl;
		std::stack<std::string> imionaStos;
		std::cout << "Random: " << (int)rozkl(gen) << " " << (int)rozkl(gen) << " " << (int)rozkl(gen) << std::endl;
		for (int i = 0; i < 200; i++) {
			//std::cout << "Modulo 533 to: " << (rozkNat(gen) % 533) << " ";
			imionaStos.push(data[(int)rozkNat(gen) % 533]);
		}
		auto kopiaImonaStos = imionaStos;
		while (!kopiaImonaStos.empty()) {
			std::cout << "Imie na gorze: " << kopiaImonaStos.top() << "\n";
			kopiaImonaStos.pop();
		}
		std::cout << "Problem, terminal nie obsluguje naszego jezyka (znakow specjalnych)\n";
		//setlocale(LC_ALL, "Polish"); //uzywa ustawien regionalnych 
		kopiaImonaStos = imionaStos;
		std::cout << " Cos sie popsulo z polskimi znakami, spobujmy to zmienic" << std::endl;
		std::cin.get();
		std::cout << "Za¿ó³æ gêœl¹ jaŸñ – polskie znaki dzia³aj¹!" << std::endl;
		std::cin.get();
		while (!kopiaImonaStos.empty()) {
			std::cout << "Imie na gorze: " << kopiaImonaStos.top() << "\n";
			kopiaImonaStos.pop();
		}
		std::cout << "O nie setlocale zawodzi, to dlatego ze nie byl ustawiony kiedy przepisywalismy pliki z JSON'a do naszego kontenera: "<<std::endl;
		//zadanie na przyszlosc zrobic tak zeby zamienic zle znaki na poprawne
		std::cout<<("Wcisnij klawisz \n");
		std::cin.get();
		system("cls");
		std::cout << "Ciezko by bylo przelozyc teraz gotowy Stos z blednymi wartosciami (odbieranie strumienia wchodzacego) wiec zrobmy nowy \n";
		while(!imionaStos.empty()) {
			imionaStos.pop();
		}
		data.clear();
		f.close();

		std::ifstream g("imiona.json");
		data = nlohmann::json::parse(g);

		for (int i = 0; i < 100; i++) {
			imionaStos.push(data[(int)rozkNat(gen) % 533]);
		}
		kopiaImonaStos = imionaStos;
		while (!kopiaImonaStos.empty()) {
			std::cout << "Imie na gorze: " << kopiaImonaStos.top() << "\n";
			kopiaImonaStos.pop();
		}

		std::cin.get();
		system("cls");

		//roznica miedzy queue a stack:
		// stack daje dostep tylko do jednego konca (top())
		// queue daje dostep do 2 koncow poczatek i koniec (fron(), back())
		// Kontenery to nakladki nie kazdy kontener moze sie nadac do roznych zawartosci:
		// dla stack mozna uzyc wszystkiego: vector, decque, list
		// dla queue nie mozesz uzyc vector, kolejka wymaga usuwania elementow z przodu,
		// kolejka akceptuje tylko deque, list
		//
		std::queue<std::string> imionaKolejka;
		for (auto i = 0; i < 100; i++) {
			imionaKolejka.emplace(data[rozkNat(gen) % 533]); // dobry nawyk emplace zamiast push, emplace odrazu wklada gotowy element do konteneraa gdy push tworzy element i kopiuje do kontenera
		}
		auto kopiaImionaKolejka = imionaKolejka;
		while (!(kopiaImionaKolejka.empty()) && kopiaImionaKolejka.size()!= 1) {
			std::cout << "Z przodu " << kopiaImionaKolejka.front() << " Z tylu "<< kopiaImionaKolejka.back()<<std::endl;
			kopiaImionaKolejka.pop();


		}
		if (kopiaImionaKolejka.size() == 1) {
			std::cout << "Ostatni element to nasz koncowy front i back:" << kopiaImionaKolejka.front() << " "<< kopiaImionaKolejka.back()<<std::endl;
		}

	//Algorytmy
		std::cout << "ALGORYTMY \n";
		std::cin.get();
		system("cls");
		std::cout << "Algorytmy niemodyfikujace" << std::endl;
		std::vector<int> k = { 2,4,6,8,10,10 };
		std::cout << "Mamy wektor 2,4,6,8,10" << std::endl;
		//all_of
		std::cout <<"all_of podzielnosc przez 4: "<< std::all_of(k.begin(), k.end(), [](int x) {
			return x % 4 == 0;
			}) 
			<< std::endl;
		std::cout << "any_of podzielnosc przez 4"<< std::any_of(k.begin(), k.end(), [](int x) {
			return x % 4 == 0;
			})
			<< std::endl;
		std::cout << "for_each podzielnosc przez 4 ";
		std::for_each(k.begin(), k.end(), [](int x) {
			std::cout << x << " % 4 bez reszty to " << (x % 4 == 0) << ", ";
			});
		std::cout << "count wartosc 4 ";
		std::cout<< std::count(k.begin(), k.end(), 4)<< std::endl;
		std::cout << "count_if podzielnosc przez 4 " << std::count_if(k.begin(), k.end(), [](int x) {
			return x % 4 == 0;
			})
			<< std::endl;

		std::cout << "find wartosc 4 " << *std::find(k.begin(),k.end(), 4)<<std::endl;//pointer dziala ale tylko dla vectora dla innych kontenerow nie zadzaiala dlatego:
		if (std::find(k.begin(), k.end(), 4) != k.end()) {
			std::cout << "Znaleziono wartosc 4"<<std::endl;
		}
		else {
			std::cout << "Nie znaleziono wartosci 4"<<std::endl;
		}

		if ((std::find_if(k.begin(), k.end(), [](int x) {
			return x % 4 == 0;
			})) != k.end()) {
			std::cout<<"Znaleziono liczbe podzielna przed 4"<<std::endl;
		}
		else 
			std::cout<<"Nie znaleziono"<<std::endl;
		if ((std::find_if_not(k.begin(), k.end(), [](int x) {
			return x % 4 == 0;
			})) != k.end()) {
			std::cout << "Znaleziono liczbe nie podzielna przed 4" << std::endl;
		}

		if ((std::adjacent_find(k.begin(), k.end())) != k.end()) {
			std::cout << "Znaleziono pare takich samych liczb " << std::endl;
		}
		std::vector<int> k1 = { 2,4,6,8,10,10, 12 };
		std::vector<double> k2 = { 2,4,6,8,10,10 };
		bool wynik = std::equal(k.begin(), k.end(), k1.begin());
		if (wynik == 1) {
			std::cout << "K i k1 sa takie same"  << std::endl;// PLAPKA k1 jest dluzsze
		}
		wynik = std::equal(k.begin(), k.end(), k2.begin());
		if (wynik == 1) {
			std::cout << "K i k2 sa takie same" << std::endl;// PLAPKA niejawna tranzycja doubla do inta
		}
		//mismatch oddaje iterator na miejsce w ktorym 2 zakresy zaczynaja byc roznce
		//auto [itmis1, itmis2] = std::mismatch(k1.begin(), k1.end(), k.begin()); dla C++17
		std::vector<int>::iterator itmis1, itmis2;
		std::vector<int> k3 = { 1,2,3,4,5,6,7,8,9,10,11 };
		std::vector<int> k4 = { 1,2,3,4,5,6,7,9,10,11,12,13,14 };
		std::tie(itmis1, itmis2) = std::mismatch(k3.begin(), k3.end(), k4.begin());
		std::cout << "Wektory zaczynaja sie roznic w :" << *itmis1 << " " << *itmis2 << std::endl;
		std::cout<< *(k3.end()-1)<<std::endl; //ostatni element .end() to juz pusta przestrzen (dziala tylko random accesst iteratorami: vector, deque, array
	
		//mismatch - do rozwiniecia i kontynuacji.

		//lexicographical_compare
		std::cout<<"Lexicographical compere "<< std::lexicographical_compare(k3.begin(), k3.end(), k4.begin(), k4.end())<<" wartosc bool "<< std::endl;
		std::cout << "Teraz algorytmy modyfikujace, nacisnij przycisk" << std::endl;
		std::cin.get();
		system("cls");

		std::vector<int> k5 = { 1,2,1,5,1,0,-4 };
		std::list<int> k6 = { 1,1,2,4,5,8,10,11 };
		std::vector<int> k7 = { 1 };
		std::cout << "Copy:" << std::endl;
		std::copy(k5.begin(), k5.end(), k6.begin());
		
		for (auto x : k6) {
			std::cout << x << " ";
		}
		//co tu sie wydarzylo? skopiowalo od 1, -4 z k5 do k6, ze k6 jest wieksze to zostalo 11
		std::cout<<std::endl;
		std::cout << "Copy_if:" << std::endl;
		k5.clear();
		k5 = { 1,5,5 };
		std::copy_if(k5.begin(), k5.end(),
			k6.begin(),
			[](int x) { return x % 5 == 0; }
		);
		for (auto x : k6) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
		std::cout << "Copy_n:" << std::endl;
		k5.clear(); // niepotrzebne
		k5 = { 2,5,1, 7,7,7,4,1,7 }; //to samo w sobie robi clear 
		std::copy_n(k5.begin(), 4, k6.begin());// wpisuje 4 pierwsze elementy z k5 do k6
		for (auto x : k6) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
		k5 = { 1,1,1,1,1,1,1 };
		std::cout << "Move:" << std::endl;
		std::cout << "K5:" << std::endl;
		for (auto x : k5) {
			std::cout << x << " ";
		}
		std::move(k5.begin(), k5.begin()+3, k6.begin());// Przenosi k6 przejmuje dane
		std::cout <<std::endl<<"K6:" << std::endl;
		for (auto x : k6) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
		k5 = { 2,6,-4,-3,5,23};
		std::cout << "Transform:" << std::endl;
		std::transform(k5.begin(), k5.end(), k6.begin(),
			[](int x) {
				return x * x * x;
			});
		std::cout << "K5:" << std::endl;
		for (auto x : k5) {
			std::cout << x << " ";
		}
		std::cout << std::endl << "K6:" << std::endl;
		for (auto x : k6) {
			std::cout << x << " ";
		}
		std::cout << std::endl;

		std::cout << "Swap: " << std::endl;
		std::swap(k5,k7);// zamienia miejscami ale kontenery musza byc tego samego typu, i atrybuty tez
		std::cout << "Swap_rages: " << std::endl;
		k5 = { 1,2,3,4,5,6,7,8,9 };
		k7 = { 10,11,12,13,14,15,16,17,18,19 };
		std::vector<int> k8 = { 21,22 };
		std::swap_ranges(k5.begin(), k5.begin() + 4, k7.begin());
		for (auto x : k5) {
			std::cout << x << " ";
		}
		std::cout << std::endl;

		for (auto x : k7) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
		//std::swap_ranges(k5.begin(), k5.begin() + 4, k8.begin());
		//for (auto x : k5) {
		//	std::cout << x << " ";
		//}
		//std::cout << std::endl;

		//for (auto x : k8) {
		//	std::cout << x << " ";
		//}
		//std::cout << std::endl; nie moze swapowac dluzsza wartosc na krotszy kontener
		std::cout << "Fill: " << std::endl;
		std::fill(k5.begin(), k5.begin() + 4, 0);
		for (auto x : k5) {
			std::cout << x << " ";
		}
		std::cout << std::endl;

		std::cout << "Fill_n: " << std::endl;
		std::fill_n(k5.begin(),2, 111
		);
		for (auto x : k5) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
		int x = 2;
		std::cout << "Generate: " << std::endl;
		std::generate(k5.begin(), k5.begin() + 4, [&]() {
			return x*(++x);
			}
		);
		for (auto x : k5) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
		std::cout << "Generate_n: " << std::endl;
		std::generate_n(k5.begin(), 3, [&]() {
			return x * (++x);
			}
		);
		for (auto x : k5) {
			std::cout << x << " ";
		}
		std::cout << std::endl;

		std::cout << "Remove: " << std::endl;
		std::remove(k5.begin(), k5.end(), 7);//remove zle dziala przesuwa smiecie, w tym przypadku 9 na koniec kontenera ale nie usuwa tego. by to naprawic uzywamy
		for (auto x : k5) {
			std::cout << x << " ";
		}
		std::cout << std::endl;


		std::cout << "Prawidlowe usuwanie, bez smieci Erese+Remove: " << std::endl;

		k5.erase(std::remove(k5.begin(), k5.end(), 9), k5.end());
		for (auto x : k5) {
			std::cout << x << " ";
		}
		std::cout << std::endl;

		auto itNew = std::remove_if(k5.begin(), k5.end(), [](int x) {
			return x % 2 == 0;

			});

		k5.erase(itNew, k5.end());
		for (auto x : k5) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
		std::cout <<"Replace"<< std::endl;
		k5 = { 1,1,1,1,2,3,4,1 };
		std::replace(k5.begin(), k5.end(), 1, 99);
		for (auto x : k5) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
		std::cout << "Replace_if" << std::endl;

		std::replace_if(k5.begin(), k5.end(), [](int x) {
			return x % 99 == 0;
			},
			98);
		for (auto x : k5) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
		std::cout << "Replace_copy" << std::endl;

		std::vector<int> k9;
		//std::replace_copy(k5.begin(), k5.end(), k9.begin(), 98, 97);
		//Niebezpiecznie poniewaz nie wiemy czy k9 bedzie mialo tyle pamieci
		std::replace_copy(k5.begin(), k5.end(), std::back_inserter(k9), 98, 97);
		//BACK INSERTER NIE ROZUMIEM WROCIC!!!!!!!!!!!!!!
		
		std::cout << "K5:" << std::endl;
		for (auto x : k5) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
		std::cout << "K9:" << std::endl;
		for (auto x : k9) {
			std::cout << x << " ";
		}
		std::cout << std::endl;

		std::cout << "Replace_copy_if" << std::endl;
		std::replace_copy_if(k5.begin(), k5.end(), std::back_inserter(k9), [](int x) {
			return x == 98;
			}, 96);
		std::cout << "K9:" << std::endl;
		for (auto x : k9) {
			std::cout << x << " ";
		}
		std::cout << std::endl;

		std::reverse(k9.begin(), k9.end());

		std::cout << "Reverse"<<std::endl<<"K9:" << std::endl;
		for (auto x : k9) {
			std::cout << x << " ";
		}
		std::cout << std::endl;

		std::cout << "Rotate" << std::endl << "K9:" << std::endl;
		std::rotate(k9.begin(), k9.begin() + 5, k9.end());

		for (auto x : k9) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
		std::cout << "Unique" << std::endl << "K9:" << std::endl;

		itNew = std::unique(k9.begin(), k9.end()); 
		//usuwa duplikaty KOLOSIEBIE LEZACE
		k9.erase(itNew, k9.end());
		for (auto x : k9) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
		std::cout << "Unique_copy" << std::endl << "K9:" << std::endl;

		std::vector<int> k10;
		std::unique_copy(k9.begin(), k9.end(), std::back_inserter(k10));
		for (auto x : k10) {
			std::cout << x << " ";
		}
		std::cout << std::endl;

		//Algorytmy sortujace i porzadkujace

		std::sort(k9.begin(), k9.end());
		std::cout << "Zwykle sortowanie\n";
		for (auto i : k9) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
		std::sort(k9.begin(), k9.end(), [](int a, int b) {
			return a > b;
			}


		);
		for (auto i : k9) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
		//sort jest niestabliny bo moze zle potraktowac takie same wartosci
		// mamy struck <string, int>
		// sortujemy po intach stringi sie nie sortuja
		// 
		// 
		//funktory:
		//std::less<> rosnaco
		//std::greater<> malejaco
		//std::less_equal<> <=
		//std::greater_equal<> >=
		//std::equal_to<> ==
		//std::not_equal_to !=
		//std::logical_and<> and
		//std::logical_or<> or
		//std::logical_not<> not
		//std::plus<> +
		//std::minus<> -
		//std::multiplies<> *
		//std::divides<> /
		//std::modulus<> %
		//std::negate<> zamienia znak
		std::vector<Osoby> vectorOsob = { {"Anna", 2},{"Olaf", 3 },{"Olef", 3 },{"Olek", 3 },{"Arek", 3 }, {"Ola", 3},{"Tomasz",2 }, {"Michal", 4}, {"Aa", 1}, {"A", 2}, {"Jakub", 5}};
		std::cout << "\n";
		for (auto i : vectorOsob) {
			std::cout << "{" << i.imie << ", " << i.indeks << "}";
		}
		std::sort(vectorOsob.begin(), vectorOsob.end(), [](Osoby a, Osoby b) {
			return a.indeks < b.indeks;

			});
		std::cout << "\n";
		for (auto i : vectorOsob) {
			std::cout <<"{"<< i.imie << ", "<<i.indeks<<"}";
		}
		std::stable_sort(vectorOsob.begin(), vectorOsob.end(), [](Osoby a, Osoby b) {
			return a.indeks < b.indeks;

			});
		std::cout << "\n";

		for (auto i : vectorOsob) {
			std::cout << "{" << i.imie << ", " << i.indeks << "}";
		}
	


	//algorytmy Stl - zrobione na labolatoriach

	//Iteratory potrafie

	//Szablony - potrafie, metaprogramowanie poczytac co to dokladnie

	//Przeciazanie operatorow potrafie

	//Zarzadzanie pamiecia i wkazniki unique_ptr, shared_ptr, weak_ptr , RAII - WROCIC

	// Wlasne kontenery robilem w C

	// WROCIC Algorytymy <numeric>, stack, queue, Adaptory kontenerow, strumieniowanie, inserter

	//Singleton, Factory, Observer, RAII, Adapter, Strategy

	//Algorytmy równoleg³e (std::execution), Concurrent containers i mutexy, Multithreading, chrono



}