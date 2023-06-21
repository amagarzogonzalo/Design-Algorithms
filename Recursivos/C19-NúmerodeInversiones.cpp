//Alejandro Magarzo Gonzalo, C82


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


/*
*/


long long int inv(std::vector <int> &v, int ini, int fin, int n) {
	if (ini == fin - 1) {
		return 0;
	}
	else {		
		int m = (ini + fin - 1) / 2;
		int i = ini, j = m + 1;
		long long int x = 0;
		long long int izq = inv(v, ini, m + 1, n);
		long long int der = inv(v, m + 1, fin, n);

		while (i < m + 1 && j < fin) {
			if (v[i] > v[j]) {
				x += (m - i + 1);
				++j;
			}
			else ++i;
		}

		std::sort(v.begin() + ini, v.end() + fin); // biblioteca algorithm

		return x + izq + der;
	}
}


void resuelveCaso() {
	int n;
	cin >> n;
	std::vector<int> v(n);

	for (int i = 0; i < n; i++) cin >> v[i];
	long long int sol;
	if (n <= 1) sol = 0;
	else sol = inv(v, 0, n-1, n);
	cout << sol << endl;


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