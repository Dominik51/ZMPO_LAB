#pragma once
#include<vector>
using namespace std;

class CKnapsackProblem
{
public:
	CKnapsackProblem();

private:
	double dCapacity;
	vector<double> vItemsSize;
	vector<double> vItemsValue;
};