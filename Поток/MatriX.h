#ifndef MatriX_H
#define MatriX_H

#include <iostream>
#include <vector>

using namespace std;

class MatriX{
public:
    int m,n;
    vector < vector<int> > Matrix;
    //int *uk=&MatriX;
public:
    MatriX(int n,const int k);
    //~MatriX();
    void add();
    void show();
    void addL();
    void addPot();
    void check();






};



#endif
