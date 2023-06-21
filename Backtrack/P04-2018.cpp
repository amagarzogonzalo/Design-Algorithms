//Alejandro Magarzo Gonzalo, C82

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void bt(int m, int n, std::vector<std::vector<int>> const& calidades, std::vector<int> const& amaq,
	std::vector<int> const& acarr, int k, int &ctmp, int &cmax, std::vector<bool> & climpia, bool &haysol, std::vector<int> const& cest) {
	for (int i = 0; i < n; i++) {
		if (!climpia[i] && amaq[k] <= acarr[i]) {
			climpia[i] = true;
			ctmp += calidades[k][i];
			if (!haysol || (cest[k] + ctmp) >= cmax){
				if (k == (m - 1)) {
					haysol = true;
					if (ctmp >= cmax) cmax = ctmp;
				}
				else bt(m, n, calidades, amaq, acarr, k + 1, ctmp, cmax, climpia, haysol, cest);
			}
			ctmp -= calidades[k][i];
			climpia[i] = false;
		}
	}
}

void resuelveCaso() {
	int m, n;
	cin >> m >> n;
	std::vector<int> amaq (m), acarr (n), mi(m), cest(m);
	std::vector<bool> climpia(n);
	std::vector<std::vector<int>> calidades(m);
	for (int i = 0; i < m; i++) cin >> amaq[i];
	for (int i = 0; i < n; i++) {
		cin >> acarr[i];
		climpia[i] = false;
	}
	for (int i = 0; i < m; i++) {
		int min = 0;
		std::vector<int> aux(n);
		for (int j = 0; j < n; j++) {
			cin >> aux[j];
			if (j == 0 || aux[j] > min) min = aux[j];
		}
		mi[i] = min;
		calidades[i] = aux;
	}

	for (int i = 0; i < m; i++) {
		int suma = 0;
		for (int j = m-1; j > i; j--) {
			suma += mi[j];
		}
		cest[i] = suma;
	}

	bool haysol = false;
	int k = 0, ctmp = 0, cmax = 0;
	if(m > 0) bt(m,n,calidades,amaq,acarr,k, ctmp,cmax, climpia, haysol, cest);
	cout << cmax << endl;


}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
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