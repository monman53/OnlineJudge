#include <iostream>
using namespace std;

int main(){
    while(1){
        int n,w,h;
        cin >> n;
        if(n == 0){
            break;
        }

        int sum[101][101];
        bool kaki[101][101];
        
        //init
        for(int i=0;i<101;i++){
            sum[i][0] = sum[0][i] = 0;
            for(int j=0;j<101;j++){
                kaki[i][j] = false;
            }
        }
        
        cin >> w >> h;
        for(int i=0;i<n;i++){
            int x,y;
            cin >> x >> y;
            kaki[y][x] = true;
        }

        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (kaki[i][j] ? 1 : 0);
            }
        }

        int s,t,max=0;
        cin >> s >> t;
        for(int i=t;i<=h;i++){
            for(int j=s;j<=w;j++){
                int now = sum[i][j] - sum[i-t][j] - sum[i][j-s] +sum[i-t][j-s];
                if(now >= max){
                    max = now;
                }
            }
        }
        cout << max << '\n';
    }
    return 0;
}
