// Alejandro Magarzo Gonzalo, c82

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

int c(int a) {
	if (a <= 9) 
		return 9 - a;
	else
		return (9 - a%10) + c(a / 10) * 10;
}

int i(int a, int potencia, int p) {
	if (potencia == 0) {
		int e = pow(10, potencia-1), tmp = pow(10, potencia), num = ((a % tmp) * 10) / tmp;
		return num * e;
	}
	else {
		int e = pow(10, potencia - 1), tmp = pow(10, potencia), num = ((a % tmp) * 10) / tmp;
		return num * e + i(a, potencia - 1, p);
	}
}


void resuelveCaso() {
	int a, comp, inv  = 0, potencia= 1, comptmp,p;
	cin >> a;
	comp = c(a);
	cout << comp << " ";
	comptmp = comp;
	while (comptmp >= 10) {
		comptmp = comptmp / 10;
		potencia++;
	}
	p = potencia;
	inv = i(comp, potencia, p);
	cout << inv << endl;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}