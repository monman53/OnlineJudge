#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

#define MOD 1000000007LL
typedef long long ll;

using namespace std;

ll memo[55][55][110];
string ss1, ss2;
map<char, int> m;

ll solve(int i, int j, int k) {
    ll ret = 0;
    
    if(i > ss1.size() || j > ss2.size()) return 0;

    if(k<0) return 0;
    if(i == ss1.size() && j == ss2.size()){
        if(k == 0) return 1LL;
        else return 0;
    }
    if(memo[i][j][k] != -1) return memo[i][j][k];

    if(i == ss1.size()){
        ret = solve(i, j+1, k+m[ss2[j]]);
    }
    if(j == ss2.size()){
        ret = solve(i+1, j, k+m[ss1[i]]);
    }
    if(i < ss1.size() && j < ss2.size()){
        ret = (ret + solve(i, j+1, k+m[ss2[j]])) % MOD;
        ret = (ret + solve(i+1, j, k+m[ss1[i]])) % MOD;
    }

    return memo[i][j][k] = ret;;
}

class InterleavingParenthesisDiv2 {
    public:
    int countWays(string s1, string s2) {
        m['('] = 1;
        m[')'] = -1;
        ss1 = s1;ss2 = s2;
        memset(memo, -1LL, sizeof(memo));
        return solve(0, 0, 0);
    }
};

// CUT begin
ifstream data("InterleavingParenthesisDiv2.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(string s1, string s2, int __expected) {
    time_t startClock = clock();
    InterleavingParenthesisDiv2 *instance = new InterleavingParenthesisDiv2();
    int __result = instance->countWays(s1, s2);
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
        string s1;
        from_stream(s1);
        string s2;
        from_stream(s2);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s1, s2, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1499908487;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "InterleavingParenthesisDiv2 (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
