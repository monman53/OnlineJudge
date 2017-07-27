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
    string s;cin >> s;
    for(int i=0;i<int(s.size());i++){
        char c = s[i];
        c = ('A' <= c && c <= 'Z' ? char(c-'A'+'a') : c);
        switch(c){
            case 'a':
            case 'o':
            case 'y':
            case 'e':
            case 'u':
            case 'i':
                break;
            default:
                cout << '.' << c;
                break;
        }
    }
    cout << endl;
    return 0;
}
