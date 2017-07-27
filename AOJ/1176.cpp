// header {{{
// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)        (abs((a)-(b)) < EPS)
#define CILING(a, b)    (((a)+(b)-1LL)/(b))

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}

int h, w, s;
// int u[105][105];
int sum[33][33];
PII memo[33][33][33][33];
int SUM;

PII solve(int si, int sj, int ti, int tj) {
    int ssum = sum[ti][tj] - sum[si][tj] - sum[ti][sj] + sum[si][sj];
    if(memo[si][sj][ti][tj] != PII{-1, -1}) return memo[si][sj][ti][tj];
    if(SUM-ssum > s) return memo[si][sj][ti][tj] = {0, 0};
    PII ret = {1, s-(SUM-ssum)};
    // -
    for(int i=si+1;i<ti;i++){
        PII u = solve(si, sj, i, tj);
        PII d = solve(i, sj, ti, tj);
        if(u != PII{0, 0} && d != PII{0, 0}){
            ret = max(ret, {u.first+d.first, min(u.second, d.second)});
        }
    }
    // |
    for(int i=sj+1;i<tj;i++){
        PII l = solve(si, sj, ti, i);
        PII r = solve(si, i, ti, tj);
        if(l != PII{0, 0} && r != PII{0, 0}){
            ret = max(ret, {l.first+r.first, min(l.second, r.second)});
        }
    }
    return memo[si][sj][ti][tj] = ret;
}

int main() {
    while(true){
        cin >> h >> w >> s;
        if(h==0) break;
        for(int i=0;i<=h;i++){
            for(int j=0;j<=w;j++){
                for(int k=0;k<=h;k++){
                    for(int l=0;l<=w;l++){
                        memo[i][j][k][l] = {-1, -1};
                    }
                }
            }
        }
        for(int i=0;i<=h;i++){
            for(int j=0;j<=w;j++){
                int u;
                if(i == 0 || j == 0){
                    sum[i][j] = 0;
                }else{
                    cin >> u;
                    sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + u;
                }
            }
        }
        SUM = sum[h][w];
        PII ans = solve(0, 0, h, w);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}
