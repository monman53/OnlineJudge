// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

// Union-Find (short) {{{
struct UF_short {
    vector<int> p;  // parent

    UF_short(int n) {
        p.resize(n);
        for(int i=0;i<n;i++){
            p[i] = i;
        }
    }

    int find(int x) {
        if(x == p[x]){
            return x;
        }else{
            return p[x] = find(p[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        p[y] = p[x];
    }
}; // }}}


int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<LL> A(n);
    UF_short uf(n);
    inc(i, 0, n) cin >> A[i];
    inc(i, 0, m){
        int x, y;cin >> x >> y;
        uf.unite(x, y);
    }
    using T = priority_queue<LL, vector<LL>, greater<LL>>;
    map<int, T> mmap;
    inc(i, 0, n){
        mmap[uf.find(i)].push(A[i]);
    }

    LL ans = 0;

    for(auto &kv : mmap){
        ans += kv.second.top();
        kv.second.pop();
    }

    T pq;
    for(auto &kv : mmap){
        while(!kv.second.empty()){
            pq.push(kv.second.top());
            kv.second.pop();
        }
    }

    int l = mmap.size();

    if(l == 1){
        cout << 0 << endl;
        return 0;
    }
    inc(i, 0, (l-1)*2-l){
        if(pq.empty()){
            cout << "Impossible" << endl;
            return 0;
        }
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;

    return 0;
}
