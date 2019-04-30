#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int data[100005], d[100005];
    for(int i=0;i<100005;i++){
        data[i] = 1;
        d[i] = 0;
    }
    cin >> n;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        d[a]++;
        d[b+1]--;
    }
    int mmax = 0;
    for(int i=1;i<100005;i++){
        data[i] = data[i-1];
        data[i] += d[i];
        if(i<=data[i])
            mmax = max(mmax, i-1);
    }
    cout << mmax << endl;
    return 0;
}
