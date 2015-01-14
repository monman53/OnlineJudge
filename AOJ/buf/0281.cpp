#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int c,a,n;
        int sum = 0;
        cin >> c >> a >> n;
        if(c > 0 && a > 0 && n > 0){
            int m = min(c,min(a,n));
            sum += m;
            c -= m;
            a -= m;
            n -= m;
        }
//        cout << c << ' ' << a << ' ' << n << '\n';
        if(a > 0){
            for(int j=1;j<=a;j++){
                if(j*2 > c){
                    sum += j-1;
                    c -= 2*(j-1);
                    a -= j-1;
                    break;
                }
                if(j==a){
                    sum += j;
                    c -= 2*j;
                    a -= j-1;
                    break;
                }
            }
        }
//        cout << c << ' ' << a << ' ' << n << '\n';
        sum += c/3;

        cout << sum << '\n';
    }
    return 0;
}
