#include <iostream>
#include <vector>
#include "MatriX.h"

using namespace std;

MatriX::MatriX(int h,int k):Matrix(h,vector <int> (h,0)) {
    n=h;
    m=k;
}

/*MatriX::~MatriX() {
    delete Matrix;

}*/

void MatriX::show() {
    for(int i=0;i<n;i++){
        for(int g=0;g<n;g++)
            cout <<" "<< Matrix[i][g];
        cout << endl;

    }



}

void MatriX::add() {
    int g,k;
    for(int i=0;i<m;i++) {
        cin >> g >> k;
        Matrix[g][k]=1;
        Matrix[k][g]=1;
    }

}

void MatriX::addL() {
    int g,k,w;
    for(int i=0;i<m;i++) {
        cin >> g >> k >> w;
        Matrix[g][k]=w;
        Matrix[k][g]=w;
    }

}


void MatriX::addPot() {
    int g,k,w;
    for(g=0;g<n;g++) {
    for(int i=0;i<n;i++) {
        cin >> (Matrix[i][g]);
    }
}
}

void MatriX::check(){
    for(int i=0;i<n;i++){
            int m=0;
            for(int g=0;g<i;g++){
                cout << endl << Matrix[i][g] << "and " << Matrix[g][i];
                if (Matrix[i][g]!=((-1)*Matrix[g][i])){
                        cout <<"Nope";
                        return;
                }
            }
    }
    for(int i=0;i<n;i++){
        m=0;
            for(int g=0 ; g<n ; g++){
                 m=m+Matrix[i][g];
                    if (g==(n-1)&&m!=0){
                        cout <<"Nope!";
                        return;

                    }

                }
            }
}











