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

bool isPrime(int n) {
    if(n == 2) return true;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    inc(i, 1, 55555){
        if(isPrime(10*i+1)){
            p.push_back(10*i+1);
            //cout << 10*i-1 << endl;
        }
        if(p.size() == 60){
            break;
        }
    }

    int n;cin >> n;
    inc(i, 0, n){
        cout << p[i];
        if(i != n-1){
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
