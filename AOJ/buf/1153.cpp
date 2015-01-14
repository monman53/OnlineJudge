#include <iostream>
#define MIN 9999999
using namespace std;

int main(){
    int n,m,nsum,msum;
    int ndata[100],mdata[100];
    int min;
    int changen,changem;
    while(1){
        cin >> n >> m;
        if(n==0 && m==0){
            break;
        }
        nsum = 0;
        msum = 0;
        for(int i=0;i<n;i++){
            cin >> ndata[i];
            nsum += ndata[i];
        }
        for(int i=0;i<m;i++){
            cin >> mdata[i];
            msum += mdata[i];
        }
        min = MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nsum-ndata[i]+mdata[j] == msum-mdata[j]+ndata[i]){
                    if(ndata[i]+mdata[j] < min){
                        changen = ndata[i];
                        changem = mdata[j];
                        min = ndata[i]+mdata[j];
                    }
                }
            }
        }
        if(min == MIN){
            cout << -1 << '\n';
        }else{
            cout << changen << ' ' << changem << '\n';
        }
    }
    return 0;
}
