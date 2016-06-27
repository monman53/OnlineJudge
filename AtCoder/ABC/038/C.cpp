#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    long ans = 0;
    int a[n];
    cin >> a[0];

    for(int i=1, j=0;i<n;i++){
        cin >> a[i];
        if(a[i-1] < a[i]){
            j++;
            ans += j;
        }else{
            j=0;
        }
    }
    ans += n;

    cout << ans << endl;
    return 0;
}
