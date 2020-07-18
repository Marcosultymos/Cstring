#include "string.hpp"
#include <iostream>
#include <chrono>
typedef unsigned long long ulli;
using namespace complete_string;

int main(){
	auto inicio = std::chrono::high_resolution_clock::now();
	auto tempo_1 = std::chrono::high_resolution_clock::now() - inicio;
	
	string a;
	
	a = "Olá, Mundo!";
	
	a*=3;
	
	std::cout << a.hash() << std::endl;
	
	
	auto resultado = std::chrono::high_resolution_clock::now() - inicio - tempo_1;
	ulli tempo = std::chrono::duration_cast<std::chrono::nanoseconds>(resultado).count();
	printf("\nTempo total: %lluns\n", tempo);
}