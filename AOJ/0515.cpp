#include <iostream>
using namespace std;

int main(){
    while(1){
        int a,b,n;
        int count[17][17];
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        for(int i=0;i<=a;i++){
            for(int j=0;j<=b;j++){
                count[i][j] = -1;
                count[0][j] = 0;
            }
            count[i][0] = 0;
        }
        cin >> n;
        count[1][1] = 1;
        for(int i=0;i<n;i++){
            int ii,jj;
            cin >> ii >> jj;
            count[ii][jj] = 0;
        }
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(count[i][j] == -1){
                    count[i][j] = count[i-1][j] + count[i][j-1];
                }
//                cout << '(' << i << ',' << j << ')'<< count[i][j];
            }
//            cout << '\n';
        }
        cout << count[a][b] << '\n';
    }
    return 0;
}
