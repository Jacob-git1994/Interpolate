#include "OneDimLine.h"

using namespace intp;

bool OneDimLine::isUnique(const DimOneGrid<double>& gridIn) const
{
	bool uniqueFlag = true;

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

void OneDimLine::addGridPair(
	const DimOneGrid<double>& gridIn, 
	const DimOneRange<double>& valIn)
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

const bool OneDimLine::getPair(
	const double& valIn, 
	DimOneGrid<double>& domainIn, 
	DimOneRange<double>& rangeIn,
	bool left = true) const
{
	//Initalize Found Boolean
	bool found = false;

	if (!line.empty())
	{
		for (const auto& grid : line)
		{
			if (grid.first.isBetween(valIn) && left)
			{
				//Save the values of the grid
				domainIn = grid.first;
				rangeIn = grid.second;
				found = true;
				break;
			}
			else if (grid.first.isBetween(valIn) && !left)
			{
				left = true;
				continue;
			}
			else
			{
				continue;
			}
		}

		//If we get here we never found a point so we will need to pick left or right side of the line
		if (valIn < line.begin()->first.left())
		{
			//Save the begining values
			domainIn = line.begin()->first;
			rangeIn = line.begin()->second;
		}
		else if (valIn > line.rbegin()->first.right())
		{
			//Save the End Values
			domainIn = line.end()->first;
			rangeIn = line.end()->second;
		}
		else if(!found)
		{
			throw runtime_error("Unable to find point in scope of line");
		}

	}
	else
	{
		throw runtime_error("No elements in Line Class");
	}
	return found;
}

const map<DimOneGrid<double>, DimOneRange<double>, DimOneGrid<double>::GridCompare>& OneDimLine::getLinearMap() const
{
	return line;
}