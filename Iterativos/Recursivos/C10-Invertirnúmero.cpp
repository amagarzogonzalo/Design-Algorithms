// Alejandro Magarzo Gonzalo c82

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int invertir(int c) {
	if (c <= 0) {
		return 0;
	}
	else {
		int x, tmp = c, cifrasn = 0;;
		while (tmp > 0) {
			tmp = tmp / 10;
			cifrasn++;
		}
		x = c % 10;
		x = x * pow(10, cifrasn - 1);
		return x + invertir(c / 10);
	}
}


bool resuelveCaso() {
	int c;
	cin >> c;
	if (!std::cin || c == 0)
		return false;
	int res = invertir(c);
	cout << res << endl;
	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}