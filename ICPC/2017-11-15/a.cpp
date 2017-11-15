// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int n, m, k;
vector<vector<int>> v;
vector<int> d;
vector<int> df;

int memo[1<<16];
int flag[1<<16];

int solve(int bit) {
    if(bit == 0){
        return 0;
    }
    if(memo[bit] != INF){
        return memo[bit];
    }
    flag[bit] = true;
    int mmin = INF;
    for(int i=0;i<k;i++){
        int next_bit = 0;
        for(int j=0;j<m;j++){
            if((bit & (1 << j)) && df[v[d[j]][i]]){
                int id = 0;
                for(int l=0;l<m;l++){
                    if(v[d[j]][i] == d[l]){
                        id = l;
                    }
                }
                next_bit |= (1 << id);
            }
        }
        if(flag[next_bit]) continue;
        mmin = min(mmin, solve(next_bit));
    }
    if(mmin == INF){
        return memo[bit] = INF;
    }
    return memo[bit] = mmin+1;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    v.resize(n);
    d.resize(m);
    df.resize(n, false);
    for(int i=0;i<m;i++){
        cin >> d[i];d[i]--;
        df[d[i]] = true;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            int vv;cin >> vv;vv--;
            v[i].push_back(vv);
        }
    }
    for(int i=0;i<(1<<m);i++){
        memo[i] = INF;
        flag[i] = false;
    }
    cout << solve((1<<m) - 1) << endl;
    return 0;
}
