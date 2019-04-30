#include <iostream>
using namespace std;

int main() {
    int n;
    int ans;

    int a1 = 0, a2 = 0, a3 = 1;

    cin >> n;

    if(n < 3){
        ans = 0;
    }
    if(n == 3){
        ans = 1;
    }

    if(n > 3){
        for(int i=3;i<n;i++){
            ans = (a1 + a2 + a3)%10007;
            a1 = a2;
            a2 = a3;
            a3 = ans;
        }
    }

    cout << ans << endl;

    return 0;
}
