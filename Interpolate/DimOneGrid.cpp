#include "DimOneGrid.h"

using namespace intp;

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
bool DimOneGrid<dType>::operator<=(
	const DimOneGrid<dType>& gridIn) const
{
	return (x1 < gridIn.x0) || (fabs(x1 - gridIn.x0) < numeric_limits<dType>::epsilon());
}

template<class dType>
bool DimOneGrid<dType>::operator>=(
	const DimOneGrid<dType>& gridIn) const
{
	return (x1 > gridIn.x0) || (fabs(x1 - gridIn.x0) < numeric_limits<dType>::epsilon());
}

template<class dType>
bool DimOneGrid<dType>::operator<(
	const DimOneGrid<dType>& gridIn) const
{
	return (x1 < gridIn.x0);
}

template<class dType>
bool DimOneGrid<dType>::operator>(
	const DimOneGrid<dType>& gridIn) const
{
	return (x1 > gridIn.x0);
}

template<class dType>
dType DimOneGrid<dType>::distance() const
{
	return static_cast<dType>(x1 - x0);
}