#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int B=0,C=0,A;
        bool flag=true;
        for(int j=0;j<10;j++){
            cin >> A;
            if(A-B > 0 && A-C > 0){
                if(A-B <= A-C) B=A;
                else C=A;            
            }else if(A-B > 0){ B=A;
            }else if(A-C > 0){ C=A;
            }else{ flag = false;
            }
        }
        cout << (flag ? "YES\n" : "NO\n"); 
    }
    return 0;
}
