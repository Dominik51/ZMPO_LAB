#include<iostream>
#include "CGeneticAlgorithm.h"
using namespace std;

int main()
{
	CKnapsackProblem ckp;
	ckp.bSetDCapacity(20);
	
	vector<double> ItemsValue;
	ItemsValue.push_back(2);
	ItemsValue.push_back(3);
	ItemsValue.push_back(4);
	ItemsValue.push_back(5);
	ItemsValue.push_back(5);
	ItemsValue.push_back(5);
	ItemsValue.push_back(6);
	ItemsValue.push_back(7);
	ItemsValue.push_back(8);
	ItemsValue.push_back(10);

	vector<double> ItemsWeight;
	ItemsWeight.push_back(1);
	ItemsWeight.push_back(2);
	ItemsWeight.push_back(2);
	ItemsWeight.push_back(3);
	ItemsWeight.push_back(4);
	ItemsWeight.push_back(7);
	ItemsWeight.push_back(10);
	ItemsWeight.push_back(4);
	ItemsWeight.push_back(5);
	ItemsWeight.push_back(7);


	ckp.bSetItems(10, &ItemsValue, &ItemsWeight);
	CGeneticAlgorithm cga;

	cga.vSetCKnapsackProblem(&ckp);
	cga.bSetIPopulationSize(20);
	cga.bSetDCrossoverChance(0.4);
	cga.bSetDMutationChance(0.5);
	cga.bSetIIterationsToStop(50);

	cga.vRun();

	vector<int> best = cga.vGetBestSolution();

	cout << "Genotyp: ";
	for (int i = 0; i < best.size(); i++)
	{
		cout << best.at(i);
	}
	cout << endl << "Wynik: " << ckp.dGetFintess(best);
	int a;
	cin >> a;
}