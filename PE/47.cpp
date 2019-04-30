#include <iostream>
#define MAX 1000000
using namespace std;

bool isPrime[MAX];

int mcount(int n){
    int ret=0;
    for(int i=2;i<=n;i++){
        if(n%i == 0){
            if(isPrime[i]){
                ret++;
            }
        }
    }
    return ret;
}

int main(){
    for(int i=2;i<MAX;i++){
        isPrime[i] = true;
    }
    for(int i=2;i<MAX;i++){
        if(isPrime[i]){
            for(int j=2;i*j<MAX;j++){
                isPrime[i*j] = false;
            }
        }
    }
    for(int i=3;i<MAX-4;i++){
        if(mcount(i) == 4){
            if(mcount(i) == mcount(i+1)){
                if(mcount(i+1) == mcount(i+2)){
                    if(mcount(i+2) == mcount(i+3)){
                        cout << i << '\n';
                        break;
                    }
                }
            }
        }
    }
    return 0;
}

