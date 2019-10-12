#include "pch.h"
#include <iostream>
#include "Vektor.h"
#include <chrono>
#include <string> 

int main()
{  
  Vektor<int> *vektor = new Vektor<int>();

  auto start = std::chrono::steady_clock::now();

  vektor->pushback(1);

  auto end = std::chrono::steady_clock::now();

  std::cout << "Elapsed time in nanoseconds : "
    << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
    << " ns" << std::endl;
  vektor->popback();
  int a;
  std::cin >> a;

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
 

  Vektor<std::string> *vektor2 = new Vektor<std::string>();
  vektor2->pushback("HELLO WORLD");
  std::cout << vektor2->at(0);
  
  std::cin >> a;
  delete vektor2;
  delete vektor;
}

