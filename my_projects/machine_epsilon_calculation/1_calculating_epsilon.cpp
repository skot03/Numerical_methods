#include <iostream>


int main() {
	int licznik_bitow_d = 0;
	int licznik_bitow_f = 0;
	float zmienna_f;
	double zmienna_d;
	zmienna_f = 1.f;
	while ((0.5f * zmienna_f + 1.f) > 1) {
		zmienna_f *= 0.5f;
		licznik_bitow_f++;



	}
	std::cout << "licznik bitow dla zmiennej typu float:" << licznik_bitow_f << std::endl;
	std::cout << "epsilon dla floata:" << zmienna_f << std::endl;
	std::cout << "epsilon biblioteczny:" << FLT_EPSILON << std::endl;
	zmienna_d = 1.0;
	while ((0.5 * zmienna_d + 1.0) > 1) {
		zmienna_d *= 0.5;
		licznik_bitow_d++;

	}
	std::cout << "licznik bitow mantysy dla zmiennej typu double " << licznik_bitow_d << std::endl;
	std::cout << "epsilon dla double: " << zmienna_d << std::endl;
	std::cout << "epsilon biblioteczny" << DBL_EPSILON << std::endl;
	return 0;





}