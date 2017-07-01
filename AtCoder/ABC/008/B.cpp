#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> count;

    for(int i=0;i<n;i++){
        string name;
        cin >> name;
        if(count.find(name) != count.end()){
            count[name]++;
        }else{
            count[name] = 1;
        }
    }

    int ans = 0;
    string name;

    for(auto v : count){
        if(v.second >= ans){
            name = v.first;
            ans = v.second;
        }
    }

    cout << name << endl;

    return 0;
}
