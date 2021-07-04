struct Edge
{
    int u, v, cap, flow = 0;
    Edge(int u, int v, int cap) : u(u), v(v), cap(cap) {}

    int rem_cap()
    {
        return cap - flow;
    }
};

struct Dinic
{
    vt<Edge> edges;
    int n, m = 0, s, t;
    vt<vt<int>> g;
    vt<int> lvl, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t)
    {
        g.resize(n+1);
        lvl.resize(n+1);
        ptr.resize(n+1);
    }

    void add_edge(int u, int v, int cap)
    {
        edges.pb({u, v, cap});
        edges.pb({v, u, 0});
        g[u].pb(m);
        g[v].pb(m+1);
        m += 2;
    }

    bool bfs()
    {
        while(q.size())
        {
            int u = q.front();
            q.pop();
            for(auto i : g[u])
            {
                if(edges[i].rem_cap() > 0 && lvl[edges[i].v] == -1)
                {
                    lvl[edges[i].v] = lvl[u] + 1;
                    q.push(edges[i].v);
                }
            }
        }
        return lvl[t] != -1;
    }

    int dfs(int u, int pushed)
    {
        if(pushed == 0)
            return 0;
        if(u == t)
            return pushed;
        for(int &cid = ptr[u]; cid < (int)g[u].size(); cid++)
        {
            int id = g[u][cid], v = edges[id].v;
            if(lvl[v] == lvl[u] + 1 && edges[id].rem_cap() > 0)
            {
                int tr = dfs(v, min(pushed, edges[id].rem_cap()));
                if(tr == 0)
                    continue;
                edges[id].flow += tr;
                edges[id ^ 1].flow -= tr;
                return tr;
            }
        }
        return 0;
    }

    int flow()
    {
        int f = 0;
        while(1)
        {
            fill(all(lvl), -1);
            lvl[s] = 0;
            q.push(s);
            if(!bfs())
                break;
            fill(all(ptr), 0);
            while(int pushed = dfs(s, inf))
                f += pushed;
        }
        return f;
    }
};
