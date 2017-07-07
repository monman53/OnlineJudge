// header {{{
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    26
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
#define INF         1000000005

typedef long long ll;
typedef unsigned long long ull;
// }}}
// data structure {{{

// Union-Find
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
};
//}}}

int main() {
    int n, k, l;cin >> n >> k >> l;
    UF ufp(n), ufr(n);
    for(int i=0;i<k;i++){
        int a, b;cin >> a >> b;a--;b--;
        ufp.unite(a, b);
    }
    for(int i=0;i<l;i++){
        int a, b;cin >> a >> b;a--;b--;
        ufr.unite(a, b);
    }

    map<pair<int, int>, int> m;

    for(int i=0;i<n;i++){
        pair<int, int> p = {ufp.find(i), ufr.find(i)};
        m[p]++;
    }

    for(int i=0;i<n;i++){
        pair<int, int> p = {ufp.find(i), ufr.find(i)};
        cout << m[p] << " ";
    }
    cout << endl;
    return 0;
}
