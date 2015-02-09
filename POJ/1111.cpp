#include <cstdio>
using namespace std;

bool data[22][22];
bool kita[22][22];
int sum;

int di[8] = {0,-1,0,1,-1,-1,1,1};
int dj[8] = {1,0,-1,0,1,-1,-1,1,};

void dfs(int ci,int cj){
    kita[ci][cj] = true;
    int count = 0;
    for(int i=0;i<8;i++){
        int ni = ci+di[i];
        int nj = cj+dj[i];
        if(!data[ni][nj] && i<4){
            count++;
        }
        if(data[ni][nj] && !kita[ni][nj]){
            dfs(ni,nj);
        }
    }
    sum += count;
}

int main(){
    while(1){
        char c[22];
        int h,w,ci,cj;
        sum = 0;
        scanf("%d%d%d%d",&h,&w,&ci,&cj);
        if(h==0){
            break;
        }
        for(int i=0;i<22;i++){
            for(int j=0;j<22;j++){
                data[i][j] = false;
                kita[i][j] = false;
            }
        }
        for(int i=1;i<=h;i++){
            scanf("%s",c);
            for(int j=1;j<=w;j++){
                data[i][j] = c[j-1]=='X' ? true : false;
            }
        }
        dfs(ci,cj);
        /*for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                printf("%d",kita[i][j]);
            }
            printf("\n");
            }*/
        printf("%d\n",sum);
    }
    return 0;
}
