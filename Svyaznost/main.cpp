//Cвязность графа

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

    int n,m,g,k;
    ifstream f;
    f.open("C:\\Users\\Gimarr\\Documents\\Svyaznost\\Matrix.txt");
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
        for(int g = 0; g < n; g++) cout <<" "<< Matrix[i][g];
        cout << endl;
    }
    vector <bool> Label(n, false);
    queue <int> Queue;

    Queue.push(0);

    while(1){
        if(Queue.empty()) break;
        k = Queue.front();
        cout <<"First in queue = " << Queue.front()<<endl;
        Queue.pop();
        for(int i=0;i<n;i++){
            if((Matrix[k][i]==true)&&(Label[i]==false)){
                Queue.push(i);
                Label[i]=true;
            }
        }

    }
    for(int i = 0; i < n; i++)
        if(Label[i] == false){
            cout << "NOT CONNECTED"<<endl;
            return 0;
        }
    cout << "CONNECTED"<<endl;

    return a.exec();

}
