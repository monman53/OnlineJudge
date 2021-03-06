#include <iostream>
using namespace std;

int w,h;
int data[20][20];
int mmin;
bool goalf;
int si,sj,gi,gj;

void dfs(int i,int j,int step){
    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
    if(data[i][j]==3){
        goalf = true;
        if(step <= mmin){
            mmin = step;
        }
        return;
    }else if(step == 10){
        return;
    }
    for(int k=0;k<4;k++){
        for(int l=1;;l++){
            int ci,cj;
            ci = i+dir[k][0]*l;
            cj = j+dir[k][1]*l;
            if(ci < 0 || ci >= h || cj < 0 || cj >= w){
                break;
            }else if(data[ci][cj] == 3){
                dfs(ci,cj,step+1);
                break;
            }else if(data[ci][cj] == 1){
                if(l==1){
                    break;
                }
                data[ci][cj] = 0;
                dfs(ci-dir[k][0],cj-dir[k][1],step+1);
                data[ci][cj] = 1;
                break;
            }
        }
    }
    return;
}

int main(){
    while(1){    
        cin >> w >> h;
        mmin = 99999999;
        goalf = false;
        if(w==0 || h==0){
            break;
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> data[i][j];
                if(data[i][j] == 2){
                    si = i;
                    sj = j;
                }
            }
        }
        dfs(si,sj,0);
        if(goalf){
            cout << mmin << '\n';
        }else{
            cout << -1 << '\n';
        }
    }
    return 0;
}
