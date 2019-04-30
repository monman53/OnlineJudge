#include <cstdio>
#include <queue>
#define INF 9999999
using namespace std;

typedef pair<int,int> P;

int h,w;
bool data[102][102];
int dis[102][102];
int di[4] = {0,-1,0,1};
int dj[4] = {1,0,-1,0};

void dfs(int cdis,int ci,int cj){
    dis[ci][cj] = cdis;
    for(int i=0;i<4;i++){
        int ni = ci+di[i];
        int nj = cj+dj[i];
        if(ni >= 0 && ni <= h+1 && nj >= 0 && nj <= w+1){
            if(cdis < dis[ni][nj] && data[ci][cj] == data[ni][nj]){
                dfs(cdis,ni,nj);
            }else if(cdis + 1 < dis[ni][nj] && data[ci][cj] != data[ni][nj]){
                dfs(cdis+1,ni,nj);
            }
        }
    }
}

int main(){
    while(1){
        int firsti,firstj;
        scanf("%d%d",&w,&h);
        if(w == 0 && h==0){
            break;
        }
        for(int i=0;i<=w+1;i++){
            data[0][i] = data[h+1][i] = true;
            dis[0][i] = dis[h+1][i] = INF;
        }
        for(int i=0;i<=h+1;i++){
            data[i][0] = data[i][w+1] = true;
            dis[i][0] = dis[i][w+1] = INF;
        }
        for(int i=1;i<=h;i++){
            char c[101];
            scanf("%s",c);
            for(int j=1;j<=w;j++){
                data[i][j] = c[j-1] == '#' ? false : true;
                if(c[j-1] == '&'){
                    dis[i][j] = 0;
                    firsti = i;
                    firstj = j;
                }else{
                    dis[i][j] = INF;
                }
            }
        }
        dfs(0,firsti,firstj);
        printf("%d\n",dis[0][0]/2);
    }
    return 0;
}
