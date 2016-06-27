#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

struct Node{
    vector<int> edge;
};

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    s--;
 
    Node node[n];     

    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        node[v].edge.push_back(u);
        node[u].edge.push_back(v);
    }

    for(int i=0;i<n;i++){
        bool kita[n];
        for(int j=0;j<n;j++){
            kita[j] = false;
        }
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int now = q.front();
            q.pop();
            kita[now] = true;
            if(now == i){
                cout << i + 1 << endl;
                break;
            }
            for(int j=0;j<(int)node[now].edge.size();j++){
                int next = node[now].edge[j];
                if(!kita[next]){
                    q.push(next);
                }
            }
        }
        for(int j=0;j<(int)node[i].edge.size();j++){
            int next = node[i].edge[j];
            node[next].edge.erase(find(node[next].edge.begin(), node[next].edge.end(), i));
        }
        node[i].edge.clear();
    }

    return 0;
}
