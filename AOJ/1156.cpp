#include <iostream>
#include <queue>
#define INF 999999999
using namespace std;

int main(){
    int di[4] = {0,-1,0,1};
    int dj[4] = {1,0,-1,0};
    int com[4][4] = {{0,1,2,3},
                     {3,0,1,2},
                     {2,3,0,1},
                     {1,2,3,0}};
    while(1){
        int w,h;
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        int map[30][30];
        int cost[4];
        int costsum[30][30][4];
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> map[i][j];
                for(int k=0;k<4;k++){
                    costsum[i][j][k] = INF;
                }
            }
        }
        for(int i=0;i<4;i++){
            cin >> cost[i];
        }

        queue<pair<pair<int,int>,int> > q;
        q.push(make_pair(make_pair(0,0), 0));
        costsum[0][0][0] = 0;
        while(q.size()){
            pair<pair<int,int>,int> cur = q.front();
            q.pop();
            int ni,ci = cur.first.first;
            int nj,cj = cur.first.second;
            int nd,cd = cur.second;
            for(int i=0;i<4;i++){
                nd = com[i][cd];
                ni = ci + di[nd];
                nj = cj + dj[nd];
                if(ni >= 0 && ni < h && nj >= 0 && nj < w){
                    if(costsum[ci][cj][cd] + ((map[ci][cj] == i) ? 0 : cost[i]) < costsum[ni][nj][nd]){
                        costsum[ni][nj][nd] = costsum[ci][cj][cd] + ((map[ci][cj] == i) ? 0 : cost[i]);
                        q.push(make_pair(make_pair(ni,nj),nd));
                    }
                }
            }
        }
        cout << min(costsum[h-1][w-1][0],min(costsum[h-1][w-1][1],min(costsum[h-1][w-1][2],costsum[h-1][w-1][3]))) << '\n';
    }
    return 0;
}
