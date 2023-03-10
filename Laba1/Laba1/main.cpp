#include <cmath>
#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;


float discriminant(float a, float b, float c)
{
    return b*b - 4 * a * c;
}

void findQuadratic(float a, float b, float c)
{
    float x1 , x2, meaningDiscrim;
    int prov = 0;
    
    meaningDiscrim = discriminant(a,b,c);
    
    if((a == prov) && (b == prov) && (c == prov))
    {
        cout << "Значение корней = 0" << endl;
    }else if(meaningDiscrim > 0)
    {
        x1 = (-b + sqrt(meaningDiscrim))/(2 * a);
        x2 = (-b - sqrt(meaningDiscrim))/(2 * a);
        cout << "Значение x1: " << x1 << " Значение x2: " << x2 << endl;
    }else if(meaningDiscrim == 0)
    {
        x1 = -b/(2 * a);
        cout << "Значение x: " << x1 << endl;
    }else
    {
        cout << "Значение корней комплексные"<< endl;
    }
    
}




int main()
{
    float a , b , c;
    ifstream file("input.txt");
    ofstream file2("output.txt");
    
    if(!file.is_open() || !file2.is_open())
    {
        cout << "error" << endl;
        return 1;
    }
    
    file >> a >> b >> c ;
    
    findQuadratic(a,b,c);
    
    file.close();
    file2.close();
    
    return 0;
}

