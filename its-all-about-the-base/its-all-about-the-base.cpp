#include <iostream>
#include <cstdio>
#include <string>
using namespace std;


#define MAXB 15000

// Return the N with given num string and base
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

        // Initialize both bases at 10.
        int X = 10;
        int Y = 10;

        while (X <= MAXB && Y <= MAXB) {
            // Get first guess of num_x (with constant string_num num_in_x and current base = X)
            int num_x = evaluate(num_in_x, X);
            // Get the guess of num_y (with constant string_num num_in_y and current base = Y)
            int num_y = evaluate(num_in_y, Y);

            // Increment the base that produces the smaller evaluated result until they yield an equal result.
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