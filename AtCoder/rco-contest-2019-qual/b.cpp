#include <bits/stdc++.h>
using namespace std;

inline uint32_t xor128(void){
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123; 
    const uint32_t t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

inline double unifom() {
    return double(xor128())/UINT32_MAX;
}

int n, m;
int a[50][50];

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};

int dfs(int i, int j) {
    if(a[i][j] == 0) return 0;
    if(a[i][j] != 9) return 0; 
    int res = 1;
    a[i][j] = 0;
    for(int k=0;k<4;k++){
        int ni = i + di[k];
        int nj = j + dj[k];
        if(ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
        res += dfs(ni, nj);
    }
    return res;
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    vector<pair<int, pair<int, int>>> v;
    for(int i=0;i<50;i++){
        while(a[i][0] < 9){
            a[i][0]++;
            if(int(v.size()) < m-1){
                v.push_back({1, {i, 0}});
            }
        }
    }
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            //if(a[i][j] < 5){
                //while(a[i][j] < 5){
                    //a[i][j]++;
                    //if(int(v.size()) < m-1){
                        //v.push_back({1, {i, j}});
                    //}
                //}
            //}else{
            //if(a[i][j] < 5) continue;
            //if(a[i][j] < 3) continue;
            //if(a[i][j] < 5 && unifom() < 0.4) continue;
            if(i%10 == 0 || (j%10 == 0 && i%10 < 5)){
                while(a[i][j] < 9){
                    a[i][j]++;
                    if(int(v.size()) < m-1){
                        v.push_back({1, {i, j}});
                    }
                }
            //}
            }
        }
    }
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            //if(a[i][j] < 5){
                //while(a[i][j] < 5){
                    //a[i][j]++;
                    //if(int(v.size()) < m-1){
                        //v.push_back({1, {i, j}});
                    //}
                //}
            //}else{
            //if(a[i][j] < 5) continue;
            if(a[i][j] < 4) continue;
            if(a[i][j] < 7 && unifom() < 0.4) continue;
                while(a[i][j] < 9){
                    a[i][j]++;
                    if(int(v.size()) < m-1){
                        v.push_back({1, {i, j}});
                    }
                }

            //}
        }
    }
    vector<pair<int, pair<int, int>>> vv;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] == 9){
                vv.push_back({dfs(i, j), {i, j}});
            }
        }
    }
    auto ans = *max_element(vv.begin(), vv.end());

    for(int i=0;i<m-1;i++){
        cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << endl;
    }
    cout << 2 << " " << ans.second.first << " " << ans.second.second << endl;
    return 0;
}
