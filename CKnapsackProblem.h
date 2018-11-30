#pragma once
#include<vector>
#include "CIndividual.h"
using namespace std;

class CKnapsackProblem
{
public:
	CKnapsackProblem();
	bool bSetDCapacity(double d_capacity);
	bool bSetVItemsSize(vector<double> *v_items_size);
	bool bSetVItemsValue(vector<double> *v_items_value);
	double dGetAdaptation(CIndividual c_individual);
	int iGetNumberOfItems();
private:
	double dCapacity;
	vector<double> *vItemsSize;
	vector<double> *vItemsValue;
};