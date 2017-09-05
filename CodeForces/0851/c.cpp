// header {{{
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

struct P {
    LL a, b, c, d, e;
};

LL angle(const P &p1, const P &p2) {
    return p1.a*p2.a + p1.b*p2.b + p1.c*p2.c + p1.d*p2.d + p1.e*p2.e;
}

P mainasu(const P &p1, const P &p2) {
    return P{p2.a-p1.a, p2.b-p1.b, p2.c-p1.c, p2.d-p1.d, p2.e-p1.e};
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<P> p(n);
    for(int i=0;i<n;i++){
        LL a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        p[i] = {a, b, c, d, e};
    }
    if(n < 3){
        cout << n << endl;
        for(int i=0;i<n;i++){
            cout << i+1 << endl;
        }
        return 0;
    }
    vector<int> ans;
    vector<bool> ok(n, true);
    for(int i=0;i<n;i++){
        bool flag = true;
        if(!ok[i]) continue;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(j == i || k == i || j == k) continue;
                if(angle(mainasu(p[i], p[j]), mainasu(p[i], p[k])) <= 0){
                    ok[j] = false;
                    ok[k] = false;
                }else{
                    flag = false;
                }
            }
        }
        if(flag) ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    for(auto anss : ans){
        cout << anss << endl;
    }
    return 0;
}
