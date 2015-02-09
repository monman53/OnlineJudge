#include <iostream>
using namespace std;

int main(){
    while(1){
        int n,q;
        cin >> n >> q;
        if(n == 0 && q == 0){
            break;
        }
        
        int conv[101];
        for(int i=0;i<101;i++){
            conv[i] = 0;
        }
        for(int i=0;i<n;i++){
            int m;
            cin >> m;
            for(int j=0;j<m;j++){
                int date;
                cin >> date;
                conv[date]++;
            }
        }
        int maxDate=0;
        for(int i=0;i<101;i++){
            if(conv[i] > conv[maxDate]){
                maxDate = i;
            }
        }
        if(conv[maxDate] < q){
            cout << 0 << '\n';
        }else{
            cout << maxDate << '\n';
        }
    }
    return 0;
}
