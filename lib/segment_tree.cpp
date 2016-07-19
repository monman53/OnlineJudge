// SegmentTree (検証済み)
//  使用方法(RMQ)
//  SegmentTree<int> st(n, INT_MAX, [](int a, int b){return min(a, b);});
//
// depends on
#define ST_MAX_N 100000
//
template <typename T> class SegmentTree{  // {{{
public:
    int n;
    T data[ST_MAX_N*4];
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
    }

    void update(int i, T x){
        i += n-1;
        data[i] = x;
        while(i > 0){
            i = (i-1)/2;
            data[i] = op(data[i*2+1], data[i*2+2]);
        }
    }

    int query(int a, int b){
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
