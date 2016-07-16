// SegmentTree
//  使用方法(RMQ)
//  SegmentTree<int> st(n, INT_MAX, [](int a, int b){return min(a, b);});
//
// depends on
#define ST_MAX_N 100
//
template <typename T> class SegmentTree{  // {{{
public:
    int n;
    T data[ST_MAX_N*2-1];
    T init;
    function<T(T, T)> op;
    
    SegmentTree(int n, T init, function<T(T, T)> op){
        this->op = op;
        this->n = 1;
        while(this->n < n){
            this->n *= 2;
        }
        this->init = init;
        for(int i=0;i<this->n*2-1;i++){
            data[i] = init;
        }
        this->op = op;
    }

    void update(int i, T x){
        i += n-1;
        data[i] = x;
        while(i > 0){
            i = (i-1)/2;
            data[i] = op(data[i*2+1], data[i*2+2]);
        }
    }

    int quety(int a, int b){
        if(a > b){
            cout << "SegmentTree: range error!" << endl;
            exit(1);
        }
        return query_r(a, b, 0, 0, n);
    }

    T query_r(int a, int b, int k, int l, int r){
        if(r <= a || b <= l){   // [l, r)が[a, b)の外
            return init;       
        }
        if(a <= l && r <= b){   // [l, r)が[a, b)の中に完全に含まれる
            return data[k];     
        }
        
        T vl = query_r(a, b, k*2+1, l, (l+r)/2);  // 二分探索(左)
        T vr = query_r(a, b, k*2+2, (l+r)/2, r);  // 二分探索(右)

        return op(vl, vr);
    }
};  // }}}

int main(){
    SegmentTree<int> st(11, 0, [](int a, int b){return max(a, b);});
    int a[] = {1, 5, 8, 3, 2, 0, 6, 4, 4, 3, 5};
    rep(i, 0, 11){
        st.update(i, a[i]);
    }
    while(1){
        int a, b;
        cin >> a >> b;
        cout << st.quety(a, b) << endl;
    }
    rep(i, 0, 16*2-1){
        print2(i, st.data[i]);
    }
    return 0;
}
