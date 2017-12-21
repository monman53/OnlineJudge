#include <iostream>
using namespace std;

int main(){
    int n,k;
    int count = 0;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        count += a;
        if(count >= k){
            cout << (i+1) << '\n';
            break;
        }
    }
    return 0;
}
