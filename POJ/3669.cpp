#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int INF = 10000;
typedef pair<int,int> P;

int data[303][303];
int dist[303][303];
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};

int main(){
    int n,x,y,t,time=-1;
    queue<P> que;
    
    for(int i=0;i<303;i++){
        for(int j=0;j<303;j++){
            data[i][j] = INF;
            dist[i][j] = -1;
        }
    }
    
    cin >> n;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&x,&y,&t);
        for(int j=0;j<5;j++){
            int cx = x+dx[j],cy = y+dy[j];
            if(cx >= 0 && cx <=303 && cy >= 0 && cy <= 303){
                if(t <= data[cx][cy]){
                    data[cx][cy] = t;
                }
            }
        }
    }
    que.push(P(0,0));
    dist[0][0] = 0;
    while(que.size()){
        P bessie = que.front();
        int bx=bessie.first,by=bessie.second;
        int d=dist[bx][by];

        que.pop();
        if(d >= data[bx][by]){
            continue;
        }else if(data[bx][by] == INF){
            time = d;
            break;
        }

        for(int i=1;i<5;i++){
            int cx = bx + dx[i],cy = by + dy[i];
            if(cx >= 0 && cx <= 303 && cy >= 0 && cy <= 303){
                if(dist[cx][cy] == -1){
                    dist[cx][cy] = d+1; 
                    que.push(P(cx,cy));
                }
            }
        }
    }
    cout << time << '\n';
    return 0;
}
