#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<string> data;

    cin >> n;
    
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        data.push_back(s);
    }

    sort(data.begin(), data.end());

    for(auto s : data){
        reverse(s.begin(), s.end());
        cout << s << endl;
    }

    return 0;
}
