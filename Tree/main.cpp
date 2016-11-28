#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int m,n,i,k,h,g;
    ifstream f;
    f.open("C:\\Users\\Gimarr\\Documents\\Tree\\Matrix.txt");
    if (!f) {
       cout << "can't open file";
       return 1;
    }

    f >> n >> m;

    vector <vector <int> > Matrix (n, vector<int> (n,0));
    vector <vector <int> > Versh(n, vector<int> (n,0));
    for(i=0;i<m;i++) {
        f >> k >> h >> g;
        if (Matrix [k][h]==0) {
            Matrix [k][h]=g;
            Matrix [h][k]=g;
            Versh [k][h]=i;
            Versh [h][k]=i;
            } else
                if (g<Matrix [k][h]){
                Matrix [k][h]=g;
                Matrix [h][k]=g;
                Versh [k][h]=i;
                Versh [h][k]=i;
                }
        }

    queue <int> Nomera;
    vector <bool> Metka(n, false);
    int br=0;

    for( i=0;i<n;i++){
        for( g=0;g<n;g++)
            cout <<" "<< Matrix [i][g];
        cout << endl;
    }
    cout << endl <<endl;
    for( i=0;i<n;i++){
        for( g=0;g<i;g++)
            cout <<" "<< Versh [i][g];
        cout << endl;
    }
    int min;
    min=32767;
    bool b;
while (1) {
    for(i=0; i<n;i++)
        for(g=0;g<i;g++){
            cout <<"min = "<< min <<"/ Matrix["<<i<< "]["<<g<<"] = " << Matrix[i][g] << endl;
            if((min >= Matrix[i][g]) && ( Metka[i]==false || Metka[g]==false  )&& Matrix[i][g]!=0){
                min=Matrix[i][g];
                k=i;
                h=g;
                b=true;
            }
        }

    cout << endl << "push " <<Versh[k][h] <<"  k="<<k <<" h="<<h <<endl;
    Matrix[k][h]=32767;
    Nomera.push(Versh[k][h]);
    Metka[k]=true; Metka[h]=true;
    br=Nomera.back();
    min=32767;
    if (!b) break;
    b=false;
}
    cout << Nomera.size() <<endl;
    cout << endl;
    for(i=0;i<=Nomera.size();i++){
        cout << Nomera.front() << " ";
        Nomera.pop();
   }


    return a.exec();
}
