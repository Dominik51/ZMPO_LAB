#pragma once
#include<vector>
using namespace std;

class CKnapsackProblem
{
public:
	CKnapsackProblem();
	bool bSetDCapacity(double d_capacity);
	bool vSetVItemsSize(vector<double> *v_items_size);
	bool vSetVItemsValue(vector<double> *v_items_value);

private:
	double dCapacity;
	vector<double> *vItemsSize;
	vector<double> *vItemsValue;
};