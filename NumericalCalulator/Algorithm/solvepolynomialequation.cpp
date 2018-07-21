#include "solvepolynomialequation.h"
#include "Common/exception.h"
#include "Algorithm/niudun.h"

std::vector<double> solvePolynomialEquation(LinkList &equation)
{

    std::vector<double> result;
    if (equation.Get_max() == 0) {
        if (equation.getCoefficient(0) != 0) {
            throw EquationNoSolutionException();
        } else {
            throw EquationSolutionIsRException();
        }
    } else if (equation.Get_max() == 1) {
        result.push_back(-double(equation.getCoefficient(0)) / equation.getCoefficient(1));
        return result;
    } else if (equation.Get_max() == 2) {
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
        result.push_back(niudun(equation));
        return result;
    }

}

