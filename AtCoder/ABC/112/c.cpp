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
    vector<int> x(n), y(n), h(n);
    inc(i, 0, n) cin >> x[i] >> y[i] >> h[i];
    inc(cx, 0, 101){
        inc(cy, 0, 101){
            set<int> st;
            int H;
            inc(i, 0, n){
                if(h[i] > 0){
                    H = h[i] + abs(x[i]-cx) + abs(y[i]-cy);
                    st.insert(H);
                }
            }
            if(st.size() == 1){
                bool f = true;
                inc(i, 0, n){
                    if(h[i] != max(H-abs(x[i]-cx)-abs(y[i]-cy), 0)){
                        f = false;
                    }
                }
                if(f){
                    cout << cx << " " << cy << " " << H << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
