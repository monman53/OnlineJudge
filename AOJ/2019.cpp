#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main(){
    while(1){
        int n,m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        vector<pair<int,int> > data(n);
        for(int i=0;i<n;i++){
            int d,p;
            cin >> d >> p;
            data[i].first = -p;
            data[i].second = d;
        }
        
        sort(data.begin(), data.end());

        int ans=0;

        for(int i=0;i<n;i++){
            if(m >= data[i].second){
                m -= data[i].second;
            }else if(m == 0){
                ans += -data[i].first*data[i].second;
            }else{
                ans += -data[i].first*(data[i].second-m);
                m = 0;
            }
        }

        cout << ans << '\n';

    }
    return 0;
}
