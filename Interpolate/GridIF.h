#pragma once

namespace intp
{
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
		virtual double size() const = 0;

		//Base Virtual Grid Check ... check to make sure the grids "Link up"
	};
}
