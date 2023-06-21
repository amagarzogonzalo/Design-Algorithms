// Alejandro Magarzo Gonzalo, C82
#include <iostream>

#include <fstream>
using namespace std;

int unos(int num, int pot, int acum) {
	int modulo = num % 10;
	if (num < 10) {
		if (modulo == 1) return pot;
		if (!modulo) return acum;
		else return acum + (--modulo) * pot;
	}
	else {
		if (modulo == 1) return unos(num / 10, pot * 9, modulo * pot);
		else if (!modulo) return unos(num / 10, pot * 9, acum);
		else return unos(num / 10, pot * 9, acum + (--modulo) * pot);
	}
}

bool resuelveCaso() {
	int num;
	cin >> num;
	if (!std::cin)
		return false;
	cout << unos(num, 1, 1) << endl;

	//Resolver problema
	//Escribir resultado
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