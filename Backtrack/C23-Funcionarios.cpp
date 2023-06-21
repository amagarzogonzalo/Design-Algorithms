// Alejandro Magarzo Gonzalo, C82

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


void asignaciones(std::vector<std::vector<int>> const& funcionarios, int k, int n, int& cost, int &costmejor, std::vector<int>& tuplasol, 
	std::vector<int>& tuplasolmejor, std::vector<bool>& trabajosasig, std::vector<int> const &sumaRapido) {
	for (int i = 0; i < n; i++) {
		if (!trabajosasig[i]) {
			tuplasol[k] = i;
			cost = cost + funcionarios[k][i];
			trabajosasig[i] = true;
			int costestimado = cost + sumaRapido[k];
			if (costestimado < costmejor || costmejor == 0) { // es valido
				if (k == n - 1) { // es solucion
					if (costmejor == 0 || cost < costmejor) {
						costmejor = cost;
						tuplasolmejor = tuplasol;
					}
				}
				else {
					asignaciones(funcionarios, k + 1, n, cost, costmejor, tuplasol, tuplasolmejor, trabajosasig, sumaRapido);
				}
			}
			cost = cost - funcionarios[k][i];
			trabajosasig[i] = false;
		}
	}
}

void preCalculoEst(int n, vector < vector <int > > const & funcionarios,
	vector <int > & sumaRapido) {
	// minimo de cada fila
	vector <int > rapido(n);
	for (int i = 0; i < n; ++i) {
		rapido[i] = funcionarios[i][0];
		for (int j = 1; j < n; ++j) {
			if (funcionarios[i][j] < rapido[i]) rapido[i] = funcionarios[i][j];
		}
	}
	// calculo de las estimaciones
	sumaRapido[n - 1] = 0;
	for (int i = n - 2; i >= 0; --i) {
		sumaRapido[i] = sumaRapido[i + 1] + rapido[i + 1];
	}
}

bool resuelveCaso() {
	int n, a;
	cin >> n;
	//Leer caso de prueba: cin>>...

	if (n == 0 || !std::cin)
		return false;

	std::vector<int> trabajos(n), tuplasol(n), tuplasolmejor(n), sumaRapido(n);
	std::vector<bool> trabajosasig(n);
	std::vector<std::vector<int>> funcionarios(n);
	int cost = 0, costmejor = 0, k = 0;
	bool m = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			trabajos[j] = a;
		}
		funcionarios[i] = trabajos;
	}
	preCalculoEst(n, funcionarios, sumaRapido);
	asignaciones(funcionarios, k, n, cost, costmejor, tuplasol, tuplasolmejor, trabajosasig, sumaRapido);
	cout << costmejor << endl;
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