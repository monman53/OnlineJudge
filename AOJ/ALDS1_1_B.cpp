#include <iostream>
using namespace std;

int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

int min(int a,int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}

int main(){
    int x,y;
    cin >> x >> y;
    while(!(x==0 || y==0)){
        if(max(x,y)==x){
            x = x%y;
        }else{
            y = y%x;
        }
    }
    if(x==0){
        cout << y <<'\n';
    }else{
        cout << x << '\n';
    }
    return 0;
}
