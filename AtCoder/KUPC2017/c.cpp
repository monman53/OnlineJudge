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

int C(char c){
    return c-'a'+1;
}

int main() {
    std::ios::sync_with_stdio(false);
    LL a;cin >> a;
    string s;cin >> s;
    int n = s.size();
    vector<LL> c(n+1);
    for(int i=1;i<=n;i++){
        c[i] = C(s[i-1]);
    }
    while(true){
        bool flag = true;
        for(int i=1;i<=n;i++){
            LL k = a;
            LL j = i+1;
            for(; k<=26&&j<=n; k*=a,j++){
                for(int l=c[j];l>0;l--){
                    if(l*k+c[i] <= 26){
                        c[i] += l*k;
                        c[j] -= l;
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag) break;
    }
    for(int i=1;i<=n;i++){
        if(c[i] == 0) break;
        cout << char('a'+c[i]-1);
    }
    cout << endl;
    return 0;
}
