#include <iostream>
using namespace std;

int main(){
    int n,a,b,c,x;
    int y[100];
    while(1){
        cin >> n >> a >> b >> c >> x;
        if(n+a+b+c+x == 0){
            break;
        }
        for(int i=0;i<n;i++){
            cin >> y[i];
        }
        int f = 0;
        for(int i=0;i<n;i++){
            while(1){
                if(f == 10001){
                    break;
                }
                if(y[i] == x){
                    if(i != n-1){
                        f++;
                        x = (a*x + b)%c;
                    }
                    break;
                }
                f++;
                x = (a*x + b)%c;
            }
            if(f == 10001){
                break;
            }
        }
        if(f == 10001){
            cout << -1 << '\n';
        }else{
            cout << f << '\n';
        } 
    }
    return 0;
}
