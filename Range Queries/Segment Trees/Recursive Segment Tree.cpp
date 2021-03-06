// Recursive segment tree (+, sum)

int Tree[2*1024*1024], Base = 1;

void treeBuild(int node)
{
    if (node >= Base) return;
    treeBuild(2*node);
    treeBuild(2*node+1);
    Tree[node] = Tree[2*node] + Tree[2*node+1];
}

void chTree(int node, int left, int right, int l, int r, int v)
{
    if (right < l or r < left) return ;
    if (l <= left and right <= r)
    {
        Tree[node] += v;
        return ;
    }

    int mid = (left + right) >> 1;
    chTree(2*node, left, mid, l, r, v);
    chTree(2*node + 1, mid + 1, right,  l, r, v);
    Tree[node] = Tree[2*node] + Tree[2*node+1];
}

int read(int node, int left, int right, int l, int r)
{
    if (right < l || r < left) return 0;
    if (l <= left && right <= r)
    {
        return Tree[node];
    }

    int mid = (left + right) >> 1;
    return read(2*node, left, mid, l, r) +
            read(2*node + 1, mid + 1, right, l, r);
}
