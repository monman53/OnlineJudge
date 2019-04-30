// header {{{
#include <bits/stdc++.h>
using namespace std;

// {u}{int,long,llong}_{max,min}
#define alphabet    (26)
#define inf         int_max
#define mod         (1000000007ll)
#define eps         (1e-10)
#define eq(a, b)        (abs((a)-(b)) < eps)
#define ciling(a, b)    (((a)+(b)-1ll)/(b))

template<class t>
using pit = pair<int, t>;
template<class t>
using pti = pair<t, int>;
using pii = pair<int, int>;
using pdi = pair<double, int>;
using ll  = long long;
using ull = unsigned long long;
// }}}

// 最大公約数
ll gcd(ll x, ll y) {
    return y ? gcd(y, x%y) : x;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    vector<ll> v(n, 1), u(m, 1);
    ll A[305][305];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll a;cin >> a;
            A[i][j] = a;
            if(gcd(v[i], u[j]) == a) continue;
            if(gcd(v[i]*a, u[j]) == a){
                v[i] *= a;
            }else if(gcd(v[i], u[j]*a) == a){
                u[j] *= a;
            }else if(gcd(v[i]*a, u[j]*a) == a){
                v[i] *= a;
                u[j] *= a;
            }else{
                cout << -1 << endl;
                return 0;
            }
            if(v[i] > 1000000000 || u[j] > 1000000000){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(gcd(v[i], u[j]) != A[i][j]){
                cout << -1 << endl;
                return 0;
            }
            if(v[i] > 1000000000 || u[j] > 1000000000){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for(auto vv : v) cout << vv << " ";
    cout << endl;
    for(auto uu : u) cout << uu << " ";
    cout << endl;
    
    return 0;
}
