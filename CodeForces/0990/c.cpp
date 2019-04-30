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
    map<int, LL> ma, mb;
    inc(i, 0, n){
        string s;cin >> s;
        int m = s.size();
        stack<char> st;
        int a = 0;
        int b = 0;
        inc(j, 0, m){
            char c = s[j];
            if(c == ')'){
                if(st.size() > 0){
                    if(st.top() == '('){
                        st.pop();
                        a--;
                    }else{
                        st.push(')');
                        b++;
                    }
                }else{
                    st.push(')');
                    b++;
                }
            }else{
                st.push('(');
                a++;
            }
        }

        if(a > 0 && b > 0){
            continue;
        }else{
            if(a == 0 && b == 0){
                ans += ma[a] + ma[b] + 1LL;
                ma[a]++;
                mb[b]++;
            }
            if(a > 0){
                ans += mb[a];
                ma[a]++;
            }
            if(b > 0){
                ans += ma[b];
                mb[b]++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
