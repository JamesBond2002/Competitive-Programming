class SegTree
{
    int n, VAL, tree[2*N+2];

    public:
    SegTree(int _n, int val)
    {
        n = _n;
        VAL = val;
        for(int i = 0; i<=2*n+2; i++)
            tree[i] = VAL;
    }
    int todo(int a, int b) { return max(a, b); }
    void update(int i, int x)
    {
        for(tree[i += n] = x; i > 1; i >>= 1)
            tree[i >> 1] = todo(tree[i], tree[i^1]);
    }
    int get(int l, int r)
    {
        int res = VAL;
        for(l += n, r += n+1; l<r; l >>= 1, r >>= 1)
        {
            if(l & 1) res = todo(res, tree[l++]);
            if(r & 1) res = todo(res, tree[--r]);
        }
        return res;
    }
};
