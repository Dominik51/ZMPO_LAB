#pragma once
#include<vector>
using namespace std;

class CKnapsackProblem
{
public:
	CKnapsackProblem();
	bool bSetDCapacity(double d_capacity);
	bool bSetItems(int i_number_of_items, vector<double> *v_items_value, vector<double> *v_items_size);
	double dGetFintess(vector <int> v_genotype);
	int iGetNumberOfItems();
private:
	double dCapacity;
	int iNumberOfItems;
	vector<double> *vItemsSize;
	vector<double> *vItemsValue;
};