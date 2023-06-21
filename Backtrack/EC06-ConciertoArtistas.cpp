//Alejandro Magarzo Gonzalo, c82

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


/* 
	-> Posibles podas optimización:
	- Sumar al beneficio actual el maximo de la matriz de donaciones multiplicado por el número de momentos que quedan por decidir.
	- Sumar al beneficio actual la suma de los máximos que se pueden conseguir en los momentos restantes (que en este caso son las columnas de la matriz).
	Estos valores de las sumas de los máximos se precalculan antes de la vuelta atrás en un vector para luego consultarlos de forma eficiente.

	-> Los marcadores que he utilizado son simplemente a través del uso del vector artistasasignados, este vector de booleanos
	de tamaño n se pone a true en una posición cuando el artista de esa posición esta asignado. 
*/

void backtrack(std::vector<std::vector<int>> const &donaciones, std::vector<std::vector<int>> const & vetos, int k, int n,
	int &coste, int &costemejor, std::vector <bool> & artistasasignados, bool &haysolucion, std::vector<int> &tuplasolucion,
	int &costeestimado, std::vector<int> const & sumaRapido) {
	for (int i = 0; i < n; i++) { // n artistas
		if (k == 0 || !artistasasignados[i] && vetos[i][tuplasolucion[k - 1]] == 1) { 
			artistasasignados[i] = true;
			coste += donaciones[i][k];
			tuplasolucion[k] = i;
			if (k == n - 1) { // es Solución
				if (!haysolucion) {
					costemejor = coste;
					haysolucion = true;
				}
				else if (coste > costemejor) costemejor = coste;
			}
			else { // vuelta Atras
				// Poda por optimización
				costeestimado = coste + sumaRapido[k];
				if (costeestimado > costemejor)
					backtrack(donaciones, vetos, k + 1, n, coste, costemejor, artistasasignados, haysolucion, tuplasolucion, costeestimado, sumaRapido);
			}
			
			coste -= donaciones[i][k];
			artistasasignados[i] = false;
		}
	}
}

void resuelveCaso() {
	int n;
	cin >> n;
	std::vector<std::vector<int>> donaciones(n), vetos(n);
	std::vector<bool> artistasasignados(n);
	std::vector<int> tuplasolucion(n), sumaRapido(n), maximos(n);
	
	

	for (int i = 0; i < n; i++) {
		artistasasignados[i] = false;
		std::vector<int> v(n);
		for (int j = 0; j < n; j++) {
			cin >> v[j];
			if (i == 0) maximos[j] = v[j];
			else if (v[j] > maximos[j]) maximos[j] = v[j]; 
			
		}
		donaciones[i] = v;
	}

	for (int i = 0; i < n; i++) {
		std::vector<int> v(n);
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		vetos[i] = v;

		int x = 0;
		for (int d = n - 1; d > i; d--) {
			x += maximos[d];
		}
		sumaRapido[i] = x;
	}
	bool haysolucion = false;
	int coste = 0, costemejor = 0, costeestimado = 0;
	backtrack(donaciones, vetos, 0, n, coste, costemejor, artistasasignados, haysolucion, tuplasolucion, costeestimado, sumaRapido);
	if (haysolucion) cout << costemejor << endl;
	else cout << "NEGOCIA CON LOS ARTISTAS" << endl;
	
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