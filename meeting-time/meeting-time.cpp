#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 100 + 1;
const int MAXM = 5000;
int n, m, Head[MAXN], EdgeCount = 0, MinLen = 100 * 5000;
bool f[2][MAXN][100 * MAXM];


struct node
{
    int p, t1, t2;
};
struct edge
{
    int Next, Aim, Bessie, Elsie;
}Edge[MAXM];

void insert(int u, int v, int b, int e)
{
    Edge[++EdgeCount] = edge{Head[u], v, b, e};
    Head[u] = EdgeCount;
}

void BFS()
{
    queue<node> Q;
    Q.push(node{ 1, 0, 0 });
    while (!Q.empty())
    {
        node u = Q.front();
        Q.pop();
        for (int i = Head[u.p]; i; i = Edge[i].Next)
        {
            int v = Edge[i].Aim;
            f[0][v][u.t1 + Edge[i].Bessie] = 1;
            f[1][v][u.t2 + Edge[i].Elsie] = 1;
            if (v == n)
            {
                if (f[0][n][u.t1 + Edge[i].Bessie] && f[1][n][u.t1 + Edge[i].Bessie])
                    MinLen = min(MinLen, u.t1 + Edge[i].Bessie);
                if (f[1][n][u.t2 + Edge[i].Elsie] && f[0][n][u.t2 + Edge[i].Elsie])
                    MinLen = min(MinLen, u.t2 + Edge[i].Elsie);
            }
            if (u.t1 + Edge[i].Bessie < MinLen || u.t2 + Edge[i].Elsie < MinLen)
                Q.push(node{ v, u.t1 + Edge[i].Bessie, u.t2 + Edge[i].Elsie });
        }
    }
    for (int i = 1; i <= 100 * 5000; i++)
    {
        if (f[0][n][i] && f[1][n][i])
        {
            cout << i << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, b, e;
        cin >> u >> v >> b >> e;
        insert(u, v, b, e);
    }
    BFS();
    return 0;
}
