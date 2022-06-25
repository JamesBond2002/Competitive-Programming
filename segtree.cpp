template <typename T>
class SegTree {
    int n;
    T VAL;
    vector<T> tree;

    function<T(T, T)> todo;

    public:
    SegTree(int n, int VAL, function<T(T, T)> todo) {
        this->n = n;
        this->VAL = VAL;
        tree.assign(2*n+2, VAL);
        this->todo = todo;
    }
    void update(int i, T x) {
        for(tree[i += n] = x; i > 1; i >>= 1)
            tree[i >> 1] = todo(tree[i], tree[i^1]);
    }
    T get(int l, int r) {
        T res = VAL;
        for(l += n, r += n+1; l<r; l >>= 1, r >>= 1) {
            if(l & 1) res = todo(res, tree[l++]);
            if(r & 1) res = todo(res, tree[--r]);
        }
        return res;
    }
};

// Usage of SegTree class
// SegTree<int> tmx(n+1, -inf, [&](int x, int y) -> int {return max(x, y);});
