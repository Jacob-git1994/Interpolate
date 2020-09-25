#pragma once

namespace intp
{
	template<class dType>
	class GridIF
	{
	public:

		//Base Constructor
		inline GridIF() = default;

		//Base Copy Constructor
		inline GridIF(const GridIF&) = default;

		//Base Virtual Destructor
		inline virtual ~GridIF() = default;

		//Base Virtual Grid Size 
		inline virtual dType distance() const = 0;
	};
}
