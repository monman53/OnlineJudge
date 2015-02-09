#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main(){
    while(1){
        int t,p,r;
        cin >> t >> p >> r;
        if(t == 0) break;
        vector<pair<int,pair<int,int> > > data(t);
        int rireki[50][10];
        for(int i=0;i<t;i++){
            data[i].first = 0;
            data[i].second.first = 0;
            data[i].second.second = i;
            for(int j=0;j<p;j++){
                rireki[i][j] = 0;
            }
        }

        for(int i=0;i<r;i++){
            int tid,pid,time;
            string message;
            cin >> tid >> pid >> time >> message;
            if(message == "CORRECT"){
                data[tid-1].first--;
                data[tid-1].second.first += rireki[tid-1][pid-1]*1200 + time;
            }
            if(message == "WRONG"){
                rireki[tid-1][pid-1]++;
            }
        }
        sort(data.begin(), data.end());
        for(int i=0;i<t;i++){
            cout << (data[i].second.second + 1) << ' ' << -data[i].first << ' ' << data[i].second.first << '\n';
        }
    }
    return 0;
}
