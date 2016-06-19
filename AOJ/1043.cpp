#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Data{
    int i, u, a, p;
};

bool sortf(Data d1, Data d2){
    if(d1.a == d2.a){
        if(d1.p == d2.p){
            return d1.i < d2.i;
        }else{
            return d1.p < d2.p;
        }
    }else{
        return d1.a > d2.a;
    }
}

int main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }

        vector<Data> data;
        map<int, int> team;
        int counter = 0;

        for(int i=0;i<n;i++){
            Data in;
            cin >> in.i >> in.u >> in.a >> in.p;
            team[in.u] = 0;
            data.push_back(in);
        }

        sort(data.begin(), data.end(), sortf);

        //for(int i=0;i<n;i++){
        //    cout << data[i].i << " " << data[i].u << " " << data[i].a << " " << data[i].p << endl;
        //}
        
        for(int i=0;i<n;i++){
            if(counter < 10){
                if(team[data[i].u] < 3){
                    team[data[i].u]++;
                    cout << data[i].i << endl;
                    counter++;
                }
            }else if(counter < 20){
                if(team[data[i].u] < 2){
                    team[data[i].u]++;
                    cout << data[i].i << endl;
                    counter++;
                }
            }else if(counter < 26){
                if(team[data[i].u] == 0){
                    team[data[i].u]++;
                    cout << data[i].i << endl;
                    counter++;
                }
            }
        }
        
    }
}
