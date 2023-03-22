#include <fstream>
#include <iostream>
#include <stdio.h>
#include "quadraticEquation.hpp"

using namespace std;

int main()
{
    ifstream file("input.txt");
    ofstream file2("output.txt");
    if(!file.is_open() || !file2.is_open())
    {
        cout << "error" << endl;
        return 1;
    }

    valueRoots result = readRoots(file, file2);

    file.close();
    file2.close();
    
    return 0;
}

