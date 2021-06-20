struct Segtree {
    int mx[N * 2], mn[N * 2];
    int lz[N];
    int n;
    void init(int _n) {
        n = _n;
        for (int i = 0; i < n; i++) mx[i+n] = mn[i+n] = i;
        for (int i = n-1; i > 0; i--) {
            mx[i] = max(mx[i<<1], mx[i<<1|1]);
            mn[i] = min(mn[i<<1], mn[i<<1|1]);
            lz[i] = 0;
        }
    }
    void upd(int p, int d) {
        mx[p] += d, mn[p] += d;
        if (p < n) lz[p] += d;
    }
    void pull(int p) {
        for (; p > 1; p >>= 1) {
            mx[p>>1] = max(mx[p], mx[p^1]);
            mn[p>>1] = min(mn[p], mn[p^1]);
            mn[p>>1] += lz[p>>1], mx[p>>1] += lz[p>>1];
        }
    }
    void push(int p) {
        for (int h = __lg(n); h >= 0; h--) {
            int i = p >> h;
            if (!lz[i>>1]) continue;
            upd(i, lz[i>>1]);
            upd(i^1, lz[i>>1]);
            lz[i>>1] = 0;
        }
    }
    void add(int l, int r, int d) {
        int L = l, R = r;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) upd(l++, d);
            if (r&1) upd(--r, d);
        }
        pull(L+n), pull(R-1+n);
    }
    int Qmin(int l, int r) {
        int res=inf;
        push(l+n), push(r-1+n);
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res=min(res, mn[l++]);
            if (r&1) res=min(res, mn[--r]);
        }
        return res;
    }
    int Qmax(int l, int r) {
        int res=-inf;
        push(l+n), push(r-1+n);
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res=max(res, mx[l++]);
            if (r&1) res=max(res, mx[--r]);
        }
        return res;
    }
};
