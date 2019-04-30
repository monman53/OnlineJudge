// header {{{
// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;
// }}}

// graph {{{
template<class T>
struct G {
    // 辺
    struct E {
        int from;
        int to;
        T w;
    };
    int n;  // 頂点数
    vector<vector<E>> e;// 隣接リスト
    // コンストラクタ
    G(){}
    G(int n) {
        this->n = n;
        e.resize(n);
    }
    // 辺の追加
    void add(int i, int j, T w) {
        e[i].push_back({i, j, w});
    }
};
//}}}

G<int> g;
int x[1000][1000];

void dfs(int v, int from, int sum, int i) {
    x[i][v] = sum;
    for(auto ee : g.e[v]){
        if(ee.to == from) continue;
        dfs(ee.to, v, sum^ee.w, i);
    }
}

class TwoDogsOnATree {
    public:
    int maximalXorSum(vector<int> parent, vector<int> w) {
        int n = parent.size()+1;
        g = G<int>(n);
        for(int i=1;i<n;i++){
            g.add(parent[i-1], i, w[i-1]);
            g.add(i, parent[i-1], w[i-1]);
        }
        for(int i=0;i<n;i++){
            dfs(i, -1, 0, i);
        }
        vector<int> p;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                p.push_back(x[i][j]);
            }
        }
        int m = p.size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                ans = max(ans, p[i]^p[j]);
            }
        }
        return ans;
    }
};

// CUT begin
ifstream data("TwoDogsOnATree.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<int> parent, vector<int> w, int __expected) {
    time_t startClock = clock();
    TwoDogsOnATree *instance = new TwoDogsOnATree();
    int __result = instance->maximalXorSum(parent, w);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> parent;
        from_stream(parent);
        vector<int> w;
        from_stream(w);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(parent, w, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1502759663;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "TwoDogsOnATree (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
