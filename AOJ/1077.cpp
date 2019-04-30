#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    while(1){
        int a,b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f;
        if(a+b+c+d+e+f == 0) break;
        //int data[3];
        a = a+d;
        b = b+e;
        c = c+f;
        int mmax = 0;
        for(int i=0;i<3;i++){
            if(a-i >= 0 && b-i >= 0 && c-i >= 0){
                mmax = max((a-i)/3 + (b-i)/3 + (c-i)/3 + i, mmax);
            }
        }
        cout << mmax << '\n';
    }
    return 0;
}
