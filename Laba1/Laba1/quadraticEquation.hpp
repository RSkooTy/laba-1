#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

enum quadraticType{
    allCoef,
    someCoef,
    twoSolution,
    oneSolution,
    complexSolution
};

struct valueRoots{
    quadraticType type;
    double x;
    double x1;
    double x2;
};

valueRoots findQuadratic(double a, double b, double c);
valueRoots readRoots(ifstream& input, ofstream& output);
void printResult(ofstream& output, valueRoots result);


