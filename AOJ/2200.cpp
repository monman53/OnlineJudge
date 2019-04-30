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
using PTT = pair<T, T>;
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
    int to;
    int w;
    char sl;
};

int d[200][200][10000];

int main() {
    while(true){
        int n, m;cin >> n >> m;
        if(n == 0) break;
        vector<vector<E>> g(n);
        for(int i=0;i<m;i++){
            int x, y, t;char sl;cin >> x >> y >> t >> sl;x--;y--;
            g[x].push_back({y, t, sl});
            g[y].push_back({x, t, sl});
        }

        int r;cin >> r;
        vector<int> z(r);
        for(auto &zz : z){
            cin >> zz;zz--;
        }

        if(r == 1){
            cout << 0 << endl;
            continue;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<r;k++){
                    d[i][j][k] = INF;
                }
            }
        }
        d[z[0]][z[0]][0] = 0;
        priority_queue<PTT<PII>, vector<PTT<PII>>, greater<PTT<PII>>> pq;
        pq.push({{0, z[0]}, {z[0], 0}});
        int now = 0;
        while(!pq.empty()){
            auto c = pq.top();pq.pop();
            int cd = c.first.first;
            int ci = c.first.second;
            int cm = c.second.first;
            int cz = c.second.second;
            if(!(cz < r-1)) continue;
            if(d[ci][cm][cz] < cd) continue;
            if(cz < now-1) continue;
            if(z[cz+1] == ci){
                now = max(now, cz+1);
                pq.push({{cd, ci}, {cm, cz+1}});
                continue;
            }
            for(auto e : g[ci]){
                int nd = cd + e.w;
                int ni = e.to;
                int nm = cm;
                int nz = cz;
                if(e.sl == 'S'){
                    if(ci != cm) continue;
                    nm = e.to;
                }
                if(cd + e.w < d[e.to][nm][cz]){
                    d[e.to][nm][cz] = nd;
                    pq.push({{nd, ni}, {nm, nz}});
                }
            }
        }
        int ans = INF;
        for(int i=0;i<n;i++){
            ans = min(ans, d[z[r-1]][i][r-2]);
        }
        cout << ans << endl;
    }
    return 0;
}
