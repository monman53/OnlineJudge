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
    int n;cin >> n;
    LL ans = 0;
    queue<string> q;
    q.push("3");
    q.push("5");
    q.push("7");
    while(!q.empty()){
        auto s = q.front();q.pop();
        set<char> st;
        for(auto c : s) st.insert(c);
        if(stoi(s) <= n && st.size() == 3) ans++;
        if(s.size() == 9) continue;
        q.push("3"+s);
        q.push("5"+s);
        q.push("7"+s);
    }
    cout << ans << endl;
    return 0;
}
