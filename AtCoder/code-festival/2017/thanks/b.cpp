// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

bool kaibun(string s){
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] != s[n-i-1]) return false;
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    string s;cin >> s;
    int n = s.size();
    for(int i=0;i<n;i++){
        string ss = "";
        for(int j=0;j<i;j++){
            ss = s[j] + ss;
        }
        if(kaibun(s + ss)){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
