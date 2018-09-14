// Computes shortest paths from the source to every other vertex
// Returns 0 in case of a negative cycle
// Complexity: O(|V| * |E|)
// Usage: [SPOJ] NEGCYC http://www.spoj.com/problems/NEGCYC/

#define st first
#define nd second

const int MAXN = 1e4 + 5, inf = 1e9 + 5;

int dist[MAXN]; // Distance from the source
vector<pair<int, int>> G[MAXN];

bool bellman_ford(int src, int n)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = inf;
    }
    dist[src] = 0;
    
    for (int k = 1; k <= n; k++)
    {
        for (int v = 1; v <= n; v++)
        {
            for (auto e : G[v])
            {
                int u = e.st, w = e.nd;
                if (dist[u] > dist[v] + w)
                {
                    dist[u] = dist[v] + w;
                    if (k == n) return 0;
                }
            }
        }
    }
    
    return 1;
}
