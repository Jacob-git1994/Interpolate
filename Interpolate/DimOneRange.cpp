#include "DimOneRange.h"

using namespace intp;

template<class dType>
DimOneRange<dType>::DimOneRange(
	const dType& y0In,
	const dType& y1In) :
	yVal0(y0In),
	yVal1(y1In),
	GridIF()
{
	//Nothing to do here
}

template<class dType>
DimOneRange<dType>::DimOneRange(
	const DimOneRange<dType>& dimOneRangeIn) :
	yVal0(dimOneRangeIn.yVal0),
	yVal1(dimOneRangeIn.yVal1),
	GridIF<dType>()
{
	//Do nothing here
}

//For Other Types avoid contrcuting class
template<class dType>
const DimOneRange<dType>& DimOneRange<dType>::initalize(
	const dType& y0In,
	const dType& y1In)
{
	//Copy over the values
	yVal0 = y0In;
	yVal1 = y1In;

	return *this;

}

template<class dType>
dType DimOneRange<dType>::distance() const
{
	return yVal1 - yVal0;
}