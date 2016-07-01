#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n, d;
    cin >> n >> d;
    int ans = 0;
    int consecutive = 0;
    for(int i=0;i<d;i++){
        int count = 0;
        string s;
        cin >> s;
        for(int j=0;j<n;j++){
            if(s[j] == '1'){
                count++;
            }
        }
        if(count == n){
            consecutive = 0;
        }else{
            consecutive++;
        }
        ans = max(ans, consecutive);
    }
    cout << ans << endl;
    return 0;
}
