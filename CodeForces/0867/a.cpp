// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    string s;cin >> s;
    int sc = 0;
    int fc = 0;
    for(int i=1;i<n;i++){
        if(s[i-1] == 'S' && s[i] == 'F'){
            sc++;
        }
        if(s[i-1] == 'F' && s[i] == 'S'){
            fc++;
        }
    }
    if(sc > fc){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
