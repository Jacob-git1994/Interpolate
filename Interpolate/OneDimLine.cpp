#include "OneDimLine.h"

using namespace intp;

bool OneDimLine::isUnique(const DimOneGrid<double>& gridIn) const
{
	bool uniqueFlag = false;

	for (auto& grid : line)
	{
		if (!grid.first.isIntersecting(gridIn))
		{
			uniqueFlag = true;
		}
		else if (grid.first.isIntersecting(gridIn))
		{
			uniqueFlag = false;
		}
		else
		{
			throw runtime_error("Unable to Identify Uniquity");
		}
	}
	
	return uniqueFlag;
}

void OneDimLine::addGridPair(const DimOneGrid<double>& gridIn, const DimOneRange<double>& valIn)
{
	if (isUnique(gridIn))
	{
		line.emplace(gridIn, valIn);
	}
	else
	{
		cerr << "Warning: Ignoring Value - Non-Unique\n";
	}

	return;
}

const auto& OneDimLine::getPair(const double& valIn) const
{
	if (!line.empty())
	{
		for (auto& grid : line)
		{
			if (grid.first.isBetween(valIn))
			{
				return grid;
			}
			else
			{
				continue;
			}
		}

		//If we get here we never found a point so we will need to pick left or right side of the line
		if (valIn < line.begin()->first.left())
		{
			return *line.begin();
		}
		else if (valIn > line.end()->first.right())
		{
			return *line.end();
		}
		else
		{
			throw runtime_error("Unable to find point in scope of line");
		}

	}
	else
	{
		throw runtime_error("No elements in Line Class");
	}
}