//Alejandro Magarzo Gonzalo, c82
 

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void backtrack(int precios[20][20], int k, int m, int n, std::vector<int> & productosxmercado, std::vector<int> & sol,int &coste, int &costemejor) {
	for (int i = 0; i < m; i++) { // supermercados
		productosxmercado[i]++;
		if (productosxmercado[i] <= 3) {
			coste += precios[i][k];
			sol[k] = precios[i][k];
			if (k == n-1) {
				//cout << coste << " ----" << endl;
				if (costemejor == -1) costemejor = coste;
				if (costemejor >= coste) costemejor = coste;
			}
			else {
				backtrack(precios, k + 1, m, n, productosxmercado, sol, coste, costemejor);
			}
			coste -= precios[i][k];
		}
		productosxmercado[i]--;
	}
}


void resuelveCaso() {
	int mercados, nproductos, a;
	cin >> mercados >> nproductos;
	std::vector <int> productosxmercado(mercados), sol(nproductos); // 3 prod por supermercado
	int precios[20][20]; // [mercados][nproductos]
	for (int i = 0; i < mercados; i++) {
		for (int j = 0; j < nproductos; j++) {
			cin >> a;
			precios[i][j] = a;
		}
	}
	for (int i = 0; i < mercados; i++) productosxmercado[i] = 0;
	int coste = 0, costemejor = -1;
	backtrack(precios, 0, mercados, nproductos, productosxmercado, sol, coste, costemejor);
	cout << costemejor << endl;
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