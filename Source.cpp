#include <iostream>
#include "operaciones.h"
#include "GA.h"

int main() {

	int popsize = 7;
	int Nt = 4;

	GA(1, 7, .1, .5, 4);
	
	/*// poblacion de enteros, sin repetir
	vector<vector<int>> pop = Arreglo(popsize, Nt);

	// Matriz provisional para pruebas
	vector<vector<float>> distancias = { {0, 10, 20, 30, 40}, {10, 0, 15, 25, 35}, {20, 15, 0, 14, 22}, {30, 25, 14, 0, 16}, {40, 35, 22, 16, 0} };

	// Calculo de costos
	vector<float> costos = FCostos(pop, distancias);

	//Impresion antes de acomodar por costos
	for (int i = 0; i < pop.size() ; i++) {

		for (int j = 0; j < pop[i].size() ; j++) {
			cout << pop[i][j] << " ";
		}
		cout << endl;
		cout << "Costo arreglo " << i + 1 << ": " << costos[i] << "\n\n";
	}

	Acomodar(pop, costos);

	cout << "------------------------------\n";
	//Impresion despues de acomodar por costos
	for (int i = 0; i < pop.size(); i++) {

		for (int j = 0; j < pop[i].size(); j++) {
			cout << pop[i][j] << " ";
		}
		cout << endl;
		cout << "Costo arreglo " << i + 1 << ": " << costos[i] << "\n\n";
	}*/

	return 0;
}