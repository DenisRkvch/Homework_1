#include <iostream>
#include "Quadratic/Quadratic.h"
#include <limits>
#include <locale>

int main()
{
    try
    {
        std::cout << "x1 = " << solve(-1.0 / 4, 0.0, 0.9*std::numeric_limits<double>::epsilon())[0] << 
            "  x2 = " << solve(-1.0 / 4, 0.0, 0.9*std::numeric_limits<double>::epsilon())[1] << '\n';
        std::cout << "epsilon is: = " << 0.9*std::numeric_limits<double>::epsilon() << '\n';
        //std::cout << "Hello  " << solve(0.0, 0.0, -1.0)[0] << solve(0.0, 0.0, -1.0)[1];
        std::cout << "Hello  " << solve(5, std::numeric_limits<double>::infinity(), -1.0)[0] << solve(5.0, 0.0, -1.0)[1];
    }
    catch (std::runtime_error e)
    {
        std::cout << e.what() << std::endl;
    }
	
    return 0;
}