class MergeSortTree
{
    int n;
    vector<vector<int>> tree;

    private:
    vector<int> merge(vector<int> &v1, vector<int> &v2)
    {
        int i = 0, j = 0;
        vector<int> v;
        while(i < (int)v1.size() && j < (int)v2.size())
        {
            if(v1[i] <= v2[j])
                v.pb(v1[i++]);
            else
                v.pb(v2[j++]);
        }
        for(int k = i; k < (int)v1.size(); k++)
            v.pb(v1[k]);
        for(int k = j; k < (int)v2.size(); k++)
            v.pb(v2[k]);
        return v;
    }

    void build(int *a, int i, int lx, int rx)
    {
        if(lx == rx)
        {
            tree[i].pb(a[lx]);
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, i*2, lx, mid);
        build(a, i*2+1, mid+1, rx);

        tree[i] = merge(tree[i*2], tree[i*2+1]);
    }

    int get(int i, int lx, int rx, int l, int r, int k)
    {
        if(r < lx || l > rx)
        {
            return 0;
        }
        if(lx >= l && rx <= r)
        {
            return (int)tree[i].size() - (upper_bound(all(tree[i]), k) - tree[i].begin());
        }
        int mid = (lx + rx) / 2;
        return (get(2*i, lx, mid, l, r, k) + get(2*i+1, mid+1, rx, l, r, k));
    }

    public:
    MergeSortTree(int *a, int _n)
    {
        n = _n;
        tree.assign(4*n+5, vector<int>());
        build(a, 1, 1, n);
    }

    int get(int l, int r, int k)
    {
        return get(1, 1, n, l, r, k);
    }
};
