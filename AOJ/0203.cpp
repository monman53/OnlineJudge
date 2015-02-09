
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> P;

int main(){
    while(1){
        int data[16][18];
        int sum[16][18];
        for(int y=0;y<18;y++){
            for(int x=0;x<16;x++){
                data[x][y] = 0;
                sum[x][y] = 0;
            }
        }
        int X,Y;
        cin >> X >> Y;
        if(X == 0 && Y == 0){
            break;
        }
        for(int y=1;y<=Y;y++){
            for(int x=1;x<=X;x++){
                cin >> data[x][y];
            }
        }
        for(int x=1;x<=X;x++){
            if(data[x][1]==0){
                sum[x][1] = 1;
            }
        }
        for(int y=1;y<=Y-1;y++){
            for(int x=1;x<=X;x++){
                for(int i=-1;i<=1;i++){
                    int nx = x + i;
                    int ny;
                    if(nx >= 1 && nx <= X){
                        switch(data[x][y]){
                        case 0:
                            ny = y + 1;
                            if(data[nx][ny] != 2 || i==0){
                                sum[nx][ny] += sum[x][y];
                            }
                            break;
                        case 2:
                            ny = y + 2;
                            if(i==0){
                                sum[nx][ny] += sum[x][y];
                            }
                            break;
                        case 1:
                            sum[x][y] = 0;
                            break;
                        }
                    }
                }
                //cout << sum[x][y] << " ";
            }
            //cout << '\n';
        }
        int count=0;
        for(int y=Y;y<=Y+1;y++){
            for(int x=1;x<=X;x++){
                if(data[x][y]==0 || data[x][y]==2){
                    count += sum[x][y];
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}
