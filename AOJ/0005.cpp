#include <iostream>
//test
using namespace std;

long long int gf(long long int a,long long int b){
    while(!(a==0 || b==0)){
        if(a>b){
            a = a%b;
        }else{
            b = b%a;
        }
    }
    if(a==0){
        return b;
    }else{
        return a;
    }
}

int main(){
    long long int a,b;
    long long int g,l;
    while(cin >> a >> b){
        g = gf(a,b);
        l = a*b/g;
        cout << g << " " << l << '\n';
    }
    return 0;
}
