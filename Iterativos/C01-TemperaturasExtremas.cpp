//Alejandro Magarzo Gonzalo, C82

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void temp(std::vector<int> const& v, int n, int &picos, int &valles) {
	int i = 0;
	while (i < n - 2) {
		if (v[i] < v[i + 1] && v[i + 2] < v[i + 1]) picos++;
		else if (v[i] > v[i + 1] && v[i + 2] > v[i + 1]) valles++;
		i++;
	}
	// I: picos = (#u: 0 <= u <= i+2: v[u+1] > v[u] && v[u+1] > v[u+2]) && valles = (#u: 0 <= u <= i+2: v[u+1] < v[u] && v[u+1] < v[u+2])
	// T: n-2 - i

}

/*
Coste: O(n) Coste lineal respecto al numero de elementos n.
P: 0 > n >= 10000
proc temp(vector v, int n, inout int picos, inout int valles)
Q: picos = (#u: 0 <= u < n - 2: v[u+1] > v[u] && v[u+1] > v[u+2]) && valles = (#u: 0 <= u < n - 2: v[u+1] < v[u] && v[u+1] < v[u+2])
*/


void resuelveCaso() {
	int n; 
	cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int picos = 0, valles = 0;
	if (n <= 2) cout << "0 0" << endl;
	else {
		temp(v, n, picos, valles);
		cout << picos << " " << valles << endl;
	}

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