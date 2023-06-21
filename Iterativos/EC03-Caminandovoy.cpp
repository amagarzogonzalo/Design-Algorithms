// Alejandro Magarzo Gonzalo, c82

#include <iostream>
#include <vector> 
#include <fstream>
using namespace std;

/*
Coste: Coste lineal respecto a numero de elmentos n, O(n)

P: 1 <= n <= longitud(v) < 100000 && 1 <= d <= 200000 && forall u:0 <= u < n: 0 <= v[u] <= 1000000
func apto(vector v, int n, int d) return bool b
Q: b = (d > (max u,w: 0 <= u < w < n && v[u] < v[w]: v[w] - v[u]))


*/

bool apto(std::vector<int> const & v, int n, int d) {
	bool b = true, carriba = false;
	int min = 0, max;
	int i = 0;
	while (i < n-1 && b) {
		if (v[i] < v[i + 1]) {
			if (!carriba) {
				carriba = true;
				min = v[i];
			}
			if ((v[i] - min) > d) b = false;
		}
		else {
			if (carriba && (v[i] - min) > d) b = false;
			if (carriba) carriba = false;
		}
		i++;
		// Función de Cota: T: n-1-i
		// I: 0 <= i <= n-1 && b = (d > (max u,w: 0 <= u < w <= i && v[u] < v[w]: v[w] - v[u])) && 
		// (forall u, w: u < w <= i && v[u] < v[w]: min <= v[w])
	}
	if (carriba && (v[n-1] - min) > d) b = false;
	return b;
}


bool resuelveCaso() {
	int n, d;
	cin >> d;
	if (!std::cin)
		return false;
	cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	bool b = apto(v, n, d);
	if (b) cout << "APTA" << endl;
	else cout << "NO APTA" << endl;
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