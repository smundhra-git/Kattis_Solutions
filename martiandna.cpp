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
typedef unordered_set<string> uset;
typedef unordered_map<int, int> umap;
typedef vector<bool> vb;
typedef vector<string> vs;


#define in(n, v) for(int top = 0; top < n; top++) cin >> v[top];
#define mult(t) int cur = 1; int t; cin >> t; while (t > 0) { solve(); t--; cur++; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n){ cout << x << endl;}
#define SORT(v) sort(v.begin(), v.end());

int main() {
    int n, a, m;
    cin >> n >> a >> m;

    vector<int> dna(n);
    for (int i = 0; i < n; i++) {
        cin >> dna[i];
    }

    unordered_map<int, int> required;
    for (int i = 0; i < m; i++) {
        int base, qty;
        cin >> base >> qty;
        required[base] = qty;
    }

    unordered_map<int, int> current;
    int left = 0, right = 0, satisfied = 0;
    int minLength = INT_MAX;

    // Initialize the sliding window
    while (right < n) {
        int base = dna[right];
        current[base]++;

        // Check if this base satisfies its required count
        if (required.count(base) && current[base] == required[base]) {
            satisfied++;
        }

        // Try to shrink the window
        while (satisfied == required.size()) {
            minLength = min(minLength, right - left + 1);

            int leftBase = dna[left];
            current[leftBase]--;

            // Check if shrinking the window violates any requirement
            if (required.count(leftBase) && current[leftBase] < required[leftBase]) {
                satisfied--;
            }
            left++;
        }

        right++;
    }

    // Output the result
    if (minLength == INT_MAX) {
        cout << "impossible" << endl;
    } else {
        cout << minLength << endl;
    }

    return 0;
}
