//Alejandro Magarzo Gonzalo, c82


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void calculocosteestimado(int &costeestimado, const int precios[20][20], std::vector<int> const & productosxmercado,
	int n, int m, int k, int coste) {

	std::vector<int> aux(m);
	for (int i = 0; i < m; i++) aux[i] = productosxmercado[i];

	costeestimado = coste;
	for (int i = k+1 ; i < n; i++) {
		int minimoiprod = 0, d = 0;
		bool minimoencontrado = false;
		for (int j = 0; j < m; j++) {
			if (!minimoencontrado && aux[j] + 1 <= 3) {
				minimoencontrado = true;
				aux[j]++;
				d = j;
				minimoiprod = precios[j][i];
			}
			else if(aux[j] + 1 <= 3 && minimoiprod > precios[j][i] && minimoencontrado){
				minimoiprod = precios[j][i];
				aux[j]++;
				aux[d]--;
				d = j;
			}			
		}
		costeestimado += minimoiprod;
	}

}


void backtrack(const int precios[20][20], int k, int m, int n, std::vector<int> & productosxmercado, std::vector<int> & sol,
	int &coste, int &costemejor, int &costeestimado, bool & haysolucion){
	for (int i = 0; i < m; i++) { // supermercados
		if (productosxmercado[i]+1 <= 3) {
			productosxmercado[i]++;
			coste += precios[i][k];
			sol[k] = precios[i][k];
			calculocosteestimado(costeestimado, precios, productosxmercado, n, m, k, coste);
			if (!haysolucion || costeestimado <= costemejor) {
				if (k == n - 1) {
					if (costemejor == -1) costemejor = coste;
					if (costemejor >= coste) {
						costemejor = coste;
						haysolucion = true;
					}
				}
				else {
					backtrack(precios, k + 1, m, n, productosxmercado, sol, coste, costemejor, costeestimado, haysolucion);
				}
			}
			coste -= precios[i][k];
			productosxmercado[i]--;
		}
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
	int coste = 0, costemejor = -1, costeestimado = 0;
	bool haysolucion = false;
	backtrack(precios, 0, mercados, nproductos, productosxmercado, sol, coste, costemejor, costeestimado, haysolucion);
	if(haysolucion) cout << costemejor << endl;
	else cout << "Sin solucion factible" << endl;
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