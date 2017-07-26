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
    string s;cin >> s;
    int n = s.size();
    char c = s[0];
    int count = 0;
    for(int i=0;i<n;i++){
        if(s[i] == c){
            count++;
        }else{
            cout << c << count;
            c = s[i];
            count = 1;
        }

        if(i == n-1){
            cout << c << count;
        }
    }
    cout << endl;
    return 0;
}
