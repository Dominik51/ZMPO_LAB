#pragma once
#include<vector>
using namespace std;

class CKnapsackProblem
{
public:
	CKnapsackProblem();
	bool bSetDCapacity(double d_capacity);
	bool bSetVItemsSize(vector<double> *v_items_size);
	bool bSetVItemsValue(vector<double> *v_items_value);
	double dGetAdaptation(vector <int> v_genotype);
	int iGetNumberOfItems();
private:
	double dCapacity;
	vector<double> *vItemsSize;
	vector<double> *vItemsValue;
};