#include<iostream>
#include "CGeneticAlgorithm.h"
using namespace std;

int main()
{
	CKnapsackProblem ckp;
	ckp.bSetDCapacity(500);
	
	vector<double> ItemsValue;
	ItemsValue.push_back(100);
	ItemsValue.push_back(100);
	ItemsValue.push_back(100);
	ItemsValue.push_back(100);
	ItemsValue.push_back(100);

	vector<double> ItemsWeight;
	ItemsWeight.push_back(20);
	ItemsWeight.push_back(20);
	ItemsWeight.push_back(20);
	ItemsWeight.push_back(20);
	ItemsWeight.push_back(20);

	for (int i = 0; i < 100; i++)
	{
		ItemsValue.push_back(1);
		ItemsWeight.push_back(1);
	}

	ckp.bSetItems(105, &ItemsValue, &ItemsWeight);
	CGeneticAlgorithm cga;

	cga.vSetCKnapsackProblem(&ckp);
	cga.bSetIPopulationSize(100);
	cga.bSetDCrossoverChance(0.4);
	cga.bSetDMutationChance(0.5);
	cga.bSetIIterationsToStop(100);

	cga.vRun();

	vector<int> best = cga.vGetBestSolution();

	for (int i = 0; i < best.size(); i++)
	{
		cout << best.at(i) << ", ";
	}

	cout << "END" << endl;
	int a;
	cin >> a;
}