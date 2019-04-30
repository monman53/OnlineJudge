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
#define CILING(a, b)    (((a)+(b)-1)/(b))

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}

vector<int> e[100];

int main() {
    int n, a, b;cin >> n >> a >> b;
    a--;b--;
    int m;cin >> m;
    for(int i=0;i<m;i++){
        int x, y;cin >> x >> y;
        x--;y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    
    vector<int> dst(n, INT_MAX);
    vector<LL> ans(n, 0LL);

    queue<PII> q;
    q.push({a, 0});
    dst[a] = 0;
    ans[a] = 1LL;
    while(!q.empty()){
        auto c = q.front();
        q.pop();
        int ci = c.first;
        int ccost = c.second;
        // if(ccost > dst[ci]){
        //     continue;
        // }
        for(auto ni : e[ci]){
            int ncost = ccost+1;
            if(dst[ni] == INT_MAX){
                dst[ni] = ncost;
                ans[ni] = (ans[ci] + ans[ni])%MOD;
                q.push({ni, ncost});
            }else if(dst[ni] == ncost){
                ans[ni] = (ans[ci] + ans[ni])%MOD;
            }
        }
    }

    // for(auto aans : ans){
    //     printf("%lld\n", aans);
    // }

    printf("%lld\n", ans[b]);

    return 0;
}
