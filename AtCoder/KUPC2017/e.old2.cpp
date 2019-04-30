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

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

struct V {
    int id;
    LL v;
    vector<int> k;
};

struct K {
    int id;
    int x, y;
    LL m;
};

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;

    // v
    vector<V> v(n);
    for(int i=0;i<n;i++){
        LL vv;cin >> vv;
        v[i] = {i, vv, {}};
    }
    sort(v.begin(), v.end(), [](V &v1, V &v2){return v1.v < v2.v;});
    reverse(v.begin(), v.end());
    map<int, int> mmap;
    for(int i=0;i<n;i++){
        mmap[v[i].id] = i;
    }

    // k
    vector<K> k(m);
    map<int, bool> mk;
    for(int i=0;i<m;i++){
        int x, y;cin >> x >> y;x--;y--;
        int nx = mmap[x];
        int ny = mmap[y];
        if(nx > ny){
            swap(nx, ny);
        }
        k[i] = {i, nx, ny, v[ny].v};
        mk[i] = false;
    }

    vector<K> ks = k;
    sort(ks.begin(), ks.end(), [](K &k1, K &k2){
            return k1.m < k2.m;
            });
    for(int i=0;i<m;i++){
        int id = ks[i].id;
        int x = k[id].x;
        int y = k[id].y;
        v[x].k.push_back(id);
        v[y].k.push_back(id);
    }

    // solve
    LL ans = 0;

    sort(ks.begin(), ks.end(), [](K &k1, K &k2){
            if(k1.x == k2.x){
                return k1.y < k2.y;
            }else{
                return k1.x < k2.x;
            }
            });
    for(int i=0;i<m;i++){
        if(ks[i].x == ks[i].y){
            ans += v[ks[i].x].v;
            v[ks[i].x].v = 0;
            mk[ks[i].id] = true;
        }
    }
    for(int i=0;i<m-1;i++){
        if(mk[ks[i].id]) continue;
        if(ks[i].x == ks[i+1].x && ks[i].y == ks[i+1].y){
            ans += v[ks[i].x].v;
            ans += v[ks[i].y].v;
            v[ks[i].x].v = 0;
            v[ks[i].y].v = 0;
            mk[ks[i].id] = true;
            mk[ks[i+1].id] = true;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(v[i].v == 0) continue;
        for(auto kk : v[i].k){
            if(!mk[kk]){
        }
    }
    /*
    for(int i=0;i<n;i++){
        cout << v[i].v << " ";
        for(auto kk : v[i].k){
            cout << kk << " ";
        }
        cout << endl;

        if(v[i].v == 0) continue;
        for(auto kk : v[i].k){
            if(!mk[kk] && k[kk].y == i){
                cout << "###########" << endl; 
                ans += v[i].v;
                v[i].v = 0;
                mk[kk] = true;
                break;
            }
        }
        if(v[i].v == 0) continue;
        for(auto kk : v[i].k){
            if(!mk[kk] && k[kk].x == i && v[k[kk].y].v == 0){
                cout << "@@@@@@@@@@@" << endl; 
                ans += v[i].v;
                v[i].v = 0;
                mk[kk] = true;
                break;
            }
        }
        if(v[i].v == 0) continue;
        for(auto kk : v[i].k){
            if(!mk[kk]){
                ans += v[i].v;
                mk[kk] = true;
                break;
            }
        }
    }
    */

    cout << ans << endl;

    return 0;
}
