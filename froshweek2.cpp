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

int main() {
    int n, m;
    cin >> n >> m; // Number of tasks and quiet intervals

    vector<int> tasks(n);
    vector<int> intervals(m);

    for (int i = 0; i < n; i++) {
        cin >> tasks[i]; // Task durations
    }

    for (int i = 0; i < m; i++) {
        cin >> intervals[i]; // Quiet interval durations
    }

    // Sort tasks and intervals
    sort(tasks.begin(), tasks.end());
    sort(intervals.begin(), intervals.end());

    int i = 0, j = 0, count = 0;

    // Match tasks with quiet intervals
    while (i < n && j < m) {
        if (tasks[i] <= intervals[j]) {
            count++;
            i++; // Move to the next task
        }
        j++; // Move to the next interval
    }

    cout << count << endl; // Output the maximum number of tasks Zac can complete

    return 0;
}