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

bool check(char c) {
    switch(c){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    string s;cin >> s;
    int ans = 0;
    for(int i=0;i<n-1;i++){
        if(check(s[i]) && check(s[i+1])) ans++;
    }
    cout << ans << endl;
    return 0;
}
