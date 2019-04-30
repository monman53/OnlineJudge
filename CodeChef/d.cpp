// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}


struct Hoge {
    int l, r;
    vector<int> seq;

    Hoge(char c, int l, int r){
        this->l = l;
        this->r = r;
        int cnt = 0;
        inc(i, 0, r-l){
            seq.push_back(cnt);
            if(c == 'I'){
                cnt++;
            }else{
                cnt--;
            }
        }
    }

    int add(char c, int l, int r){

        set<int> st;
        int cnt = 0;
        inc(i, l-this->l, this->r-this->l){
            st.insert(seq[i]-cnt);
            if(c == 'I'){
                cnt++;
            }else{
                cnt--;
            }
        }
        if(st.size() != 1){
            return 1;
        }else{
            inc(i, this->r-this->l, r-this->l){
                if(c == 'I'){
                    seq.push_back(seq[i-1]+1);
                }else{
                    seq.push_back(seq[i-1]-1);
                }
            }
            this->r = r;
            return 0;
        }
    }
};

int solve() {
    int n, m, k;
    vector<int> a;
    vector<pair<pair<int, int>, char>> lr;
    vector<int> imos;
    stack<Hoge> st;
    LL ans = 1;
    cin >> n >> m >> k;
    a.resize(n);
    lr.resize(m);
    imos.resize(n+5, 0);
    inc(i, 0, n) cin >> a[i];
    inc(i, 0, m){
        char c;
        int l, r;
        cin >> c >> l >> r;
        l--;
        imos[l]++;
        imos[r]--;
        lr[i] = {{l, r}, c};
    }
    inc(i, 1, n+4){
        imos[i] = imos[i-1] + imos[i];
    }
    sort(lr.begin(), lr.end());

    inc(i, 0, m){
        char c = lr[i].se;
        int l = lr[i].fi.fi;
        int r = lr[i].fi.se;
        if(st.size() == 0){
            st.push(Hoge(c, l, r));
        }else{
            auto now = st.top();
            st.pop();
            if(now.r-l > 0){
                if(now.add(c, l, r)){
                    return 1;
                }
                st.push(now);
            }else{
                st.push(now);
                st.push(Hoge(c, l, r));
            }
        }
    }

    while(!st.empty()){
        auto now = st.top();
        st.pop();
        int l = now.l;
        int r = now.r;
        set<int> ss;
        int mmax = -INF;
        int mmin = INF;
        inc(i, l, r){
            if(a[i] != -1){
                ss.insert(now.seq[i-l]-a[i]);
            }
            mmax = max(now.seq[i-l], mmax);
            mmin = min(now.seq[i-l], mmin);
        }
        //cout << "ss" << ss.size() << endl;
        //cout << "a" << ans << endl;
        if(ss.size() == 0){
            if(k-(mmax-mmin) < 1){
                return 1;
            }
            MODP(ans, k-(mmax-mmin));
        }else{
            if(ss.size() != 1) return 1;
        }
    }

    inc(i, 0, n+5){
        if(imos[i] == 0 && a[i] == -1){
            MODP(ans, k);
        }
    }
    cout << ans << endl;

    return 0;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    while(t--){
        if(solve()){
            cout << 0 << endl;
        }
    }
    return 0;
}
