// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int d[1000][1000];
char c[1000][1000];
int h, w;
int si, sj, ti, tj;

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    cin >> w >> h;
    inc(i, 0, h){
        inc(j, 0, w){
            cin >> c[i][j];
            if(c[i][j] == 's'){
                si = i;
                sj = j;
            }
            if(c[i][j] == 'g'){
                ti = i;
                tj = j;
            }
            d[i][j] = INF;
        }
    }

    queue<pair<int, int>> q;
    q.push({si, sj});
    d[si][sj] = 0;

    while(!q.empty()){
        int ci = q.front().fi;
        int cj = q.front().se;
        q.pop();
        inc(k, 0, 4){
            int ni = ci + di[k];
            int nj = cj + dj[k];
            if(ni >= 0 && ni < h && nj >= 0 && nj < w){
                if(c[ni][nj] == '1') continue;
                if(d[ci][cj] + 1 >= d[ni][nj]) continue;
                d[ni][nj] = d[ci][cj] + 1;
                q.push({ni, nj});
            }
        }
    }

    if(d[ti][tj] == INF){
        cout << "Fail" << endl;
    }else{
        cout << d[ti][tj] << endl;
    }

    return 0;
}
