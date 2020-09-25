#include "DimOneGrid.h"
#include "DimOneRange.h"
#include "GridIF.h"


using namespace intp;

#include <iostream>
#include <map>

using std::map;

int main()
{
	map<DimOneGrid<double>, int> mp;

	for (int i = 1; i <= 10; ++i)
	{
		mp.emplace(DimOneGrid<double>(i*5,i*10), i);
	}

	for (auto& el : mp)
	{
		std::cout << el.first.distance() << "\n";
	}
}

