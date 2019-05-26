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

int n, k;
int V[50];

int solve(int take) {
    deque<int> q;
    inc(i, 0, n){
        q.push_back(V[i]);
    }

    int anss = 0;

    inc(i, 0, take+1){
        vector<int> v;
        deque<int> dq = q;
        int a = i;
        int b = take-i;
        while(dq.size() && a > 0){
            v.pb(dq.front());
            dq.pop_front();
            a--;
        }

        while(dq.size() && b > 0){
            v.pb(dq.back());
            dq.pop_back();
            b--;
        }

        sort(v.begin(), v.end());
        int m = v.size();
        int ans = 0;
        int res = k-take;
        inc(i, 0, m){
            if(v[i] < 0 && res > 0){
                res--;
                continue;
            }
            ans += v[i];
        }

        anss = max(ans, anss);
    }

    return anss;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    cin >> n >> k;
    inc(i, 0, n){
        cin >> V[i];
    }

    int ans = 0;
    inc(i, 0, k+1){
        ans = max(ans, solve(i));
    }
    cout << ans << endl;
    return 0;
}
