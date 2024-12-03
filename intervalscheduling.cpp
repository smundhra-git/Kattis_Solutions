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
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct interval {
    int lower;
    int higher;
};

bool compare(interval a, interval b) {
    return a.higher < b.higher; // Sort intervals by their end points
}

int main() {
    int n;
    cin >> n;

    vector<interval> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].lower >> intervals[i].higher;
    }

    // Sort intervals by their end points
    sort(intervals.begin(), intervals.end(), compare);

    int max_intervals = 0;
    int last_selected_end = INT32_MIN;

    // Select intervals greedily
    for (const auto& inter : intervals) {
        if (inter.lower >= last_selected_end) {
            max_intervals++;
            last_selected_end = inter.higher;
        }
    }

    cout << max_intervals << endl;
    return 0;
}