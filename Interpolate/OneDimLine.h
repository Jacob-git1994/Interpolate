#pragma once

#include <iostream>
#include <map>
#include <stdexcept>

#include "DimOneGrid.h"
#include "DimOneRange.h"
#include "GridIF.h"
#include "LineIF.h"

using std::cerr;
using std::map;
using std::runtime_error;

namespace intp
{
    class OneDimLine : public LineIF
    {
    private:

        //Storage for Dim One Grid
        map<DimOneGrid<double>, DimOneRange<double>, DimOneGrid<double>::GridCompare> line;

        //Private Check to see if insertion is correctly unique for the grid
        bool isUnique(const DimOneGrid<double>&) const;

    public:

        //Default Constructor
        OneDimLine() = default;

        //We don't want to copy the line
        OneDimLine(const OneDimLine&) = delete;

        //We don't want to assign this class
        const OneDimLine& operator=(const OneDimLine&) = delete;

        //Virtual default destructor
        virtual ~OneDimLine() = default;

        //Add set of grids and values to the map
        virtual void addGridPair(const DimOneGrid<double>&, const DimOneRange<double>&) override;

        //Get the Grid and Value Pair that can be interpolated
        virtual const bool getPair(const double&, DimOneGrid<double>&, DimOneRange<double>&, bool) const override;

        //Get the map to analysis
        virtual const map<DimOneGrid<double>, DimOneRange<double>, DimOneGrid<double>::GridCompare>& getLinearMap() const override;

    };
}


