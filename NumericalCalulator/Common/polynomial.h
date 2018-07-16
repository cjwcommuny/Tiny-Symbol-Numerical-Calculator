#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H


class Polynomial
{
public:
    Polynomial();
    int getHighestRank() const;
    double getCoefficient(int rank);
};

#endif // POLYNOMIAL_H
