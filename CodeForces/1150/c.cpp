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
    int n1 = 0;
    int n2 = 0;
    inc(i, 0, n){
        int a;cin >> a;
        if(a == 1){
            n1++;
        }else{
            n2++;
        }
    }
    vector<int> ans;
    if(n1 > 0){
        if(n2 > 0){
            ans.pb(2);
            n2--;
            ans.pb(1);
            n1--;
        }
    }
    while(n1 > 0 || n2 > 0){
        if(n2 > 0){
            ans.pb(2);
            n2--;
        }else{
            ans.pb(1);
            n1--;
        }
    }
    inc(i, 0, n){
        cout << ans[i];
        if(i < n-1){
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
