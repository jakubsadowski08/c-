//Definicja znajduje się w pliku Point.cpp
#include <cmath>
#include <ostream>
#include "Square.h"
#include<iostream>
using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using namespace std;

/* Aby wskazać, ze definicja funkcji dotyczy metody danej klasy
  stosujemy tzw. operator zasięgu - "::"
*/

//Specjalna inicjalizacja zmiennych. Zmienne są inicjowane
//nim zostanie wywołane ciało konstruktora
geometry::Point::Point():x_(0),y_(0){
    cout << "Konstruktor bezparametrowy" << endl;
}

geometry::Point::Point(double x, double y){
    cout << "Konstruktor parametrowy" << endl;
    x_ = x;
    y_ = y;
}


