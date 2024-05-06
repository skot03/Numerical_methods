#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
double oblicz(double x);
double oblicz_blad(double a, double b);
double funkcja_taylora(double x);
double calculate_dbl_epsilon() {

	double zmienna_d = 1.0;
	while ((0.5 * zmienna_d + 1.0) > 1) {
		zmienna_d *= 0.5;

	}
	return zmienna_d;
}
int main() {
	fstream plik;
	plik.open("dane.txt",ios::in);
	if (!plik) {
		cout << "Wystapił problem z otwrzeniem pliku z danymi do funkcji. Sprawdz poprawnosc nazwy" << endl;
		cerr << "Blad otwarcia pliku" << endl;
		exit(1);


	}
	fstream error;
	error.open("error.txt", ios::out);
	if (!error) {
		exit(4);
	}
	double blad, x, y, logarithm, err;
	double y2;
	while (plik >> logarithm >> x >> y) {
		if (logarithm > 0) {
			y2 = oblicz(x);
		}
		else {
			y2 = funkcja_taylora(x);
		}
		err = oblicz_blad(y2, y);
		error << logarithm << "\t" << log10(err) << std::endl;
		/*
		y2 = oblicz(x);

		err = oblicz_blad(y2, y);
		error << logarithm << "\t" << log10(err) << std::endl;
		
		*/
	}
}
double oblicz(double x) {

	return((1.0 - exp(-x)) / x);

}
double oblicz_blad(double a, double b) {
	return fabs((a - b) / b);



}
double funkcja_taylora(double x) {
    double suma_funkcji = 0.0;
    double pierwszy_wyraz = 1.0;
    double i = 2.0;
	double dbl_epsilon = calculate_dbl_epsilon();

    while (fabs(pierwszy_wyraz) >= dbl_epsilon) {
        suma_funkcji += pierwszy_wyraz;
        pierwszy_wyraz *= (-x / i);
        i += 1.0;
    }

    return suma_funkcji;
}
