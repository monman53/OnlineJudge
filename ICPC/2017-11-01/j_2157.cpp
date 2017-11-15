#include <bits/stdc++.h>
using namespace std;

int main() {
    while(true){
        int k;cin >> k;
        if(k == 0) break;
        string s, t;cin >> s >> t;
        int dp[11][11];
        for(int i=0;i<=k;i++){
            for(int j=0;j<=k;j++){
                dp[i][j] = 100;
            }
        }

        for(int i=1;i<=k;i++){
            for(int j=0;j+i<=k;j++){
                bool flag = true;
                int diff = int(s[j] - t[j]);
                for(int l=0;l<i;l++){
                    int m = j+l;
                    if(int(s[m] - t[m]) != diff){
                        flag = false;
                    }
                }
                if(flag){
                    dp[j][j+i] = 1;
                    cout << diff << " " <<  j << " " << j+i << endl;
                }
                for(int l=1;l<i;l++){
                    dp[j][j+i] = min(dp[j][j+i], dp[j][j+l]+dp[j+l][j+i]);
                }
            }
        }

        /*
        for(int i=0;i<=k;i++){
            for(int j=0;j<=k;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        */

        cout << dp[0][k] << endl;
    }
    return 0;
}
