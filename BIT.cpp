template <typename T>
class BIT {
    int n; T VAL;
    vector<int> bit;

    function<T(T, T)> todo;

    public:
    BIT(int n, int VAL, function<T(T, T)> todo)
    {
        this->n = n;
        this->VAL = n;
        bit.assign(2*n+2, VAL);
        this->todo = todo;
    }
    void update(int i, T x)
    {
        for(; i<=n; i += (i&-i))
            bit[i] = todo(bit[i], x);
    }
    T get(int i)
    {
        T res = VAL;
        for(; i; i -= (i&-i))
            res = todo(res, bit[i]);
        return res;
    }
};

// Usage
// BIT<int> bit(n, inf, [&](int x, int y) {return min(x, y);});
