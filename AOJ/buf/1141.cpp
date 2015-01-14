#include <iostream>
using namespace std;

int main(){
    bool isPrime[1000000];
    for(int i=0;i<1000000;i++){
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = 0;
    for(int i=2;i*i<1000000;i++){
        if(isPrime[i]){
            for(int j=2;i*j<1000000;j++){
                isPrime[i*j] = false;
            }
        }
    }
    while(1){
        int a,d,n;
        cin >> a >> d >> n;
        if(a+d+n == 0){
            break;
        }
        int count=0;
        for(int i=0;;i++){
            if(isPrime[a+d*i]){
                count++;
                if(count == n){
                    cout << (a+d*i) << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}
