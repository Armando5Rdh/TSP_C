#include "operaciones.h"
#include "GA.h"

void GA(int maxit, int popsize, float mutrate, float selection, int Nt) {

	int keep = (selection * popsize);
	float mincost = -9999999;
	//vector<vector<int>> pop = Arreglo(popsize, Nt);

	vector<vector<int>> pop = { {0,1,2,3,4},{4,2,1,3,0},{0,3,4,1,2},{3,2,4,1,0},{4,1,0,3,2},{4,3,2,0,1},{2,4,0,1,3} };
	vector<vector<float>> distancias = { {0, 10, 20, 30, 40}, {10, 0, 15, 25, 35}, {20, 15, 0, 14, 22}, {30, 25, 14, 0, 16}, {40, 35, 22, 16, 0} };
	vector<float> costos = FCostos(pop, distancias);
	Acomodar(pop, costos);

	vector<float> minC;
	vector<float> meanC;

	minC.push_back(costos[0]);
	meanC.push_back(CalcularPromedio(costos));

	int iga = 0;
	
	while (iga < maxit) {
		iga++;
		int M = ceil((popsize - keep) / 2);
		
		double sum = 0;
		int a = popsize / 2;
		vector<double> prob;

		for (int i = 1; i < a + 1; i++) {
			prob.push_back(i);
			sum += prob[i - 1];
			
		}
		

		for (int i = 0; i < prob.size(); i++) {
			prob[i] = prob[i] / sum;
		}
		
		reverse(prob.begin(), prob.end());
		vector<double> odds = { 0 };
		double b = 0;

		for (double value : prob) {
			b += value;
			odds.push_back(b);
		}
		
		vector<double> pick1(M);
		vector<double> pick2(M);

		pick1 = { 0.56365, 0.0016474 };
		pick2 = { 0.963219, 0.965783 };

		random_device rd;
		mt19937 gen(rd());
		uniform_real_distribution<double> distribution(0.0, 1.0);
		/*for (int i = 0; i < M; i++) {
			pick1[i] = distribution(gen);
			pick2[i] = distribution(gen);
		}*/

		for (int i = 0; i < pick1.size(); i++) {
			cout << pick1[i] << endl << pick2[i] << "\n\n";
		}

		int ic = 0;
		vector<int> ma, pa;

		while (ic < M) {
			for (int id = 1; id <= keep; id++) {

				if (pick1[ic] <= odds[id] && pick1[ic] > odds[id - 1]) {
					ma.push_back(id - 1);
				}
				if (pick2[ic] <= odds[id] and pick2[ic] > odds[id - 1]) {
					pa.push_back(id - 1);
				}
			}
			ic += 1;
		}

		for (int element : ma) {
			cout << element<< "  ";
		}
		cout << endl;
		for (int element : pa) {
			cout << element << "  ";
		}
	}

	
	
}