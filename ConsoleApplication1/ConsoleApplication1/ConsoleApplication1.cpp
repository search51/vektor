#include "pch.h"
#include <iostream>
#include "Vektor.h"
#include <chrono>
#include <string> 
#include <vector>



int main()
{  
  //Vektor<int> *vektor = new Vektor<int>();

  //auto start = std::chrono::steady_clock::now();

  //vektor->pushback(1);

  //auto end = std::chrono::steady_clock::now();

  //std::cout << "Elapsed time in nanoseconds : "
  //  << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
  //  << " ns" << std::endl;
  //vektor->popback();
  //int a;
  //std::cin >> a;

  //for (int i = 0; i < 5; i++) {
  //  vektor->pushback(i);
  //}
  //for (int i = 0; i < vektor->size(); i++) {
  //  std::cout << vektor->at(i) << std::endl;
  //}

  //std::cout << std::endl;

  //vektor->popback();
  //for (int i = 0; i < vektor->size(); i++) {
  //  std::cout << vektor->at(i) << std::endl;
  //}

  //std::cout << std::endl;

  //vektor->resize(10);
  //for (int i = 0; i < vektor->size(); i++) {
  //  std::cout << vektor->at(i) << std::endl;
  //}

  //std::cout << std::endl;

  //vektor->resize(3);
  //for (int i = 0; i < vektor->size(); i++) {
  //  std::cout << vektor->at(i) << std::endl;
  //}

  //std::cout << std::endl;

  //vektor->clear();
  //for (int i = 0; i < vektor->size(); i++) {
  //  std::cout << vektor->at(i) << std::endl;
  //}
 
  ////Due to the usage of a template class, it's possible to switch data types
  //Vektor<std::string> *vektor2 = new Vektor<std::string>();
  //vektor2->pushback("HELLO WORLD");
  //std::cout << vektor2->at(0);
  //
  //std::cin >> a;
  //delete vektor2;
  //delete vektor;
  //Just for presentation purpose: a comparison between our "vektor" and the standard vector
  std::vector<int> *vec = new std::vector<int>();
  Vektor<int> *vektor3 = new Vektor<int>();
  auto mytime = 0;
  auto vectortime = 0;
  int iterations = 0;
  int itmark = 5000000;

  while (iterations < itmark) {
    auto start = std::chrono::steady_clock::now();

    vec->push_back(1);

    auto end = std::chrono::steady_clock::now();
    vectortime = vectortime + std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    vec->pop_back();
    start = std::chrono::steady_clock::now();

    vektor3->pushback(1);
    end = std::chrono::steady_clock::now();
    mytime = mytime + std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    vektor3->popback();
    ++iterations;

  }
  iterations = 0;
  while (iterations < itmark) {

    auto start = std::chrono::steady_clock::now();

    vektor3->pushback(1);

    auto end = std::chrono::steady_clock::now();
    mytime = mytime + std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    vektor3->popback();

    start = std::chrono::steady_clock::now();

    vec->push_back(1);

    end = std::chrono::steady_clock::now();
    vectortime = vectortime + std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    vec->pop_back();
    ++iterations;
  }
  std::cout << "Unsere Vektorklasse braucht, bei " << iterations * 2 << " durchfuehrungen, durchschnittlich " << mytime / (itmark * 2) << " ns" << std::endl;
  std::cout << "Die fertige Vectorclass braucht, bei " << iterations * 2 << " durchfuehrungen, durchschnittlich " << vectortime / (itmark * 2) << " ns" << std::endl;
}

