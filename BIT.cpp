class BIT
{
    int n, VAL;
    vt<int> bit;

    public:
    BIT(int _n, int val)
    {
        n = _n;
        VAL = val;
        bit.assign(2*n+2, VAL);
    }
    int todo(int a, int b) { return max(a, b); }
    void update(int i, int x)
    {
        for(; i<=n; i += (i&-i))
            bit[i] = todo(bit[i], x);
    }
    int get(int i)
    {
        int res = VAL;
        for(; i; i -= (i&-i))
            res = todo(res, bit[i]);
        return res;
    }
};
