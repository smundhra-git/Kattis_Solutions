#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#define vi vector<int>
#define vii(n, m) vector<vector<char> > v(n, vector<char>(m, ' '))
#define viin vector<vector<int> > 
#define us unordered_set<int>
#define pii pair<int, int>
#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int t; cin >> t; while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 1; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;

using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, s, r;
    cin >> n >> s >> r;

    vector<bool> v(n, true); // true means the kayak is good
    vector<int> reserve(r);

    // Mark damaged kayaks
    for (int i = 0; i < s; i++) {
        int x;
        cin >> x;
        v[x - 1] = false; // Convert to 0-based index
    }

    // Read reserve kayaks
    for (int i = 0; i < r; i++) {
        cin >> reserve[i];
        reserve[i]--; // Convert to 0-based index
    }

    // Sort reserve kayaks for optimal lending
    sort(reserve.begin(), reserve.end());

    // Attempt to lend kayaks
    for (int x : reserve) {
        if (x > 0 && !v[x - 1]) {
            // Lend to the left
            v[x - 1] = true;
        } else if (x < n - 1 && !v[x + 1]) {
            // Lend to the right
            v[x + 1] = true;
        }
    }

    // Count good kayaks
    int good_kayaks = 0;
    for (bool kayak : v) {
        if (kayak) good_kayaks++;
    }

    cout << n-good_kayaks << endl;

    return 0;
}

