#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n, k;
vector<int> data;
set<int> s;
vector<int> v2;

void solve2(int ii, int sum){
    s.insert(sum);
    if(ii < (int)v2.size()){
        solve2(ii+1, sum);
        solve2(ii+1, sum+v2[ii]);
    }
}

void solve(vector<int> v, int ii, int sum){
    if(sum == k){
        //s.insert(sum);
        v2 = v;
        solve2(0, 0);
    }else if(sum > k){
        return;
    }
    if(ii < (int)data.size()){
        solve(v, ii+1, sum);
        v.push_back(data[ii]);
        solve(v, ii+1, sum+data[ii]);
    }
}

int main(){
    cin >> n >> k;
    
    for(int i=0;i<n;i++){
        int j;
        cin >> j;
        data.push_back(j);
    }
    sort(data.begin(), data.end());
    
    vector<int> v;
    solve(v, 0, 0);
    
    vector<int> ans;
    for(int i=0;i<=k;i++){
        if(s.find(i) != s.end()){
            ans.push_back(i);
        }
    }


    cout << ans.size() << endl;
    for(int i=0;i<(int)ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
