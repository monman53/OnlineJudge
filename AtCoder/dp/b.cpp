#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin >> n;
    int k;cin >> k;
    vector<long long> h(n+k+5), dp(n+k+5, 1e9+5);
    for(int i=0;i<n;i++) cin >> h[i];
    dp[0] = 0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++){
            dp[i+j] = min(dp[i+j], dp[i]+abs(h[i+j]-h[i]));
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}
