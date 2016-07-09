// depends on
//#define N_MAX
struct union_find{
    int rank[N_MAX], parent[N_MAX];

    union_find(int n){
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
};
