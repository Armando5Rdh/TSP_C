#include <iostream>
#include "operaciones.h"
#include "GA.h"
#include "maps.h"

int main() {

	int Nt = 23;
	int maxit = 1000;
	int	popzise = 200;
	float	mutrate = 0.1;
	float	selection = 0.5;
	string archivo = "Distancias_Republica.csv";

	auto start = high_resolution_clock::now();
	GA(maxit, popzise, mutrate, selection, Nt, archivo);
	auto stop = high_resolution_clock::now();

	auto duracion = duration_cast<seconds>(stop - start);
	printf("\nTiempo de ejecucion GA: %d segundos\n", duracion.count());

	return 0;
}