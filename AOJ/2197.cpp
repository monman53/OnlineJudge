#include <iostream>
#define MAX 10001
using namespace std;

int main(){
    int sum[MAX];
    sum[0] = 0;
    for(int i=1;i<MAX;i++){
        sum[i] = sum[i-1] + i;
    }
    while(1){
        int n,count;
        cin >> n;
        if(n == 0){
            break;
        }
        count = 0;
        for(int i=2;i<MAX;i++){
            for(int j=0;j<i-1;j++){
                if(sum[i]-sum[j] == n){
                    count++;
                    break;
                }
            }
        }
        cout << count << '\n';
    }
                   
    return 0;
}
