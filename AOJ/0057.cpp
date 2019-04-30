#include <iostream>
using namespace std;

int main(){
    int sum[10001];
    sum[0] = 1;
    for(int i=1;i<10001;i++){
        sum[i] = sum[i-1] + i;
    }
    int n;
    while(cin >> n){
        cout << sum[n] << '\n';
    }
    return 0;
}
