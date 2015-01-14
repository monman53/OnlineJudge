#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;

typedef pair<string,pair<int,int> > data;

short di[4] = {-1,1,-4,4};

int main(){
    map<string,int> dist;
    queue<data> queue;
    queue.push(data("01234567",pair<int,int>(0,1)));
    while(queue.size()){
        data nq=queue.front();
        queue.pop();
        string s=nq.first;
        int count=nq.second.first;
        int lastmove=nq.second.second;

        if(dist.find(s)==dist.end()){
            dist[s] = count;
        }else{
            if(dist[s] > count){
                dist[s] = count;
            }
            continue;
        }

        for(int i=0;i<8;i++){
            if(s[i]=='0'){
                for(int j=0;j<4;j++){
                    int ni = i+di[j];
                    if(ni >= 0 && ni < 8 && !(j==0 && ni == 3) && !(j==1 && ni==4) && (di[lastmove] != -di[j])){
                        string ns=s;
                        int ncount=count+1;
                        int nlastmove=j;
                        ns[i]=s[ni];
                        ns[ni]=s[i];
                        queue.push(data(ns,pair<int,int>(ncount,nlastmove)));
                    }
                }
            }
        }
    }

    while(1){
        string s="00000000";
        for(int i=0;i<8;i++){
            if(!(cin >> s[i])){
                return 0;
            }
        }
        cout << dist[s] << '\n';
    }
    return 0;
}
