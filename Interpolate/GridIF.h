#pragma once

namespace intp
{
	template<class dType>
	class GridIF
	{
	private:

		//Virtual Base Check for valid inputs
		virtual void validInputs() const = 0;

	public:

		//Base Constructor
		GridIF() = default;

		//Base Copy Constructor
		GridIF(const GridIF&) = default;

		//Base Virtual Destructor
		virtual ~GridIF() = default;

		//Base Virtual Grid Size 
		virtual dType distance() const = 0;
	};
}
