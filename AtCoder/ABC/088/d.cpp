// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int h, w;
string c[50];
int d[50][50];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> h >> w;
    int ans = h*w;
    inc(i, 0, h){
        cin >> c[i];
        inc(j, 0, w){
            if(c[i][j] == '#') ans--;
            d[i][j] = INF;
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    d[0][0] = 0;
    while(!q.empty()){
        auto n = q.front();q.pop();
        int i = n.fi;
        int j = n.se;

        inc(k, 0, 4){
            int ni = i + di[k];
            int nj = j + dj[k];
            if(ni >= 0 && ni < h && nj >= 0 && nj < w){
                if(c[ni][nj] == '#') continue;
                if(d[ni][nj] != INF) continue;
                q.push({ni, nj});
                d[ni][nj] = d[i][j] + 1;
            }
        }
    }

    if(d[h-1][w-1] == INF){
        cout << -1 << endl;
        return 0;
    }

    cout << ans - d[h-1][w-1] -1 << endl;

    return 0;
}
