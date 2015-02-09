#include <iostream>
#define INF 999999999
using namespace std;

int main(){
    int f;
    cin >> f;
    for(int i=0;i<f;i++){
        int n,m,w;
        cin >> n >> m >> w;

        int fields[501];
        int path[501][501];
        int pathcount[501];
        int pathlength[501][501];

        for(int j=1;j<=n;j++){
            pathcount[j] = 0;
        }

        for(int j=0;j<m;j++){
            int s,e,t;
            cin >> s >> e >> t;
            //cout << s << e << t << '\n';
            path[s][pathcount[s]] = e;
            path[e][pathcount[e]] = s;
            pathlength[e][pathcount[e]] = pathlength[s][pathcount[s]] = t;
            pathcount[s]++;
            pathcount[e]++;
        }

        for(int j=0;j<w;j++){
            int s,e,t;
            cin >> s >> e >> t;
            //cout << s << e << t << '\n';
            path[s][pathcount[s]] = e;
            pathlength[s][pathcount[s]] = -t;
            pathcount[s]++;
        }

        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                fields[k] = INF;
            }
            fields[j] = 0;
            while(1){
                bool changed=false;
                //cout << "koko";

                for(int l=1;l<=n;l++){
                    for(int o=0;o<pathcount[l];o++){
                        if(fields[path[l][o]] > fields[l] + pathlength[l][o]){
                            fields[path[l][o]] = fields[l] + pathlength[l][o];
                            //cout << fields[path[l][o]];
                            changed = true;
                        }
                    }
                }
                if(!changed || fields[j] < 0){
                    break;
                }
            }
            if(fields[j] < 0){
                cout << "YES\n";
                break;
            }else if(j==n){
                cout << "NO\n";
            }
        }

    }
    return 0;
}
