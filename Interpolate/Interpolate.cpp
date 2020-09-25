#include "DimOneGrid.h"
#include "GridIF.h"


using namespace intp;

#include <iostream>

int main()
{
	DimOneGrid<double> g;

	g.initalize(5, 10);

	std::cout << g.distance() << "\n";
}

