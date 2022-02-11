class DSU
{
    int n;
    vector<int> sz, par;
public:
    DSU(int n)
    {
        this->n = n;
        sz.assign(n+1, 1);
        par.assign(n+1, 0);
        iota(par.begin(), par.end(), 0ll);
    }

    int find(int u)
    {
        if(u == par[u])
            return u;
        return (par[u] = find(par[u]));
    }

    bool join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if(u == v)
            return 0;
        if(sz[u] < sz[v])
            swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        return 1;
    }
};
