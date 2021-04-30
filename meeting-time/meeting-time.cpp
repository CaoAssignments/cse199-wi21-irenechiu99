#include <iostream>
#include <queue>
using namespace std;
#define VISUAL //------------> Comment this line out if the cout code is not needed

const int MAXN = 100 + 1;
const int MAXM = 5000;
int n, m, Head[MAXN], EdgeCount = 0, MinLen = 100 * 5000;
bool f[2][MAXN][100 * MAXM];


/* node:
* field = the field ID we are able to reach with t1 and t2 respectively for B and E
* t1 t2 = time needed by Bessie and Elsie respectively
*/
struct node
{
    int field, t1, t2;
};

/* edge:
* one-directed edge 
* prev_edge = previous edge_ID starts from the same field 
*           ---> If prev_edge = 0, there's no other previous edge starting from the same node
* to_field = the field ID that this edge ends at
* Bessie = time needed by Bessie
* Elsie = time needed by Elsie
*/
struct edge
{
    int prev_edge, to_field, Bessie, Elsie;
}Edge[MAXM];

// Read in data: 
// Record the edges in Edge[]{last recorded edgeID that starts from the same node, to_field, time needed for B, and for E}
// Record the nodes in Head[] (update Head[u] with this current edgeID as the latest edgeID starting from this field (the field ID = u))
void insert(int u, int v, int b, int e)
{
    Edge[++EdgeCount] = edge{Head[u], v, b, e};
    Head[u] = EdgeCount; 
}

void BFS()
{
    queue<node> Q;
    // Start from the barn (field ID = 1 with time needed for B and E as 0) 
    Q.push(node{ 1, 0, 0 });

    #ifdef VISUAL
    cout << "Bfs(): HEAD[] = " << endl;
    for (int j = 0; j < 5; j++) cout << Head[j] << endl;
    cout << "Edge[] = " << endl;
    for (int j = 0; j < 5; j++) cout << Edge[j].prev_edge << " " << Edge[j].to_field << " " << Edge[j].Bessie << " " << Edge[j].Elsie << " " << endl;
    #endif

    while (!Q.empty())
    {
        // Get node from the front of the queue, remove it from the queue afterward
        // u.field with t1 and t2 = we can start from this field to the target field with t1 and t2 that we already spent
        node u = Q.front();
        Q.pop();
        
        #ifdef VISUAL
        cout << "Q:pop(): p = " << u.field << ", t1,t2 = " << u.t1 << u.t2 << endl;
        #endif

        // using i to iterate through every node that starts from the u.field
        // i = current edge we at;
        // while i /= 0 (means there are other edges starting from the u.field);
        // starting the next iteration through update the i to the previous edge that starts from the same field. 
        for (int i = Head[u.field]; i; i = Edge[i].prev_edge)
        {
            #ifdef VISUAL
            cout << "In loop: i = " << i << endl;
            #endif

            // Get the next field, v, through the edge starting from u.field
            int v = Edge[i].to_field;

            // Record the path in 3-d array f
            /* X: (X=0) path recorded for Bessie (X=1) path recorded for Elsie
            *  Y: the field we are able to get to
            *  Z: time needed to get to that field 
            *       (u.t = time nedded to get to u.field) 
            *       (Edge[i].Name = time needed to get to the v from the u.field)
            *        u.t1 + Edge[i].Bessie = time needed for Bessie to go to the field v
            *        u.t2 + Edge[i].Elsie = time needed for Elsie to go to the field v
            */ 
            f[0][v][u.t1 + Edge[i].Bessie] = 1;
            f[1][v][u.t2 + Edge[i].Elsie] = 1;

            // If v field is our favorite/target field AND B and E can get there with the same amount of time, update the minLen
            if (v == n)
            {
                //  case 1: u.t1 + Edge[i].Bessie < MinLen ------> Update the MinLen as u.t1 + Edge[i].Bessie
                if (f[0][n][u.t1 + Edge[i].Bessie] && f[1][n][u.t1 + Edge[i].Bessie])
                    MinLen = min(MinLen, u.t1 + Edge[i].Bessie);
                //  case 2: u.t2 + Edge[i].Elsie < MinLen ------> Update the MinLen as u.t2 + Edge[i].Elsie
                if (f[1][n][u.t2 + Edge[i].Elsie] && f[0][n][u.t2 + Edge[i].Elsie])
                    MinLen = min(MinLen, u.t2 + Edge[i].Elsie);
            }

            // case 3: if 
            // 1. not case 1 and case , AND
            // 2. the (u.t1 + Edge[i].Bessie) or the (u.t2 + Edge[i].Elsie) is less than the current MinLen
            // ----> It is possible for the current next node to be a part of our final path solution
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
        int u, v, b, e;
        cin >> u >> v >> b >> e;
        insert(u, v, b, e);
    }
    BFS();

    return 0;
}
