#include <iostream>
using namespace std;

int isPrime(int n){
    if(n<2){
        return 0;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int psum[1234568];
    psum[0] = 0;
    for(int i=1;i<1234568;i++){
        psum[i] = psum[i-1] + isPrime(i);
    }
    while(1){
        int n;
        cin >> n;
        if(n==0){
            break;
        }
        cout << (psum[2*n] - psum[n]) << '\n';
    }
    return 0;
}
