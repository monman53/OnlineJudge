#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin >> n;
    string m[500];
    for(int i=0;i<n;i++){
        cin >> m[i];
    }
    int ans = 0;
    int di[] = {-1, -1, 1, 1};
    int dj[] = {1, -1, -1, 1};
    for(int i=1;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            if(m[i][j] == 'X'){
                int cnt = 0;
                for(int k=0;k<4;k++){
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    cnt += m[ni][nj] == 'X';
                }
                ans += cnt == 4;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
