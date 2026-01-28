#ifndef MY_FUNCTION
#define MY_FUNCTION
#include <initializer_list>
#include <set> 
#include <ostream>
//moze tez byc pragma once ale jest to mniej dokladne
struct Osoby {
    std::string imie;
    int indeks;
};


void wydrukuj(int i);
struct Punkt1 {
    double a;
    double b;
    bool operator<(const Punkt1& inny) const {
        if (a != inny.a) {
            return a < inny.a;
        }
        return b < inny.b;
    }
};
struct Punkt2 {
    double a;
    double b;
    bool operator<(const Punkt2& inny) const {
        if (b != inny.b) {
            return b < inny.b;
        }
        return a < inny.a;
    }
};

// // Zakomentowane poniewaz zrobilem wspolny szablon dla seta i multiseta


// template dla set<> by przeciazyc operatory
//template<typename T>
//class OperatorowySet {
//private:
//    std::set<T> data;
//
//public:
//    OperatorowySet() = default;
//
//    OperatorowySet(std::initializer_list<T> list) { //initializer list bo to jedyna struktura danych ktora mozna zanicjalizowac poptrzez {}
//        for (auto& el : list)
//            data.insert(el);
//    }
//
//    // podstawowe operacje
//    void add(const T& value) {
//        data.insert(value);
//    }
//
//    void remove(const T& value) {
//        data.erase(value);
//    }
//
//    size_t size() const { //size_t jest typ liczbowy (unsigned przechowuje rozmiar obiektu w pamieci
//        return data.size(); // rownie dobrze mogl  by tu byc int byla by wtedy konwersja niejawna z data_s (typ) na inta0
//    }// site_t ma ogromny zakres na arch 32 32 bity ale na 64 64bity
//    
//    template<typename U>
//    friend std::ostream& operator<<(std::ostream&, const OperatorowySet<U>&); // friend poniewaz data jest prywatna, przeciazam operator zeby moc cout<<OperatorowySet;
//    
//    
//     OperatorowySet operator+(const OperatorowySet& j) const{
//        OperatorowySet wynik = *this;// tworze kopie
//        for (const auto& x : j.data) {
//            wynik.data.insert(x);
//        }
//        return wynik;
//    }
//     OperatorowySet operator+=(const OperatorowySet& j) const  { // stworzylem kolejny moze niezbyt czytelny przeciazony operator byle sie nauczyc tego dobrze
//         OperatorowySet wynik;
//         auto it1 = data.begin();
//         auto it2 = j.data.begin();
//
//         while (it1 != data.end() && it2 != j.data.end()) {
//             wynik.data.insert(*it1 + *it2);
//             ++it1;
//             ++it2;
//         }
//         return wynik;
//     }
//
//};

 

 // CHCIALEM STWORZYC TEMPLATE JEDNOCZESNIE DLA SETA I MULTISETA
 
  
 //template T-zwykly typ dany przechowywany w multiset, set, template<typename, typename..> -
template<typename T, template<typename, typename...> class Container = std::set> 
class OperatorowySet {
private:
    Container<T> data;
public:
    OperatorowySet() = default;

    OperatorowySet(std::initializer_list<T> list) { //initializer list bo to jedyna struktura danych ktora mozna zanicjalizowac poptrzez {}
        for (auto& el : list)
            data.insert(el);
    }

    // podstawowe operacje
    void add(const T& value) {
        data.insert(value);
    }

    void remove(const T& value) {
        data.erase(value);
    }

    size_t size() const { //size_t jest typ liczbowy (unsigned przechowuje rozmiar obiektu w pamieci
        return data.size(); // rownie dobrze mogl  by tu byc int byla by wtedy konwersja niejawna z data_s (typ) na inta0
    }// site_t ma ogromny zakres na arch 32 32 bity ale na 64 64bity

   // template<typename U, template<typename, typename...> class C>
    friend std::ostream& operator<<(std::ostream& os, const OperatorowySet& s) {// typ std::ostream& zwraca referencje do strumienia wyjsciowego np cout<< A 
        os << "{ ";// operator<< nie jest przypadkowa nazwa ale specjalna funkcja do przeciazenia operatora <<, dlaczego const Oper..<T>& - poniwaz nie chcemy kopiowac calego kontenera i pracowac na nim tylko pracujemy na referencji ale const czyli nie mozemy jej popsuc
        for (const auto& a : s.data)
            os << a << " ";
        os << "}";
        return os;
    }


    OperatorowySet operator+(const OperatorowySet& j) const {
        OperatorowySet wynik = *this;// tworze kopie
        for (const auto& x : j.data) {
            wynik.data.insert(x);
        }
        return wynik;
    }
    OperatorowySet operator+=(const OperatorowySet& j) const { // stworzylem kolejny moze niezbyt czytelny przeciazony operator byle sie nauczyc tego dobrze
        OperatorowySet wynik;
        auto it1 = data.begin();
        auto it2 = j.data.begin();

        while (it1 != data.end() && it2 != j.data.end()) {
            wynik.data.insert(*it1 + *it2);
            ++it1;
            ++it2;
        }
        return wynik;
    }

};


//template<typename U>
//std::ostream& operator<<(std::ostream&, const OperatorowySet<U>&) {// typ std::ostream& zwraca referencje do strumienia wyjsciowego np cout<< A 
//    os << "{ ";// operator<< nie jest przypadkowa nazwa ale specjalna funkcja do przeciazenia operatora <<, dlaczego const Oper..<T>& - poniwaz nie chcemy kopiowac calego kontenera i pracowac na nim tylko pracujemy na referencji ale const czyli nie mozemy jej popsuc
//    for (const auto& a : s.data)
//        os << a << " ";
//    os << "}";
//    return os;
//}
//




#endif
