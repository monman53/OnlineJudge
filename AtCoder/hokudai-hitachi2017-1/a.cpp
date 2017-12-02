// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

// graph G
int n, m;
struct V {
    int id;
    vector<pair<int, int>> e;
    int sum;
};
vector<V> g;
vector<pair<int, pair<int, int>>> e;
int gf[500][500];
int gw[500][500];

// graph GE
int ne, me;
struct VE {
    vector<int> e;
    int g_id;
};
vector<VE> ge;
int gef[3600][3600];

// G -> GE map
vector<int> f;

int main() {
    std::ios::sync_with_stdio(false);

    // init
    memset(gf, 0, sizeof(gf));
    memset(gw, 0, sizeof(gw));
    memset(gef, 0, sizeof(gef));

    //----------------
    // input
    //----------------

    // input G
    cin >> n >> m;
    g.resize(n);
    for(int i=0;i<m;i++){
        int u, v, w;cin >> u >> v >> w;u--;v--;
        g[u].e.push_back({v, w});
        g[v].e.push_back({u, w});
        e.push_back({w, {u, v}});
        gf[u][v] = gf[v][u] = 1;
        gw[u][v] = gw[v][u] = w;
    }
    f.resize(n);
    for(int i=0;i<n;i++){
        f[i] = -1;
    }

    // input GE
    cin >> ne >> me;
    ge.resize(ne);
    for(int i=0;i<me;i++){
        int a, b;cin >> a >> b;a--;b--;
        ge[a].e.push_back(b);
        ge[b].e.push_back(a);
        gef[a][b] = gef[b][a] = 1;
    }
    for(int i=0;i<ne;i++){
        ge[i].g_id = -1;
    }


    //----------------
    // calc
    //----------------
    sort(e.begin(), e.end());
    reverse(e.begin(), e.end());

    for(int i=0;i<m;i++){
        int u = e[i].second.first;
        int v = e[i].second.second;
        //int w = e[i].first;

        // 既にどちらも張られている場合
        if(f[u] != -1 && f[v] != -1) continue;

        // どちらも張られていない時
        if(f[u] == -1 && f[v] == -1){
            for(int j=0;j<ne;j++){
                if(ge[j].g_id != -1) continue;
                ge[j].g_id = u;
                f[u] = j;

                int mmax = 0;
                int mmax_id = 0;
                for(int k : ge[j].e){
                    if(ge[k].g_id != -1) continue;
                    ge[k].g_id = v;
                    f[v] = k;
                    break;
                }
                break;
            }
            continue;
        }

        // 片方(u)が張られている時
        if(f[v] != -1) swap(u, v);
        for(int k : ge[f[u]].e){
            if(ge[k].g_id != -1) continue;
            ge[k].g_id = v;
            f[v] = k;
            break;
        }
    }

    // まだ張られていない頂点に関して
    for(int i=0;i<n;i++){
        if(f[i] == -1){
            for(int j=0;j<ne;j++){
                if(ge[j].g_id != -1) continue;
                ge[j].g_id = i;
                f[i] = j;
                break;
            }
        }
    }

    //----------------
    // output
    //----------------
    for(int i=0;i<n;i++){
        cout << i+1 << " " << f[i]+1 << endl;
    }

    return 0;
}
