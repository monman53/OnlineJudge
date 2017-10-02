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
    LL n, m;cin >> n >> m;

    vector<V> v(n);
    for(int i=0;i<n;i++){
        LL vv;cin >> vv;
        v[i] = {i, vv, {}};
    }

    vector<K> k(m);
    map<int, bool> mk;
    for(int i=0;i<m;i++){
        int x, y;cin >> x >> y;x--;y--;
        if(x > y){
            swap(x, y);
        }
        k[i] = {i, x, y, -abs(v[x].v-v[y].v)};
        mk[i] = false;
    }
    vector<K> k2 = k;
    sort(k.begin(), k.end(), [](K &k1, K &k2){return k1.m < k2.m;});
    for(int i=0;i<m;i++){
        int id = k[i].id;
        int x = k[i].x;
        int y = k[i].y;
        v[x].k.push_back(id);
        v[y].k.push_back(id);
    }

    LL sum = 0;
    sort(k.begin(), k.end(), [](K &k1, K &k2){
            if(k1.x == k2.x){
                return k1.y < k2.y;
            }else{
                return k1.x < k2.x;
            }
            });
    for(int i=0;i<m;i++){
        if(mk[i]) continue;
        if(k[i].x == k[i].y){
            mk[k[i].id] = true;
            sum += v[k[i].x].v;
            v[k[i].x].v = 0;
        }
    }
    for(int i=0;i<m-1;i++){
        if(mk[i]) continue;
        if(k[i].x == k[i+1].x && k[i].y == k[i+1].y){
            mk[k[i].id] = true;
            mk[k[i+1].id] = true;
            sum += v[k[i].x].v + v[k[i].y].v;
            v[k[i].x].v = 0;
            v[k[i].y].v = 0;
        }
    }

    sort(v.begin(), v.end(), [](V &v1, V &v2){return v1.v < v2.v;});
    reverse(v.begin(), v.end());
    /*
    for(int i=0;i<n;i++){
        v[i].sid = i;
    }
    */
    for(int i=0;i<n;i++){
        if(v[i].v == 0) continue;
        //int ni = -1;
        //int nk = -1;
        for(auto kk : v[i].k){
            if(!mk[kk]){
                /*
                int x = v[k2[kk].x].sid;
                int y = v[k2[kk].y].sid;
                int nni = 0;

                if(x == i){
                    nni = y;
                }else{
                    nni = x;
                }

                if(nni < i){
                    nk = kk;
                    break;
                }

                if(nni > ni){
                    ni = nni;
                    nk = kk;
                }
                */
                sum += v[i].v;
                mk[kk] = true;
                break;
            }
        }
        /*
        if(nk != -1){
            cout << nk << endl;
            sum += v[i].v;
            mk[nk] = true;
        }
        */
        //cout << v[i].v << " " << sum << endl;
        //for(auto kk : v[i].k){
            //cout << kk << " ";
        //}
        //cout << endl;
    }
    cout << sum << endl;
    return 0;
}
