#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, k;
    vector<int> important;

    int ans = 0;

    cin >> n >> k;

    for(int i=0;i<n;i++){
        int l, t;
        cin >> l >> t;
        if(t == 1){
            important.push_back(l);
        }
        ans += l;
    }

    sort(important.begin(), important.end());

    for(int i=0;i<(int)important.size() - k;i++){
        ans -= important[i]*2;
    }

    cout << ans << endl;

    return 0;
}
