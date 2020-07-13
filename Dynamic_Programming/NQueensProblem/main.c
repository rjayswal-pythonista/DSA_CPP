#include "NQueensheader.h"
#include <chrono>
#include <iostream>
#include <array>
using namespace std;

int main()
{   
	QueensProblem problem{ 1 };
	auto start = std::chrono::high_resolution_clock::now(); 
	problem.solve();
	auto finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << " msec\n";
	return 0;
}
