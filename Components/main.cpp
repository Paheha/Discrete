//Кол-во компонент связности графа

#include <QCoreApplication>
#include <queue>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

     int n,m,g,k,komp;
    ifstream f;
    f.open("C:\\Users\\Gimarr\\Documents\\Components\\Matrix.txt");
    if (!f) {
        cout << "can't open file";
        return 1;
    }

    f >> n >> m;
    vector <vector <bool> > Matrix( n, vector<bool>(n, false) );
    for(int i = 0; i < m; i++) {
        f >> g >> k;
        Matrix[g][k]=true;
        Matrix[k][g]=true;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout <<" "<< Matrix[i][j];
        cout << endl;

    }
    vector <int> Metka(n,0);
    queue <int> Queue;
    Queue.push(0);
    komp = 1;
    int out = 0;

    while(1){
        out = 0;
        if(Queue.empty()) {
            for(int i = 0; i < n; i++){
                if(Metka[i]==0){
                    komp++;
                    Queue.push(i);
                    break;
                    }
                }
            }

            for(int i=0; i < n; i++){
                if(Metka[i]!=0){
                    out++;
                    if (out==n){
                        cout <<endl << komp<< endl;
                        return komp;
                    }
                }

            }

        k = Queue.front();
        cout << endl << "First in queue = " << k;
        Queue.pop();
        for(int i = 0; i < n; i++){
            if((Matrix[k][i]==true)&&(Metka[i]==0)){
                Queue.push(i);
                Metka[i]=komp;
            }
        }

    }
    return a.exec();
}
