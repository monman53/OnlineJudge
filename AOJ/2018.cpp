#include <iostream>
using namespace std;

int main(){
    int n,m,p;
    while(1){
        cin >> n >> m >> p;
        if(n+m+p == 0){
            break;
        }
        int sum=0;
        int tokuhyou;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            sum += x;
            if(i+1 == m){
                tokuhyou = x;
            }
        }
        if(tokuhyou == 0){
            cout << 0 << '\n';
        }else{
            cout << (((100*sum*(100-p))/100)/tokuhyou) << '\n';
        }
    }
    return 0;
}
