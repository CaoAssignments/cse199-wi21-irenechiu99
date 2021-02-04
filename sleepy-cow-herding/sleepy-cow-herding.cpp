#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //Read the three numbers
    int a, b, c;
    ifstream fin ("herding.in");
    fin >> a >> b >> c;

    // Arrange a,b,c in the increasing order.
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);

    // Initialize output ofstream
    ofstream fout("herding.out");

    /* The minimum number of moves should be:
    *  1. 0, if the three cows (a, b, and c) are consecutive
    *  2. 1, if there are two cows consecutive except for the other one.
    *  3. 2, if this is neighther the first nor the second case. 
    */
    // Case 1: the answer is 0
    if (c == a + 2)
        fout << "0\n";
    // Case 2: the answer is 1
    else if (b == a + 2 || c == b + 2)
        fout << "1\n";
    // Case 3: the answer is 2
    else fout << "2\n";

    /* The maximum number of moves should be:
    * the maximum number of units between any two cows - 1 
    */
    fout << max(b - a, c - b) - 1 << "\n";

    return 0;
}