#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int m,n;
    cin >> m >> n;
    int status;
    int mmax = 0;
    for(int i=0;i<m;i++){
        int data = 0;
        for(int j=0;j<n;j++){
            cin >> status;
            data += status;
        }
        mmax = max(mmax, data);
    }

    cout << mmax << '\n';
        
    return 0;
}
