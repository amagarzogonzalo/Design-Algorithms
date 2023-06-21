//Alejandro Magarzo Gonzalo, c82


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int seg(int n, std::vector<int> const& v) {
	int x = 0, i = 0, xtmp = 1;
	bool b = false;
	while (i < n - 1) {
		if (v[i] < v[i + 1]) {
			if (b) xtmp = 2;
			else xtmp++;
			b = true;
		}
		else {
			xtmp++;
			b = false;
		}
		if (xtmp > x) x = xtmp;
		i++;
	}
	return x;
}

// Cota: T: n-1-i
// I: x = (max p,q: 0 <= p < q <= i+1 && nohayseg(v,p,q): q - p) && 0 <= i <= n-1 
// nohayseg(v, p, q) = (exists u : p <= u <= q - 2 : v[u] < v[u + 1] && v[u + 1] < v[u + 2]) = false


/*
P: 0 <= long(v) <= n
func seg (int n, vector v) return int x
Q: x = (max p,q: 0 <= p < q < n && nohayseg(v,p,q): q - p)
nohayseg(v,p,q) = (exists u: p <= u <= q-2: v[u] < v[u+1] && v[u+1] < v[u+2]) = false

nohayseg(v,p,q) = (p - q) < 3 || (existe u, z, w: p <= u < z < w <= q - 1: v[u] < v[z] < v[w])

El coste es lineal respecto al numero de elementos del vector, n, por lo tanto se puede afirmar que el coste
del vector es lineal, O(n). El bucle se recorre n-1 veces siempre que n sea mayor que 2, en caso de que sea 
menor igual que 2, el coste es constante, O(1).
*/

void resuelveCaso() {
	int n;
	cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (n <= 2) cout << n << endl;
	else cout << seg(n, v) << endl;
	
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