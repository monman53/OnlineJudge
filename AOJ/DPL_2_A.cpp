// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int v, e;cin >> v >> e;
    int d[15][15];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            d[i][j] = -1;
        }
    }
    for(int i=0;i<e;i++){
        int s, t, dd;cin >> s >> t >> dd;
        d[s][t] = dd;
    }
    vector<int> u(v);
    for(int i=0;i<v;i++) u[i] = i;

    int ans = INF;
    do{
        int sum = 0;
        for(int i=0;i<v;i++){
            int f = u[i];
            int t = u[(i+1)%v];
            if(d[f][t] == -1){
                sum = INF;
                break;
            }else{
                sum += d[f][t];
            }
        }
        ans = min(ans, sum);
    }while(next_permutation(u.begin(), u.end()));
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
