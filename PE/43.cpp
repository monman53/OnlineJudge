#include <iostream>
using namespace std;

bool use[10];
long long sum = 0;

bool isPrime(long long n){
    for(long long i=2;i*i<=n;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

void dfs(int count, long long data){
    if(count == 11){
        if((data%1000)%17 == 0 &&
           ((data%10000)/10)%13 == 0 &&
           ((data%100000)/100)%11 == 0 &&
           ((data%1000000)/1000)%7 == 0 &&
           ((data%10000000)/10000)%5 == 0 &&
           ((data%100000000)/100000)%3 == 0 &&
           ((data%1000000000)/1000000)%2 == 0){
            sum += data;
            cout << data << '\n';
        }
    }else{
        for(long long i=0;i<=9;i++){
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
    cout << "\nans=" << sum << '\n';
    return 0;
}
