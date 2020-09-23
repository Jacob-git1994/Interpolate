#include "DimOneGrid.h"
#include "GridIF.h"


using namespace intp;

#include <iostream>

int main()
{
    GridIF* grid = nullptr;
    try 
    {
        grid = new DimOneGrid(10, 9);
    }
    catch (std::exception e)
    {
        std::cerr << e.what() << "\n";
        exit(-1);
    }

    if(grid != nullptr)
        std::cout << grid->size() << "\n";
    else{}
}

