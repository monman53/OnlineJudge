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

int n;
vector<int> v;
vector<vector<int>> g;
vector<int> ans;

// 最大公約数
LL gcd(LL x, LL y) {
    return y ? gcd(y, x%y) : x;
}

int solve(int from, int i) {
    if(g[i].size() == 1 && i != 0){
        return v[i];
    }
    for(int i=0;i<
}

int main() {
    scanf("%d", &n);
    v.resize(n);
    g.resize(n);
    ans.resize(n);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d", &a);
        v[i] = a;
    }
    for(int i=0;i<n-1;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    solve(-1, 0);
    if(n == 1){
        printf("%d\n", v[0]);
    }
    for(int i=0;i<n;i++){
        printf("%d", ans[i]);
        if(i != n-1) printf(" ");
    }
    printf("\n");
    return 0;
}
