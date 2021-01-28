#include <iostream>
#include <cstdio>
#include <string>
using namespace std;


#define MAXB 15000

int evaluate(const string& num, int base) {
    return (num[0] - '0') * base * base +
        (num[1] - '0') * base +
        (num[2] - '0');
}


int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string num_in_x, num_in_y;
        cin >> num_in_x >> num_in_y;

        /* Initialize both bases at 10.  Increment the base that produces the
         * smaller evaluated result until they yield an equal result. */
        int X = 10;
        int Y = 10;
        while (X <= MAXB && Y <= MAXB) {
            int num_x = evaluate(num_in_x, X);
            int num_y = evaluate(num_in_y, Y);
            if (num_x < num_y) {
                X++;
            }
            else if (num_y < num_x) {
                Y++;
            }
            else {
                cout << X << ' ' << Y << '\n';
                break;
            }
        }
    }
    return 0;
}