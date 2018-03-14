// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

struct E {
    int to, w;
};
 
using G = vector<vector<E>>;
 
template <typename T>
pair<vector<T>, vector<int>> dijkstra(G g, int s, T inf) {
    int n = g.size();
    vector<T> d(n, inf);
    vector<int> r(n, -1);
    d[s] = 0;
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        auto c = pq.top();pq.pop();
        if(d[c.second] < c.first) continue;
        for(auto e : g[c.second]){
            if(d[e.to] > d[c.second] + e.w){
                d[e.to] = d[c.second] + e.w;
                r[e.to] = c.second;
                pq.push({d[e.to], e.to});
            }
        }
    }
    return {d, r};
}

int main() {
    std::ios::sync_with_stdio(false);
    int h, w, t;cin >> h >> w >> t;
    int si, sj;
    int ti, tj;
    vector<string> c(h);
    G g(h*w);
    inc(i, 0, h){
        cin >> c[i];
        inc(j, 0, w){
            if(c[i][j] == 'S'){
                si = i;
                sj = j;
            }
            if(c[i][j] == 'G'){
                ti = i;
                tj = j;
            }
        }
    }
    inc(i, 0, h){
        inc(j, 0, w){
            inc(k, 0, 4){
                int ni = i + di[k];
                int nj = j + dj[k];
                if(ni >= 0 && ni < h && nj >= 0 && nj < w){
                    if(c[ni][nj] == '#'){
                        g[i*w+j].push_back({ni*w+nj, 0});
                    }else{
                        g[i*w+j].push_back({ni*w+nj, 1});
                    }
                }
            }
        }
    }

    LL ok = 1;
    LL ng = 1000000000;
    while(ng-ok>1){
        LL m = (ok+ng)/2;
        inc(i, 0, h*w){
            for(auto &e : g[i]){
                if(e.w != 1){
                    e.w = m;
                }
            }
        }
        auto d = dijkstra<LL>(g, si*w+sj, LLONG_MAX/3).first;
        //cout << d[ti*w+tj] << endl;
        if(d[ti*w+tj]<=t){
            ok = m;
        }else{
            ng = m;
        }
    }

    cout << ok << endl;

    return 0;
}
