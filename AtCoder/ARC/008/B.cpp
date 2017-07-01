#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    string name, kit;
    cin >> n >> m;
    cin >> name >> kit;

    vector<int> need(100, 0), exist(100, 0);

    for(auto c : name){
        need[c-'A']++;
    }

    for(auto c : kit){
        exist[c-'A']++;
    }

    int ans = 1;

    for(int i=0;i<100;i++){
        if(need[i] > 0 && exist[i] == 0){
            ans = -1;
            break;
        }
        if(need[i] > exist[i]){
            ans = max(ans, need[i]/exist[i] + (need[i]%exist[i] == 0 ? 0 : 1));
        }
    }

    cout << ans << endl;

    return 0;
}
