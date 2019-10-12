#include "pch.h"
#include <iostream>
#include "Vektor.h"
int main()
{

  Vektor<int> *vektor = new Vektor<int>();
  for (int i = 0; i < 5; i++) {
    vektor->pushback(i);
  }
  for (int i = 0; i < vektor->size(); i++) {
    std::cout << vektor->at(i) << std::endl;
  }

  std::cout << std::endl;

  vektor->popback();
  for (int i = 0; i < vektor->size(); i++) {
    std::cout << vektor->at(i) << std::endl;
  }

  std::cout << std::endl;

  vektor->resize(10);
  for (int i = 0; i < vektor->size(); i++) {
    std::cout << vektor->at(i) << std::endl;
  }

  std::cout << std::endl;

  vektor->resize(3);
  for (int i = 0; i < vektor->size(); i++) {
    std::cout << vektor->at(i) << std::endl;
  }

  std::cout << std::endl;

  vektor->clear();
  for (int i = 0; i < vektor->size(); i++) {
    std::cout << vektor->at(i) << std::endl;
  }
  int a;
  std::cin >> a;

}

