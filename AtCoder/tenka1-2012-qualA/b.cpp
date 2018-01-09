// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(r);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    string s;getline(cin, s);
    int n = s.size();
    bool flag = false;
    inc(i, 0, n-1){
        if(s[i] == ' ' && !flag){
            cout << ',';
            flag = true;
        }else if(s[i] != ' '){
            flag = false;
            cout << s[i];
        }
    }
    cout << s[n-1] << endl;
    return 0;
}
