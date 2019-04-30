#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin >> n;
    vector<int> h(n), dp(n+5, 1e9+5);
    for(int i=0;i<n;i++) cin >> h[i];
    dp[0] = 0;
    for(int i=0;i<n;i++){
        dp[i+1] = min(dp[i+1], dp[i]+abs(h[i+1]-h[i]));
        dp[i+2] = min(dp[i+2], dp[i]+abs(h[i+2]-h[i]));
    }
    cout << dp[n-1] << endl;
    return 0;
}
