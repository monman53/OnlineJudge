#include <iostream>
using namespace std;

int w,h;
int di[4] = {0,-1,0,1};
int dj[4] = {1,0,-1,0};
bool ice[90][90];
int mcount;
int mmax;

void dfs(int ci,int cj){
    ice[ci][cj]=false;
    mcount++;
    if(mcount > mmax){
        mmax=mcount;
    }
    for(int i=0;i<4;i++){
        int ni = ci + di[i];
        int nj = cj + dj[i];
        if(ni >= 0 && ni < h && nj >= 0 && nj < w){
            if(ice[ni][nj]){
                dfs(ni,nj);
            }
        }
    }
    mcount--;
    ice[ci][cj]=true;
}


int main(){
    while(1){
        cin >> w >> h;
        if(w == 0 && h==0){
            break;
        }
        mmax=0;
        mcount=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                int buf;
                cin >> buf;
                ice[i][j] = buf==1 ? true : false;
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(ice[i][j]){
                    dfs(i,j);
                }
            }
        }
        cout << mmax << '\n';
    }
    return 0;
} 
