// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int n, m;
int g[8][8];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    memset(g, 0, sizeof(g));
    for(int i=0;i<m;i++){
        int a, b;cin >> a >> b;a--;b--;
        g[a][b] = g[b][a] = 1;
    }
    vector<int> v;
    for(int i=0;i<n;i++) v.push_back(i);

    int ans = 0;
    do{
        if(v[0] != 0) continue;
        ans++;
        for(int i=0;i<n-1;i++){
            if(!g[v[i]][v[i+1]]){
                ans--;
                break;
            }
        }
    }while(next_permutation(v.begin(), v.end()));

    cout << ans << endl;
    return 0;
}
