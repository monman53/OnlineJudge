#include <bits/stdc++.h>
using namespace std;

int main() {
    // input
    int n;
    cin >> n;
    int a[2][100];
    for(int i=0;i<n;i++){
        cin >> a[0][i];
    }
    for(int i=0;i<n;i++){
        cin >> a[1][i];
    }

    // calc
    int ans = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            if(j <= i) sum += a[0][j];
            if(j >= i) sum += a[1][j];
        }
        ans = max(ans, sum);
    }

    // output
    cout << ans << endl;
    return 0;
}
