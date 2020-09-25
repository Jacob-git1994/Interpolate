#pragma once
#include <exception>
#include <limits>
#include <cmath>
#include <stdexcept>

#include "GridIF.h"

using std::invalid_argument;
using std::numeric_limits;
using std::fabs;

namespace intp
{
	template<class dType>
	class DimOneGrid : public GridIF<dType>
	{
	private:

		//Begining Grid Point for a 1D Grid
		dType x0;

		//End Grid Point for a 1D Grid
		dType x1;

		//Check if inputs are valid
		virtual void validInputs() const override;

	public:

		//Default Constructor
		DimOneGrid();

		//Constructor the Grid
		DimOneGrid(const dType&, const dType&);

		//Copy Constructor
		DimOneGrid(const DimOneGrid<dType>&);

		//Grid Assign Constructor
		const DimOneGrid<dType>& operator=(const DimOneGrid<dType>&);

		//Virtual Default Destructor
		virtual ~DimOneGrid() = default;

		//Initalize the Grid
		const DimOneGrid& initalize(const dType&, const dType&);

		//Impliment Operator <=
		bool operator<=(const DimOneGrid<dType>&) const;

		//Impliment Operator >=
		bool operator>=(const DimOneGrid<dType>&) const;

		//Impliment Operator <
		bool operator<(const DimOneGrid<dType>&) const;

		//Impliment Operator >
		bool operator>(const DimOneGrid<dType>&) const;

		//Impliment Size Method from Base Class
		virtual dType distance() const override;
	};

}
