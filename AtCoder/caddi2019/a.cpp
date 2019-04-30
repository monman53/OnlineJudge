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

int l, n, m;
int r[1000], p[1000];
struct P {
    int x, y, z;
};
map<pair<int, int>, vector<pair<int, int>>> mp;

int main() {
    cin >> l >> n >> m;
    vector<pair<double, int>> v;
    for(int i=0;i<n;i++){
        cin >> r[i] >> p[i];
        v.push_back({double(p[i])/r[i]/r[i], i});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(int i=0;i<m;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        mp[{a, b}].push_back({c, d});
    }

    vector<P> ans(n);
    long long ans_score = -1;
    for(int kk=0;kk<10;kk++){
        vector<pair<int, P>> s;
        long long score = 0;
        for(int i=0;i<n;i++){
            int ci = v[i].second;
            for(int jj=0;jj<10;jj++){
                int x = r[ci] + xor128()%(l-2*r[ci]);
                int y = r[ci] + xor128()%(l-2*r[ci]);
                int z = r[ci] + xor128()%(l-2*r[ci]);

                bool ok = true;
                for(auto ss : s){
                    const auto np = ss.second;
                    const int dx = (x-np.x)*(x-np.x);
                    const int dy = (y-np.y)*(y-np.y);
                    const int dz = (z-np.z)*(z-np.z);
                    if(dx+dy+dz < (r[ci]+r[ss.first])){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    break;
                }
            }
        }
        if(score > ans_score){
            ans_score = score;
            for(int i=0;i<n;i++){
                ans[i] = {-1, -1, -1};
            }
            for(auto ss : s){
                ans[ss.first] = ss.second;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << ans[i].x << " " << ans[i].y << " " << ans[i].z << endl;
    }

    return 0;
}
