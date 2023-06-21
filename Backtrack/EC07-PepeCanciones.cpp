// NOMBRE Y APELLIDOS

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


struct tCancion{
	int punt;
	int dur;
};


 
void backtrack(std::vector<tCancion> const &v, int duracioncara, int n, int k, std::vector<int> &tupla_sol,
	int &puntuacion, int&puntestimada, int& puntmejor, int &duracionA, int &duracionB, std::vector<int> const & puntosAsignar, bool &hays){
	duracionA += v[k].dur;
	puntuacion += v[k].punt;
	if (duracionA <= duracioncara) {
		if (k + 1 == n) {
			if (puntmejor < puntuacion) puntmejor = puntuacion;
		}
		else if (!hays ||puntuacion + puntosAsignar[k] > puntmejor) backtrack(v, duracioncara, n, k + 1, tupla_sol, puntuacion, puntestimada, puntmejor, duracionA, duracionB, puntosAsignar, hays);
	}
	duracionA -= v[k].dur;
	puntuacion -= v[k].punt;

	duracionB += v[k].dur;
	puntuacion += v[k].punt;

	if (duracionB <= duracioncara) {
		if (k + 1 == n) {
			if (puntmejor < puntuacion) puntmejor = puntuacion;
		}
		else if (!hays || puntuacion + puntosAsignar[k] > puntmejor) backtrack(v, duracioncara, n, k + 1, tupla_sol, puntuacion, puntestimada, puntmejor, duracionA, duracionB, puntosAsignar, hays);
	}
	duracionB -= v[k].dur;
	puntuacion -= v[k].punt;

	if (k+1 == n) {
		hays = true;
		if (puntmejor < puntuacion) puntmejor = puntuacion;
	}
	else if (!hays || puntuacion + puntosAsignar[k] > puntmejor) backtrack(v, duracioncara, n, k + 1, tupla_sol, puntuacion, puntestimada, puntmejor, duracionA, duracionB, puntosAsignar, hays);
}


bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;

	int duracioncara, puntuacion = 0, puntestimada = 0, puntmejor = 0, k = 0, duracionA = 0, duracionB = 0;
	cin >> duracioncara;
	std::vector<tCancion> v(n);
	std::vector<int> tupla_sol(n), puntosAsignar(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].dur >> v[i].punt;
	}
	for (int i = 0; i < n; i++) {
		int suma = 0; 
		for (int j = n - 1; j > i; j--) {
			suma += v[j].punt;
		}
		puntosAsignar[i] = suma;
	}

	bool hays = false;
	backtrack(v, duracioncara, n, k, tupla_sol, puntuacion, puntestimada, puntmejor, duracionA, duracionB, puntosAsignar, hays);

	cout << puntmejor << endl;
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