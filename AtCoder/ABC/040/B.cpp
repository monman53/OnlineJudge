#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int n;
    int mmin = 999999999;
    
    cin >> n;

    for(int i=1;i*i<=n;i++){
        mmin = min(mmin, n%i + abs(n/i-i));
    }

    cout << mmin << endl;

    return 0;
}
