#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;

vector<vector<int>> Arreglo(int popsize, int Nt) {

	vector<vector<int>> Pop;

	for (int i = 0; i < popsize; i++) {
		Pop.push_back(vector<int> (Nt+1));

		for (int j = 0; j <= Nt; j++) {

			Pop[i][j] = j;

		}
		unsigned seed = chrono::system_clock::now().time_since_epoch().count();
		shuffle(Pop[i].begin(), Pop[i].end(), default_random_engine(seed));
	}
	return Pop;
}


int main() {

	int popsize = 3;
	int Nt = 5;

	vector<vector<int>> Pop = Arreglo(popsize, Nt);

	for (int i = 0; i < popsize; ++i) {
		for (int j = 0; j <= Nt; ++j) {
			cout << Pop[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}