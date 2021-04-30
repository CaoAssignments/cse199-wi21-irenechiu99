#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define pii pair<int,int>

int N;
// unvisited cell
bool unvis[7][7];
// given graph
int graph[7][7]; //-1 is border, 0 is open, 1 is close
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans = 0;

void calc(int r, int c, int numopen, int numclose, bool second)
{

    // When numopen = numclose, this path is over. An additional optimization can optionally be made. 
    if (numopen == numclose)
    {
        ans = max(ans, numopen + numclose);
        return;
    }

    //there is no need to check solutions that we know cannot be better than the best answer that we have found so far
    //this optimization is not required to solve the given test cases within 1 second
    if (second && (2 * numopen <= ans))
        return;

    // Marked current cell as visited
    unvis[r][c] = false;

    for (int i = 0; i < 4; i++)
    {
        // Four different next steps: up, down, right, left
        int r2 = r + dx[i];
        int c2 = c + dy[i];

        // If that next step has not been visited
        if (unvis[r2][c2])
        {
            // If the current step is '(' and the next step is ')', \
            recursion: once a ')' is found, second is marked as true and only ')' can be added to the path. 
            // If the current step is ')' and the next step is '(', \
            resursion: once a '(' is found, second is marked as false and only '(' can be added to the path
            if (graph[r2][c2] == 1)
                calc(r2, c2, numopen, numclose + 1, true);
            else if (!second)
                calc(r2, c2, numopen + 1, numclose, false);
        }
    }

    // Reset the cell to unvisited
    unvis[r][c] = true;
}
int main()
{
    ifstream in("hshoe.in");
    ofstream out("hshoe.out");

    // Read in the size of the 2-d array
    in >> N;

    //adding a border around the grid makes it easier to check if a location is within the grid
    for (int i = 0; i <= N + 1; i++) 
    {
        unvis[0][i] = unvis[N + 1][i] = unvis[i][0] = unvis[i][N + 1] = false;
        graph[0][i] = graph[N + 1][i] = graph[i][0] = graph[i][N + 1] = -1;
    }

    // Read in data
    for (int i = 1; i <= N; i++)
    {
        string s;
        in >> s;
        for (int j = 1; j <= N; j++)
        {
            unvis[i][j] = true;
            if (s[j - 1] == '(')
                graph[i][j] = 0;
            else
                graph[i][j] = 1;
        }
    }

    // This problem can be solved by recursion, and we can try all possible paths.
    // The part of the path consisting of '(' is constructed first, 
    // and this corresponds to second = false
    if (graph[1][1] == 0)
        calc(1, 1, 1, 0, false);

    out << ans << "\n";
    out.close();
    return 0;
}
