// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

// Union-Find {{{
// verified AOJ DSL_1_A
struct UF {
    vector<int> p;  // parent
    vector<int> r;  // rank

    UF(int n) {
        p.resize(n);
        r.resize(n);
        for(int i=0;i<n;i++){
            p[i] = i;
            r[i] = 1;
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
        if(r[x] < r[y]){
            p[x] = y;
        }else{
            p[y] = x;
            if(r[x] == r[y]){
                r[x]++;
            }
        }
    }
}; // }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    int a[50], b[50];
    for(int i=0;i<m;i++){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
    }

    int ans = 0;

    for(int i=0;i<m;i++){
        UF uf(n);
        for(int j=0;j<m;j++){
            if(i != j){
                uf.unite(a[j], b[j]);
            }
        }
        bool flag = false;
        for(int j=0;j<n;j++){
            if(uf.find(0) != uf.find(j)){
                flag = true;
            }
        }
        if(flag) ans++;
    }

    cout << ans << endl;

    return 0;
}
