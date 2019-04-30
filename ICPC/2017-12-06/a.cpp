// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

bool check(int n) {
    int b = n%10+1;
    while(n > 0){
        int a = n%10;
        if(b-a != 1){
            return false;
        }
        b = a%10;
        n /= 10;
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans = -1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(check(a[i]*a[j])){
                ans = max(ans, a[i]*a[j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
