#include <cmath>
#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;


double Discriminant(double a, double b, double c)
{
    return b*b - 4 * a * c;
}

double firstDoubleRoots(double a, double b, double c)
{
    double x1;
    double disk = Discriminant(a, b, c);
    x1 = (-b - sqrt(disk)/(2*a));
    return x1;
}

double secondDoubleRoots(double a, double b, double c)
{
    double x2;
    double disk = Discriminant(a, b, c);
    x2 = (-b + sqrt(disk)/(2*a));
    return x2;
}

double oneRoot(double a, double b, double c)
{
    double x;
    x = -b/(2*a);
    return x;
}

void findQuadratic(double a, double b, double c,ofstream& output)
{
    double searchDisc = Discriminant(a, b, c);
    if(searchDisc > 0)
    {
        output << "два корня : " << firstDoubleRoots(a, b, c) << " "<< secondDoubleRoots(a, b, c);
    }else if (searchDisc == 0)
    {
        output << "единственный корень : " << oneRoot(a, b, c);
    }else if (searchDisc < 0)
    {
        output << "Корни комплексные";
    }
    
}




int main()
{
    ifstream file("input.txt");
    ofstream file2("output.txt");
    if(!file.is_open() || !file2.is_open())
    {
        cout << "error" << endl;
        return 1;
    }
    double a,b,c;
    while (file >> a >> b >> c)
    {
        findQuadratic(a, b, c, file2);
    }

    file.close();
    file2.close();
    
    return 0;
}

