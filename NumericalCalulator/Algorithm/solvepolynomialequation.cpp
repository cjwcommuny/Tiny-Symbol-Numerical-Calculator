#include "solvepolynomialequation.h"
/*
std::vector<double> solvePolynomialEquation(Polynomial &equation)
{

    std::vector<double> result;
    if (equation.getHighestRank() == 0) {
        if (equation.getCoefficient(0) != 0) {
            //no answer
        } else {
            //solution can be any number in R
        }
    } else if (equation.getHighestRank() == 1) {
        result.push_back(-double(equation.getCoefficient(0)) / equation.getCoefficient(1));
        return result;
    } else if (equation.getHighestRank() == 2) {
        double a = equation.getCoefficient(2);
        double b = equation.getCoefficient(1);
        double c = equation.getCoefficient(0);
        double delta = b * b - 4 * c * a;
        if (delta < 0) {
            //bo solution
        } else if (delta == 0) {
            double solution = -double(b) / (2 * a);
            result.push_back(solution);
            return result;
        } else {
            double solution1 = (-b + sqrt(delta)) / (2 * a);
            double solution2 = (-b - sqrt(delta)) / (2 * a);
            result.push_back(solution1);
            result.push_back(solution2);
            return result;
        }
    } else {
        //high order equation
    }

}
*/
