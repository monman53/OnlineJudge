// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         LLONG_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

struct ES {
    int from;
    int to;
    LL cost;
};

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    vector<ES> es;
    for(int i=0;i<m;i++){
        int a, b;LL c;cin >> a >> b >> c;
        a--;b--;
        c *= -1;
        es.push_back({a, b, c});
    }

    // shortest path
    vector<LL> d(n, INF);
    d[0] = 0;
    for(int i=0;i<n-1;i++){
        for(auto e : es){
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
            }
        }
    }

    vector<bool> neg(n);
    for(int i=0;i<n;i++){
        for(auto e : es){
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                neg[e.to] = true;
            }
            if(neg[e.from]) neg[e.to] = true;
        }
    }

    if(neg[n-1]){
        cout << "inf" << endl;
    }else{
        cout << -d[n-1] << endl;
    }

    return 0;
}
