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
		DimOneRange() = default;

		//Constructor for the Y Values
		DimOneRange(const dType&, const dType&);

		//Copy Constructor
		DimOneRange(const DimOneRange<dType>&);

		//Assign Operator
		const DimOneRange& operator=(const DimOneRange<dType>&);

		//Default Virtual Destructor 
		virtual ~DimOneRange() = default;

		//Initalize the Method
		const DimOneRange<dType>& initalize(const dType&, const dType&);

		//Distance Method for other situations
		virtual dType distance() const override;
	};

}
