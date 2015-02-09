#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int x,y,s,nx,ny;
    int paper[10][10];
    int count[3] = {5,9,13};
    int dx[3][13] = {{0,1,0,-1,0,0,0,0,0,0,0,0,0},
                     {0,1,1,0,-1,-1,-1,0,1,0,0,0,0},
                     {0,1,1,0,-1,-1,-1,0,1,2,0,-2,0}};
    int dy[3][13] = {{0,0,-1,0,1,0,0,0,0,0,0,0,0},
                     {0,0,-1,-1,-1,0,1,1,1,0,0,0,0},
                     {0,0,-1,-1,-1,0,1,1,1,0,-2,0,2}};
    for(int i=0;i<10;i++) for(int j=0;j<10;j++) paper[i][j] = 0;
    while(scanf("%d,%d,%d",&x,&y,&s) != EOF){
        for(int i=0;i<count[s-1];i++){
            nx = x + dx[s-1][i];
            ny = y + dy[s-1][i];
            if(nx >= 0 && nx < 10 && ny >= 0 && ny < 10){
                paper[nx][ny]++;
            }
        }
    }
    int mmax = 0;
    int mcount = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            mmax = max(mmax, paper[i][j]);
            if(paper[i][j] == 0) mcount++;
        }
    }
    cout << mcount << '\n' << mmax << '\n';
    return 0;
}
