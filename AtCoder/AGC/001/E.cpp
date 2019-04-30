#include "./template.cpp"
#include "./union_find.cpp"

int main(){
    UnionFind uf = UnionFind(100);

    uf.unite(0, 2);
    uf.unite(5, 2);
    uf.unite(1, 3);
    uf.unite(6, 3);
    
    print4(0, 0, 0, 2);
    print4(0, 0, 5, 2);
    print4(0, 0, 1, 3);
    print4(0, 0, 6, 3);

    while(1){
        int a, b;
        cin >> a >> b;

        cout << (uf.same(a, b) ? "YES\n" : "NO\n");
    }
}
