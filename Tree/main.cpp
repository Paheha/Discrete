#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int m,n,S,T,g;
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
        f >> S >> T >> g;
        if (Matrix [S][T]==0) {
            Matrix [S][T]=g;
            Matrix [T][S]=g;
            Vertex [T][S]=i;
            Vertex [S][T]=i;
            } else
                if (g < Matrix [S][T]){
                Matrix [S][T]=g;
                Matrix [T][S]=g;
                Vertex [S][T]=i;
                Vertex [T][S]=i;
                }
    }

    queue <int> Edges;
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
    min = 32767;
    bool b;
    while (1) {
        for(int i = 0; i < n;i++)
            for(int g = 0; g < i; g++){

                if(( Matrix[i][g] <= min ) && (Labels[i] == false || Labels[g] == false) && (Matrix[i][g]!=0)){
                    min = Matrix[i][g];
                    S = i;
                    T = g;
                    b = true;
                    cout <<"min egde = "<< min <<"  Matrix["<<i<< "]["<<g<<"] = " << Matrix[i][g] << endl;
                }
            }

        cout << endl << "push " <<Vertex[S][T] <<"  S = "<<S <<" T = "<< T <<endl;
        Matrix[S][T] = 32767;
        Edges.push(Vertex[S][T]);
        Labels[S] = true;
        Labels[T] = true;

        min = 32767;
        if (!b) break;
        b = false;
    }
        cout << Edges.size() << endl;
        cout << endl;
        for(int i = 0; i <= Edges.size(); i++){
            cout << Edges.front() << " ";
            Edges.pop();
       }

    return a.exec();
}
