#include <iostream>
#include <algorithm>
#include <string>
#define INF 2000000000
using namespace std;

int ston(string s){
    int ret=0;
    int i,j;
    for(i=s.size()-1, j=1;i>=0;i--,j*=10){
        ret += int(s[i]-'0')*j;
    }
    return ret;
}

int main(){
    while(1){
        int n;
        int sample[1002];
        cin >> n;
        if(n == 0) break;
        for(int i=1;i<=n;i++){
            string s;
            cin >> s;
            if(s == "x"){
                if(i%2 == 0){
                    sample[i] = INF;
                }else{
                    sample[i] = -INF;
                }
            }else{
                sample[i] = ston(s);
            }
            //cout << sample[i] << ' ';
        }
        //cout << '\n';
        sample[0] = INF;
        if(n%2 == 0){
            sample[n+1] = -INF;
        }else{
            sample[n+1] = INF;
        }

        int mmin = -INF;
        int mmax = INF;
        for(int i=1;i<=n;i++){
            if(sample[i] == INF){
                mmin = max(max(sample[i-1],sample[i+1]) + 1,mmin);
            }
            if(sample[i] == -INF){
                mmax = min(min(sample[i-1],sample[i+1]) - 1,mmax);
            }
        }
        cout << mmin << ' ' << mmax << '\n';
        if(mmin == mmax){
            cout << mmin;
        }
        if(mmin == -INF || mmax == INF || mmin > mmax){
            cout << "none";
        }else if(mmin < mmax){
            cout << "ambiguous";
        }
        cout << '\n';
    }
    return 0;
}
