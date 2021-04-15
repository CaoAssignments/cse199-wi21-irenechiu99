#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
using namespace std;

int main()
{
    // Read the number of the pastures and the cows
    int N, M;
    ifstream fin("revegetate.in");
    fin >> N >> M;

    // Set the fav_1 fav_2 vector size to M (the number of cows)
    // Set the color vector size to N (the number of pastures)
    vector<int> fav_1(M);
    vector<int> fav_2(M);
    vector<int> color(N + 1);

    // Read the data and store them in the three vectors 
    // Swap the value to store in fav_1 and fav_2, so at the same index, fav_1[i] is less than fav_2[i]
    for (int i = 0; i < M; i++) {
        cin >> fav_1[i] >> fav_2[i];
        if (fav_1[i] > fav_2[i]) swap(fav_1[i], fav_2[i]);
    }

    // Initialize the output ofstream
    ofstream fout("revegetate.out");

    /* Greedy Algorithm in Graph Coloring:
    *  For i, c, and j, we try fill in colors one by one, starting from the lowest index to the uppder bound of the vector.
    *  i = the place we want to fill in with a color 
    *  c = the final color we choose 
    *  j = iterate through fav_1 and fav_2 to check if there is any conflict
    * 
    *  ref: https://en.wikipedia.org/wiki/Graph_coloring
    *  ref: https://en.wikipedia.org/wiki/Greedy_coloring
    *  
    *  
    *  The following code and the one at the bottom was implemented to measure the time needed for this algorithm.
    *  Note that this solution is different from the one provided by the USACO.
    *  The thing we do differently is to break the loop right after we find a conflict.
    *  By doing this, the runtie should be reduced. This might be proved by amortized complexity model founded by Tarjan.
    *  Even though the worst case is still O(NM), Tarjan's model might be able to prove that the run time of this program is actually linear.
    *  We might need to do more research on it to make a concrete proof on the run time reduction.
    *  However, feel free to play around with the time measurement function and measure the average time needed.
    *  On my side, the run time was half of the one from the USACO website.
    * 
    *  ref: https://epubs.siam.org/doi/pdf/10.1137/0606031?casa_token=72mBETzNsVkAAAAA:cWFw5QX3lSuh6PK8A8pEWxnJV82s-prJcyMrp1BDsUL1gpqlY121Z6whPgMV4N8-yhDfW5BP2_4
    */

    // Real run time measurement (trying to visualize the amortized complexity)
    //clock_t begin_time = clock();

    // i = the place we want to fill in with a color (greedy: starting from 1 to N)
    for (int i = 1; i <= N; i++) {
        // c = the final color we choose
        // (greedy: starting from first color, keep trying until we reach the fourth)
        int c;
        for (c = 1; c <= 4; c++) {

            // j = for each combination of i and c, 
            // we iterate through fav_1 and fav_2 to check if there is any conflict
            for (int j = 0; j <= M; j++) {

                // If there is no conflict (at this point, j should be equal to M),
                // we append that to our final answer and update the color vector
                if (j == M) {
                    color[i] = c;
                    fout << c;

                    // Set c = 5, so we can jump out of this loop to iterate through the next i
                    c = 5;
                }
                else {
                    //If there is a conflict, we break the loop to stop iterate jand start trying next value c
                    if (fav_2[j] == i && color[fav_1[j]] == c) break;
                }       
            }
        }
    }
    fout << "\n";

    // Real run time measurement (trying to visualize the amortized complexity)
    //cout << float(clock() - begin_time) / CLOCKS_PER_SEC;

    return 0;
}

