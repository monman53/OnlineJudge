#include <iostream>
using namespace std;

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        bool flag = true;
        int sum = 0;
        for(int i=0;i<n;i++){
            int k;
            cin >> k;
            if(k >= 2) flag = false;
            if(k > 0) sum++;
        }
        if(flag){
            cout << "NA\n";
        }else{
            cout << (sum+1) << '\n';
        }
    }
    return 0;
}
