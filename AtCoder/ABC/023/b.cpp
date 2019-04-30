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
    int n;cin >> n;
    string s;cin >> s;
    string now = "b";
    int step = 0;
    while(true){
        if(now == s){
            cout << step << endl;
            break;
        }
        if((int)now.size() > n){
            cout << -1 << endl;
            break;
        }
        step++;
        switch(step%3){
            case 1:
                now = "a" + now + "c";
                break;
            case 2:
                now = "c" + now + "a";
                break;
            case 0:
                now = "b" + now + "b";
                break;
        }
    }
    return 0;
}
