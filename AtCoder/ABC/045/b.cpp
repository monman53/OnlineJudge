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
#define CILING(a, b)    (((a)+(b)-1)/(b))

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}

int main() {
    queue<int> q[3];
    for(int i=0;i<3;i++){
        string s;cin >> s;
        for(auto c : s){
            q[i].push(int(c-'a'));
        }
    }
    int t = 0;
    while(true){
        if(q[t].empty()) break;
        int nt = q[t].front();
        q[t].pop();
        t = nt;
    }
    cout << char('A'+t) << endl;
    return 0;
}
