#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    while(1){
        int b,a,bs;
        cin >> b >> a >> bs;
        if(b == 0 && a == 0 && bs == 0) break;
        int asmax = 0;
        for(int i=1;i<bs;i++){
            for(int j=1;i+j<=bs;j++){
                if( (i*(100+b))/100 + (j*(100+b))/100 == bs){
                    asmax = max(asmax, (i*(100+a))/100 + (j*(100+a))/100 );
                }
            }
        }
        cout << asmax << '\n';
    }
    return 0;
}
