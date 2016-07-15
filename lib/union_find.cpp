// UnionFind
//  UnionFind(int n)            要素数nで初期化
//  int find(int x)             xの親を返す
//  void unite(int x, int y)    xが属する木とyが属する木を結合する
//  bool same(int x, int y)     xとyが同じ木に属するか?
//
// depends on 
#define UnionFind_N_MAX 10000
//
class UnionFind{   // {{{
private:
    int rank[UnionFind_N_MAX], parent[UnionFind_N_MAX];

public:
    UnionFind(int n){
        for(int i=0;i<n;i++){
            rank[i] = 1;
            parent[i] = i;
        }
    }

    int find(int x){
        if(x == parent[x]){
            return x;
        }else{
            return parent[x] = find(parent[x]);
        }
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y){
            return;
        }
        if(rank[x] < rank[y]){
            parent[x] = y;
        }else{
            parent[y] = x;
            if(rank[x] == rank[y]){
                rank[x]++;
            }
        }
    }
    
    bool same(int x, int y){
        return find(x) == find(y);
    }
};  // }}}
