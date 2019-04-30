#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Node {
    vector<int> to;
    vector<int> year;
};

int main(){
    int n, m;
    Node data[100001];
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, y;
        cin >> a >> b >> y;
        data[a].to.push_back(b);
        data[a].year.push_back(y);
        data[b].to.push_back(a);
        data[b].year.push_back(y);
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int v, w;
        cin >> v >> w;

        bool kita[100001];
        for(int j=1;j<=n;j++){
            kita[j] = false;
        }
        
        stack<int> s;
        s.push(v);

        int ans = 0;

        while(!s.empty()){
            int now = s.top();
            s.pop();

            if(kita[now]){
                continue;
            }

            kita[now] = true;
            ans++;

            for(int k=0;k<data[now].to.size();k++){
                if(data[now].year[k] > w){
                    s.push(data[now].to[k]);
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
