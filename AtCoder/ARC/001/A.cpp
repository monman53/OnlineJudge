#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N;
string cs;

vector<int> ans(4, 0);

int main() {
    cin >> N >> cs;
    
    for(const auto &c : cs){
        ans[c-'1']++;
    }

    cout << *max_element(ans.begin(), ans.end())
         << " "
         << *min_element(ans.begin(), ans.end())
         << endl;

    return 0;
}
