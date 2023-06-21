//Alejandro Magarzo Gonzalo c82


#include <fstream>
#include <vector>
#include <iostream>


using namespace std;


/*
Coste lineal respecto a n, número de elementos del vector, O(n).

P: 0 < n <= long(v)
func atletismo (vector v, int n) return int sol
Q: sol = (max p,q: 0 <= p < q < n && maximo(v,0,p,p) && (maximo(v,p,q,q) || q == n): q - p)
maximo(v,x,y,posmax): forall u: x<= u <= y: v[posmax] > v[u]

*/

int atletismo(std::vector<int> const & v, int n) {
	int sol = 0, i = 0, max = 0, soltmp = 0;
	while (i < n) {
		if (v[i] > max) {
			max = v[i];
			if (soltmp > sol) sol = soltmp;
			soltmp = 0;
		}
		else {
			soltmp++;
		}
		if (soltmp > sol) sol = soltmp;
		i++;
		// Función de cota: T: n-i
		// I: soltmp = (max p,q: 0 <= p < q <= i && maximo(v,0,p,p) && (maximo(v,p,q,q) || q == n): q - p) && 
		// (forall u: 0 <= u <= i: max >= v[u]) && 0 <= i <= n
	}
	return sol;
}


void resuelveCaso() {
	int n;
	cin >> n;
	std::vector <int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	
	int x; bool b = false;
	int sol = atletismo(v, n);
	cout << sol << endl;

}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int numCasos = 0;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}