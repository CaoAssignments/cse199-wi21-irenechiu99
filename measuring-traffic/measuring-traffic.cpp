// measuring-traffic.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // Read the number of miles
    int N;
    ifstream fin("traffic.in");
    fin >> N;
    
    // Set the vector size to N
    vector<int> lower(N);
    vector<int> upper(N); 
    vector<string> type(N);

    // Read the data and store them in the three vectors 
    for (int i = 0; i < N; i++) { fin >> type[i] >> lower[i] >> upper[i]; }

    // Initilize output ofstream
    ofstream fout("traffic.out");

    /* First, find the lower and upper bound of the INITIAL traffic at mile = 1,
    *  The rule should be simple:
    *  1. When type == "none", narrow down the current range/boundary.
    *  2. When type == "on", current lower bound of the initial traffic - upper bound of the on-ramp traffic.
    *                        current upper bound of the initial traffic - lower bound of the on-ramp traffic.
    *  3. When type == "off", current lower bound of the initail traffic + lower bound of the off-ramp traffic.
    *                         current upper bound of the initial traffic + upper bound of the off-ramp traffic.
    */

    // Initialize a starting value (There is no strict limitation for the initialization)
    int init_lower = -99999, init_upper = 99999;
    // Iterate from index = N-1 (miles = N) to index = 0 (miles = 1)
    for (int i = N - 1; i >= 0; i--) {

        // If the high way does not have on-ramps and off-ramps, narrow/ modify the traffic range
        if (type[i] == "none") { init_lower = max(init_lower, lower[i]); init_upper = min(init_upper,upper[i]); }

        // If the high way has a on-ramp, minus the specific values to the current boundary
        // Make sure the init_lower is not less than 0 before goint into the next iteration
        if (type[i] == "on") { init_lower -= upper[i]; init_upper -= lower[i];  init_lower = max(0, init_lower); }

        // If the high way has a off-ramp, add the specific values to the current boundary 
        if (type[i] == "off") { init_lower += lower[i]; init_upper += upper[i]; }
    }
    //Output the INITIAL traffic in traffic.out file through the fout ofstream
    fout << init_lower << " " << init_upper << endl;

    /* Second, find the lower and upper bound of the ENDING traffic at mile = N,
    *  The rule should be simple:
    *  1. When type == "none", narrow down the current range/boundary.
    *  2. When type == "on", current lower bound of the ending traffic + lower bound of the on-ramp traffic.
    *                        current upper bound of the ending traffic + upper bound of the on-ramp traffic.
    *  3. When type == "off", current lower bound of the ending traffic - upper bound of the off-ramp traffic.
    *                         current upper bound of the ending traffic - lower bound of the off-ramp traffic.
    */

    // Initialize a starting value (There is no strict limitation for the initialization)
    int end_lower = -99999, end_upper = 99999;
    // Iterate from index = 0 (miles = 1) to index = N-1 (miles = N)
    for (int i = 0; i < N; i++) {
        // if the high way does not have on-ramps and off-ramps, narrow/ modify the traffic range
        if (type[i] == "none") { end_lower = max(end_lower, lower[i]); end_upper = min(end_upper, upper[i]); }

        // if the high way has a on-ramp, minus the specific values to the current boundary
        if (type[i] == "on") { end_lower += lower[i]; end_upper += upper[i]; }

        // if the high way has a off-ramp, add the specific values to the current boundary 
        // make sure end_lower is not less than 0 before going into the next iteration
        if (type[i] == "off") { end_lower -= upper[i]; end_upper -= lower[i]; end_lower = max(0, end_lower); }
    }
    //Output the ENDING traffic in traffic.out file through the fout ofstream
    fout << end_lower << " " << end_upper << endl;


}
