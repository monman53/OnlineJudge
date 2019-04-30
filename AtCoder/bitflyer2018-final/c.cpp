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

vector<int> v;
LL ans = 0LL;

void dfs(int l, int r) {
    //cout << l << " " << r << endl;
    if(r-l == 1) return;
    LL cnt = 0LL;
    inc(i, l+1, r){
        dfs(i, v[i]);
        i = v[i];
        cnt++;
    }
    ans += cnt*(cnt+1LL)/2LL;
    //if(hoge == 0) cout << "hoge" << endl;
    return;
}

void solve(string ss) {
    int m = ss.size();
    v.clear();
    v.resize(m);

    stack<int> st2;
    inc(i, 0, m){
        if(ss[i] == '('){
            st2.push(i);
        }else{
            if(st2.size() > 0){
                int j = st2.top();
                st2.pop();
                v[i] = j;
                v[j] = i;
            }
        }
    }

    LL cnt = 0LL;
    inc(i, 0, m){
        //cout << i << " " << v[i] << endl;
        dfs(i, v[i]);
        cnt++;
        i = v[i];
    }
    ans += cnt*(cnt+1LL)/2LL;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    deque<char> dq;
    string s;cin >> s;
    int n = s.size();
    string t = s;
    stack<int> st;
    inc(i, 0, n){
        if(s[i] == '('){
            st.push(i);
        }else{
            if(st.size() > 0){
                int j = st.top();
                st.pop();
                t[j] = ' ';
                t[i] = ' ';
            }
        }
    }

    string ss = "";
    inc(i, 0, n){
        if(t[i] == ' '){
            ss.pb(s[i]);
        }else{
            //cout << ss << endl;
            solve(ss);
            ss = "";
        }
    }
    solve(ss);
    cout << ans << endl;
    return 0;
}
