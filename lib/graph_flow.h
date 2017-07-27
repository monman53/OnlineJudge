// graph flow {{{
template<class T>
struct GF {
    struct EF {
        int to;
        T cap;
        int rev;
    };

    int n;
    vector<vector<EF>> e;

    GF() {}
    GF(int n) {
        this->n = n;
        e.resize(n);
    }

    void add(int from, int to, T cap) {
        e[from].push_back({to, cap, int(e[to].size())});
        e[to].push_back({from, 0, int(e[from].size()-1)});
    }
};


// 最大流 (Ford-Fulkerson) {{{
// O(FE)
// verified AOJ GRL_6_A
template<class T>
struct MF {
    GF<T> g;
    vector<bool> visited;

    MF() {}
    MF(const GF<T> &g) {
        this->g = g;
        visited.resize(g.n, false);
    };

    T dfs(int v, int t, T f) {
        if(v == t) return f;
        visited[v] = true;
        for(auto &e : g.e[v]){
            if(!visited[e.to] && e.cap > 0){
                T d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    g.e[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T query(int from, int to) {
        T flow = 0;
        while(true){
            fill(visited.begin(), visited.end(), false);
            T f = dfs(from, to, INF);
            if(f == 0) break;
            flow += f;
        }
        return flow;
    }
};//}}}
//}}}
