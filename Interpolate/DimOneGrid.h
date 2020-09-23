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
	class DimOneGrid : public GridIF
	{
	private:

		//Begining Grid Point for a 1D Grid
		double x0;

		//End Grid Point for a 1D Grid
		double x1;

		//Check if inputs are valid
		virtual void validInputs() const override;

	public:

		//Default Constructor
		DimOneGrid();

		//Constructor the Grid
		DimOneGrid(double, double);

		//Copy Constructor
		DimOneGrid(const DimOneGrid&);

		//Grid Assign Constructor
		const DimOneGrid& operator=(const DimOneGrid&);

		//Virtual Default Destructor
		virtual ~DimOneGrid() = default;

		//Initalize the Grid
		const DimOneGrid& initalize(double, double);

		//Impliment Operator <=
		bool operator<=(const DimOneGrid&) const;

		//Impliment Operator >=
		bool operator>=(const DimOneGrid&) const;

		//Impliment Operator <
		bool operator<(const DimOneGrid&) const;

		//Impliment Operator >
		bool operator>(const DimOneGrid&) const;

		//Impliment Size Method from Base Class
		virtual double size() const override;
	};

}
