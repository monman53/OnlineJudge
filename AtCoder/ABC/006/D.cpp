#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int n;

    vector<int> c;

    cin >> n;

    for(int i=0;i<n;i++){
        int cc;
        cin >> cc;
        c.push_back(cc);
    }

    int ans = 0;

    for(int i=0;i<n-1;i++){
        if(c[i] != i+1){
            for(int j=i+1;j<n;j++){
                if(c[j] == i+1){
                    swap(c[i], c[j]);
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
