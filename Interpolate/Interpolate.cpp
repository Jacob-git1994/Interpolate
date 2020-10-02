#include "DimOneGrid.h"
#include "DimOneRange.h"
#include "GridIF.h"


using namespace intp;

#include <iostream>
#include <list>
#include <map>

using std::list;
using std::map;

int main()
{
	list<DimOneGrid<double>> grids;

	for (int i = 0; i < 10; ++i)
	{
		grids.push_back(DimOneGrid<double>(i*i, i*i + 10));
		std::cout << i * i << "\t" << i * i + 10 << "\n";
	}

	DimOneGrid<double> check(5, 10);

	for (auto& el : grids)
	{
		std::cout << el.isIntersecting(check) << "\n";
	}

	std::cout << "\\n\n\n\n\n";

	auto comp = [](const DimOneGrid<double>& lhs, const DimOneGrid<double>& rhs)
	{
		std::cout << lhs.isIntersecting(rhs) << "\n";
		if (!lhs.isIntersecting(rhs))
		{
			return lhs.left() < rhs.left();
		}
		else
		{
			return lhs.right() < rhs.right();
		}
	};

	map<DimOneGrid<double>,int,DimOneGrid<double>::GridCompare> grids2;

	grids2.emplace(DimOneGrid<double>(10, 20),10);
	grids2.emplace(DimOneGrid<double>(40, 80), 10);
	grids2.emplace(DimOneGrid<double>(80, 100), 10);
	grids2.emplace(DimOneGrid<double>(100, 2000), 10);

	for (auto& el : grids2)
	{
		std::cout << el.first.left() << "\t" << el.first.right() << "\n";
	}
}

