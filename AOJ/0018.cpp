#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n[5];
    for(int i=0;i<5;i++){
        cin >> n[i];
    }
    sort(n,n+5);
    for(int i=4;i>=0;i--){
        cout << n[i];
        if(i == 0){
            cout << '\n';
        }else{
            cout << ' ';
        }
    }
    return 0;
}
