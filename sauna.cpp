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
    int n;
    cin >> n;
    
    int max_lower = INT_MIN;  // This will store the maximum of all lower bounds
    int min_upper = INT_MAX;  // This will store the minimum of all upper bounds

    // Read each friend's preferred temperature range
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        // Update the maximum of the lower bounds and the minimum of the upper bounds
        max_lower = max(max_lower, a);
        min_upper = min(min_upper, b);
    }

    // If there's no valid intersection (max_lower > min_upper), print 0
    if (max_lower > min_upper) {
        cout << "bad news" << endl;
    } else {
        // The number of valid temperatures is the size of the intersection
        int count = min_upper - max_lower + 1;
        cout << count << " " << max_lower << endl;
    }

    return 0;
}

