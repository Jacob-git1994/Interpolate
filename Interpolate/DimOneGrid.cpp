#include "DimOneGrid.h"

using namespace intp;

void DimOneGrid::validInputs() const
{
	//Verify the values are ordered corrected and are not equivlent. 
	const bool check = (x0 > x1) || (fabs(x0 - x1) < numeric_limits<double>::epsilon());
	if (check)
	{
		throw invalid_argument("Grid Not Implimented Correctly");
		exit(-1);
	}
	return;
}

DimOneGrid::DimOneGrid() :
	x0(0.),
	x1(1.),
	GridIF()
{
	//Check if Inputs are valid
	validInputs();
}

DimOneGrid::DimOneGrid(
	double x0In,
	double x1In) :
	x0(x0In),
	x1(x1In),
	GridIF()
{
	//Check if inputs are valid
	validInputs();
}

DimOneGrid::DimOneGrid(
	const DimOneGrid& gridIn) :
	x0(gridIn.x0),
	x1(gridIn.x1),
	GridIF()
{
	//Check if Inputs are Valid
	validInputs();
}

const DimOneGrid& DimOneGrid::operator=(
	const DimOneGrid& gridIn)
{
	//Copy the grid values based on input grid
	x0 = gridIn.x0;
	x1 = gridIn.x1;

	//Check if Inputs are valid
	validInputs();

	return *this;
}

const DimOneGrid& DimOneGrid::initalize(
	double x0In, 
	double x1In)
{
	//Copy values to form new grid
	x0 = x0In;
	x1 = x1In;

	//Check if Inputs are Valid
	validInputs();

	return *this;
}

bool DimOneGrid::operator<=(
	const DimOneGrid& gridIn) const
{
	return (x1 < gridIn.x0) || (fabs(x1 - gridIn.x0) < numeric_limits<double>::epsilon());
}

bool DimOneGrid::operator>=(
	const DimOneGrid& gridIn) const
{
	return (x1 > gridIn.x0) || (fabs(x1 - gridIn.x0) < numeric_limits<double>::epsilon());
}

bool DimOneGrid::operator<(
	const DimOneGrid& gridIn) const
{
	return (x1 < gridIn.x0);
}

bool DimOneGrid::operator>(
	const DimOneGrid& gridIn) const
{
	return (x1 > gridIn.x0);
}

double DimOneGrid::size() const
{
	return x1 - x0;
}