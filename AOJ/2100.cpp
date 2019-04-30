#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        int bh,nh;
        cin >> bh;
        int upmax=0,downmax=0;
        for(int j=1;j<n;j++){
            cin >> nh;
            if(nh - bh >= 0){
                upmax = max(upmax, nh - bh);
            }else{
                downmax = max(downmax, bh - nh);
            }
            bh = nh;
        }
        cout << upmax << ' ' << downmax << '\n';
    }
    return 0;
}
