// header {{{
// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
// #define EQ(a, b)    (abs((a)-(b)) < EPS)
inline bool EQ(double a, double b) {return abs(a-b) < EPS;}
// ciling(x/y) = (x+y-1)/y

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
    int count = 1;
    char c = s[0];
    for(int i=1;i<n;i++){
        if(s[i] == '1'){
            count++;
        }else{
            if(c == '0'){
                cout << '0';
            }else{
                cout << count;
                count = 0;
            }
        }
        c = s[i];
    }
    cout << count << endl;
    return 0;
}
