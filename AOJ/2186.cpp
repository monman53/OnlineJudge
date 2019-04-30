#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    int gx,gy;
    int p;
    int x1,y1,x2,y2;
    int data[17][17];
    bool dir[17*17][17*17];
    for(int i=0;i<17;i++){
        data[i][0] = data[0][i] = 0;
    }
    data[0][1] = 1;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<17*17;j++){
            for(int k=0;k<17*17;k++){
                dir[j][k] = false;
            }
        }
        cin >> gx >> gy;
        cin >> p;
        for(int i=0;i<p;i++){
            cin >> x1 >> y1 >> x2 >> y2;
            dir[(x1+1)*17+(y1+1)][(x2+1)*17+(y2+1)] = dir[(x2+1)*17+(y2+1)][(x1+1)*17+(y1+1)] = true;
        }

        for(int i=1;i<=gx+1;i++){
            for(int j=1;j<=gy+1;j++){
                data[i][j] = ((dir[i*17+j][(i-1)*17+j]) ? 0 : data[i-1][j]) + ((dir[i*17+j][i*17+(j-1)]) ? 0 : data[i][j-1]);
            }
        }
        if(data[gx+1][gy+1] == 0){
            cout << "Miserable Hokusai!\n";
        }else{
            cout << data[gx+1][gy+1] << '\n';
        }
    }
    return 0;
}
                
