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
    if(n == 3){
        cout << "2 5 63" << endl;
        return 0;
    }
    if(n == 4){
        cout << "3 9 2 4" << endl;
        return 0;
    }
    queue<int> a, b, c;

    inc(i, 2, 30001){
        if(i%2 == 0){
            if(i%3 == 0){
                b.push(i);
            }else{
                a.push(i);
            }
        }else{
            if(i%3 == 0){
                c.push(i);
            }
        }
    }

    vector<int> ans;

    int m = n-2;
    while(c.size() > 1 && m > 1){
        m-=2;
        ans.pb(c.front());
        c.pop();
        ans.pb(c.front());
        c.pop();
    }
    m+=2;

    inc(i, 0, m/3*3){
        if(i%3 == 0 || i%3 == 1){
            ans.pb(a.front());
            a.pop();
        }else{
            ans.pb(b.front());
            b.pop();
        }
    }

    if(m%3 == 2){
        ans.pb(a.front());a.pop();
        ans.pb(a.front());a.pop();
    }
    if(m%3 == 1){
        ans.pb(b.front());b.pop();
    }


    inc(i, 0, n){
        cout << ans[i];
        if(i != n){
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
