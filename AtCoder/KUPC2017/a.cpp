// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, k;cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
        if(sum >= k){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
