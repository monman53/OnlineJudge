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
    while(true){
        int N, Q;cin >> N >> Q;
        if(N == 0) break;
        UF uf(N);
        vector<int> p(N);
        vector<PTI<char>> q;
        map<int, bool> m;
        p[0] = 0;
        m[0] = true;
        for(int i=1;i<N;i++){
            cin >> p[i];p[i]--;
            m[i] = false;
        }
        for(int i=0;i<Q;i++){
            PTI<char> qq;
            cin >> qq.first >> qq.second;
            qq.second--;
            if(qq.first == 'M'){
                if(m[qq.second]){
                    continue;
                }
                m[qq.second] = true;
            }
            q.push_back(qq);
        }
        for(int i=0;i<N;i++){
            if(!m[i]){
                uf.unite(i, p[i]);
            }
        }

        reverse(q.begin(), q.end());

        int ans = 0;
        for(int i=0;i<Q;i++){
            if(q[i].first == 'Q'){
                ans += uf.find(q[i].second) + 1;
                // cout << ans << endl;
            }else{
                uf.unite(q[i].second, p[q[i].second]);
                cout << q[i].second << endl;
                cout << uf.find(q[i].second) << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}