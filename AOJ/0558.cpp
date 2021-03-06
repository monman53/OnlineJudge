#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> P;

const int INF=100000000;

int di[4] = {0,-1,0,1};
int dj[4] = {1,0,-1,0};

int h,w,n;
int d[1000][1000];
char data[1000][1000];
int cheesei[10];
int cheesej[10];
int sum=0;

int bfs(int si,int sj,int gi,int gj){
    queue<P> que;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            d[i][j]=INF;
        }
    }
    que.push(P(si,sj));
    d[si][sj]=0;
    while(que.size()){
        P p = que.front();
        que.pop();
        if(p.first == gi && p.second == gj){
            break;
        }
        for(int i=0;i<4;i++){
            int ci = p.first + di[i];
            int cj = p.second + dj[i];
            if(ci>=0 && ci<h && cj>=0 && cj<w){
                if((data[ci][cj]=='.' || data[ci][cj]=='S' || (data[ci][cj]-'0' > 0 && data[ci][cj]-'0' < 10)) && d[ci][cj] == INF){
                    que.push(P(ci,cj));
                    d[ci][cj] = d[p.first][p.second] + 1;
                }
            }
        }
    }
    return d[gi][gj];
}

int main(){
    int count =0;
    cin >> h >> w >> n;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> data[i][j];
            if(data[i][j] != '.' && data[i][j] != 'X' && data[i][j] != 'S'){
                cheesei[data[i][j] - '0'] = i;
                cheesej[data[i][j] - '0'] = j;
            }
            if(data[i][j] == 'S'){
                cheesei[0] = i;
                cheesej[0] = j;
            }
        }
    }

    for(int i=0;i<n;i++){
        sum += bfs(cheesei[i],cheesej[i],cheesei[i+1],cheesej[i+1]);
    }
    cout << sum << '\n';
    return 0;
}
