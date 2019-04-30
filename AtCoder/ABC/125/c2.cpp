#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin >> n;
    int v[20];
    int c[20];
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) cin >> c[i];

    int ans = 0;
    for(int bit=0;bit<(1<<n);bit++){
        int sum = 0;
        for(int i=0;i<n;i++){
            if((bit >> i) & 1){
                sum += v[i] - c[i];
            }
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
