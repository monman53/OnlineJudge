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

struct E {
    int to, w, c;
};

int main() {
    while(true){
        int n, m;cin >> n >> m;
        vector<vector<E>> g(n);
        if(n == 0) break;
        for(int i=0;i<m;i++){
            int u, v, d, c;cin >> u >> v >> d >> c;u--;v--;
            g[u].push_back({v, d, c});
            g[v].push_back({u, d, c});
        }

        priority_queue<PTI<PII>, vector<PTI<PII>>, greater<PTI<PII>>> pq;
        vector<PII> dc(n, {INT_MAX, INT_MAX});
        dc[0] = {0, 0};
        pq.push({{0, 0}, 0});
        int ans = 0;
        while(!pq.empty()){
            auto c = pq.top();
            pq.pop();
            int ci = c.second;
            int cd = c.first.first;
            int cc = c.first.second;
            if(dc[ci] < PII{cd, cc}) continue;
            ans += cc;
            for(auto e : g[ci]){
                PII ndc = {dc[ci].first+e.w, e.c};
                if(dc[e.to] > ndc){
                    dc[e.to] = ndc;
                    pq.push({ndc, e.to});
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
