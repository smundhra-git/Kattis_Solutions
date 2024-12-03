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
#define mult(t) int t; cin >> t; while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;
using namespace std;


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate time required for a problem
long long calculate_t(int A, int B, int C, long long prev_t) {
    return (A * prev_t + B) % C + 1;
}

int main() {
    int n, t;
    cin >> n >> t;

    int A, B, C, t0;
    cin >> A >> B >> C >> t0;

    // Generate the problem times
    vector<long long> times(n);
    times[0] = t0;
    for (int i = 1; i < n; ++i) {
        times[i] = calculate_t(A, B, C, times[i - 1]);
    }

    // Sort times to solve problems with the least time first
    sort(times.begin(), times.end());

    // Calculate the maximum problems solved and the total penalty
    int max_problems = 0;
    long long penalty = 0;
    long long current_time = 0;

    for (int i = 0; i < n; ++i) {
        if (current_time + times[i] > t) {
            break;
        }
        current_time += times[i];
        penalty += current_time;
        max_problems++;
    }

    // Modulo for penalty as it can be large
    const int MOD = 1e9 + 7;
    penalty %= MOD;

    cout << max_problems << " " << penalty << endl;

    return 0;
}
