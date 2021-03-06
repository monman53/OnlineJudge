// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, k;cin >> n >> k;
    priority_queue<pair<int, int>> pq;
    inc(i, 0, n){
        int x;cin >> x;
        if(i < k){
            pq.push({x, i});
        }
        if(i >= k-1){
            if(i != k-1){
                if(x < pq.top().first){
                    pq.pop();
                    pq.push({x, i});
                }
            }
            cout << pq.top().second+1 << endl;
        }
    }
    return 0;
}
