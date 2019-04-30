#include <iostream>
using namespace std;

int main(){
    int t;
    long long int l,a,b,ret;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> l >> a >> b;
        if(l <= a){
            cout << 1 << '\n';
            continue;
        }
        if(a <= b){
            cout << -1 << '\n';
            continue;
        }
        ret = (l-b)/(a-b);
        if((l-b)%(a-b)!=0){
            ret++;
        }
        cout << ret << '\n';
    }
    return 0;
}
