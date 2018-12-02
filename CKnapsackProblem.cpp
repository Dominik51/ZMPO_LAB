#include "CKnapsackProblem.h"

CKnapsackProblem::CKnapsackProblem()
{
}

bool CKnapsackProblem::bSetDCapacity(double d_capacity)
{
	if (d_capacity > 0)
	{
		dCapacity = d_capacity;
		return true;
	}
	else
	{
		return false;
	}
}

bool CKnapsackProblem::bSetVItemsSize(vector<double> *v_items_size)
{
	if (v_items_size != nullptr)
	{
		vItemsSize = v_items_size;
		return true;
	}
	else
	{
		return false;
	}

}

bool CKnapsackProblem::bSetVItemsValue(vector<double>* v_items_value)
{
	if (v_items_value != nullptr)
	{
		vItemsValue = v_items_value;
		return true;
	}
	else
	{
		return false;
	}
}

double CKnapsackProblem::dGetAdaptation(vector <int> v_genotype)
{
	double dValue = 0;
	double dSize = 0;
	for (int i = 0; i < v_genotype.size(); i++)
	{
		if (v_genotype.at(i) == 1)
		{
			dValue += vItemsSize->at(i);
			dSize += vItemsValue->at(i);
		}
	}
	return dSize <= dCapacity ? dValue : 0;
}

int CKnapsackProblem::iGetNumberOfItems()
{
	return vItemsSize->size();
}
