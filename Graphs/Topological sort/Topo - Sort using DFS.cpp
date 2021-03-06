// Topo - sort using DFS
// Graph must be a DAG
// Adds a vertex to the stack after processing its neighbours
// Complexity: O(|V| + |E|)
// Usage: [SPOJ] TOPOSORT http://www.spoj.com/problems/TOPOSORT/

const int MAXN = 1e6+5;

bool vis[MAXN];
vector<int> G[MAXN];
stack<int> topo;

void dfs(int v)
{
    vis[v] = 1;
    for (int u : G[v])
    {
        if (vis[u]) continue;
        dfs(u);
    }
    topo.push(v);
}

void sortuj(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
}
