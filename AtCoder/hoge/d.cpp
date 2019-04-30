// header {{{
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    (26)
#define EPS         (1e-10)
#define INF         (1000000005LL)
#define MOD         (1000000007LL)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
// ciling(x/y) = (x+y-1)/y

typedef long long ll;
typedef unsigned long long ull;
// }}}

typedef pair<int, int> P;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};

char c[600][600];
int N, M;

int solve(P s, P g){
    int dst[N][M];
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) dst[i][j] = INF;
    queue<pair<P, int>> q;
    q.push({s, 0});
    while(!q.empty()){
        auto nv = q.front();
        q.pop();
        int ci = nv.first.first;
        int cj = nv.first.second;
        int ccost = nv.second;
        if(dst[ci][cj] != INF) continue;
        if(dst[ci][cj] == INF) dst[ci][cj] = ccost;
        if(g == P{ci, cj}) return ccost;

        for(int i=0;i<4;i++){
            int ni = ci + di[i];
            int nj = cj + dj[i];
            if(c[ni][nj] != '#'){
                q.push({{ni, nj}, ccost+1});
            }
        }
    }
    return dst[g.first][g.second];
}

int main() {
    cin >> N >> M;
    P S, C, G;
    for(int i=0;i<N;i++){
        string s;cin >> s;
        for(int j=0;j<M;j++){
            c[i][j] = s[j];
            if(c[i][j] == 'S') S = {i, j};
            if(c[i][j] == 'C') C = {i, j};
            if(c[i][j] == 'G') G = {i, j};
        }
    }

    int sc = solve(S, C);
    int cg = solve(C, G);

    if(sc == INF || cg == INF) cout << -1 << endl;
    else cout << sc + cg << endl;

    return 0;
}
