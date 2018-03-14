#include <bits/stdc++.h>
using namespace std;

int n, k;
int imos[1000*4][1000*4];

int main() {

    // input
    cin >> n >> k;
    while(n--){
        int x, y;
        char c;
        cin >> x >> y >> c;
        if(c == 'W') x += k;
        x %= 2*k;
        y %= 2*k;

        // +1, -1 for 2D-imos
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                int xx = x%k+i*k+1;
                int yy = y%k+j*k+1;
                if((xx+yy)%(2*k) != (x+1+y+1)%(2*k)) continue;
                if(xx+k < 4*k && yy+k < 4*k){
                    imos[xx][yy]++;
                    imos[xx+k][yy]--;
                    imos[xx][yy+k]--;
                    imos[xx+k][yy+k]++;
                }
            }
        }
    }

    // 2D-imos
    int ans = 0;
    for(int i=0;i<4*k;i++){
        for(int j=1;j<4*k;j++){
            imos[i][j] += imos[i][j-1];
        }
    }
    for(int i=1;i<4*k;i++){
        for(int j=0;j<4*k;j++){
            imos[i][j] += imos[i-1][j];
            ans = max(ans, imos[i][j]);
        }
    }

    // output
    cout << ans << endl;

    return 0;
}
