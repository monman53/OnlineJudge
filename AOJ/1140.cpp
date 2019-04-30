// header {{{
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    26
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

typedef long long ll;
typedef unsigned long long ull;
// }}}

int INF = 10000;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};

int dn;
bool flag[11];
int dist[15][15];
map<pair<int, int>, int> id;

int dfs(int cid, int sum) {
    int mmin = INF;
    for(int i=1;i<dn;i++){
        if(!flag[i]){
            flag[i] = true;
            mmin = min(mmin, dfs(i, sum + dist[cid][i]));
            flag[i] = false;
        }
    }
    if(mmin == INF){
        return sum;
    }
    return mmin;
}

int main() {
    while(true){
        char c[25][25];
        dn = 1;

        int w, h;cin >> w >> h;
        if(w == 0 && h == 0) break;
        
        id.clear();

        for(int i=0;i<h;i++){
            string s;cin >> s;
            for(int j=0;j<w;j++){
                c[i][j] = s[j];
                if(c[i][j] == 'o'){
                    c[i][j] = '*';
                    id[{i, j}] = 0;
                }else if(c[i][j] == '*'){
                    id[{i, j}] = dn++;
                }
            }
        }

        for(int i=0;i<dn;i++){
            flag[i] = false;
            for(int j=0;j<dn;j++){
                dist[i][j] = i == j ? 0 : INF;
            }
        }

        for(const auto &kv : id) {
            int mmap[h][w];
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    mmap[i][j] = INF;
                }
            }

            int si = kv.first.first;
            int sj = kv.first.second;
            int sid = kv.second;
            queue<pair<pair<int, int>, int>> q;
            q.push({{si, sj}, 0});

            while(!q.empty()){
                auto now = q.front();q.pop();
                int ci = now.first.first;
                int cj = now.first.second;
                int cost = now.second;
                if(mmap[ci][cj] != INF){
                    continue;
                }
                mmap[ci][cj] = cost;
                if(c[ci][cj] == '*'){
                    dist[sid][id[{ci, cj}]] = cost;
                }

                for(int i=0;i<4;i++){
                    int ni = ci + di[i];
                    int nj = cj + dj[i];
                    if(ni >= 0 && ni < h && nj >= 0 && nj < w){
                        if(c[ni][nj] != 'x'){
                            q.push({{ni, nj}, cost+1});
                        }
                    }
                }
            }
        }

        bool inf_flag = false;
        for(int i=0;i<dn;i++){
            flag[i] = false;
            for(int j=0;j<dn;j++){
                if(dist[i][j] == INF){
                    inf_flag = true;
                }
            }
        }
        if(inf_flag){
            cout << -1 << endl;
            continue;
        }

        flag[0] = true;
        cout << dfs(0, 0) << endl;
    }
    return 0;
}
