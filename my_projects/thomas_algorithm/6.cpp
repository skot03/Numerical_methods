#include <iostream>
#include <iomanip>
#define N 6

using namespace std;

void calculateN();
void calculateR();
void calculateX();

double L[N - 1] = { 1.0 / 3.0, 1.0 / 5.0, 1.0 / 7.0, 1.0 / 9.0, 1.0 / 11.0 };
double D[N] = { 10.0, 20.0, 30.0, 30.0, 20.0, 10.0 };
double U[N - 1] = { 1.0 / 2.0, 1.0 / 4.0, 1.0 / 6.0, 1.0 / 8.0, 1.0 / 10.0 };
double b[N] = { 31.0, 165.0 / 4.0, 917.0 / 30.0, 851.0 / 28.0, 3637.0 / 90.0, 332.0 / 11.0 };
double x[N];

void calculateN() {
    
    for (int i = 1; i < N; ++i) {
        D[i] = D[i] - (L[i - 1] * U[i - 1]) / D[i - 1];
    }
}

void calculateR() {
   
    for (int i = 1; i < N; ++i) {
        b[i] = b[i] - (L[i - 1] *b[i - 1]) / D[i - 1];
    }
    calculateX();
}

void calculateX() {
    x[N - 1] = b[N - 1] / D[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        x[i] = (b[i] - U[i] * x[i + 1]) / D[i];
    }
}

void printMatrix() {
    cout << endl << "Matrix A:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                cout << setw(10) << D[i];
            }
            else if (j == i - 1) {
                cout << setw(10) << L[j];
            }
            else if (i == j - 1) {
                cout << setw(10) << U[i];
            }
            else {
                cout << setw(10) << 0;
            }
        }
        cout << endl;
    }
}

void printVector() {
    cout << "Vector x:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << setw(10) << x[i];
    }
}

int main() {
    calculateN();
    calculateR();
    printMatrix();
    cout << endl;
    printVector();
    return 0;
}
