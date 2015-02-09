#include <iostream>
#include <string>
using namespace std;

string ans(int n){
    int sum=1;
    int i;
    for(i=2;i*i<=n;i++){
        if(n%i == 0){
            sum += i + n/i;
            if(i*i == n){
                sum -= i;
            }
        }
    }
    if(n == 1){
        sum = 0;
    }

    string s = " number\n";
    if(n < sum){
        s = "abundant" + s;
    }else if(n > sum){
        s = "deficient" + s;
    }else{
        s = "perfect" + s;
    }
    //cout << sum << '\n';
    return s;
}

int main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0) break;
        cout << ans(n);
    }
    return 0;
}
