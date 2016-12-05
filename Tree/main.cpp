#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int m,n,k,h,g;
    ifstream f;
    f.open("C:\\Users\\Gimarr\\Documents\\Tree\\Matrix.txt");
    if (!f) {
       cout << "can't open file";
       return 1;
    }

    f >> n >> m;

    vector <vector <int> > Matrix (n, vector<int> (n,0));
    vector <vector <int> > Vertex(n, vector<int> (n,0));
    for(int i = 0; i < m; i++) {
        f >> k >> h >> g;
        if (Matrix [k][h]==0) {
            Matrix [k][h]=g;
            Matrix [h][k]=g;
            Vertex [h][k]=i;
            Vertex [k][h]=i;
            } else
                if (g < Matrix [k][h]){
                Matrix [k][h]=g;
                Matrix [h][k]=g;
                Vertex [k][h]=i;
                Vertex [h][k]=i;
                }
    }

    queue <int> Numbers;
    vector <bool> Labels(n, false);

    for(int i = 0; i < n; i++){
        for(int g = 0;g < n; g++)
            cout <<" "<< Matrix [i][g];
        cout << endl;
    }
    cout << endl <<endl;
    for(int i = 0; i < n; i++){
        for(int g = 0; g < n; g++)
            cout <<" "<< Vertex [i][g];
        cout << endl;
    }
    int min;
    min=32767;
    bool b;
    while (1) {
        for(int i = 0; i < n;i++)
            for(int g = 0; g < i; g++){
                cout <<"min egde = "<< min <<"  Matrix["<<i<< "]["<<g<<"] = " << Matrix[i][g] << endl;
                if(( min >= Matrix[i][g] ) && ( Labels[i]==false || Labels[g]==false  )&& Matrix[i][g]!=0){
                    min=Matrix[i][g];
                    k=i;
                    h=g;
                    b=true;
                }
            }

        cout << endl << "push " <<Vertex[k][h] <<"  k = "<<k <<" h = "<< h <<endl;
        Matrix[k][h]=32767;
        Numbers.push(Vertex[k][h]);
        Labels[k] = true;
        Labels[h] = true;

        min = 32767;
        if (!b) break;
        b = false;
    }
        cout << Numbers.size() <<endl;
        cout << endl;
        for(int i = 0; i <= Numbers.size(); i++){
            cout << Numbers.front() << " ";
            Numbers.pop();
       }

    return a.exec();
}
