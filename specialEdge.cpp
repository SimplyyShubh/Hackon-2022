#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> mark;
vector<bool> vis;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1)
{
    vis[v] = true;
    tin[v] = low[v] = timer++;
    for (pair<int, int> curr : adj[v])
    {
        int to = curr.first;
        int idx = curr.second;
        if (to == p)
            continue;
        if (vis[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
            {
                mark[idx] = 1;
            }
        }
    }
}

void find_bridges(int N)
{
    timer = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
}

class DSU
{

public:
    vector<int> par;
    vector<int> sz;

    DSU(int n)
    {
        par = vector<int>(n + 1);
        sz = vector<int>(n + 1);
        for (int i = 0; i <= n; ++i)
            par[i] = i;
        for (int i = 0; i <= n; ++i)
            sz[i] = 1;
    }

    int findP(int u)
    {
        if (par[u] == u)
            return u;
        return par[u] = findP(par[u]);
    }

    void join(int u, int v)
    {
        if (findP(u) == findP(v))
            return;
        int paru = findP(u);
        int parv = findP(v);
        if (sz[paru] > sz[parv])
        {
            par[parv] = par[paru];
            sz[paru] += sz[parv];
        }
        else
        {
            par[paru] = par[parv];
            sz[parv] += sz[paru];
        }
    }
};

long long special_sol(int N, int M, vector<vector<int>> Edg)
{

    adj = vector<vector<pair<int, int>>>(N + 1);
    vis = vector<bool>(N + 1);
    tin = vector<int>(N + 1, -1);
    low = vector<int>(N + 1, -1);
    for (int i = 0; i < M; ++i)
    {
        int u = Edg[i][0];
        int v = Edg[i][1];
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});:
    }
    mark = vector<int>(M);
    find_bridges(N);
    DSU s(N);
    for (int i = 0; i < M; ++i)
    {
        if (!mark[i])
            s.join(Edg[i][0], Edg[i][1]);
    }

    long long ans = 0;
    for (int i = 0; i < M; ++i)
    {
        if (mark[i] == 0)
            continue;
        int a = Edg[i][0];
        int b = Edg[i][1];
        long long para = s.findP(a);
        long long parb = s.findP(b);
        ans += s.sz[para] * s.sz[parb];
    }
    return ans;
}