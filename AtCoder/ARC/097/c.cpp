// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    string s;cin >> s;
    int k;cin >> k;
    int n = s.size();
    set<string> st;
    for(int i=1;i<=min(10, n);i++){
        for(int j=0;j<n-i+1;j++){
            st.insert(s.substr(j, i));
        }
    }
    vector<string> v;
    for(auto ss : st){
        v.push_back(ss);
    }
    sort(v.begin(), v.end());
    cout << v[k-1] << endl;
    return 0;
}
