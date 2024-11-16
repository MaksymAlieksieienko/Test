#include <iostream>
#include <cmath>	// Підключення pow

using namespace std;

void checkValidInput() {
	if (cin.fail()) {
		throw "Incorrect input";
	}
}
void checkValidParams(int n) {
	if (n < 0) {
		throw "Input correct data";
	}
}
// Обчислення при x < 0
double calculateSum(int n, double x) {
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += pow(i + x, 2); // (i + x)^2
	}
	return sum;
}

// Обчислення при x >= 0
double calculateProduct(int n, double x) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		double product = 1;
		for (int j = 1; j <= n; j++) {
			product *= (x + i) / (i + j);
		}
		sum += product;
	}
	return sum;
}

// Введення значень x_start, x_end, step та n
int main() {
	double x_start, x_end, step;
	int n;
	try {
		cout << "Print x start:";
		cin >> x_start;
		cout << "Print x end:";
		cin >> x_end;
		cout << "Print step:";
		cin >> step;
		cout << "Print n:";
		cin >> n;

		if (n >= 1) {
			// Цикл з x кроком
			for (double x = x_start; x <= x_end; x += step) {
				double y;
				if (x < 0) {
					y = calculateSum(n, x);
				}
				else {
					y = calculateProduct(n, x);
				}
				cout << "x = " << x << ", y = " << y << endl;
			}
		}
		else {
			cout << "invalid value n" << endl;
		}
	}
	catch (const char* ex) {
		cout << ex << endl;
		return -1;
	}
	catch (...) {
		cout << "Unknown error" << endl;
		return -2;
	}
}
