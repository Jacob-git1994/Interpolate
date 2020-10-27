#pragma once

#include <map>

#include "DimOneGrid.h"
#include "DimOneRange.h"
#include "GridIF.h"

using std::map;

namespace intp
{
	class LineIF
	{
	public:
		
		//Default Constructor
		inline LineIF() = default;

		//Virtual default destructor
		virtual inline ~LineIF() = default;

		//Add pair of grids to One Dim Line
		virtual void addGridPair(const DimOneGrid<double>&, const DimOneRange<double>&) = 0;

		//Get the Grid and Value Pair that can be interpolated for a One Dim Line
		virtual const bool getPair(const double&, DimOneGrid<double>&, DimOneRange<double>&, bool) const = 0;

		//Get the map to analysis
		virtual const map<DimOneGrid<double>, DimOneRange<double>, DimOneGrid<double>::GridCompare>& getLinearMap() const = 0;

		//Todo: Add Virtual methods for the other dimentions to be derrived in each class (i.e. dim one will throw if using dim 2 method)
	};
}
