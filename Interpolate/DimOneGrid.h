#pragma once
#include <exception>
#include <limits>
#include <cmath>
#include <stdexcept>

#include "GridIF.h"

using std::invalid_argument;
using std::runtime_error;
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
		virtual void validInputs() const;

	public:

		//Default Constructor
		inline DimOneGrid();

		//Constructor the Grid
		inline DimOneGrid(const dType&, const dType&);

		//Copy Constructor
		inline DimOneGrid(const DimOneGrid<dType>&);

		//Grid Assign Constructor
		inline const DimOneGrid<dType>& operator=(const DimOneGrid<dType>&);

		//Virtual Default Destructor
		inline virtual ~DimOneGrid() = default;

		//Initalize the Grid
		inline const DimOneGrid& initalize(const dType&, const dType&);

		//Impliment Size Method from Base Class
		inline virtual dType distance() const override;

		//Check if pair of Grids are Intersecting
		virtual inline bool isIntersecting(const DimOneGrid<dType>&) const;

		//Get the left grid point
		inline const dType& left() const;

		//Get the right grid point
		inline const dType& right() const;

		//Find if point is between the two other points
		inline bool isBetween(const dType&) const;

		//Comparison Class
		class GridCompare
		{
		public:

			//Compare operator
			virtual inline bool operator()(const DimOneGrid<dType>&, const DimOneGrid<dType>&) const;
		};

	};

	template<class dType>
	void DimOneGrid<dType>::validInputs() const
	{
		//Verify the values are ordered corrected and are not equivlent. 
		const bool check = (x0 > x1) || (fabs(x0 - x1) < numeric_limits<dType>::epsilon());
		if (check)
		{
			throw invalid_argument("Grid Not Implimented Correctly");
			exit(-1);
		}
		return;
	}

	template<class dType>
	DimOneGrid<dType>::DimOneGrid() :
		x0(static_cast<dType>(0.)),
		x1(static_cast<dType>(1.)),
		GridIF<dType>()
	{
		//Check if Inputs are valid
		validInputs();
	}

	template<class dType>
	DimOneGrid<dType>::DimOneGrid(
		const dType& x0In,
		const dType& x1In) :
		x0(x0In),
		x1(x1In),
		GridIF<dType>()
	{
		//Check if inputs are valid
		validInputs();
	}

	template<class dType>
	DimOneGrid<dType>::DimOneGrid(
		const DimOneGrid<dType>& gridIn) :
		x0(gridIn.x0),
		x1(gridIn.x1),
		GridIF<dType>()
	{
		//Check if Inputs are Valid
		validInputs();
	}

	template<class dType>
	const DimOneGrid<dType>& DimOneGrid<dType>::operator=(
		const DimOneGrid<dType>& gridIn)
	{
		//Copy the grid values based on input grid
		x0 = gridIn.x0;
		x1 = gridIn.x1;

		//Check if Inputs are valid
		validInputs();

		return *this;
	}

	template<class dType>
	const DimOneGrid<dType>& DimOneGrid<dType>::initalize(
		const dType& x0In,
		const dType& x1In)
	{
		//Copy values to form new grid
		x0 = x0In;
		x1 = x1In;

		//Check if Inputs are Valid
		validInputs();

		return *this;
	}

	template<class dType>
	dType DimOneGrid<dType>::distance() const
	{
		return static_cast<dType>(x1 - x0);
	}

	template<class dType>
	bool DimOneGrid<dType>::isIntersecting(const DimOneGrid<dType>& gridIn) const
	{
		return ((gridIn.x0 < x1) && (gridIn.x0 > x0)) ||
			((gridIn.x1 < x1) && (gridIn.x1 > x0)) ||
			((x0 < gridIn.x1) && (x0 > gridIn.x0)) ||
			((x1 < gridIn.x1) && (x1 > gridIn.x0));
	}

	template<class dType>
	const dType& DimOneGrid<dType>::left() const
	{
		return x0;
	}

	template<class dType>
	const dType& DimOneGrid<dType>::right() const
	{
		return x1;
	}

	template<class dType>
	bool DimOneGrid<dType>::isBetween(const dType& valIn) const
	{
		return (fabs(x0 - valIn) < numeric_limits<dType>::epsilon() || x0 < valIn) &&
			(fabs(x1 - valIn) < numeric_limits<dType>::epsilon() || x1 > valIn);
	}

	template<class dType>
	bool DimOneGrid<dType>::GridCompare::operator()(const DimOneGrid<dType>& lhs, const DimOneGrid<dType>& rhs) const
	{
		if (!lhs.isIntersecting(rhs))
		{
			return lhs.left() < rhs.left();
		}
		else
		{
			throw runtime_error("Non-Unique Comparison");
		}
	}
}
