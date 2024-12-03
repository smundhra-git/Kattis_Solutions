#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <climits>
#include <queue>
#include <stack>
#include <numeric>
#include <iomanip>

using namespace std;

typedef vector<int> vi;
typedef pair<double, double> ii;
typedef vector<ii> vii;
typedef vector<vector<int> > vvi;
typedef unordered_set<int> uset;
typedef unordered_map<int, int> umap;
typedef vector<bool> vb;
typedef vector<string> vs;


#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int cur = 1; int t; cin >> t; while (t > 0) { solve(); t--; cur++; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n){ cout << x << " ";} cout << endl;;
#define SORT(v) sort(v.begin(), v.end());

// Function to determine if a dog is aggressive at time t
bool isAggressive(int t, int aggressive, int calm) {
    int cycle = aggressive + calm;
    int timeInCycle = t % cycle; // Time within the dog's cycle
    return timeInCycle > 0 && timeInCycle <= aggressive; // Aggressive if within the aggressive period
}

int main() {
    int a, b, c, d; // Aggressive and calm periods for both dogs
    cin >> a >> b >> c >> d;

    int p, m, g; // Arrival times of postman, milkman, and garbage man
    cin >> p >> m >> g;

    // Store the arrival times in a vector
    vi v(3); v[0] = p; v[1] = m; v[2] = g;

    // Process each arrival time
    for (int t : v) {
        bool dog1Aggressive = isAggressive(t, a, b);
        bool dog2Aggressive = isAggressive(t, c, d);

        // Determine the result
        if (dog1Aggressive && dog2Aggressive) {
            cout << "both" << endl;
        } else if (dog1Aggressive || dog2Aggressive) {
            cout << "one" << endl;
        } else {
            cout << "none" << endl;
        }
    }

    return 0;
}