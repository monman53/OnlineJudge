#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y,b,p;
        cin >> x >> y >> b >> p;
        if(b >= 5 && p >= 2){
            cout << (x*b + y*p)*0.8 << '\n';
        }else if(b >= 5){
            cout << min(x*b + y*p, int((x*b + y*2)*0.8)) << '\n';
        }else if(p >= 2){
            cout << min(x*b + y*p, int((x*5 + y*p)*0.8)) << '\n';
        }else{
            cout << min(x*b + y*p, int((x*5 + y*2)*0.8)) << '\n';
        }
    }
    return 0;
}
