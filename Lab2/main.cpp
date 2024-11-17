#include <iostream>
#include <fstream>
#include "Point.h"
#include "Point.cpp"
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  
    ifstream fi("D:\\CODE\\BaitapC++\\Lab2\\data.txt");
    int n;
    fi >> n; 
    vector<Point> lstPoint;
    for (int i = 0; i < n; i++)
    {
        Point* ptr=new Point(0,0);
        fi >> *ptr;
        lstPoint.push_back(*ptr);
    }
    fi.close();
    sort(lstPoint.begin(), lstPoint.end());
    for (int i = 0; i < n; i++)
        cout << lstPoint[i] << " ";
    return 0;
}