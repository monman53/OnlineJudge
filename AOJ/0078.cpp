#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int data[15][15];
    int n;
    while(1){
        cin >> n;
        if(n == 0) break;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                data[i][j] = 0;
            }
        }
        int ni,nj;
        ni = n/2 + 1;
        nj = n/2;
        for(int i=1;i<=n*n;i++){
            ni = ni%n;
            nj = nj%n;
            if(data[ni][nj] == 0){
                data[ni][nj] = i;
                ni++;
                nj++;
            }else{
                i--;
                nj += n - 1;
                ni += n + 1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //cout << data[i][j] << ' ';
                printf("%4d",data[i][j]);
            }
            cout << '\n';
        }
    }
    return 0;
}
