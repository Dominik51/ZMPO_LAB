#include<iostream>
#include "CGeneticAlgorithm.h"
using namespace std;

int main()
{
	CKnapsackProblem ckp;
	ckp.bSetDCapacity(12);
	
	vector<double> ItemsValue;
	ItemsValue.push_back(1);
	ItemsValue.push_back(2);
	ItemsValue.push_back(3);
	ItemsValue.push_back(4);
	ItemsValue.push_back(5);

	vector<double> ItemsWeight;
	ItemsWeight.push_back(3);
	ItemsWeight.push_back(3);
	ItemsWeight.push_back(3);
	ItemsWeight.push_back(4);
	ItemsWeight.push_back(5);

	ckp.bSetVItemsValue(&ItemsValue);
	ckp.bSetVItemsSize(&ItemsWeight);

	CGeneticAlgorithm cga;

	cga.vSetCKnapsackProblem(&ckp);
	cga.bSetIPopulationSize(4);
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