#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    vector<pair<int,int> > data;
    cin >> n;
    int max=0;
    for(int i=0;i<n;i++){
        int a,v;
        cin >> a >> v;
        data.push_back(pair<int,int>(v,a));
    }
    sort(data.begin(),data.end());
    int lasta,lastv;
    for(int i=data.size()-1;i>=0;i--){
        if(data[i].first!=lastv && i!=data.size()-1){
            break;
        }
        lastv = data[i].first;
        lasta = data[i].second;
    }
    cout << lasta << ' ' << lastv << '\n';
    return 0;
} 
