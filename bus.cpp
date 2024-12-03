#include <iostream>
#include <vector>
using namespace std;

int calculate_initial_passengers(int stops) {
    int passengers = 0;
    for (int i = 0; i < stops; ++i) {
        passengers = passengers * 2 + 1;
    }
    return passengers;
}

int main() {
    int t;
    cin >> t;
    vector<int> results;
    for (int i = 0; i < t; ++i) {
        int stops;
        cin >> stops;
        results.push_back(calculate_initial_passengers(stops));
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
