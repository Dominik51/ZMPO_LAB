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

bool CKnapsackProblem::bSetItems(int i_number_of_items, vector<double>* v_items_value, vector<double>* v_items_size)
{
	if (v_items_size != nullptr && v_items_value != nullptr)
	{
		if (i_number_of_items > 0 && i_number_of_items == v_items_size->size() && i_number_of_items == v_items_value->size())
		{
			iNumberOfItems = i_number_of_items;
			vItemsValue = v_items_value;
			vItemsSize = v_items_size;
			return true;
		}
	}
	return false;
}

double CKnapsackProblem::dGetFintess(vector <int> v_genotype)
{
	double dValue = 0;
	double dSize = 0;
	for (int i = 0; i < v_genotype.size(); i++)
	{
		if (v_genotype.at(i) == 1)
		{
			dValue += vItemsValue->at(i);
			dSize += vItemsSize->at(i);
		}
	}
	return dSize <= dCapacity ? dValue : 0;
}

int CKnapsackProblem::iGetNumberOfItems()
{
	return iNumberOfItems;
}
