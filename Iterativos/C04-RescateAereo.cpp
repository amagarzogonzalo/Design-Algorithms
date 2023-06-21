//Alejandro Magarzo Gonzalo, c82


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void resc(std::vector <int> const & v, int n, int t, int &q, int & p) {
	int j = n - 1, longtmp = 0, longmax = 0;
	while (j >= 0) {
		if (v[j] > t) {
			longtmp++;
		}
		else longtmp = 0;

		if (longtmp >= longmax) {
			longmax = longtmp;
			q = j;
			p = q + longmax - 1;
		}
		j--;
		// Función de cota: T : j
		// I: longmax = (max p,q: j <= p < q < n && v[q] > t && v[p] > t: p-q) && -1 <= j <= n-1

	}
}

/*
Coste lineal respecto a n, tamaño de vector, O(n).

P: long(v) = n
proc resc (in vector v, in int n, int t, inout int q, out int p)
Q: longmax = (max p,q: 0 <= p < q < n && crec(v,p,q,t): p-q)
crec(v,p,q,t): forall u: p <= u <= q: v[u] > t
*/

void resuelveCaso() {
	int n, t;
	cin >> n >> t;
	std::vector <int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int q, p;
	resc(v, n, t, q, p);
	cout << q << " " << p << endl;

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