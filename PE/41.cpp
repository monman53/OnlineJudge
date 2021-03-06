#include <iostream>
using namespace std;

bool use[10];
long long int mmax = 0;

bool isPrime(long long n){
    for(long long i=2;i*i<=n;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

void dfs(int count, long long data){
    if(count == 8){
        cout << data << '\n';
        if(isPrime(data) && data > mmax) mmax = data;
    }else{
        for(long long i=1;i<=7;i++){
            if(!use[i]){
                use[i] = true;
                dfs(count+1, data*10 + i);
                use[i] = false;
            }
        }
    }
}

int main(){
    for(int i=0;i<=9;i++){
        use[i] = false;
    }
    dfs(1,0);
    cout << "\nans=" << mmax << '\n';
    return 0;
}
