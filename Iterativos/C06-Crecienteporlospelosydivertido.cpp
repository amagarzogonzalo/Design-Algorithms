//Alejandro Magarzo Gonzalo, C82

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool crec(std::vector<int> const &v, int n, int d) {
	std::vector<int> marc(100);
	for (int j = 0; j < 100; j++) marc[j] = 0;
	bool b = true;
	int i = 0;
	while (i < n - 1) {
		marc[v[i]]++;
		if (i == n - 2) marc[v[i + 1]]++;
		if (marc[v[i]] > d || marc[v[i + 1]] > d) b = false;

		if (v[i] + 1 == v[i + 1] || v[i] == v[i + 1]);
		else b = false;
		
		i++;
		// Función de cota: T: n-1-i
		// I:  b = ( (forall u: 0 <= u <= i+1: v[u] == v[u+1] || v[u]+1 == v[u+1]) && (d > (maxt: 0 <= t <= i+1: (#w: 0 <= w <= i+1: v[w]))) )
	}
	return b;
}


/*
Coste Lineal respecto tamaño vector, O(n).
P: long(v) = n && 0 <= n < 1000
func crec(vector v, int n, int d) return bool b
Q: b = ( (forall u: 0 <= u < n-1: v[u] == v[u+1] || v[u]+1 == v[u+1]) && (d > (maxt: 0 <= t < n: (#w: 0 <= w < n: v[w]))) )
*/

void resuelveCaso() {
	int n, d;
	cin >> d >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	bool b = crec(v, n, d);
	if (b) cout << "SI" << endl;
	else cout << "NO" << endl;
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