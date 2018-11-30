#include<iostream>
#include "CGeneticAlgorithm.h"
using namespace std;

int main()
{
	CKnapsackProblem ckp;
	ckp.bSetDCapacity(30);
	
	vector<double> ItemsValue;
	ItemsValue.push_back(1);
	ItemsValue.push_back(2);
	ItemsValue.push_back(3);
	ItemsValue.push_back(4);
	ItemsValue.push_back(5);
	ItemsValue.push_back(6);
	ItemsValue.push_back(7);
	ItemsValue.push_back(8);
	ItemsValue.push_back(9);
	ItemsValue.push_back(10);
	ItemsValue.push_back(1);
	ItemsValue.push_back(2);
	ItemsValue.push_back(3);
	ItemsValue.push_back(4);
	ItemsValue.push_back(5);
	ItemsValue.push_back(6);
	ItemsValue.push_back(7);
	ItemsValue.push_back(8);
	ItemsValue.push_back(9);
	ItemsValue.push_back(50);

	vector<double> ItemsWeight;
	ItemsWeight.push_back(2);
	ItemsWeight.push_back(4);
	ItemsWeight.push_back(4);
	ItemsWeight.push_back(3);
	ItemsWeight.push_back(5);
	ItemsWeight.push_back(8);
	ItemsWeight.push_back(7);
	ItemsWeight.push_back(9);
	ItemsWeight.push_back(10);
	ItemsWeight.push_back(10);
	ItemsWeight.push_back(2);
	ItemsWeight.push_back(3);
	ItemsWeight.push_back(4);
	ItemsWeight.push_back(5);
	ItemsWeight.push_back(6);
	ItemsWeight.push_back(7);
	ItemsWeight.push_back(8);
	ItemsWeight.push_back(9);
	ItemsWeight.push_back(10);
	ItemsWeight.push_back(29);

	ckp.bSetVItemsValue(&ItemsValue);
	ckp.bSetVItemsSize(&ItemsWeight);

	CGeneticAlgorithm cga;

	cga.vSetCKnapsackProblem(&ckp);
	cga.bSetIPopulationSize(12);
	cga.bSetDCrossoverChance(0.4);
	cga.bSetDMutationChance(0.5);
	cga.bSIIterationsToStop(5000);

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