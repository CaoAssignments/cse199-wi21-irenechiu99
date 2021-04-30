#include <iostream>
#include <queue>
using namespace std;
#define VISUAL //------------> Comment this line out if the cout code is not needed

const int MAXN = 100 + 1;
const int MAXM = 5000;
int n, m, Head[MAXN], EdgeCount = 0, MinLen = 100 * 5000;
bool f[2][MAXN][100 * MAXM];


/* node:
* p = node num (node p can be reached by Head[p])
* t1 t2 = time needed by Bessie and Elsie respectively
*/
struct node
{
    int p, t1, t2;
};

/* edge:
* one-directed edge starts from curr node and ends at next node (node recorded with node_ID_num)
* Bessie = time needed by Bessie (from curr to next)
* Elsie = time needed by Elsie (from curr to next)
*/
struct edge
{
    int curr, next, Bessie, Elsie;
}Edge[MAXM];

// Read in data: 
// Record the edges in Edge[] (index = node_ID_num that the edge starts from)
// Record the nodes in Head[] (index = node_ID_num)
void insert(int u, int v, int b, int e)
{
    Edge[++EdgeCount] = edge{Head[u], v, b, e};
    Head[u] = EdgeCount;
}

void BFS()
{
    queue<node> Q;
    // Start from the barn (node_ID_num = 1) 
    Q.push(node{ 1, 0, 0 });

    #ifdef VISUAL
    cout << "Bfs(): HEAD[] = " << endl;
    for (int j = 0; j < 5; j++) cout << Head[j] << endl;
    cout << "Edge[] = " << endl;
    for (int j = 0; j < 5; j++) cout << Edge[j].curr << " " << Edge[j].next << " " << Edge[j].Bessie << " " << Edge[j].Elsie << " " << endl;
    #endif

    while (!Q.empty())
    {
        // Get node from the front of the queue, remove it from the queue afterward
        node u = Q.front();
        Q.pop();
        
        #ifdef VISUAL
        cout << "Q:pop(): p = " << u.p << ", t1,t2 = " << u.t1 << u.t2 << endl;
        #endif

        // i = current node we at, loop til the i is equal to the initial i
        for (int i = Head[u.p]; i; i = Edge[i].curr)
        {
            #ifdef VISUAL
            cout << "In loop: i = " << i << endl;
            #endif

            // Get the next node v through the edge starting from i
            int v = Edge[i].next;

            // Record the path in 3-d array f
            /* X: (X=0) path recorded for Bessie (X=1) path recorded for Elsie
            *  Y: the next node
            *  Z: time needed to get to that node 
            *       (u.t = time nedded to get to the current node) 
            *       (Edge[i].Name = time needed to get to the next node from the current ont)
            */ 
            f[0][v][u.t1 + Edge[i].Bessie] = 1;
            f[1][v][u.t2 + Edge[i].Elsie] = 1;

            // If next node is equal to the favorite field (the target node) AND B and E can get there with the same amount of time,
            // Update the minLen
            if (v == n)
            {
                // Because we need the minimum time we check if its either the given cases
                //  case 1: u.t1 + Edge[i].Bessie < MinLen ------> Update the MinLen as u.t1 + Edge[i].Bessie
                if (f[0][n][u.t1 + Edge[i].Bessie] && f[1][n][u.t1 + Edge[i].Bessie])
                    MinLen = min(MinLen, u.t1 + Edge[i].Bessie);
                //  case 2: u.t2 + Edge[i].Elsie < MinLen ------> Update the MinLen as u.t2 + Edge[i].Elsie
                if (f[1][n][u.t2 + Edge[i].Elsie] && f[0][n][u.t2 + Edge[i].Elsie])
                    MinLen = min(MinLen, u.t2 + Edge[i].Elsie);
            }
            // case 3: if 
            // 1. the next node is not the target node AND
            // 2. the (u.t1 + Edge[i].Bessie) or the (u.t2 + Edge[i].Elsie) is less than the current MinLen
            // ----> It is possible for the current next node to be a part of our final path
            //       so that we will push this part of path into the queue
            if (u.t1 + Edge[i].Bessie < MinLen || u.t2 + Edge[i].Elsie < MinLen)
                Q.push(node{ v, u.t1 + Edge[i].Bessie, u.t2 + Edge[i].Elsie });
        }
    }
    // When the queue is empty, we check if there is a possible answer
    for (int i = 1; i <= 100 * 5000; i++)
    {
        if (f[0][n][i] && f[1][n][i])
        {
            cout << i << endl;
            return;
        }
    }
    // If not, we will print "IMPOSSIBLE"
    cout << "IMPOSSIBLE" << endl;
}
int main()
{
    // Read in data
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        // Update the Edge[] (edge array) and Head[] (node array)
        int u, v, b, e;
        cin >> u >> v >> b >> e;
        insert(u, v, b, e);
    }
    BFS();

    return 0;
}
