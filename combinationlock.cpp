#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <climits>
#define vi vector<int>
#define vii(n, m) vector<vector<char> > v(n, vector<char>(m, ' '))
#define viin vector<vector<int> > 
#define us unordered_set<int>
#define pii pair<int, int>
#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int cur = 1; int t; cin >> t; while (t > 0) { solve(cur); t--; cur++; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;
using namespace std;

const int p = 9;
const int N = 40; // Number of positions on the dial


int main() {
    int s, a, b, c;

    while (cin >> s >> a >> b >> c && (s || a || b || c)) {
        int totalDegrees = 0;

        // Step 1: Turn 2 full turns clockwise
        totalDegrees += 720;

        // Step 2: Turn clockwise to the 1st number
        totalDegrees += ((s - a + N) % N) * p;

        // Step 3: Turn 1 full turn counter-clockwise
        totalDegrees += 360;

        // Step 4: Continue counter-clockwise to the 2nd number
        totalDegrees += ((b - a + N) % N) * p;

        // Step 5: Turn clockwise to the 3rd number
        totalDegrees += ((b - c + N) % N) * p;

        // Output the total degrees
        cout << totalDegrees << endl;
    }

    return 0;
}
