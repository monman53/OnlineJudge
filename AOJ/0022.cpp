#include <iostream>
using namespace std;

int main(){
    while(1){
        int n;
        long long int sum[5001];
        int a;
        long long int max=-1000000,maxi;
        cin >> n;
        if(n == 0){
            break;
        }
        sum[0] = 0;
        for(int i=0;i<n;i++){
            cin >> a;
            sum[i+1] = sum[i] + a;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(sum[i] - sum[j] > max){
                    max = sum[i] -sum[j];
                }
            }
        }
        cout << max << '\n';
    }
    return 0;
}
