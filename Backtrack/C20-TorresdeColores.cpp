// Alejandro Magarzo, C82

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

const int colores = 3;

bool esValido(std::vector<int> &tupla, int k, std::vector<int> & cont) {
	if (tupla[k] == 2 && tupla[k - 1] == 2) return false; // dos verdes seguidas
	if (cont[0] == 0 && cont[2] == 0) return true; // si nh hay verdes ni azules
	else return cont[0] >= cont[2]; // azules mas que verdes
}

void tratarsolucion(std::vector<int> &tupla) {
	for (int j = 0; j < tupla.size(); j++) {
		if (tupla[j] == 0) cout << "azul ";
		else if (tupla[j] == 1) cout << "rojo ";
		else cout << "verde ";
	}
	cout << endl; 
}

void vueltaatras(std::vector<int> &tupla, int k, int altura, int a, int r, int v, std::vector<int> & cont, bool &ok) {
	for (int i = 0; i < colores; i++) {
		tupla[k] = i;
		cont[i]++;
		bool fichasnec = true;
		if (cont[0] > a || cont[1] > r || cont[2] > v) fichasnec = false;
		if (esValido(tupla, k, cont) && fichasnec) {
			if (k == (altura - 1)) {
				if (cont[1] > (cont[0] + cont[2])) {
					ok = true;
					tratarsolucion(tupla);
				}
			}
			else {
				vueltaatras(tupla, k + 1, altura, a, r, v, cont, ok);
			}
		}
		cont[i]--;
	}
}



bool resuelveCaso() {
	int altura, a, r, v;
	cin >> altura >> a >> r >> v;
	//Leer caso de prueba: cin>>...
	// AZUL -> 0, ROJO -> 1, VERDE -> 2
	if (altura == 0 && a == 0 && r == 0 && v == 0)
		return false;
	std::vector<int> tupla(altura);
	int k = 1; bool ok = false;
	tupla[0] = 1;
	std::vector<int> cont(colores); 
	cont[0] = 0; cont[1] = 1; cont[2] = 0;
	vueltaatras(tupla, k, altura, a, r, v, cont, ok);
	if (!ok) cout << "SIN SOLUCION" << endl; 
	cout << endl;

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