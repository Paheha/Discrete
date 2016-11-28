#include <iostream>
#include "MatriX.h"
#include "MatriX.cpp"
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    MatriX mt(n,0);
    mt.addPot();
    mt.show();
    mt.check();





    return 0;
}
