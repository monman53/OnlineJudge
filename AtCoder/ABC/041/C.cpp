#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct Data{
    int id;
    long height;
    bool operator < (const Data &other) const {
        return height > other.height;
    }
};

int main(){
    vector<Data> data;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        Data a;
        cin >> a.height;
        a.id = i + 1;
        data.push_back(a);
    }
    sort(data.begin(), data.end());

    for(int i=0;i<(int)data.size();i++){
        cout << data[i].id << endl;
    }
    return 0;
}
