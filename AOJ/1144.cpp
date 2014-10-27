#include <iostream>
#define INF 999999999
using namespace std;

int w,h;
int data[20][20];
int di[] = {0,-1,0,1};
int dj[] = {1,0,-1,0};
int mmin;

void calc(int i, int j, int count){
    //cout << count;
    if(count > 10){
        return;
    }
    if(data[i][j] == 3){
        if(count <= mmin) mmin = count;
        return;
    }
    for(int k=0;k<4;k++){
        for(int l=1;;l++){
            int ni = i+di[k]*l;
            int nj = j+dj[k]*l;
            if(ni >= 0 && ni < h && nj >= 0 && nj < w){
                if(data[ni][nj] == 3){
                    calc(ni,nj,count+1);
                    break;
                }
                if(data[ni][nj] == 1){
                    if(l == 1){
                        break;
                    }else{
                        data[ni][nj] = 0;
                        calc(ni-di[k],nj-dj[k],count+1);
                        data[ni][nj] = 1;
                        break;
                    }
                }               
            }else{
                break;
            }
        }
    }
}
int main(){
    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        mmin = INF;
        int si,sj;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> data[i][j];
                if(data[i][j] == 2){
                    si = i;
                    sj = j;
                }
            }
        }
        calc(si, sj, 0);
        cout << (mmin == INF ? -1 : mmin) << '\n';
    }
    return 0;
}
