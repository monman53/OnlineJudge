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
    int n;cin >> n;
    set<string> st;
    vector<string> s(n);
    inc(i, 0, n) cin >> s[i];
    st.insert(s[0]);
    inc(i, 1, n){
        if(st.find(s[i]) != st.end() ||
           s[i][0] != s[i-1][s[i-1].size()-1]){
            if(i%2 == 0){
                cout << "LOSE" << endl;
            }else{
                cout << "WIN" << endl;
            }
            return 0;
        }
        st.insert(s[i]);
    }
    cout << "DRAW" << endl;
    return 0;
}
