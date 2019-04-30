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

// Union-Find {{{
// O(a(n))
// verified AOJ DSL_1_A
struct UF {
    vector<int> p;  // parent
    vector<int> r;  // rank

    UF(int n) {
        p.resize(n);
        r.resize(n);
        for(int i=0;i<n;i++){
            p[i] = i;
            r[i] = 1;
        }
    }

    int find(int x) {
        if(x == p[x]){
            return x;
        }else{
            return p[x] = find(p[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(r[x] < r[y]){
            p[x] = y;
        }else{
            p[y] = x;
            if(r[x] == r[y]){
                r[x]++;
            }
        }
    }
}; // }}}

struct E {
    int to;
    double w;
};

class RoadsAndJunctions {
public:
    int nc, nj;
    vector<int> x, y;
    vector<int> buildJunctions(int s,
                               vector<int> cities, 
                               double junctionCost, 
                               double failureProbability) {
        nc = cities.size() / 2;
        for(int i=0;i<nc;i++){
            x.push_back(cities[2*i]);
            y.push_back(cities[2*i+1]);
        }
        return {};
    }

    vector<int> buildRoads(vector<int> junctionStatus) {
        vector<pair<double, pair<int, int>>> e;
        for(int i=0;i<nc;i++){
            for(int j=i+1;j<nc;j++){
                double dx = x[i] - x[j];
                double dy = y[i] - y[j];
                e.push_back({sqrt(dx*dx + dy*dy), {i, j}});
            }
        }

        vector<int> res;
        sort(e.begin(), e.end());
        UF uf(nc);
        for(auto &ee : e){
            int i = ee.second.first;
            int j = ee.second.second;
            if(uf.find(i) != uf.find(j)){
                uf.unite(i, j);
                res.push_back(i);
                res.push_back(j);
            }
        }
        return res;
    }
};

// -------8<------- end of solution submitted to the website -------8<-------

template<class T> void getVector(vector<T>& v) {
    for (int i = 0; i < v.size(); ++i)
        cin >> v[i];
}

int main() {
    RoadsAndJunctions rj;
    int S, C;
    cin >> S >> C;
    vector<int> cities(C);
    getVector(cities);
    double junctionCost, failureProbability;
    cin >> junctionCost >> failureProbability;

    vector<int> ret = rj.buildJunctions(S, cities, junctionCost, failureProbability);
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
    
    int J;
    cin >> J;
    vector<int> junctionStatus(J);
    getVector(junctionStatus);

    ret = rj.buildRoads(junctionStatus);
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
}
