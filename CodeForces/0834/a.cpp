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

int main() {
    string c = ">^<v";
    char s, t;cin >> s >> t;
    int n;cin >> n;n%=4;
    if(n == 0 || n == 2){
        cout << "undefined" << endl;
    }else{
        int i;
        for(i=0;i<4;i++){
            if(s == c[i]) break;
        }
        if(c[(i+n)%4] == t){
            cout << "ccw" << endl;
        }else{
            cout << "cw" << endl;
        }
    }
    return 0;
}
