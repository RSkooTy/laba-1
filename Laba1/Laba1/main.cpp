#include "quadraticEquation.hpp"
#include <cmath>

using namespace std;

valueRoots oneRoot(double a, double b, double c)
{
    valueRoots result;
    result.x = -b/(2*a);
    result.type = oneSolution;
    return result;
}

valueRoots DoubleRoots(double a, double b, double c)
{
    valueRoots result;
    double disk = b*b - 4 * a * c;
    result.x1 = (-b - sqrt(disk)/(2*a));
    result.x2 = (-b + sqrt(disk)/(2*a));
    result.type = twoSolution;
    return result;
}

valueRoots findQuadratic(double a, double b, double c)
{
    valueRoots result;
    double searchDisc = b*b - 4 * a * c;
    if((a == 0) || ((a == 0) && (b = 0)))
    {
        result.type  = someCoef;
    }else if((a == 0) && (b == 0) && (c == 0))
    {
        result.type = allCoef;
    }else if(searchDisc > 0)
    {
        result = DoubleRoots(a, b, c);
    }else if(searchDisc == 0)
    {
        result = oneRoot(a, b, c);
    }else
    {
        result.type = complexSolution;
    }
    
    return result;
}

void printResult(ofstream& output, valueRoots result)
{
    switch (result.type) {
        case allCoef:
            output << "Все коэфициенты равны нулю -> корни равны 0" << endl;
            break;
        case someCoef:
            output << "Некоторые коэфициенты равны 0 -> корни равны 0" << endl;
            break;
        case twoSolution:
            output << "Первый корень: " << result.x1 << " Второй корень: "<< result.x2 << endl;
            break;
        case oneSolution:
            output << "Корень уравнения: " << result.x << endl;
            break;
        case complexSolution:
            output << "Значение корней комплексные" << endl;
            break;
        default:
            output << "ERROR" << endl;
            break;
    }
}

valueRoots readRoots(ifstream& input, ofstream& output)
{
    double a, b , c;
    input >> a >> b >> c;
    
    valueRoots result = findQuadratic(a, b, c);
    printResult(output, result);

    return result;
}
