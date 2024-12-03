#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef pair<double, double> ii;
typedef vector<ii> vii;
typedef vector<vector<int> > vvi;
typedef unordered_set<int> uset;
typedef unordered_map<int, int> umap;
typedef vector<bool> vb;


#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int cur = 1; int t; cin >> t; while (t > 0) { solve(cur); t--; cur++; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n){ cout << x.first << " " << x.second; cout << endl;};

// Function to check if a subset with sum 100 exists using exactly 7 elements
bool solve(int cur_sum, vi& v, vi& ans, int cur, int count) {
    if (cur_sum > 100) return false;  // If the current sum exceeds 100, stop
    if (count == 7) {  // If we've selected 7 elements
        return cur_sum == 100;  // Check if their sum is 100
    }
    if (cur >= v.size()) return false;  // If we've processed all elements, no solution

    // Include the current element in the sum
    ans.push_back(v[cur]);
    if (solve(cur_sum + v[cur], v, ans, cur + 1, count + 1)) return true;  // Move forward including current element

    // Backtrack: Remove the current element and check excluding it
    ans.pop_back();
    return solve(cur_sum, v, ans, cur + 1, count);  // Move forward excluding current element
}

int main() {
    vi v(9);  // Vector to hold the input elements
    for (int i = 0; i < 9; i++) cin >> v[i];  // Input 9 numbers into vector v
    
    vi ans;  // Vector to store the elements that sum up to 100
    if (solve(0, v, ans, 0, 0)) {  // Start with cur_sum = 0, index = 0, and count = 0
        // Output the elements that form the sum of 100
        for (int i : ans) cout << i << endl;
    } else {
        cout << "No solution found!" << endl;  // In case no subset adds up to 100
    }
    
    return 0;
}

