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

// Function to check if a given code can be formed by all strings in v
bool canFormFromAll(const vector<string>& v, const string& code) {
    for (const string& s : v) {
        int pos = 0; // Pointer for the `code`
        for (char c : s) {
            if (pos < code.size() && c == code[pos]) pos++;
        }
        if (pos < code.size()) return false; // If not all characters of `code` are matched
    }
    return true;
}

// Recursive function to generate all k-digit strings
void generateStrings(int k, string current, vector<string>& result) {
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    for (char digit = '0'; digit <= '9'; digit++) {
        generateStrings(k, current + digit, result);
    }
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<string> v(n);
    in(n, v);
    // Generate all possible k-digit strings
    vector<string> k_s;
    generateStrings(k, "", k_s);
    // Check which strings can be formed by all sequences in v
    vector<string> ans;
    for (const string& code : k_s) {
        if (canFormFromAll(v, code)) {
            ans.push_back(code);
        }
    }
    // Output the results
    cout << ans.size() << endl;
    for (const string& a : ans) {
        cout << a << endl;
    }

    return 0;
}
