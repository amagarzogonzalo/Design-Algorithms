// Alejandro Magarzo Gonzalo, C82

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


bool resolver(std::vector<int> const& v, int ini, int fin) {
	if (ini + 1 == fin) 
		return true;
	if (ini + 2 == fin) {
		return v[ini] <= v[fin - 1];
	}
	else {
		int m = (ini + fin) / 2;

		int sumaIz = 0;
		for (int i = ini; i < m; ++i)
			sumaIz += v[i];
		int sumaDr = 0;
		for (int i = m; i < fin; ++i)
			sumaDr += v[i];

		return (sumaIz <= sumaDr) && resolver(v, ini, m) && resolver(v, m, fin);
	}

}

bool resuelveCaso() {
	int fila, col;
	std::cin >> fila;

	if (!std::cin)
		return false;
	std::cin >> col;

	std::vector<int> v(col);

	bool sol = true;
	for (int i = 0; i < fila; ++i) {
		for (int i = 0; i < v.size(); ++i)
			std::cin >> v[i];

		sol = sol && resolver(v, 0, v.size());
	}

	if (sol) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 


	while (resuelveCaso());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}