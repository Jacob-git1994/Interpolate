#pragma once
#include <stdexcept>
#include <valarray>

#include "GridIF.h"

using std::valarray;
using std::invalid_argument;

namespace intp
{
	template<class dType>
	class DimOneRange : public GridIF<dType>
	{
	private:

		//Function Value at "Left Grid Point"
		dType yVal0;

		//Function Value at "Right Grid Point"
		dType yVal1;

	public:

		//Default Constructor
		inline DimOneRange();

		//Constructor for the Y Values
		inline DimOneRange(const dType&, const dType&);

		//Copy Constructor
		inline DimOneRange(const DimOneRange<dType>&);

		//Assign Operator
		inline const DimOneRange& operator=(const DimOneRange<dType>&);

		//Default Virtual Destructor 
		inline virtual ~DimOneRange() = default;

		//Initalize the Method
		inline const DimOneRange<dType>& initalize(const dType&, const dType&);

		//Distance Method for other situations
		inline virtual dType distance() const override;

		//Get Left Value
		inline const dType& left() const;

		//Get Right Value
		inline const dType& right() const;
	};

	template<class dType>
	DimOneRange<dType>::DimOneRange() :
		yVal0(static_cast<dType>(0.)),
		yVal1(static_cast<dType>(1.)),
		GridIF<dType>()
	{
		//Nothing to do here
	}

	template<class dType>
	DimOneRange<dType>::DimOneRange(
		const dType& y0In,
		const dType& y1In) :
		yVal0(y0In),
		yVal1(y1In),
		GridIF<dType>()
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

	template<class dType>
	const DimOneRange<dType>& DimOneRange<dType>::operator=(
		const DimOneRange<dType>& dimOneRangeIn)
	{
		//Copy Over Values
		yVal0 = dimOneRangeIn.yVal0;
		yVal1 = dimOneRangeIn.yVal1;

		return *this;
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

	template<class dType>
	const dType& DimOneRange<dType>::left() const
	{
		return yVal0;
	}

	template<class dType>
	const dType& DimOneRange<dType>::right() const
	{
		return yVal1;
	}
}
